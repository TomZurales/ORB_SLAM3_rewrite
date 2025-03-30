#!/bin/bash


SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
ROOT_DIR=$SCRIPT_DIR/../../..

mkdir -p $SCRIPT_DIR/../Thirdparty

# Install Sophus
DEPTHAI_DIR=$SCRIPT_DIR/../Thirdparty/depthai-core
if [ -d "$DEPTHAI_DIR" ]; then
    echo "DepthAI is already installed. Skipping installation."
else
    git clone git@github.com:luxonis/depthai-core.git $DEPTHAI_DIR
    cd $DEPTHAI_DIR
    latestTag=$(git describe --tags "$(git rev-list --tags --max-count=1)")
    git checkout $latestTag
    git submodule update --init --recursive
    cmake -S. -Bbuild -D'BUILD_SHARED_LIBS=ON'
    cmake --build build --parallel 8
    cmake --install build --prefix=$ROOT_DIR/thirdparty_root
    echo "depthai_DIR=$ROOT_DIR/thirdparty_root/lib/cmake/depthai/" >> $ROOT_DIR/.env
fi

sudo -k