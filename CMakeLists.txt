cmake_minimum_required (VERSION 2.8.7)
project (OpenMAMA-msgpack)

set (OPENMAMA_SRC /home/fquinn/SourceExternal/cascadium/OpenMAMA)
set (MAMA_ROOT "/opt/openmama" CACHE PATH "Path to OpenMAMA installation")
set (OMNM_ROOT "/opt/openmama" CACHE PATH "Path to OpenMAMA OMNM installation for extending")

add_subdirectory(src)

# Only build the extra unit tests if OPENMAMA_SRC is provided
if(OPENMAMA_SRC)
    include_directories(${MAMA_ROOT}/include)
    include_directories(${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c)
    include_directories(${OPENMAMA_SRC}/mama/c_cpp/src/c)
    link_directories(${MAMA_ROOT}/lib)
    link_directories(${GTEST_ROOT}/lib)

    add_executable(UnitTestMamaMsgC
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/MainUnitTestC.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/mamamsg/msgatomictests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/mamamsg/msgcompositetests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/mamamsg/msgfieldatomictests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/mamamsg/msgfieldcompositetests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/mamamsg/msgfieldvectortests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/mamamsg/msggeneraltests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/mamamsg/msgiterationtests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/mamamsg/msgstatustests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/mamamsg/msgvectortests.cpp
    )
    target_link_libraries(UnitTestMamaMsgC mama gtest pthread wombatcommon)

    add_executable(UnitTestMamaPayloadC
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/MainUnitTestC.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/payload/fieldatomictests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/payload/fieldcompositetests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/payload/fieldvectortests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/payload/payloadatomictests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/payload/payloadcompositetests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/payload/payloadgeneraltests.cpp
        ${OPENMAMA_SRC}/mama/c_cpp/src/gunittest/c/payload/payloadvectortests.cpp
    )
    target_link_libraries(UnitTestMamaPayloadC mama gtest pthread wombatcommon)
else()
    message(WARNING "If you want full unit tests, you should provide -DOPENMAMA_SRC=")
endif()
