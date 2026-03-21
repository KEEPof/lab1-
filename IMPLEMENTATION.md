# Реализация C++ классов

## Файловая структура исходного кода

```
src/
├── Lab1.h              # Заголовочный файл Lab1
├── Lab1.cpp            # Регистрация методов Lab1
├── RecursionResult.h   # Заголовочный файл RecursionResult
├── RecursionResult.cpp # Регистрация методов RecursionResult
├── example_class.h    # Пример класса из шаблона
├── example_class.cpp
├── register_types.h   # Регистрация всех типов
├── register_types.cpp
├── types.h            # Определения типов (i64, i32)
└── gen/               # Сгенерированные файлы
    └── doc_data.gen.cpp
```

## Класс Lab1

Наследуется от `RefCounted` (объект с подсчётом ссылок).

### Заголовочный файл (Lab1.h)

```cpp
class Lab1 : public RefCounted {
    GDCLASS(Lab1, RefCounted)

public:
    // Рекурсия 1
    Ref<RecursionResult> recursion1(i32 n);
    
    // Рекурсия 2
    Ref<RecursionResult> recursion2(i32 n);
};
```

### Регистрация методов (Lab1.cpp)

```cpp
void Lab1::_bind_methods() {
    ClassDB::bind_method(D_METHOD("recursion1", "n"), &Lab1::recursion1);
    ClassDB::bind_method(D_METHOD("recursion2", "n"), &Lab1::recursion2);
}
```

## Класс RecursionResult

Структура для возврата результата вычисления.

### Свойства
- `bool success` - успешность выполнения
- `i64 value` - вычисленное значение
- `i32 calls` - количество вызовов рекурсии
- `String error` - сообщение об ошибке

### Геттеры
```cpp
bool get_success() const;
i64 get_value() const;
i32 get_calls() const;
String get_error() const;
```

## Итеративные версии

### Lab1 - iteration1
Итеративная версия первой рекурсии. Использует два последних значения для вычисления следующего.

### Lab1 - iteration2
Итеративная версия второй рекурсии. Использует два последних значения, для чётных n вычисляет сумму всех предыдущих.

## Регистрация типов (register_types.h/cpp)

Все типы должны быть зарегистрированы в Godot:

```cpp
// register_types.cpp
void register_lab1_types() {
    ClassDB::register_class<Lab1>();
    ClassDB::register_class<RecursionResult>();
}

void unregister_lab1_types() {
    // Очистка при выгрузке
}
```

## Типы данных (types.h)

```cpp
using i64 = int64_t;
using i32 = int32_t;
using u32 = uint32_t;
```

## Использование в GDScript

```gdscript
var lab = Lab1.new()
var result = lab.recursion1(5)

if result.get_success():
    print("Value: ", result.get_value())
    print("Calls: ", result.get_calls())
else:
    print("Error: ", result.get_error())
```
