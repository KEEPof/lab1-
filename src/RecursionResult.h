//
// Created by Кип on 28.02.2026.
//

#ifndef GODOT_CPP_TEMPLATE_RECURSIONRESULT_H
#define GODOT_CPP_TEMPLATE_RECURSIONRESULT_H
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/string.hpp"
#include "types.h"

class RecursionResult : public godot::RefCounted {
	GDCLASS(RecursionResult, godot::RefCounted)

protected:
	static void _bind_methods();

public:
	bool success = false;
	i64 value = 0;
	int calls = 0;
	godot::String error = godot::String();
	godot::String time = godot::String();
	u64 memory_amount = 0;

	RecursionResult() = default;
	~RecursionResult() override = default;

	bool get_success() const { return success; }
	i64 get_value() const { return value; }
	i32 get_calls() const { return calls; }
	godot::String get_error() const { return error; }
	godot::String get_time() const { return time; }
	u64 get_memory_amount() const { return memory_amount; }
};

#endif //GODOT_CPP_TEMPLATE_RECURSIONRESULT_H
