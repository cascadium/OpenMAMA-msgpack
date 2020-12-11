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

add_executable(
    unittests
    UnitTests.cpp
)
target_link_libraries(unittests gtest mamamsgpackmsgimpl pthread)

target_link_libraries(mamamsgpackmsgimpl wombatcommon mama msgpackc mamaomnmmsgimpl-static)
install(TARGETS mamamsgpackmsgimpl DESTINATION lib)


