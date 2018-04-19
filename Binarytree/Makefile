# C++ compiler
CC = g++
CC_FLAGS = -fopenmp -std=c++11

destDir = /tmp/BinaryTree

all: gen_bin gen_data mv_bin

gen_bin: btree.cpp
	$(CC) $(CC_FLAGS) -o main btree.cpp

gen_data: gen_bin
	./main 200000 gold_file

mv_bin: gen_data
	mkdir -p $(destDir)
	mv main gold_file $(destDir)
	@echo "All Done, executables should be in the $(destDir)"
