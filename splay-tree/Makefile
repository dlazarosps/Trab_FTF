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


#DUPLICATION
destDir_dup = /tmp/splay-dup

all_dup: gen_bin_dup gen_data_dup mv_bin_dup

gen_bin_dup: main_dup.cpp splay.cpp
	$(CC) $(CC_FLAGS) -o main_dup main_dup.cpp splay.cpp

gen_data_dup: gen_bin_dup
	./main_dup input_$(size) gold_$(size) /tmp/splay-dup-detection.log output2_$(size)

mv_bin_dup: gen_data_dup
	mkdir -p $(destDir_dup)
	mv main_dup $(destDir_dup)
	cp input_$(size) $(destDir_dup)
	cp gold_$(size) $(destDir_dup)
	cp output2_$(size) $(destDir_dup)
	@echo "All Done, executables should be in the $(destDir_dup)"

clean:
	clear
	rm -rf *.o
	rm -rf main
	rm -rf output2_$(size)
	rm -rf main_dup