cmake_minimum_required(VERSION 3.13)

project(GWInstekController LANGUAGES CXX)

# set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# we cannot analyse results without gcov
find_program(GCOV_PATH gcov)
if(NOT GCOV_PATH)
  message(FATAL_ERROR "Code coverage analysis requires gcov!")
endif()

include(FetchContent)
FetchContent_Declare(SerialCommunication
  GIT_REPOSITORY https://github.com/JY-Quek/SerialCommunication.git
  GIT_TAG 6567ea6a70b1faef29aeeaadc9eb5def74808362
)
FetchContent_MakeAvailable(SerialCommunication)

add_subdirectory(src)
add_subdirectory(sample)

enable_testing()
add_subdirectory(test)
