//
// Created by Кип on 28.02.2026.
//

#include "RecursionResult.h"

void RecursionResult::_bind_methods() {
	godot::ClassDB::bind_method(godot::D_METHOD("get_success"), &RecursionResult::get_success);
	godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &RecursionResult::get_value);
	godot::ClassDB::bind_method(godot::D_METHOD("get_calls"), &RecursionResult::get_calls);
	godot::ClassDB::bind_method(godot::D_METHOD("get_error"), &RecursionResult::get_error);
	godot::ClassDB::bind_method(godot::D_METHOD("get_time"), &RecursionResult::get_time);
	godot::ClassDB::bind_method(godot::D_METHOD("get_digits_output"), &RecursionResult::get_digits_output);
	godot::ClassDB::bind_method(godot::D_METHOD("get_memory_amount"), &RecursionResult::get_memory_amount);

	ADD_PROPERTY(godot::PropertyInfo(godot::Variant::BOOL, "success"), "", "get_success");
	ADD_PROPERTY(godot::PropertyInfo(godot::Variant::STRING, "digits_output"), "", "get_digits_output");
}