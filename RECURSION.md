# Рекурсивные алгоритмы

## Recursion 1

### Логика
```cpp
if (n == 1) return 1;
if (n % 2 == 0)  // n чётное
    return n + recursion_internal1(n - 1, call_count);
else             // n нечётное
    return recursion_internal1(n - 1, call_count) + 2 * recursion_internal1(n - 2, call_count);
```

### Примеры вычислений
| n | f(n) |
|---|------|
| 1 | 1 |
| 2 | 2 + f(1) = 2 + 1 = 3 |
| 3 | f(2) + 2*f(1) = 3 + 2 = 5 |
| 4 | 4 + f(3) = 4 + 5 = 9 |
| 5 | f(4) + 2*f(3) = 9 + 18 = 27 |

### Особенности
- Базовый случай: n = 1
- Для чётных n: прибавляет n к результату
- Для нечётных n: удваивает предыдущий результат

---

## Recursion 2

### Логика
```cpp
if (n < 3) return 1;
if (n % 2 != 0)  // n нечётное
    return recursion_internal2(n - 1, call_count) + recursion_internal2(n - 2, call_count);
else             // n чётное
    // сумма f(i) для i от 1 до n-1
```

### Примеры вычислений
| n | f(n) |
|---|------|
| 1 | 1 |
| 2 | 1 |
| 3 | f(2) + f(1) = 1 + 1 = 2 |
| 4 | f(1) + f(2) + f(3) = 1 + 1 + 2 = 4 |
| 5 | f(4) + f(3) = 4 + 2 = 6 |

### Особенности
- Базовый случай: n < 3 (возвращает 1)
- Для нечётных n: похоже на Фибоначчи f(n-1) + f(n-2)
- Для чётных n: сумма всех предыдущих значений

---

## Взаимодействие с UI

### Интерфейс (lab1.tscn)
- **CheckBox2** - выбор Recursion 1
- **CheckBox** - выбор Recursion 2
- **TextEdit** - ввод числа n
- **Button** - запуск вычисления
- **Label3** - вывод результата
- **Label4** - отображение названия выбранной рекурсии

### Обработка (lab1.gd)
```gdscript
func _on_button1_pressed():
    var n = int(text_input.text)
    if check_box_1.button_pressed:
        result = lab.recursion1(n)
    if check_box_2.button_pressed:
        result = lab.recursion2(n)
    text_output1.text = str(result.get_value())
```

### Доступные методы
- `recursion1(n)` - рекурсивная версия 1
- `recursion2(n)` - рекурсивная версия 2
- `iteration1(n)` - итеративная версия 1
- `iteration2(n)` - итеративная версия 2

### Тип RecursionResult
Возвращается из обоих методов:
- `success` - bool
- `value` - i64 (результат вычисления)
- `calls` - i32 (количество вызовов)
- `error` - String (сообщение об ошибке, если n <= 0)
