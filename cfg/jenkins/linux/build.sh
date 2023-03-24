#!/bin/bash

cd ../../..

export TEST=~/Downloads
echo $TEST

export FMT_INCLUDE_DIR=~/Downloads/libfmt/include
echo $FMT_INCLUDE_DIR
export FMT_LIB_PATH=~/Downloads/libfmt/build/libfmt.so
echo $FMT_LIB_PATH

export SPDLOG_INCLUDE_DIR=~/Downloads/libspdlog/include
echo $SPDLOG_INCLUDE_DIR
export SPDLOG_LIB_PATH=~/Downloads/libspdlog/build/libspdlog.so
echo $SPDLOG_L

export GTEST_INCLUDE_DIR=~/Downloads/libgtest/googletest/include
echo $GTEST_INCLUDE_DIR
export GTEST_LIB_PATH=~/Downloads/libgtest/build/lib/libgtest.so
echo $GTEST_LIB_PATH

cd cmaked
cmake .. -G "Unix Makefiles" -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DSPDLOG_FMT_EXTERNAL=ON -DCMAKE_BUILD_TYPE=Debug -DFMT_LIB_INCLUDE=$FMT_INCLUDE_DIR -DFMT_LIB=$FMT_LIB_PATH -DSPDLOG_LIB_INCLUDE=$SPDLOG_INCLUDE_DIR -DSPDLOG_LIB=$SPDLOG_LIB_PATH -DGTEST_LIB_INCLUDE=$GTEST_INCLUDE_DIR -DGTEST_LIB=$GTEST_LIB_PATH -DESS_BUILD_UNIT_TESTS=ON -DBUILD_SHARED_LIBS=ON
make

cd ..
cd cmake
cmake .. -G "Unix Makefiles" -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DSPDLOG_FMT_EXTERNAL=ON -DCMAKE_BUILD_TYPE=Release -DFMT_LIB_INCLUDE=$FMT_INCLUDE_DIR -DFMT_LIB=$FMT_LIB_PATH -DSPDLOG_LIB_INCLUDE=$SPDLOG_INCLUDE_DIR -DSPDLOG_LIB=$SPDLOG_LIB_PATH -DGTEST_LIB_INCLUDE=$GTEST_INCLUDE_DIR -DGTEST_LIB=$GTEST_LIB_PATH -DESS_BUILD_UNIT_TESTS=ON -DBUILD_SHARED_LIBS=ON
make