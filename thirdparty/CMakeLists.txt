cmake_minimum_required(VERSION 3.2.0 FATAL_ERROR)

project(StorehouseThirdparty)

include(ExternalProject)

set(GLOBAL_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(THIRDPARTY_SOURCE_DIR "${CMAKE_SOURCE_DIR}")

string(REPLACE ";" ";" AWS_MODULES_STR "${AWS_MODULES}")
ExternalProject_Add(AWS
  GIT_REPOSITORY "https://github.com/aws/aws-sdk-cpp"
  GIT_TAG "1.11.540"

  UPDATE_COMMAND ""

  SOURCE_DIR "${THIRDPARTY_SOURCE_DIR}/aws-sdk-cpp"
  INSTALL_DIR ${GLOBAL_OUTPUT_PATH}/aws-sdk-cpp
  CMAKE_ARGS
  -D CMAKE_INSTALL_PREFIX=${GLOBAL_OUTPUT_PATH}/aws-sdk-cpp
  -D BUILD_ONLY=core$<SEMICOLON>s3
  -D BUILD_SHARED_LIBS=OFF
  -D MINIMIZE_SIZE=ON
  -D ENABLE_TESTING=OFF
  )

# googletest
ExternalProject_Add(GoogleTest
  GIT_REPOSITORY "https://github.com/google/googletest"
  GIT_TAG 0a439623f75c029912728d80cb7f1b8b48739ca4

  UPDATE_COMMAND ""

  SOURCE_DIR "${THIRDPARTY_SOURCE_DIR}/googletest"

  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${GLOBAL_OUTPUT_PATH}/googletest
  -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
  -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
  -DCMAKE_CXX_FLAGS="-Wno-error=maybe-uninitialized"
  INSTALL_DIR "${GLOBAL_OUTPUT_PATH}/googletest"
  )
