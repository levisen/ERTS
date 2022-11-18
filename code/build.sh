#!/bin/bash

if [[ -z $1 ]];
then
    echo "No project name passed."
    echo "Use: ./build.sh <project_name>"
    exit 1
fi

DIR=$(pwd)/src/$1
if ! [ -d "$DIR" ];
then
    echo "Project $1 does not exist"
    exit 1
fi

cmake -DCMAKE_BUILD_TYPE=Debug -B build/$1 $(pwd)/src/$1
cd build/$1
make
./exec

