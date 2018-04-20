#include <bits/stdc++.h>
#include <vector>

#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <fstream>		// std::fstream

using namespace std;

struct AVLTree
{
	AVLTree *left, *right;
	int data;
};

struct AVLTree *gen(int data)
{
	struct AVLTree *element = new AVLTree;
	element->data = data;
	element->left = 0;
	element->right = 0;
	return element;
}

int count(struct AVLTree *root)
{
	if(!root)
		return 0;
	if(!(root->left) && !(root->right))
		return 1;
	if(root->left && root->right)
		return count(root->left)+count(root->right)+1;
	if(root->left && !(root->right))
		return count(root->left)+1;
	if(!(root->left) && root->right)
		return count(root->right)+1;
}

void print(struct AVLTree *root)
{

	if(root->left)
		print(root->left);
	if(root)
		cout << std::bitset<16>(root->data) << endl;
	if(root->right)
		print(root->right);
}

void printExtended(struct AVLTree *root, int hight)
{
	if(root)
	{
		if(root->right)
			printExtended(root->right, hight+1);
		for(int h = hight; h > 0; h--)
			cout << "\t";
		cout << root->data << "\n";
		if(root->left)
			printExtended(root->left, hight+1);
	}
}

int height(struct AVLTree *root)
{
	if(root)
	{
		if(!(root->left) && !(root->right))
			return 1;
		if(root->left && root->right)
		{
			int heightLeft = height(root->left);
			int heightRight = height(root->right);
			if(heightLeft > heightRight)
				return heightLeft+1;
			else
				return heightRight+1;
		}
		if(root->left && !(root->right))
			return height(root->left)+1;
		if(!(root->left) && root->right)
			return height(root->right)+1;
	}
	else
		return 0;
}

int heightDiff(AVLTree *root)
{
	int heightLeft, heightRight;
	if(root->left)
		heightLeft = height(root->left);
	else
		heightLeft = 0;
	if(root->right)
		heightRight = height(root->right);
	else
		heightRight = 0;
	return heightRight - heightLeft;
}

struct AVLTree *rotateLeft(struct AVLTree *root)
{
	struct AVLTree *tmp1 = root->right;
	struct AVLTree *tmp2 = root->right->left;
	tmp1->left = root;
	root->right = tmp2;
	return tmp1;
}

struct AVLTree *rotateRight(struct AVLTree *root)
{
	struct AVLTree *tmp1 = root->left;
	struct AVLTree *tmp2 = root->left->right;
	tmp1->right = root;
	root->left = tmp2;
	return tmp1;
}

struct AVLTree *sort(struct AVLTree *root)
{
	int hDiff = heightDiff(root);
	if(hDiff == 2)
		if(root->right->right)
			root = rotateLeft(root);
		else
		{
			root->right = rotateRight(root->right);
			root = rotateLeft(root);
		}
	else if(hDiff == -2)
		if(root->left->left)
			root = rotateRight(root);
		else
		{
			root->left = rotateLeft(root->left);
			root = rotateRight(root);
		}
    return root;
}

struct AVLTree *add(struct AVLTree *root, int data)
{
    if(root == 0)
		return gen(data);
	else if(data < root->data)
		root->left = add(root->left, data);
    else if(data > root->data)
		root->right = add(root->right, data);
	root = sort(root);
    return root;
}

// rückgabe adresse des knotens (falls knoten selbe adresse hat wie parameterknoten - kein vorgänger)
struct AVLTree *preRoot(struct AVLTree *root, int data)
{
	if(root)
		if(root->data > data)
			if(root->left)
				if(root->left->data == data)
					return sort(root);
				else
					return preRoot(root->left, data);
			else
				return 0;
		else if(root->data < data)
			if(root->right)
				if(root->right->data == data)
					return sort(root);
				else
					return preRoot(root->right, data);
			else
				return 0;
		else
			return root;
	else
		return 0;
}

struct AVLTree *findAndPrepareDelReplaceRoot(struct AVLTree *root, struct AVLTree **del, int data)
{
	if(root->data == data)
	{
		// erste root (delRoot) -> muss erst nach links oder rechts (hier rechts)
		root->right = findAndPrepareDelReplaceRoot(root->right, del, data);
		return sort(root);
	}
	else if(root->left) // es gibt noch mindestens eine linke root
	{
		root->left = findAndPrepareDelReplaceRoot(root->left, del, data);
		return sort(root);
	}
	else // replace gefunden
	{
		*del = root;
		if(root->right)
			return sort(root->right);
		else
			return 0;
	}
}

struct AVLTree *del(struct AVLTree *root, int data)
{
	if(root)
	{
		if(root->data > data)
		{
			root->left = del(root->left, data);
			return sort(root);
		}
		else if(root->data < data)
		{
			root->right = del(root->right, data);
			return sort(root);
		}
		else // if(root->data == data)
		{
			if(root->left && root->right)
			{
				struct AVLTree *tmp;
				root = findAndPrepareDelReplaceRoot(root, &tmp, root->data);
				tmp->left = root->left;
				tmp->right = root->right;
				delete root;
				return sort(tmp);
			}
			else if(!root->left && !root->right)
			{
				delete root;
				return 0;
			}
			else if(!root->left && root->right)
			{
				struct AVLTree *tmp = root->right;
				delete root;
				return sort(tmp);
			}
			else // if(root->left && !root->right)
			{
				struct AVLTree *tmp = root->left;
				delete root;
				return sort(tmp);
			}
		}
	}
	else
		return root;
}

struct AVLTree *find(struct AVLTree *root, int data)
{
	if(data == root->data)
		return root;
	if(data < root->data)
		if(root->left)
			return find(root->left, data);
		else
			return 0;
	if(data > root->data)
		if(root->right)
			return find(root->right, data);
		else
			return 0;
}

// random generator function:
int myrandom (int i) { std::srand(std::time(nullptr)); return std::rand()%(i*2);}

int main(int argc, char *argv[])
{

    if (argc != 3){
        cerr << "Uso correto: ./main [input file] [output file] " << endl;
        return 0;
    }

    std::ifstream is(argv[1]);
    std::istream_iterator<int> start(is), end;
    std::vector<int> v_nodes(start, end);


	struct AVLTree *root = 0;

    //insere na arvore
    for(int i = 0; i < v_nodes.size()+1; i++)
        root = add(root, v_nodes[i]);

    freopen(argv[2],"w",stdout);
    print(root);

    fclose(stdout);
	return 0;
}
