# C++ compiler
CC = g++ 
CC_FLAGS = -fopenmp -std=c++11

destDir = /tmp/AVLTree

all: gen_bin gen_data mv_bin

gen_bin: avl.cpp
	$(CC) $(CC_FLAGS) -o main avl.cpp

gen_data: gen_bin
	./main > gold_

mv_bin: gen_data
	mkdir -p $(destDir)
	mv main gold_ $(destDir)
	@echo "All Done, executables should be in the $(destDir)"