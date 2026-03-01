//
// Created by Кип on 27.02.2026.
//

#ifndef GODOT_CPP_TEMPLATE_LAB1_H
#define GODOT_CPP_TEMPLATE_LAB1_H

#include "RecursionResult.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/dictionary.hpp"
#include "godot_cpp/variant/string.hpp"
#include "types.h"

using namespace godot;

class Lab1 : public RefCounted {
	GDCLASS(Lab1, RefCounted)

private:
protected:
	static void _bind_methods();

public:
	Lab1() = default;
	~Lab1() override = default;

	i64 recursion_internal1(i32 n, i32 &call_count) {
		call_count++;

		if (n == 1)
			return 1;

		if (n % 2 == 0)
			return n + recursion_internal1(n - 1, call_count);

		return recursion_internal1(n - 1, call_count) + 2 * recursion_internal1(n - 2, call_count);
	}

	Ref<RecursionResult> recursion1(i32 n) {
		Ref<RecursionResult> result;
		result.instantiate();
		int call_count = 0;

		if (n <= 0) {
			result->success = false;
			result->value = 0;
			result->calls = 0;
			result->error = "n must be > 0";
			return result;
		}

		i64 value = recursion_internal1(n, call_count);

		result->success = true;
		result->value = value;
		result->calls = call_count;
		result->error = "";

		return result;
	}


	i64 recursion_internal2(i32 n, i32 &call_count) {
		call_count++;

		if (n < 3)
			return 1;
		if (n % 2 != 0)
			return recursion_internal2(n - 1, call_count) + recursion_internal2(n - 2, call_count);

		i64 sum = 0;
		for (int i = 1; i <= n - 1; i++) {
			sum += recursion_internal2(i, call_count);
		}
		return sum;
	}

	Ref<RecursionResult> recursion2(i32 n) {
		Ref<RecursionResult> result;
		result.instantiate();
		int call_count = 0;

		if (n <= 0) {
			result->success = false;
			result->value = 0;
			result->calls = 0;
			result->error = "n must be > 0";
			return result;
		}

		i64 value = recursion_internal2(n, call_count);

		result->success = true;
		result->value = value;
		result->calls = call_count;
		result->error = "";

		return result;
	}
};

#endif //GODOT_CPP_TEMPLATE_LAB1_H
