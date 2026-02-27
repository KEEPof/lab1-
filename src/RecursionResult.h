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
	bool success;
	i64 value;
	int calls;
	godot::String error;

	RecursionResult() = default;
	~RecursionResult() override = default;

	bool get_success() const { return success; }
	i64 get_value() const { return value; }
	i32 get_calls() const { return calls; }
	godot::String get_error() const { return error; }
};

#endif //GODOT_CPP_TEMPLATE_RECURSIONRESULT_H
