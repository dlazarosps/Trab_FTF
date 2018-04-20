# C++ compiler
CC = g++ 
CC_FLAGS = -fopenmp -std=c++11

size = 1000
destDir = ./RBTree

all: gen_bin gen_data

gen_bin: inputer.cpp
	$(CC) $(CC_FLAGS) -o inputer inputer.cpp

gen_data: gen_bin
	./inputer $(size) input

# TO DO mover arquivo gerado para pasta da arvore e rodar makefile da arvore 
rb_tree: all
	mkdir -p $(destDir)
	mv input_$(size) $(destDir)

# 	@echo "All Done, executables should be in the $(destDir)"
# 	$(MAKE) ./RBTree/make gen_data
