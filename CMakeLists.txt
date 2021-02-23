cmake_minimum_required(VERSION 3.10)
project(asiocom CXX)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")

if(WIN32)
  set(CMAKE_WIN32_EXECUTABLE ON)
endif()

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake" 
                 TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(CONANFILE conanfile.txt
                BASIC_SETUP 
                BUILD missing)

set(QT_UIC_EXECUTABLE ${CONAN_QT_ROOT}/bin/uic)
set(QT_MOC_EXECUTABLE ${CONAN_QT_ROOT}/bin/moc)
set(QT_RCC_EXECUTABLE ${CONAN_QT_ROOT}/bin/rcc)

add_subdirectory(src)
