#!/bin/bash


SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
ROOT_DIR=$SCRIPT_DIR/../..

sudo -v

# Install apt packages
sudo apt update && sudo apt upgrade -y
sudo apt install -y git gcc cmake build-essential libeigen3-dev libopencv-dev libceres-dev libgoogle-glog-dev libunwind-dev

mkdir -p $SCRIPT_DIR/../Thirdparty

# Install Sophus
SOPHUS_DIR=$SCRIPT_DIR/../Thirdparty/Sophus
if [ -d "$SOPHUS_DIR" ]; then
    echo "Sophus is already installed. Skipping installation."
else
    git clone git@github.com:strasdat/Sophus.git $SOPHUS_DIR
    cd $SOPHUS_DIR
    latestTag=$(git describe --tags "$(git rev-list --tags --max-count=1)")
    git checkout $latestTag
    sed -i '/^project/a find_package(glog REQUIRED)' CMakeLists.txt
    cmake -B build -DBUILD_SOPHUS_TESTS=OFF
    cmake --build build --parallel 8
    cmake --install build --prefix=$ROOT_DIR/thirdparty_root
    echo "Sophus_DIR=$ROOT_DIR/thirdparty_root/share/sophus/cmake/" >> $ROOT_DIR/.env
fi

sudo -k