# C++ compiler
CC = g++ 
CC_FLAGS = -fopenmp -std=c++11

destDir = ./RBTree

all: gen_bin gen_data

gen_bin: inputer.cpp
	$(CC) $(CC_FLAGS) -o inputer inputer.cpp

gen_data: gen_bin
	./inputer 50000 input

# TO DO mover arquivo gerado para pasta da arvore e rodar makefile da arvore 
rb_tree: all
	mkdir -p $(destDir)
	mv input_50000 $(destDir)

# 	@echo "All Done, executables should be in the $(destDir)"
# 	$(MAKE) ./RBTree/make gen_data
