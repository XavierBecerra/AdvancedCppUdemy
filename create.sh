#!/bin/bash
#Script to create a specific-directory on all subfolders in a parent-directory

mkdir "$1" "$1/src" "$1/build" 
cp "BasicCMakeLists.txt" "$1/CMakeLists.txt"
cp "Basic.cpp" "$1/src/$2"
chmod 777 -R "./$1/"