//
// Created by Кип on 28.02.2026.
//

#ifndef GODOT_CPP_TEMPLATE_TYPES_H
#define GODOT_CPP_TEMPLATE_TYPES_H

using i8  = signed char;
using i16 = short;
using i32 = int;
using i64 = long long;

using u8  = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;

using f32 = float;
using f64 = double;

using bool8 = bool;

using char8  = char;
using wchar  = wchar_t;
using char16 = char16_t;
using char32 = char32_t;

using usize = unsigned long long;
using isize = long long;

static_assert(sizeof(i8)  == 1, "i8 must be 1 byte");
static_assert(sizeof(i16) == 2, "i16 must be 2 bytes");
static_assert(sizeof(i32) == 4, "i32 must be 4 bytes");
static_assert(sizeof(i64) == 8, "i64 must be 8 bytes");
static_assert(sizeof(u8)  == 1, "u8 must be 1 byte");
static_assert(sizeof(u16) == 2, "u16 must be 2 bytes");
static_assert(sizeof(u32) == 4, "u32 must be 4 bytes");
static_assert(sizeof(u64) == 8, "u64 must be 8 bytes");
static_assert(sizeof(f32) == 4,  "f32 must be 4 bytes");
static_assert(sizeof(f64) == 8,  "f64 must be 8 bytes");
static_assert(sizeof(bool8) == 1, "bool must be 1 byte");
static_assert(sizeof(usize) == sizeof(void*), "usize must match pointer size");
static_assert(sizeof(isize) == sizeof(void*), "isize must match pointer size");


#endif //GODOT_CPP_TEMPLATE_TYPES_H
