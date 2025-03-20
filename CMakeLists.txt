# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Download milkv resources
execute_process(
    COMMAND bash ${CMAKE_SOURCE_DIR}/download_milkvduo_wiringx.sh
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Name your project
project(morse_blink_led)

# Source files
set(SRC_FILES blink.c delay.c morse.c)

# Include directory for testing
include_directories(unity/src)

# Unity test files
set(TEST_FILES test.c unity/src/unity.c)

# For release builds
if(CMAKE_BUILD_TYPE STREQUAL "RELEASE")
    message(STATUS "Configuring Release build")

    add_executable(morse_blink_led main.c ${SRC_FILES})
    target_compile_definitions(morse_blink_led PRIVATE RELEASE)
    target_compile_options(morse_blink_led PRIVATE -O3)
    target_link_libraries(morse_blink_led wiringx)

    # uncomment below if you want to a test binary that actually blinks the led
    # add_executable(test ${SRC_FILES} ${TEST_FILES})
    # target_compile_definitions(test PRIVATE RELEASE)
    # target_compile_options(test PRIVATE -O3)
    # target_link_libraries(test wiringx)

# For debug builds
elseif(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
    message(STATUS "Configuring Debug build")

    add_executable(morse_blink_led main.c ${SRC_FILES})
    target_compile_definitions(morse_blink_led PRIVATE DEBUG)
    target_compile_options(morse_blink_led PRIVATE -g)
    target_link_libraries(morse_blink_led wiringx)

    # uncomment below if you want to a test binary that actually blinks the led
    # add_executable(test ${SRC_FILES} ${TEST_FILES})
    # target_compile_definitions(test PRIVATE DEBUG)
    # target_compile_options(test PRIVATE -g)
    # target_link_libraries(test wiringx)

# For test builds
else()
    message(STATUS "Configuring Test build")
    # Test executable
    add_executable(test ${SRC_FILES} ${TEST_FILES})
    target_compile_definitions(test PRIVATE TEST)
    target_compile_options(test PRIVATE -g)

endif()