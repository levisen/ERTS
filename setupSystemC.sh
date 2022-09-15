#!/bin/bash
sudo apt install -y g++ cmake build-essential gdb doxygen graphviz gtkwave

cd ..
WORK_DIR=$(pwd)
wget https://www.accellera.org/images/downloads/standards/systemc/systemc-2.3.3.tar.gz
tar -xzf systemc-2.3.3.tar.gz
rm systemc-2.3.3.tar.gz


mkdir $WORK_DIR/systemc-2.3.3/buildDebug
cd $WORK_DIR/systemc-2.3.3/buildDebug
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_DEBUG_POSTFIX="-d" -DCMAKE_INSTALL_PREFIX=$WORK_DIR/systemc-2.3.3-install -DCMAKE_CXX_STANDARD=14 -DBUILD_SOURCE_DOCUMENTATION=OFF ..
make -j 4
make check -j 4
make install
SYSTEMC_HOME=${WORK_DIR}/systemc-2.3.3-install
EXPORT_STRING="export SYSTEMC_HOME=${SYSTEMC_HOME}"
BASHRC=~/.bashrc
if grep -q $SYSTEMC_HOME "$BASHRC"; then
  echo "SYSTEMC_HOME path environment variable already set."
else
    echo "Setting SYSTEMC_HOME path var."
    echo "$EXPORT_STRING" >> ~/.bashrc
fi
