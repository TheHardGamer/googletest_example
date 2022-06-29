cmake_minimum_required(VERSION 3.22.1)

project(mygoogletest_sample)

#Fetch googletest
include(FetchContent)
#Build googletest as shared libs
set(BUILD_SHARED_LIBS ON CACHE INTERNAL "")
FetchContent_Declare(googletest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG v1.12.0)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
	FetchContent_Populate(googletest)
	add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

#Build libcode as a dynamic lib, change SHARED to STATIC to build a static lib
add_library(code SHARED LibCode.cpp)
#Build the main executable
add_executable(mainapp main.cpp)
#Link libcode to mainapp
target_link_libraries(mainapp code)

#Build the testrunner executable
add_executable(testRunner test.cpp)
#Link libcode and gtest libs dynamically
target_link_libraries(testRunner code gtest_main gmock_main)
