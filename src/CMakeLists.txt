include_directories(.)
include_directories(${MAMA_ROOT}/include)

# Default to installing directly to MAMA directory
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "${MAMA_ROOT}" CACHE PATH "default install path" FORCE)
endif()

link_directories(${MAMA_ROOT}/lib)
link_directories(${MAMA_ROOT}/lib/dynamic)
link_directories(${MAMA_ROOT}/lib/dynamic-debug)

add_definitions(-DBRIDGE -DMAMA_DLL -DOPENMAMA_INTEGRATION)

add_library(
        mamamsgpackmsgimpl
        SHARED
            msgpackmsgpayloadfunctions.h
            base.c
            bridge.c
            bridge.h
)

target_link_libraries(mamamsgpackmsgimpl wombatcommon mama msgpackc mamaomnmmsgimpl-static)
install(TARGETS mamamsgpackmsgimpl DESTINATION lib)

add_executable(
    unittests
    UnitTests.cpp
)
target_link_libraries(unittests gtest mamamsgpackmsgimpl mamaomnmmsgimpl pthread)
gtest_discover_tests(
    unittests
    PROPERTIES ENVIRONMENT
        "WOMBAT_PATH=${openmama_SOURCE_DIR}/mama/c_cpp/src/examples:${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c"
)
