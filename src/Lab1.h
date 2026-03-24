//
// Created by Кип on 27.02.2026.
//

#ifndef GODOT_CPP_TEMPLATE_LAB1_H
#define GODOT_CPP_TEMPLATE_LAB1_H

#include "RecursionResult.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/time.hpp"
#include "godot_cpp/variant/dictionary.hpp"
#include "godot_cpp/variant/string.hpp"
#include "types.h"

using namespace godot;

class Lab1 : public RefCounted {
	GDCLASS(Lab1, RefCounted)

private:
	static String format_duration_us(u64 us) {
		if (us < 1000)
			return String::num_uint64(us) + " us";
		if (us < 1'000'000)
			return String::num(us / 1e3, 2) + " ms";
		return String::num(us / 1e6, 3) + " s";
	}

protected:
	static void _bind_methods();

public:
	Lab1() = default;
	~Lab1() override = default;

	// ================= РЕКУРСИЯ 1 =================
	i64 recursion_internal1(i32 n, i32 &call_count,
							i32 current_depth, i32 &max_depth) {
		call_count++;

		current_depth++;
		if (current_depth > max_depth)
			max_depth = current_depth;

		if (n == 1)
			return 1;

		if (n % 2 == 0)
			return n + recursion_internal1(n - 1, call_count, current_depth, max_depth);

		return recursion_internal1(n - 1, call_count, current_depth, max_depth)
			 + 2 * recursion_internal1(n - 2, call_count, current_depth, max_depth);
	}

	Ref<RecursionResult> recursion1(i32 n) {
		Ref<RecursionResult> result;
		result.instantiate();

		int call_count = 0;
		int max_depth = 0;

		if (n <= 0) {
			result->success = false;
			result->value = 0;
			result->calls = 0;
			result->error = "n must be > 0";
			return result;
		}

		u64 start = Time::get_singleton()->get_ticks_usec();

		i64 value = recursion_internal1(n, call_count, 0, max_depth);

		u64 end = Time::get_singleton()->get_ticks_usec();

		result->success = true;
		result->value = value;
		result->calls = call_count;
		result->error = "";
		result->time = format_duration_us(end - start);

		u64 frame_size =
			sizeof(i32) +
			sizeof(i32) +
			sizeof(i32) +
			sizeof(i32) +
			sizeof(i64);

		result->memory_amount = max_depth * frame_size;

		return result;
	}

	// ================= РЕКУРСИЯ 2 =================
	i64 recursion_internal2(i32 n, i32& call_count,
							 i32 current_depth, i32& max_depth) {
		call_count++;

		current_depth++;
		if (current_depth > max_depth)
			max_depth = current_depth;

		if (n < 3)
			return 1;

		if (n % 2 != 0)
			return recursion_internal2(n - 1, call_count, current_depth, max_depth)
				 + recursion_internal2(n - 2, call_count, current_depth, max_depth);

		i64 sum = 0;
		for (int i = 1; i <= n - 1; i++) {
			sum += recursion_internal2(i, call_count, current_depth, max_depth);
		}
		return sum;
	}

	Ref<RecursionResult> recursion2(i32 n) {
		Ref<RecursionResult> result;
		result.instantiate();

		int call_count = 0;
		int max_depth = 0;

		if (n <= 0) {
			result->success = false;
			result->value = 0;
			result->calls = 0;
			result->error = "n must be > 0";
			return result;
		}

		u64 start = Time::get_singleton()->get_ticks_usec();

		i64 value = recursion_internal2(n, call_count, 0, max_depth);

		u64 end = Time::get_singleton()->get_ticks_usec();

		result->success = true;
		result->value = value;
		result->calls = call_count;
		result->error = "";
		result->time = format_duration_us(end - start);

		u64 frame_size =
			sizeof(i32) +
			sizeof(i32) +
			sizeof(i32) +
			sizeof(i32) +
			sizeof(i64);

		result->memory_amount = max_depth * frame_size;

		return result;
	}






	// ================= ИТЕРАЦИЯ 1 =================
	i64 iteration_internal1(i32 n) {
		if (n == 1)
			return 1;
		if (n == 2)
			return 3;

		i64 prev2 = 1;
		i64 prev1 = 3;

		for (int i = 3; i <= n; i++) {
			i64 current;
			if (i % 2 == 0)
				current = i + prev1;
			else
				current = prev1 + 2 * prev2;
			prev2 = prev1;
			prev1 = current;
		}

		return prev1;
	}

	Ref<RecursionResult> iteration1(i32 n) {
		Ref<RecursionResult> result;
		result.instantiate();

		if (n <= 0) {
			result->success = false;
			result->value = 0;
			result->calls = 0;
			result->error = "n must be > 0";
			return result;
		}

		u64 start = Time::get_singleton()->get_ticks_usec();
		i64 value = iteration_internal1(n);
		u64 end = Time::get_singleton()->get_ticks_usec();

		result->success = true;
		result->value = value;
		result->calls = n;
		result->error = "";
		result->time = format_duration_us(end - start);

		result->memory_amount =
			sizeof(i32) +
			sizeof(i64) * 3 +
			sizeof(int);

		return result;
	}

	// ================= ИТЕРАЦИЯ 2 =================
	i64 iteration_internal2(i32 n) {
		if (n < 3)
			return 1;

		i64 f1 = 1;
		i64 f2 = 1;
		i64 total = 2;

		for (int i = 3; i <= n; i++) {
			i64 f_i;
			if (i % 2 != 0) {
				f_i = f2 + f1;
			} else {
				f_i = total;
			}
			total += f_i;
			f1 = f2;
			f2 = f_i;
		}

		return f2;
	}

	Ref<RecursionResult> iteration2(i32 n) {
		Ref<RecursionResult> result;
		result.instantiate();

		if (n <= 0) {
			result->success = false;
			result->value = 0;
			result->calls = 0;
			result->error = "n must be > 0";
			return result;
		}

		u64 start = Time::get_singleton()->get_ticks_usec();
		i64 value = iteration_internal2(n);
		u64 end = Time::get_singleton()->get_ticks_usec();

		result->success = true;
		result->value = value;
		result->calls = n;
		result->error = "";
		result->time = format_duration_us(end - start);

		result->memory_amount =
			sizeof(i64) * 4 +
			sizeof(int) +
			sizeof(i32);

		return result;
	}

};

#endif //GODOT_CPP_TEMPLATE_LAB1_H
