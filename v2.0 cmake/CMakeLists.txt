cmake_minimum_required(VERSION 3.14)

project("CMake2.0")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")


# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# -----------------------------------------------------------------------------
# GoogleTest
# -----------------------------------------------------------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# -----------------------------------------------------------------------------
# Shared Library (Your Project Code)
# -----------------------------------------------------------------------------
add_library(student_lib STATIC
  Studentas.cpp
)
target_include_directories(student_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# -----------------------------------------------------------------------------
# Main Executable
# -----------------------------------------------------------------------------
add_executable(CMake2.0 main.cpp)
target_link_libraries(CMake2.0 PRIVATE student_lib)

# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------
add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE student_lib gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(tests)



