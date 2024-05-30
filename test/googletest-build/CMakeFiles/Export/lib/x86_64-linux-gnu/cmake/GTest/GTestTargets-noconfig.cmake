#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "GTest::gtest" for configuration ""
set_property(TARGET GTest::gtest APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(GTest::gtest PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libgtest.so.1.11.0"
  IMPORTED_SONAME_NOCONFIG "libgtest.so.1.11.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS GTest::gtest )
list(APPEND _IMPORT_CHECK_FILES_FOR_GTest::gtest "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libgtest.so.1.11.0" )

# Import target "GTest::gtest_main" for configuration ""
set_property(TARGET GTest::gtest_main APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(GTest::gtest_main PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libgtest_main.so.1.11.0"
  IMPORTED_SONAME_NOCONFIG "libgtest_main.so.1.11.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS GTest::gtest_main )
list(APPEND _IMPORT_CHECK_FILES_FOR_GTest::gtest_main "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libgtest_main.so.1.11.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
