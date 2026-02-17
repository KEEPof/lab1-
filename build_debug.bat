@echo off
echo ============================================
echo  Дебаг-сборка (template_debug)
echo ============================================

:: Проверяем что субмодули на месте
if not exist "godot-cpp\SConstruct" (
    echo [ОШИБКА] Субмодули не найдены! Сначала запустите setup.bat
    pause
    exit /b 1
)

:: Сборка debug
scons platform=windows target=template_debug use_mingw=yes -j%NUMBER_OF_PROCESSORS% compiledb=yes dev_build=yes

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [ОШИБКА] Сборка debug провалилась!
    pause
    exit /b 1
)

echo.
echo ============================================
echo  [OK] Debug-сборка завершена успешно!
echo  compile_commands.json обновлён.
echo ============================================
pause