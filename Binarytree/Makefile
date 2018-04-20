# C++ compiler
CC = g++
CC_FLAGS = -fopenmp -std=c++11

size = 50000
inputFile = input_$(size)
outputFile = gold_$(size)
destDir = /tmp/BinaryTree

all: gen_bin gen_data mv_bin

gen_bin: btree.cpp
	$(CC) $(CC_FLAGS) -o main btree.cpp

gen_data: gen_bin
	./main $(inputFile) $(outputFile)

mv_bin: gen_data
	mkdir -p $(destDir)
	mv main $(inputFile) $(outputFile) $(destDir)
	@echo "All Done, executables should be in the $(destDir)"
