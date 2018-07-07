# C++ compiler
CC = g++
CC_FLAGS = -fopenmp -std=c++11

size = 50000
thread_num = 1
inputFile = input_$(size)
outputFile = gold_$(size)
outputFile2 = output2_$(size)
detectionLogFile = /tmp/Tree234/detectionLog_$(size).log
destDir = /tmp/Tree234

all: gen_bin gen_data mv_bin

gen_bin: tree234.cpp
	$(CC) $(CC_FLAGS) -o main tree234.cpp

gen_data: gen_bin
	./main $(inputFile) $(outputFile) $(detectionLogFile) $(outputFile2)

mv_bin: gen_data
	mkdir -p $(destDir)
	mv main $(destDir)
	cp $(inputFile) $(outputFile) $(outputFile2) $(destDir)
	@echo "All Done, executables should be in the $(destDir)"
