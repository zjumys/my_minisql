# CMake generated Testfile for 
# Source directory: /root/Database/lab6/minisql/thirdparty/glog
# Build directory: /root/Database/lab6/minisql/test/glog-build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(demangle "/root/Database/lab6/minisql/test/glog-build/demangle_unittest")
set_tests_properties(demangle PROPERTIES  _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;848;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(logging "/root/Database/lab6/minisql/test/glog-build/logging_unittest")
set_tests_properties(logging PROPERTIES  SKIP_REGULAR_EXPRESSION "Check failed: time_ns within LogTimes::LOG_PERIOD_TOL_NS of LogTimes::LOG_PERIOD_NS" TIMEOUT "30" _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;849;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(signalhandler "/root/Database/lab6/minisql/test/glog-build/signalhandler_unittest")
set_tests_properties(signalhandler PROPERTIES  _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;864;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(stacktrace "/root/Database/lab6/minisql/test/glog-build/stacktrace_unittest")
set_tests_properties(stacktrace PROPERTIES  TIMEOUT "30" _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;868;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(stl_logging "/root/Database/lab6/minisql/test/glog-build/stl_logging_unittest")
set_tests_properties(stl_logging PROPERTIES  _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;872;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(symbolize "/root/Database/lab6/minisql/test/glog-build/symbolize_unittest")
set_tests_properties(symbolize PROPERTIES  _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;875;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(cmake_package_config_init "/usr/local/cmake/bin/cmake" "-DTEST_BINARY_DIR=/root/Database/lab6/minisql/test/glog-build/test_package_config" "-DINITIAL_CACHE=/root/Database/lab6/minisql/test/glog-build/test_package_config/glog_package_config_initial_cache.cmake" "-DCACHEVARS=set (BUILD_TESTING ON CACHE BOOL \"Build the testing tree.\")
set (CLANG_FORMAT_BIN \"CLANG_FORMAT_BIN-NOTFOUND\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_ADDR2LINE \"/usr/bin/addr2line\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_AR \"/usr/bin/ar\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_AR \"/usr/bin/ar\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_COLOR_MAKEFILE ON CACHE BOOL \"Enable/Disable color output during build.\")
set (CMAKE_CXX_COMPILER \"/usr/bin/c++\" CACHE FILEPATH \"CXX compiler\")
set (CMAKE_CXX_COMPILER \"/usr/bin/c++\" CACHE FILEPATH \"CXX compiler\")
set (CMAKE_CXX_COMPILER_AR \"/usr/bin/gcc-ar-9\" CACHE FILEPATH \"A wrapper around 'ar' adding the appropriate '--plugin' option for the GCC compiler\")
set (CMAKE_CXX_COMPILER_AR \"/usr/bin/gcc-ar-9\" CACHE FILEPATH \"A wrapper around 'ar' adding the appropriate '--plugin' option for the GCC compiler\")
set (CMAKE_CXX_COMPILER_RANLIB \"/usr/bin/gcc-ranlib-9\" CACHE FILEPATH \"A wrapper around 'ranlib' adding the appropriate '--plugin' option for the GCC compiler\")
set (CMAKE_CXX_COMPILER_RANLIB \"/usr/bin/gcc-ranlib-9\" CACHE FILEPATH \"A wrapper around 'ranlib' adding the appropriate '--plugin' option for the GCC compiler\")
set (CMAKE_CXX_FLAGS_DEBUG \"-g\" CACHE STRING \"Flags used by the CXX compiler during DEBUG builds.\")
set (CMAKE_CXX_FLAGS_MINSIZEREL \"-Os -DNDEBUG\" CACHE STRING \"Flags used by the CXX compiler during MINSIZEREL builds.\")
set (CMAKE_CXX_FLAGS_RELEASE \"-O3 -DNDEBUG\" CACHE STRING \"Flags used by the CXX compiler during RELEASE builds.\")
set (CMAKE_CXX_FLAGS_RELWITHDEBINFO \"-O2 -g -DNDEBUG\" CACHE STRING \"Flags used by the CXX compiler during RELWITHDEBINFO builds.\")
set (CMAKE_C_COMPILER \"/usr/bin/cc\" CACHE FILEPATH \"C compiler\")
set (CMAKE_C_COMPILER \"/usr/bin/cc\" CACHE FILEPATH \"C compiler\")
set (CMAKE_C_COMPILER_AR \"/usr/bin/gcc-ar-9\" CACHE FILEPATH \"A wrapper around 'ar' adding the appropriate '--plugin' option for the GCC compiler\")
set (CMAKE_C_COMPILER_AR \"/usr/bin/gcc-ar-9\" CACHE FILEPATH \"A wrapper around 'ar' adding the appropriate '--plugin' option for the GCC compiler\")
set (CMAKE_C_COMPILER_RANLIB \"/usr/bin/gcc-ranlib-9\" CACHE FILEPATH \"A wrapper around 'ranlib' adding the appropriate '--plugin' option for the GCC compiler\")
set (CMAKE_C_COMPILER_RANLIB \"/usr/bin/gcc-ranlib-9\" CACHE FILEPATH \"A wrapper around 'ranlib' adding the appropriate '--plugin' option for the GCC compiler\")
set (CMAKE_C_FLAGS_DEBUG \"-g\" CACHE STRING \"Flags used by the C compiler during DEBUG builds.\")
set (CMAKE_C_FLAGS_MINSIZEREL \"-Os -DNDEBUG\" CACHE STRING \"Flags used by the C compiler during MINSIZEREL builds.\")
set (CMAKE_C_FLAGS_RELEASE \"-O3 -DNDEBUG\" CACHE STRING \"Flags used by the C compiler during RELEASE builds.\")
set (CMAKE_C_FLAGS_RELWITHDEBINFO \"-O2 -g -DNDEBUG\" CACHE STRING \"Flags used by the C compiler during RELWITHDEBINFO builds.\")
set (CMAKE_DLLTOOL \"CMAKE_DLLTOOL-NOTFOUND\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_INSTALL_BINDIR \"bin\" CACHE PATH \"User executables (bin)\")
set (CMAKE_INSTALL_DATAROOTDIR \"share\" CACHE PATH \"Read-only architecture-independent data root (share)\")
set (CMAKE_INSTALL_INCLUDEDIR \"include\" CACHE PATH \"C header files (include)\")
set (CMAKE_INSTALL_LIBDIR \"lib/x86_64-linux-gnu\" CACHE PATH \"Object code libraries (lib/x86_64-linux-gnu)\")
set (CMAKE_INSTALL_LIBEXECDIR \"libexec\" CACHE PATH \"Program executables (libexec)\")
set (CMAKE_INSTALL_LOCALSTATEDIR \"var\" CACHE PATH \"Modifiable single-machine data (var)\")
set (CMAKE_INSTALL_OLDINCLUDEDIR \"/usr/include\" CACHE PATH \"C header files for non-gcc (/usr/include)\")
set (CMAKE_INSTALL_PREFIX \"/usr/local\" CACHE PATH \"Install path prefix, prepended onto install directories.\")
set (CMAKE_INSTALL_SBINDIR \"sbin\" CACHE PATH \"System admin executables (sbin)\")
set (CMAKE_INSTALL_SHAREDSTATEDIR \"com\" CACHE PATH \"Modifiable architecture-independent data (com)\")
set (CMAKE_INSTALL_SYSCONFDIR \"etc\" CACHE PATH \"Read-only single-machine data (etc)\")
set (CMAKE_LINKER \"/usr/bin/ld\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_LINKER \"/usr/bin/ld\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_MAKE_PROGRAM \"/usr/bin/make\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_NM \"/usr/bin/nm\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_OBJCOPY \"/usr/bin/objcopy\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_OBJDUMP \"/usr/bin/objdump\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_RANLIB \"/usr/bin/ranlib\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_RANLIB \"/usr/bin/ranlib\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_READELF \"/usr/bin/readelf\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_SKIP_INSTALL_RPATH NO CACHE BOOL \"If set, runtime paths are not added when installing shared libraries, but are added when building.\")
set (CMAKE_SKIP_RPATH NO CACHE BOOL \"If set, runtime paths are not added when using shared libraries.\")
set (CMAKE_STRIP \"/usr/bin/strip\" CACHE FILEPATH \"Path to a program.\")
set (CMAKE_VERBOSE_MAKEFILE FALSE CACHE BOOL \"If this value is on, makefiles will be generated without the .SILENT directive, and all commands will be echoed to the console during the make.  This is useful for debugging only. With Visual Studio IDE projects all commands are done without /nologo.\")
set (COVERAGE_COMMAND \"/usr/bin/gcov\" CACHE FILEPATH \"Path to the coverage program that CTest uses for performing coverage inspection\")
set (COVERAGE_EXTRA_FLAGS \"-l\" CACHE STRING \"Extra command line flags to pass to the coverage tool\")
set (CPACK_BINARY_DEB OFF CACHE BOOL \"Enable to build Debian packages\")
set (CPACK_BINARY_FREEBSD OFF CACHE BOOL \"Enable to build FreeBSD packages\")
set (CPACK_BINARY_IFW OFF CACHE BOOL \"Enable to build IFW packages\")
set (CPACK_BINARY_NSIS OFF CACHE BOOL \"Enable to build NSIS packages\")
set (CPACK_BINARY_RPM OFF CACHE BOOL \"Enable to build RPM packages\")
set (CPACK_BINARY_STGZ ON CACHE BOOL \"Enable to build STGZ packages\")
set (CPACK_BINARY_TBZ2 OFF CACHE BOOL \"Enable to build TBZ2 packages\")
set (CPACK_BINARY_TGZ ON CACHE BOOL \"Enable to build TGZ packages\")
set (CPACK_BINARY_TXZ OFF CACHE BOOL \"Enable to build TXZ packages\")
set (CPACK_BINARY_TZ ON CACHE BOOL \"Enable to build TZ packages\")
set (CPACK_SOURCE_RPM OFF CACHE BOOL \"Enable to build RPM source packages\")
set (CPACK_SOURCE_TBZ2 ON CACHE BOOL \"Enable to build TBZ2 source packages\")
set (CPACK_SOURCE_TGZ ON CACHE BOOL \"Enable to build TGZ source packages\")
set (CPACK_SOURCE_TXZ ON CACHE BOOL \"Enable to build TXZ source packages\")
set (CPACK_SOURCE_TZ ON CACHE BOOL \"Enable to build TZ source packages\")
set (CPACK_SOURCE_ZIP OFF CACHE BOOL \"Enable to build ZIP source packages\")
set (CTEST_SUBMIT_RETRY_COUNT \"3\" CACHE STRING \"How many times to retry timed-out CTest submissions.\")
set (CTEST_SUBMIT_RETRY_DELAY \"5\" CACHE STRING \"How long to wait between timed-out CTest submissions.\")
set (DART_TESTING_TIMEOUT \"1500\" CACHE STRING \"Maximum time allowed before CTest will kill the test.\")
set (GTest_DIR \"GTest_DIR-NOTFOUND\" CACHE PATH \"The directory containing a CMake configuration file for GTest.\")
set (INSTALL_GTEST ON CACHE BOOL \"Enable installation of googletest. (Projects embedding googletest may want to turn this OFF.)\")
set (MAKECOMMAND \"/usr/local/cmake/bin/cmake --build . --config \\\"\${CTEST_CONFIGURATION_TYPE}\\\"\" CACHE STRING \"Command to build the project\")
set (MEMORYCHECK_COMMAND \"MEMORYCHECK_COMMAND-NOTFOUND\" CACHE FILEPATH \"Path to the memory checking command, used for memory error detection.\")
set (PRINT_UNSYMBOLIZED_STACK_TRACES OFF CACHE BOOL \"Print file offsets in traces instead of symbolizing\")
set (SITE \"LAPTOP-FF8A20UD\" CACHE STRING \"Name of the computer/site where compile is being run\")
set (Unwind_INCLUDE_DIR \"Unwind_INCLUDE_DIR-NOTFOUND\" CACHE PATH \"unwind include directory\")
set (Unwind_LIBRARY \"Unwind_LIBRARY-NOTFOUND\" CACHE FILEPATH \"unwind library\")
set (WITH_CUSTOM_PREFIX OFF CACHE BOOL \"Enable support for user-generated message prefixes\")
set (WITH_GFLAGS ON CACHE BOOL \"Use gflags\")
set (WITH_GMOCK ON CACHE BOOL \"Use Google Mock\")
set (WITH_GTEST ON CACHE BOOL \"Use Google Test\")
set (WITH_PKGCONFIG ON CACHE BOOL \"Enable pkg-config support\")
set (WITH_SYMBOLIZE ON CACHE BOOL \"Enable symbolize module\")
set (WITH_THREADS ON CACHE BOOL \"Enable multithreading support\")
set (WITH_TLS ON CACHE BOOL \"Enable Thread Local Storage (TLS) support\")
set (WITH_UNWIND ON CACHE BOOL \"Enable libunwind support\")
set (gflags_DIR \"gflags_DIR-NOTFOUND\" CACHE PATH \"The directory containing a CMake configuration file for gflags.\")
set (gtest_build_samples OFF CACHE BOOL \"Build gtest's sample programs.\")
set (gtest_build_tests OFF CACHE BOOL \"Build all of gtest's own tests.\")
set (gtest_disable_pthreads OFF CACHE BOOL \"Disable uses of pthreads in gtest.\")
set (gtest_force_shared_crt OFF CACHE BOOL \"Use shared (DLL) run-time lib even when Google Test is built as static lib.\")
set (gtest_hide_internal_symbols OFF CACHE BOOL \"Build gtest with internal symbols hidden in shared libraries.\")
" "-P" "/root/Database/lab6/minisql/thirdparty/glog/cmake/TestInitPackageConfig.cmake")
set_tests_properties(cmake_package_config_init PROPERTIES  FIXTURES_SETUP "cmake_package_config" _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;898;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(cmake_package_config_generate "/usr/local/cmake/bin/cmake" "-DGENERATOR=Unix Makefiles" "-DGENERATOR_PLATFORM=" "-DGENERATOR_TOOLSET=" "-DINITIAL_CACHE=/root/Database/lab6/minisql/test/glog-build/test_package_config/glog_package_config_initial_cache.cmake" "-DPACKAGE_DIR=/root/Database/lab6/minisql/test/glog-build" "-DPATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin" "-DSOURCE_DIR=/root/Database/lab6/minisql/thirdparty/glog/src/package_config_unittest/working_config" "-DTEST_BINARY_DIR=/root/Database/lab6/minisql/test/glog-build/test_package_config/working_config" "-P" "/root/Database/lab6/minisql/thirdparty/glog/cmake/TestPackageConfig.cmake")
set_tests_properties(cmake_package_config_generate PROPERTIES  FIXTURES_REQUIRED "cmake_package_config" FIXTURES_SETUP "cmake_package_config_working" _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;905;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(cmake_package_config_build "/usr/local/cmake/bin/cmake" "--build" "/root/Database/lab6/minisql/test/glog-build/test_package_config/working_config" "--config" "")
set_tests_properties(cmake_package_config_build PROPERTIES  FIXTURES_REQUIRED "cmake_package_config;cmake_package_config_working" _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;917;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(cmake_package_config_cleanup "/usr/local/cmake/bin/cmake" "-E" "remove_directory" "/root/Database/lab6/minisql/test/glog-build/test_package_config")
set_tests_properties(cmake_package_config_cleanup PROPERTIES  FIXTURES_CLEANUP "cmake_package_config" _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;922;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(cleanup_init "/usr/local/cmake/bin/cmake" "-E" "make_directory" "/root/Database/lab6/minisql/test/glog-build/cleanup_tests")
set_tests_properties(cleanup_init PROPERTIES  FIXTURES_SETUP "logcleanuptest" _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;960;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(cleanup_logdir "/usr/local/cmake/bin/cmake" "-E" "remove_directory" "/root/Database/lab6/minisql/test/glog-build/cleanup_tests")
set_tests_properties(cleanup_logdir PROPERTIES  FIXTURES_CLEANUP "logcleanuptest" _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;962;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(cleanup_immediately "/usr/local/cmake/bin/cmake" "-DLOGCLEANUP=/root/Database/lab6/minisql/test/glog-build/cleanup_immediately_unittest" "-DTEST_DIR=/root/Database/lab6/minisql/test/glog-build/cleanup_tests/" "-P" "/root/Database/lab6/minisql/thirdparty/glog/cmake/RunCleanerTest1.cmake")
set_tests_properties(cleanup_immediately PROPERTIES  FIXTURES_REQUIRED "logcleanuptest" WORKING_DIRECTORY "/root/Database/lab6/minisql/test/glog-build" _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;964;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(cleanup_with_absolute_prefix "/usr/local/cmake/bin/cmake" "-DLOGCLEANUP=/root/Database/lab6/minisql/test/glog-build/cleanup_with_absolute_prefix_unittest" "-DTEST_DIR=/root/Database/lab6/minisql/test/glog-build/" "-P" "/root/Database/lab6/minisql/thirdparty/glog/cmake/RunCleanerTest2.cmake")
set_tests_properties(cleanup_with_absolute_prefix PROPERTIES  FIXTURES_REQUIRED "logcleanuptest" WORKING_DIRECTORY "/root/Database/lab6/minisql/test/glog-build" _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;971;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
add_test(cleanup_with_relative_prefix "/usr/local/cmake/bin/cmake" "-DLOGCLEANUP=/root/Database/lab6/minisql/test/glog-build/cleanup_with_relative_prefix_unittest" "-DTEST_DIR=/root/Database/lab6/minisql/test/glog-build/" "-DTEST_SUBDIR=test_subdir/" "-P" "/root/Database/lab6/minisql/thirdparty/glog/cmake/RunCleanerTest3.cmake")
set_tests_properties(cleanup_with_relative_prefix PROPERTIES  FIXTURES_REQUIRED "logcleanuptest" WORKING_DIRECTORY "/root/Database/lab6/minisql/test/glog-build" _BACKTRACE_TRIPLES "/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;977;add_test;/root/Database/lab6/minisql/thirdparty/glog/CMakeLists.txt;0;")
