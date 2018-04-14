
#include <bits/stdc++.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <fstream>		// std::fstream


#define MAX_LEAF 2000

using namespace std;


struct node{
	int value;
	node *left;
	node *right;
};

class btree{
public:
	btree();
	~btree();

	void insert(int key);
	node *search(int key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();

private:
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);
	void inorder_print(node *leaf);
	void inorder_print_binary(node *leaf);
	void postorder_print(node *leaf);
	void preorder_print(node *leaf);

	node *root;
};


btree::btree(){
	root = NULL;
}

btree::~btree(){
	destroy_tree();
}

void btree::destroy_tree(node *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key, node *leaf){

	if(key < leaf->value){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(key >= leaf->value){
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

void btree::insert(int key){
	if(root != NULL){
		insert(key, root);
	}else{
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node *btree::search(int key, node *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}
		if(key < leaf->value){
			return search(key, leaf->left);
		}else{
			return search(key, leaf->right);
		}
	}else{
		return NULL;
	}
}

node *btree::search(int key){
	return search(key, root);
}

void btree::destroy_tree(){
	destroy_tree(root);
}

void btree::inorder_print(){
	inorder_print_binary(root);
	cout << "\n";
}

void btree::inorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void btree::inorder_print_binary(node *leaf){
	if(leaf != NULL){
		inorder_print_binary(leaf->left);
		cout << std::bitset<16>(leaf->value) << ",";
		inorder_print_binary(leaf->right);
	}
}

void btree::postorder_print(){
	postorder_print(root);
	cout << "\n";
}

void btree::postorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

void btree::preorder_print(){
	preorder_print(root);
	cout << "\n";
}

void btree::preorder_print(node *leaf){
	if(leaf != NULL){
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}

// random generator function:
int myrandom (int i) { return std::rand()%i;}

int main(int argc, char * argv[]){


	if (argc != 3){
			cerr << "Uso correto: ./main <input size> <output file> " << endl;
			return 0;
	}


	//btree tree;
	int max_leaf = atoi(argv[1]); //input size
	btree *tree = new btree();
	vector<int>v_nodes(max_leaf); //vetor de nós
  int i = -((max_leaf-1)/2); //limite inferior de valores

	generate(v_nodes.begin(), v_nodes.end(), [&]{ return i++; });

    // Embaralhar elementos do vetor
  random_shuffle (v_nodes.begin(), v_nodes.end(),  myrandom);

	//insere na arvore
	for(int i = 0; i < v_nodes.size(); i++){
			tree->insert(v_nodes[i]);
	}

	// tree->insert(10);
	// tree->insert(6);
	// tree->insert(14);
	// tree->insert(5);
	// tree->insert(8);
	// tree->insert(11);
	// tree->insert(18);

	 // tree->preorder_print();
	 // tree->inorder_print();
	 // tree->postorder_print();

	//salva print da saida em arquivo output
	freopen(argv[2],"w",stdout);
	tree->inorder_print();
	fclose (stdout);

	//delete tree;
	return 0;
}
