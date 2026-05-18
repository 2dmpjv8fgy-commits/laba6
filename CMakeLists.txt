cmake_minimum_required(VERSION 3.10)
project(SolverProject VERSION 1.0.0)

# Выставляем переменные версий для CPack
set(PRINT_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(PRINT_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(PRINT_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(PRINT_VERSION_TWEAK 0)
set(PRINT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем библиотеку форматирования
add_subdirectory(formatter_lib)

# Собираем исполняемый файл напрямую из исходников приложения и самого солвера
add_executable(solver_app solver_application/main.cpp solver_lib/solver.cpp)

# Линкуем базовый formatter
target_link_libraries(solver_app formatter)

# Указываем папки для поиска заголовочных файлов (.h)
target_include_directories(solver_app PRIVATE 
    ${PROJECT_SOURCE_DIR}/formatter_lib
    ${PROJECT_SOURCE_DIR}/formatter_ex_lib
    ${PROJECT_SOURCE_DIR}/solver_lib
)

# Указываем CMake упаковать бинарник solver_app в bin
install(TARGETS solver_app RUNTIME DESTINATION bin)

include(CPackConfig.cmake)
