cmake_minimum_required(VERSION 3.10)
project(banking)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(banking STATIC Account.cpp Transaction.cpp)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../third-party/gtest ${CMAKE_CURRENT_BINARY_DIR}/gtest)
  
  file(GLOB BANKING_TEST_SOURCES tests/*.cpp)
  add_executable(check ${BANKING_TEST_SOURCES})
  
  target_link_libraries(check banking gtest_main gmock)
  add_test(NAME check COMMAND check)
endif()
