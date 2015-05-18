project(tests)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(test_integers_sources
test_integers.cpp
)

add_executable(test_integers ${test_integers_sources})

add_test(NAME test_integers 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests
    COMMAND test_integers)

set(test_example_sources
test_github.cpp
)

add_executable(test_example ${test_example_sources})
add_test(NAME test_example
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests
    COMMAND test_example)
