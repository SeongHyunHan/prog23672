#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
};

struct TreeType {
	TreeNode* root;
	void insert(TreeNode*& parent, TreeNode*& tree, int value, int num);

	void insertItem(int value) {
		insert(root, root, value, 0);
	}
	int searchItem(TreeNode* tree,int value);
	bool search(TreeNode* tree, int value);
};

void TreeType::insert(TreeNode*& parent, TreeNode*& tree, int value, int num) {
	if (tree == NULL) {
		tree = new TreeNode;
		tree->left = NULL;
		tree->right = NULL;
		tree->value = value;
		if (parent->value > tree->value) {
			parent->left = tree;
		}
		else if(parent->value < tree->value){
			parent->right = tree;
		}
	}
	else if (value < tree->value)
		insert(tree, tree->left, value, 0);
	else
		insert(tree, tree->right, value, 0);
}

bool TreeType::search(TreeNode* tree, int value) {
	if (value == tree->value)
		return true;
	else 
		return false;
}

int TreeType::searchItem(TreeNode* tree, int value) {
	int numSearch = 0;
	if (root == NULL)
		return 0;
	bool find = false;
	while (find == false) {
		numSearch++;
		if (value < tree->value)
			tree = tree->left;
		else if (value > tree->value)
			tree = tree->right;
		else
			find = true;
	}
	return numSearch;
}

int main() {
	TreeType* myTree = new TreeType;
	myTree->root = NULL;
	TreeNode* rootNode = new TreeNode;
	
	int arraySize = 100;
	int *intArray = new int[arraySize + 1];
	int arraySearch = 0;
	int bstSearch = 0;
	
	ifstream myFile("integers.txt");

	if (myFile.is_open()) {
		int i = 0;
		string line;
		while (!myFile.eof()) {
			myFile >> intArray[i];
			myTree->insertItem(intArray[i]);
			if (i == 0)
				rootNode = myTree->root;
			else if (i == 1 && rootNode->value > myTree->root->value)
				rootNode->left = myTree->root;
			else if(i == 1 && rootNode->value < myTree->root->value)
				rootNode->right = myTree->root;
			i++;
		}
		myTree->root = rootNode;
	}
	bool arrayfind = false;

	int input[10] = { 90, 49, 100, 30, 75, 79, 25, 5, 15, 55 };
	int i = 0;
	for (int j = 0; j < 10; j++) {
		while (arrayfind == false) {
			arraySearch++;
			if (intArray[i] == input[j]) {
				arrayfind = true;
			}
			else {
				i++;
			}
		}
		bstSearch = myTree->searchItem(myTree->root, input[j]);

		cout << "Search Value: " << input[j] << " Num of Tries: " << j << "\n";
		cout << "Array searched its value in " << arraySearch << " times\n";
		cout << "BST searched its value in " << bstSearch << " times\n\n";
		arrayfind = false;
		arraySearch = 0;
		i = 0;
	}

	system("pause");
	return 0;
}

