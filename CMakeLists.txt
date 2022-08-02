cmake_minimum_required (VERSION 3.11)
project (OpenMAMA-msgpack)

include(GoogleTest)
include(FetchContent)
enable_testing()

set (CMAKE_CXX_STANDARD 11)
set (MAMA_ROOT "/opt/openmama" CACHE PATH "Path to OpenMAMA installation")

add_definitions(-DOPENMAMA_INTEGRATION)

if (MSVC)
  set (OPENMAMA_LIBS libmamacmd libwombatcommonmd)
else (NOT MSVC)
  set (OPENMAMA_LIBS mama pthread wombatcommon)
endif()

# We'll need OpenMAMA's source code for unit test code
FetchContent_Declare(
  openmama
  GIT_REPOSITORY https://github.com/fquinner/OpenMAMA.git
  GIT_TAG        next
)
FetchContent_GetProperties(openmama)
if(NOT openmama_POPULATED)
  set(WITH_MAMDA OFF CACHE BOOL "" FORCE)
  set(WITH_CPP OFF CACHE BOOL "" FORCE)
  set(WITH_BASE_BRIDGE OFF CACHE BOOL "" FORCE)
  set(WITH_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(WITH_TESTTOOLS OFF CACHE BOOL "" FORCE)
  set(WITH_PROTON OFF CACHE BOOL "" FORCE)
  set(WITH_BASE_BRIDGE OFF CACHE BOOL "" FORCE)
  if(NOT openmama_POPULATED)
    FetchContent_Populate(openmama)
    add_subdirectory(${openmama_SOURCE_DIR} ${openmama_BINARY_DIR} EXCLUDE_FROM_ALL)
  endif()
endif()

# We'll need OpenMAMA-omnm's source code for unit test code
FetchContent_Declare(
  openmamaomnm
  GIT_REPOSITORY https://github.com/cascadium/OpenMAMA-omnm.git
  GIT_TAG        master
)
FetchContent_GetProperties(openmamaomnm)
if(NOT openmamaomnm_POPULATED)
  set(WITH_UNITTEST OFF CACHE BOOL "" FORCE)
  FetchContent_Populate(openmamaomnm)
  add_subdirectory(${openmamaomnm_SOURCE_DIR} ${openmamaomnm_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# We need gtest for unit tests
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.10.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

string(TOLOWER ${CMAKE_SYSTEM_NAME} system)
include_directories(${MAMA_ROOT}/include)
include_directories(${MAMA_ROOT}/include/wombat)
include_directories(${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c)
include_directories(${openmama_SOURCE_DIR}/mama/c_cpp/src/c)
include_directories(${openmama_SOURCE_DIR}/common/c_cpp/src/c)
include_directories(${openmama_SOURCE_DIR}/common/c_cpp/src/c/${system})
include_directories(${openmamaomnm_SOURCE_DIR}/src)
include_directories(${openmama_BINARY_DIR}/mama/c_cpp/src/c)
link_directories(${MAMA_ROOT}/lib)
link_directories(${GTEST_ROOT}/lib)

add_subdirectory(src)

add_executable(UpstreamOpenMamaUnitTests
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/MainUnitTestC.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/mamamsg/msgatomictests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/mamamsg/msgcompositetests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/mamamsg/msgfieldatomictests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/mamamsg/msgfieldcompositetests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/mamamsg/msgfieldvectortests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/mamamsg/msggeneraltests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/mamamsg/msgiterationtests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/mamamsg/msgstatustests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/mamamsg/msgvectortests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/payload/fieldatomictests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/payload/fieldcompositetests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/payload/fieldvectortests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/payload/payloadatomictests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/payload/payloadcompositetests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/payload/payloadgeneraltests.cpp
    ${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c/payload/payloadvectortests.cpp
)

target_link_libraries(UpstreamOpenMamaUnitTests ${OPENMAMA_LIBS} gtest)
gtest_discover_tests(
    UpstreamOpenMamaUnitTests
    EXTRA_ARGS -m qpid -p msgpackmsg -i 0xde --gtest_filter=MamaPublisherTestC.Send
    PROPERTIES ENVIRONMENT
        "WOMBAT_PATH=${openmama_SOURCE_DIR}/mama/c_cpp/src/examples:${openmama_SOURCE_DIR}/mama/c_cpp/src/gunittest/c"
)

