# C++ compiler
CC = g++
CC_FLAGS = -fopenmp -std=c++11

size = 50000
thread_num = 1
inputFile = input_$(size)
outputFile = gold_$(size)
detectionLogFile = detectionLog_$(size)
destDir = /tmp/Tree234

all: gen_bin gen_data mv_bin

gen_bin: tree234.cpp
	$(CC) $(CC_FLAGS) -o main tree234.cpp

gen_data: gen_bin
	./main $(thread_num) $(inputFile) $(outputFile) $(detectionLogFile)

mv_bin: gen_data
	mkdir -p $(destDir)
	mv main $(inputFile) $(outputFile) $(detectionLogFile) $(destDir)
	@echo "All Done, executables should be in the $(destDir)"
