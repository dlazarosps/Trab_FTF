# C++ compiler
CC = g++ 
CC_FLAGS = -fopenmp -std=c++11

# Testa se foi passado quantidade de nós via terminal
ifdef PARM_SIZE
	size = $(PARM_SIZE)
else
	size = 50000
endif

#diretórios
rbDir = ./RBTree
defaultDir = ./Inputs

all: gen_bin gen_data
	mkdir -p $(defaultDir)
	cp input_$(size) input_$(size)_defaut
	mv input_$(size)_defaut $(defaultDir)

gen_bin: inputer.cpp
	$(CC) $(CC_FLAGS) -o inputer inputer.cpp

gen_data: gen_bin
	./inputer $(size) input

rb_tree: all
	mkdir -p $(rbDir)
	mv input_$(size) input_
	mv input_ $(rbDir)
