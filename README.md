# Godot C++ Template

Шаблон проекта для создания GDExtension (C++ расширений) для Godot 4.

## Быстрый старт

### Требования
- Godot 4.x
- SCons
- C++ компилятор (MSVC для Windows)

### Сборка

```bash
# Debug сборка
scons platform=windows target=template_debug

# Release сборка
scons platform=windows target=template_release
```

Или используйте готовые скрипты:
- `build_debug.bat`
- `build_release.bat`

### Структура проекта

```
godot-cpp-template/
├── bin/                    # Скомпилированные библиотеки
├── doc_classes/            # XML документация классов
├── godot-cpp/              # Подмодуль godot-cpp
├── project/                # Godot проект
│   ├── bin/                # DLL для.runtime
│   ├── lab1.gd            # Скрипт лабораторной работы
│   └── lab1.tscn          # Сцена лабораторной работы
├── src/                    # Исходный код C++
│   ├── Lab1.cpp/h         # Класс лабораторной работы
│   ├── RecursionResult.h  # Результат рекурсии
│   └── example_class.cpp/h # Пример класса
├── SConstruct             # Скрипт сборки
└── build_profile.json     # Профиль оптимизации сборки
```

## Классы

### Lab1
Основной класс с реализацией рекурсивных алгоритмов:
- `recursion1(n)` - первая рекурсия
- `recursion2(n)` - вторая рекурсия

### RecursionResult
Структура результата вычисления:
- `success` - успешность операции
- `value` - вычисленное значение
- `calls` - количество вызовов рекурсии
- `error` - сообщение об ошибке

## Использование

1. Соберите расширение: `scons platform=windows target=template_debug`
2. Скопируйте DLL в `project/bin/windows/`
3. Запустите проект в Godot
4. Введите число n и нажмите кнопку для вычисления
