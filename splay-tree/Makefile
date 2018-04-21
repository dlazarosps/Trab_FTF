# C++ compiler
CC = g++ 
CC_FLAGS = -fopenmp -std=c++11

size = 50000
destDir = /tmp/splay

all: gen_bin gen_data mv_bin

gen_bin: main.cpp splay.cpp
	$(CC) -o main main.cpp splay.cpp

gen_data: gen_bin
	./main input_$(size) gold_$(size)

mv_bin: gen_data
	mkdir -p $(destDir)
	mv main  input_$(size) gold_$(size) $(destDir)
	@echo "All Done, executables should be in the $(destDir)"
