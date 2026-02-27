@echo off
echo ============================================
echo  Релиз-сборка (template_release)
echo ============================================

:: Проверяем что субмодули на месте
if not exist "godot-cpp\SConstruct" (
    echo [ОШИБКА] Субмодули не найдены! Сначала запустите setup.bat
    pause
    exit /b 1
)

:: Сборка release
scons platform=windows target=template_release compiler=clang-cl -j%NUMBER_OF_PROCESSORS% compiledb=yes

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [ОШИБКА] Сборка release провалилась!
    pause
    exit /b 1
)

echo.
echo ============================================
echo  [OK] Release-сборка завершена успешно!
echo  compile_commands.json обновлён.
echo ============================================
pause