@echo off
echo ============================================
echo  Инициализация субмодулей...
echo ============================================

git submodule update --init --recursive

if %ERRORLEVEL% NEQ 0 (
    echo [ОШИБКА] Не удалось скачать субмодули!
    pause
    exit /b 1
)

echo.
echo [OK] Субмодули успешно загружены.

:: Генерация compile_commands.json
echo.
echo Генерация compile_commands.json...
scons compiledb=yes compile_commands.json

echo.
echo ============================================
echo  Готово!
echo ============================================
pause