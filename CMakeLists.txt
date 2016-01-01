CMAKE_POLICY(SET CMP0048 NEW)
#to be abe to use version
project(Hello 
LANGUAGES CXX
VERSION 0.0.1.0)
cmake_minimum_required(VERSION 2.8.12)
set(AUTHOR "Alin M Elena")
set(AUTHOR_DETAILS "alin@elena.space")
set(DESCRIPTION "Hello World project cmake with C++ example")
include(GNUInstallDirs)
include(FeatureSummary)
if (CMAKE_VERSION VERSION_LESS 3.1.0)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
	set(CMAKE_CXX_STANDARD 11)
endif()
message(STATUS "Building prepareation for ${PROJECT_NAME} version: ${Hello_VERSION_MAJOR}.${Hello_VERSION_MINOR}.${Hello_VERSION_PATCH}.${Hello_VERSION_TWEAK}")
option (WITH_MYMATH "Build with my math implementation" ON) 
if (WITH_MYMATH)
  add_definitions("-DWITH_MYMATH")
  message(STATUS "Build with my math implementation" )
else()
  message(STATUS "Build without my math implementation" )
endif()
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BUILD_TESTING "Build with tests" ON)
option(BUILD_DOCS "Build with tests" ON)
if (${BUILD_TESTING})
  include(CTest)
endif()
#advance but may be useful
configure_file (
  "${PROJECT_SOURCE_DIR}/source/hello.h.in"
  "${PROJECT_SOURCE_DIR}/source/hello.h"
  )

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

add_subdirectory(source)
add_executable(hello source/hello.cxx)
target_include_directories(hello PRIVATE "${PROJECT_BINARY_DIR}/source")
target_link_libraries(hello ${Hello_LIBS})

#installation
install(TARGETS hello RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES ${PROJECT_BINARY_DIR}/source/hello.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if(BUILD_DOCS)
  find_package(Doxygen REQUIRED)
  configure_file(${PROJECT_SOURCE_DIR}/cmake/Doxyfile.cmake ${PROJECT_BIN_DIR}Doxyfile)
  add_custom_target(docs
    ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/Doxyfile)
endif()

if (${BUILD_TESTING})
#testing this macro in big projects may go in its own file
macro (do_test arg result)
  add_test(HelloTest${arg} ${CMAKE_INSTALL_BINDIR}/hello ${arg})
  set_tests_properties (HelloTest${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

  do_test(36 " is 6")
  do_test(0.0001 " is 0.01")
endif()

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
