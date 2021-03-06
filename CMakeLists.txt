cmake_minimum_required(VERSION 3.10)
set(PROJECT "hell")
project(${PROJECT} CXX)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake" 
                 TLS_VERIFY ON)
endif()

set(CMAKE_CONAN_TARGET_PROFILE default)
if(ANDROID)
   set(CMAKE_CONAN_TARGET_PROFILE ${CMAKE_SOURCE_DIR}/cmake/android/android_arm64)
elseif(APPLE)
   set(CMAKE_CONAN_TARGET_PROFILE ${CMAKE_SOURCE_DIR}/cmake/ios/ios_arm64)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(CONANFILE conanfile.txt
                PROFILE ${CMAKE_CONAN_TARGET_PROFILE}
                BASIC_SETUP 
                BUILD missing)

set(QT_UIC_EXECUTABLE ${CONAN_QT_ROOT}/bin/uic)
set(QT_MOC_EXECUTABLE ${CONAN_QT_ROOT}/bin/moc)
set(QT_RCC_EXECUTABLE ${CONAN_QT_ROOT}/bin/rcc)

if(WIN32)
  set(CMAKE_WIN32_EXECUTABLE ON)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
  include(${CMAKE_SOURCE_DIR}/cmake/windows/windows.cmake)
elseif(UNIX)
  if(APPLE)
    include(${CMAKE_SOURCE_DIR}/cmake/ios/ios.cmake)
  elseif(ANDROID)
    include(${CMAKE_SOURCE_DIR}/cmake/android/android.cmake)
  else()
    include(${CMAKE_SOURCE_DIR}/cmake/linux/linux.cmake)
  endif()
endif()

add_subdirectory(src)
