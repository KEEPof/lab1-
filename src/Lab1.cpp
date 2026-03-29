//
// Created by Кип on 27.02.2026.
//

#include "Lab1.h"

void Lab1::_bind_methods() {
	UtilityFunctions::print("!!! Lab1::_bind_methods CALLED !!!");
	ClassDB::bind_method(D_METHOD("recursion1", "n"), &Lab1::recursion1);
	ClassDB::bind_method(D_METHOD("recursion2", "n"), &Lab1::recursion2);
	ClassDB::bind_method(D_METHOD("recursion3", "n"), &Lab1::recursion3);
	ClassDB::bind_method(D_METHOD("iteration1", "n"), &Lab1::iteration1);
	ClassDB::bind_method(D_METHOD("iteration2", "n"), &Lab1::iteration2);
}