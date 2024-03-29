#!/bin/bash

. /etc/profile

# All errors fatal
set -e -x

export OPENMAMA_INSTALL_DIR=/opt/openmama
BUILD_DIR=/build-ci-run
SOURCE_PATH_RELATIVE=$(dirname "$0")/../..
SOURCE_PATH_ABSOLUTE=$(cd "$SOURCE_PATH_RELATIVE" && pwd)

git config --global --add safe.directory SOURCE_PATH_ABSOLUTE
git config --global user.email "devops@cascadium.io"
git config --global user.name "Cascadium Devops"

# Update to required cmake version
cd /usr
wget -q -c https://github.com/Kitware/CMake/releases/download/v3.19.4/cmake-3.19.4-Linux-x86_64.tar.gz -O - | tar -xz  --strip-components 1

# Constants
RHEL=CentOS
UBUNTU=Ubuntu

if [ -f /etc/redhat-release ]
then
    DISTRIB_RELEASE=$(cat /etc/redhat-release | tr " " "\n" | egrep "^[0-9]")
    DEPENDS_FLAGS="-d libuuid -d libevent -d ncurses -d apr"
    DISTRIB_ID=$RHEL
    PACKAGE_TYPE=rpm
    CLOUDSMITH_DISTRO_NAME=centos
    CLOUDSMITH_DISTRO_VERSION=${DISTRIB_RELEASE%%.*}
    PACKAGE_MANAGER=yum
    yum install -y msgpack-devel
fi

if [ -f /etc/lsb-release ]
then
    # Will set DISTRIB_ID and DISTRIB_RELEASE
    source /etc/lsb-release
    PACKAGE_TYPE=deb
    DEPENDS_FLAGS="-d uuid -d libevent-dev -d libzmq3-dev -d ncurses-dev -d libapr1-dev"
    CLOUDSMITH_DISTRO_NAME=ubuntu
    CLOUDSMITH_DISTRO_VERSION=${DISTRIB_CODENAME}
    PACKAGE_MANAGER=apt
    apt install -y libmsgpack-dev
fi

# Build the project
if [ -d $BUILD_DIR ]
then
    rm -rf $BUILD_DIR
fi

mkdir -p $BUILD_DIR
cd $BUILD_DIR
export LD_LIBRARY_PATH=$(echo $(find "$BUILD_DIR" -name "*.so" -exec dirname {} \; | sort -u | tr "\n" ":"))
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_INSTALL_PREFIX=/opt/openmama-msgpack -DMAMA_ROOT=$OPENMAMA_INSTALL_DIR "$SOURCE_PATH_ABSOLUTE"
make -j VERBOSE=1
make install
ctest . --timeout 120 --output-on-failure -E MsgFieldVectorBoolTests.GetVectorBoolNullField

# Generate the package (deb / rpm / tarball).
# Globals
ARTIFACT_TYPE=${ARTIFACT_TYPE:-dev}
VERSION_FILE=${VERSION_FILE:-"$SOURCE_PATH_ABSOLUTE/VERSION"}
VERSION=$(cat "$VERSION_FILE" | xargs)

if [ "$DISTRIB_ID" == "$RHEL" ]
then
    DISTRIB_PACKAGE_QUALIFIER=el${DISTRIB_RELEASE%%.*}
elif [ "$DISTRIB_ID" == "$UBUNTU" ]
then
    DISTRIB_PACKAGE_QUALIFIER=ubuntu${DISTRIB_RELEASE%%.*}
else
    echo "Unsupported distro [$DISTRIB_ID] found: $(cat /etc/*-release)" && exit $LINENO
fi

DIST_DIR="$SOURCE_PATH_ABSOLUTE/dist"
if [ ! -d "$DIST_DIR" ]
then
    mkdir "$DIST_DIR"
fi

PACKAGE_FILE="$DIST_DIR/openmama-msgpack-$VERSION-1.$DISTRIB_PACKAGE_QUALIFIER.x86_64.$PACKAGE_TYPE"
fpm -s dir --force \
        -t $PACKAGE_TYPE \
        -m "contact@cascadium.io" \
        --name openmama-msgpack \
        --version $VERSION \
        --iteration 1 \
        --url "http://cascadium.io" \
        --license MIT \
        -d openmama \
        -p "$PACKAGE_FILE" \
        --description "OpenMAMA OMNM payload bridge" \
        /opt/openmama-msgpack/=/opt/openmama/

if [ "true" = "$PACKAGE_UPLOAD_ENABLED" ]
then
    echo cloudsmith push $PACKAGE_TYPE "openmama/openmama-thirdparty/$CLOUDSMITH_DISTRO_NAME/$CLOUDSMITH_DISTRO_VERSION" "${PACKAGE_FILE}"
fi
