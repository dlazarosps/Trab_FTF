# C++ compiler
CC = g++ 
CC_FLAGS = -fopenmp -std=c++11

size = 1000
inputFile = input_$(size)
outputFile = gold_$(size)
destDir = /tmp/AVLTree

all: gen_bin gen_data mv_bin

gen_bin: avl.cpp
	$(CC) $(CC_FLAGS) -o avlMain avl.cpp

gen_data: gen_bin
	./avlMain $(inputFile) $(outputFile)

mv_bin: gen_data
	mkdir -p $(destDir)
	mv avlMain $(inputFile) $(outputFile) $(destDir)
	@echo "All Done, executables should be in the $(destDir)"
