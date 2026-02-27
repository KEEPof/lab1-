//
// Created by Кип on 27.02.2026.
//

#include "Lab1.h"

void Lab1::_bind_methods() {
	UtilityFunctions::print("!!! Lab1::_bind_methods CALLED !!!");
	ClassDB::bind_method(D_METHOD("recursion1", "n"), &Lab1::recursion1);
}