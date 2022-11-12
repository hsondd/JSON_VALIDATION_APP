#!/bin/bash

GREEN='\033[0;32m'
NC='\033[0m'
TOP_DIR=$(pwd)
BUILD_DIR=$(pwd)/build
PROJECT_NAME="JSON_VALIDATION_APP"

#Check exist build dir and clean
if [ -d $BUILD_DIR ]; then
echo -e "${GREEN}Clean BUILD_DIR $BUILD_DIR${NC}"
    rm -rf $BUILD_DIR
fi

#create build dir
echo -e  "${GREEN}Make BUILD_DIR $BUILD_DIR${NC}"
mkdir -p $BUILD_DIR

#build
echo -e  "${GREEN}BUILD PROJECT $PROJECT_NAME${NC}"
cd $BUILD_DIR
cmake ..
make
