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

	i64 recursion_internal(i32 n, i32& call_count) {
		call_count++;

		if (n == 1)
			return 1;

		if (n % 2 == 0)
			return n + recursion_internal(n - 1, call_count);

		return recursion_internal(n - 1, call_count) + 2 * recursion_internal(n - 2, call_count);
	}

	Ref<RecursionResult> recursion1(i32 n) {
		Ref<RecursionResult> result;
		result.instantiate();
		int call_count = 0;

		if (n <= 0) {
			result->success = false;
			result->value   = 0;
			result->calls   = 0;
			result->error   = "n must be > 0";
			return result;
		}

		i64 value = recursion_internal(n, call_count);

		result->success = true;
		result->value   = value;
		result->calls   = call_count;
		result->error   = "";

		return result;
	}
};

#endif //GODOT_CPP_TEMPLATE_LAB1_H
