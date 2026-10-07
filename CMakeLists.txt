cmake_minimum_required(VERSION 3.22)
project(upstream_a VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

find_package(LibXml2 REQUIRED)

add_library(upstream_a SHARED src/upstream_a.cpp)
add_library(upstream_a::upstream_a ALIAS upstream_a)
target_include_directories(upstream_a PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(upstream_a PRIVATE LibXml2::LibXml2)

install(TARGETS upstream_a EXPORT upstream_aTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT upstream_aTargets NAMESPACE upstream_a::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/upstream_a)
configure_package_config_file(cmake/upstream_aConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/upstream_aConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/upstream_a)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/upstream_aConfigVersion.cmake
  COMPATIBILITY SameMajorVersion)
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/upstream_aConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/upstream_aConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/upstream_a)

include(CTest)
if(BUILD_TESTING)
  find_package(GTest REQUIRED)
  add_executable(test_upstream_a test/test_upstream_a.cpp)
  target_link_libraries(test_upstream_a PRIVATE upstream_a GTest::gtest_main)
  add_test(NAME test_upstream_a COMMAND test_upstream_a)
endif()
