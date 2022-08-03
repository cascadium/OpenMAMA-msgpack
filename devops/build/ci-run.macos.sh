#!/bin/bash

# All errors fatal
set -x

. /etc/profile

set -e

brew install apr apr-util msgpack

APR_ROOT=$(find /usr/local/Cellar/apr -type d -name libexec)
APRUTIL_ROOT=$(find /usr/local/Cellar/apr-util -type d -maxdepth 1 -mindepth 1)
MSGPACK_ROOT=$(find /usr/local/Cellar/msgpack -type d -maxdepth 1 -mindepth 1)

mkdir bld
cd bld
export DYLD_LIBRARY_PATH=$(pwd)/install/lib:$(echo /usr/local/Cellar/openmama/*)/lib
cmake -DCMAKE_INSTALL_PREFIX=$(pwd)/install -DAPR_ROOT=$APR_ROOT -DAPRUTIL_ROOT=$APRUTIL_ROOT -DMSGPACK_ROOT=$MSGPACK_ROOT ..
make -j
make install
ctest . -E MsgFieldVectorBoolTests.GetVectorBoolNullField --timeout 120 --output-on-failure
