#!/bin/bash


SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

sudo -v

# Install apt packages
# sudo apt update && sudo apt upgrade -y
# sudo apt install -y git gcc cmake build-essential libeigen3-dev libopencv-dev libceres-dev libgoogle-glog-dev libunwind-dev

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
    sudo cmake --install
fi

sudo -k