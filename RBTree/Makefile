# C++ compiler
CC = g++ 
CC_FLAGS = -fopenmp -std=c++11

destDir = /tmp/RBTree

all: gen_bin gen_data mv_bin

gen_bin: main.cpp RBTree.cpp
	$(CC) $(CC_FLAGS) -o main main.cpp RBTree.cpp

gen_data: gen_bin
	./main input_ gold_

mv_bin: gen_data
	mkdir -p $(destDir)
	mv main $(destDir)
	cp input_ $(destDir)
	cp gold_ $(destDir)
	@echo "All Done, executables should be in the $(destDir)"

#DUPLICATION
destDir_dup = /tmp/RBTree-dup

all_dup: gen_bin_dup gen_data_dup mv_bin_dup

gen_bin_dup: main_dup.cpp RBTree.cpp
	$(CC) $(CC_FLAGS) -o main_dup main_dup.cpp RBTree.cpp

gen_data_dup: gen_bin_dup
	./main_dup input_ gold_ /tmp/RBTree-dup-detection.log

mv_bin_dup: gen_data_dup
	mkdir -p $(destDir_dup)
	mv main $(destDir_dup)
	cp input_ $(destDir_dup)
	cp gold_ $(destDir_dup)
	@echo "All Done, executables should be in the $(destDir_dup)"