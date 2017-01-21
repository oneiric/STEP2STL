#!/usr/bin/bash

# initialize the variables
export SrcDir='/home/alex/Documents/STEP2STL'

cd $SrcDir/build

# generate make files 
cmake -G "Unix Makefiles" $SrcDir

make
