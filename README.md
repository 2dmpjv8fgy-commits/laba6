# Laboratory work V

Реализация банковской системы с комплексным модульным тестированием с использованием фреймворков **Google Test** и **Google Mock**. Настроена автоматическая сборка и проверка покрытия кода через GitHub Actions и Coveralls.

## CI/CD Status

- **GitHub Actions**: Сборка и тесты проходят успешно 
- **Coveralls**: Отчет о покрытии кода генерируется автоматически 

## Building

Проект собирается с помощью CMake. Для сборки тестов используется флаг `BUILD_TESTS`.

```bash
cmake -H. -B_build -DBUILD_TESTS=ON
cmake --build _build
```

<details>
<summary>Вывод</summary>

```bash
-- The C compiler identification is AppleClang 17.0.0.17000013
-- The CXX compiler identification is AppleClang 17.0.0.17000013
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
CMake Deprecation Warning at third-party/gtest/CMakeLists.txt:4 (cmake_minimum_required):
  Compatibility with CMake < 3.10 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value.  Or, use the <min>...<max> syntax
  to tell CMake that the project requires at least <min> but has been updated
  to work with policies introduced by <max> or earlier.


CMake Deprecation Warning at third-party/gtest/googlemock/CMakeLists.txt:45 (cmake_minimum_required):
  Compatibility with CMake < 3.10 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value.  Or, use the <min>...<max> syntax
  to tell CMake that the project requires at least <min> but has been updated
  to work with policies introduced by <max> or earlier.


CMake Deprecation Warning at third-party/gtest/googletest/CMakeLists.txt:56 (cmake_minimum_required):
  Compatibility with CMake < 3.10 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value.  Or, use the <min>...<max> syntax
  to tell CMake that the project requires at least <min> but has been updated
  to work with policies introduced by <max> or earlier.


-- Found Python: /opt/homebrew/Frameworks/Python.framework/Versions/3.14/bin/python3.14 (found version "3.14.3") found components: Interpreter
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Configuring done (0.8s)
-- Generating done (0.0s)
-- Build files have been written to: /Users/aleksandrgolikov/workspace/projects/laba5/laba5/_build



[  7%] Building CXX object banking/CMakeFiles/banking.dir/Account.cpp.o
[ 15%] Building CXX object banking/CMakeFiles/banking.dir/Transaction.cpp.o
[ 23%] Linking CXX static library libbanking.a
[ 23%] Built target banking
[ 30%] Building CXX object banking/gtest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 38%] Linking CXX static library ../../../lib/libgtest.a
[ 38%] Built target gtest
[ 46%] Building CXX object banking/gtest/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 53%] Linking CXX static library ../../../lib/libgtest_main.a
[ 53%] Built target gtest_main
[ 61%] Building CXX object banking/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 69%] Linking CXX static library ../../../lib/libgmock.a
[ 69%] Built target gmock
[ 76%] Building CXX object banking/CMakeFiles/check.dir/tests/test_banking.cpp.o
[ 84%] Linking CXX executable check
[ 84%] Built target check
[ 92%] Building CXX object banking/gtest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[100%] Linking CXX static library ../../../lib/libgmock_main.a
[100%] Built target gmock_main
```
</details>

##Running Tests

`./_build/banking/check`

<details>
<summary>Вывод</summary>

```bash

Running main() from /Users/aleksandrgolikov/workspace/projects/laba5/laba5/third-party/gtest/googletest/src/gtest_main.cc
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from BankingTest
[ RUN      ] BankingTest.TransactionAppliesChanges
[       OK ] BankingTest.TransactionAppliesChanges (0 ms)
[----------] 1 test from BankingTest (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
```
</details>

## Code Coverage


| File | Coverage |
|------|----------|
| Account.cpp | 100% ✅ |
| Transaction.cpp | 100% ✅ |
| **Total** | **100%** ✅ |

## Особенности реализации
- Account management: Поддержка блокировки счета, изменения баланса и получения текущего состояния.
- Isolated testing: Использование Mock-объектов (gmock) для тестирования транзакций без зависимости от реальных объектов аккаунтов.
- Error handling: Покрытие тестами случаев выброса исключений (std::runtime_error) при попытке изменения незаблокированного счета.
- Automated Reporting: Интеграция с сервисом Coveralls для визуализации покрытия строк кода.





