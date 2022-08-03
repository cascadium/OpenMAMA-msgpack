include_directories(.)
include_directories(${MAMA_ROOT}/include)
include_directories(${MSGPACK_ROOT}/include)
include_directories(${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c)
include_directories(${openmama_SOURCE_DIR}/mama/c_cpp/src/c)
include_directories(${openmama_SOURCE_DIR}/common/c_cpp/src/c)
include_directories(${openmama_BINARY_DIR}/mama/c_cpp/src/c)

# Default to installing directly to MAMA directory
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "${MAMA_ROOT}" CACHE PATH "default install path" FORCE)
endif()

link_directories(${MSGPACK_ROOT}/lib)
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

target_link_libraries(mamamsgpackmsgimpl wombatcommon mama msgpackc mamaomnmmsgimpl)
install(TARGETS mamamsgpackmsgimpl DESTINATION lib)

add_executable(
    unittests_msgpack
    UnitTests.cpp
)
target_link_libraries(unittests_msgpack gtest mamamsgpackmsgimpl mamaomnmmsgimpl pthread)
gtest_discover_tests(
    unittests_msgpack
    PROPERTIES ENVIRONMENT
        "WOMBAT_PATH=${openmama_SOURCE_DIR}/mama/c_cpp/src/examples:${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c"
)
