project(tests)

set(test_integers_sources
test_integers.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(test_integers ${test_integers_sources})

add_test(NAME test_integers 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests
    COMMAND test_integers)
