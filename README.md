# Laboratory work VI

Цель работы: создание покетов для изменения(должны сочетаться с тегами) Для этого нужно добавить ветлвение в конфигурационные файлы для СL.

Сборка проекта и локальная генерация пакетов

Команда: `cmake -H. -B_build`

<details>
<summary>Вывод</summary>

```bash
-- The C compiler identification is AppleClang 17.0.0.17000013
-- The CXX compiler identification is AppleClang 17.0.0.17000013
-- Configuring done (0.4s)
-- Generating done (0.0s)
-- Build files have been written to: /Users/aleksandrgolikov/workspace/projects/lab06/_build
```
</details>

`cmake --build _build`

<details>
<summary>Вывод</summary>

```bash
[ 20%] Building CXX object formatter_lib/CMakeFiles/formatter.dir/formatter.cpp.o
[ 40%] Linking CXX static library libformatter.a
[ 40%] Built target formatter
[ 60%] Building CXX object CMakeFiles/solver_app.dir/solver_application/main.cpp.o
[ 80%] Building CXX object CMakeFiles/solver_app.dir/solver_lib/solver.cpp.o
[100%] Linking CXX executable solver_app
[100%] Built target solver_app
```
</details>

После успешной компиляции была выполнена локальная проверка работоспособности утилиты cpack для создания архивов формата .tar.gz и .zip

`cd _build`
`cpack -G "TGZ"`

CPack: Create package using TGZ

CPack: - package: /Users/aleksandrgolikov/workspace/projects/lab06/_build/SolverProject-1.0.0-Darwin.tar.gz generated.

`cpack -G "ZIP"`

CPack: Create package using ZIP

CPack: - package: /Users/aleksandrgolikov/workspace/projects/lab06/_build/SolverProject-1.0.0-Darwin.zip generated.

`cd ..`

Инициализация и очистка сценариев автоматизации

 `mkdir -p .github/workflows`
`ls -la .github/workflows/total 16`

<details>
<summary>Вывод</summary>

```bash
drwxr-xr-x  4 aleksandrgolikov  staff   128 18 май 21:07 .
drwxr-xr-x  3 aleksandrgolikov  staff    96 18 май 11:24 ..
-rw-r--r--  1 aleksandrgolikov  staff   972 18 май 11:24 cmake.yml
-rw-r--r--  1 aleksandrgolikov  staff  1462 18 май 21:07 release.yml
```
</details>

`rm .github/workflows/cmake.yml`

Настройка конфигурации GitHub Actions

<details>
<summary>Вывод</summary>

```bash
name: Share Releases

on:
  push:
    tags:
      - 'v*'

permissions:
  contents: write

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
    - name: Checkout code
      uses: actions/checkout@v3

    - name: Install CPack Dependencies
      run: |
        sudo apt-get update
        sudo apt-get install -y rpm dpkg

    - name: Configure CMake
      run: cmake -H. -B_build

    - name: Build project
      run: cmake --build _build

    - name: Run CPack Packages
      run: |
        cd _build
        cpack -G "DEB"
        cpack -G "RPM"
        cpack -G "TGZ"

    - name: Create and Upload Release
      uses: softprops/action-gh-release@v1
      env:
        GITHUB_TOKEN: ${{ secrets.GITHUB_TOKEN }}
      with:
        files: |
          _build/*.deb
          _build/*.rpm
          _build/*.tar.gz
```
</details>

Перепривязка репозитория и фиксация изменений

`git remote set-url origin git@github.com:2dmpjv8fgy-commits/laba6.git`
`git add .`
`git commit -m "build: explicitly grant write permissions for releases"`

<details>
<summary>Вывод</summary>

```bash
[main 5d588a2] build: explicitly grant write permissions for releases
 1 file changed, 3 insertions(+)
```
</details>

`git push origin main`

<details>
<summary>Вывод</summary>

```bash
Перечисление объектов: 9, готово.
Запись объектов: 100% (5/5), 469 bytes | 469.00 KiB/s, готово.
To github.com:2dmpjv8fgy-commits/laba6.git
   d601f07..5d588a2  main -> main
```
</details>

Запуск деплоя через создание тега

`git tag v1.0.5`
`git push origin v1.0.5`

<details>
<summary>Вывод</summary>

```bash
Total 0 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To github.com:2dmpjv8fgy-commits/laba6.git
 * [new tag]         v1.0.5 -> v1.0.5
```
</details>

Для исключения ошибок отображения структуры проекта на GitHub, из корня репозитория был удален пустой некорректный файл-дубликат CPackConfig.cmake\, созданный из-за опечатки экранирования в терминале.

`rm CPackConfig.cmake\\`
`git add .`
`git commit -m "chore: remove accidental duplicate file"`

<details>
<summary>Вывод</summary>

```bash
[main a28d92e] chore: remove accidental duplicate file
 1 file changed, 29 deletions(-)
 delete mode 100644 "CPackConfig.cmake\\"
```
</details>

`git push origin main`

<details>
<summary>Вывод</summary>

```bash
To github.com:2dmpjv8fgy-commits/laba6.git
   5d588a2..a28d92e  main -> main
```
</details>




