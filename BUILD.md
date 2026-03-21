# Сборка проекта

## Инструменты

- **SCons** - система сборки
- **godot-cpp** - C++ библиотека для создания GDExtension

## Скрипты сборки

### build_debug.bat
```bat
scons platform=windows target=template_debug
```
Создаёт отладочную сборку с символами отладки.

### build_release.bat
```bat
scons platform=windows target=template_release
```
Создаёт оптимизированную релизную сборку.

## Конфигурация (SConstruct)

Основные параметры:
- `platform` - целевая платформа (windows, linux, macos)
- `target` - тип сборки (template_debug, template_release)
- `build_profile.json` - профиль оптимизации (опционально)

## Профиль сборки (build_profile.json)

Можно использовать для уменьшения времени компиляции путём отключения неиспользуемых классов.

```json
{
    "enabled_classes": [
        "Lab1",
        "RecursionResult"
    ]
}
```

## Результат сборки

После компиляции создаётся:
- `bin/windows/EXTENSION-NAME.windows.template_debug.x86_64.dll`
- `bin/windows/EXTENSION-NAME.windows.template_debug.x86_64.lib`

DLL копируется в:
- `project/bin/windows/EXTENSION-NAME.windows.template_debug.x86_64.dll`

## Требования для компиляции

- Godot 4.x headers (в godot-cpp подмодуле)
- MSVC или другой C++ компилятор
- Python 3.x с SCons
