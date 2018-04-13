# C++ compiler
CC = g++ 
CC_FLAGS = -fopenmp -std=c++11

destDir = /tmp/RBTree

all: gen_bin gen_data mv_bin

gen_bin: main.cpp RBTree.cpp
	$(CC) $(CC_FLAGS) -o main main.cpp RBTree.cpp

gen_data: gen_bin
	./main 50000 gold_

mv_bin: gen_data
	mkdir -p $(destDir)
	mv main gold_ $(destDir)
	@echo "All Done, executables should be in the $(destDir)"


