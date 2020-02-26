project(GoogleTest)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(GoogleTestRun TestMerge.cpp)

# linking Google_Tests_run with DateConverter_lib which will be tested
#target_link_libraries(GoogleTestRun main)

target_link_libraries(GoogleTestRun gtest gtest_main)