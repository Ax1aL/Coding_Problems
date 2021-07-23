#include<iostream>
#include<string>

using namespace std;

//Problem:------------------
//Given the root to a binary tree, implement serialize(root),
//which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.
//The following test should pass:
//node = Node('root', Node('left', Node('left.left')), Node('right'))
//assert deserialize(serialize(node)).left.left.val == 'left.left'


//Soltuions:----------------
//For serialization we do a Pre-order traversal and add level of the node and the value(which is a string)
//For deserialization we just take each info and add and we know when to go back because of the level we specify 

class Node {
public:
	Node(string val, Node* left=NULL, Node* right=NULL) {
		this->val = val;
		this->left = left;
		this->right = right;
	}
	string val="";
	Node* left = NULL;
	Node* right = NULL;
};

string serialization(Node* node) {
	string str;
	bool newLevel = false;
	str += node->val;
	//For left node
	if (node->left != NULL) {
		str += "'";//shows that theres another level
		newLevel = true;
		str+=serialization(node->left);
	}
	else {
		if (node->right == NULL) { 
			return str; 
		}	else {
			str += "'/";
			newLevel = true;
		}
	}

	//For right node
	if (node->right != NULL) {
		str += "|";//to indicate the begging of the right side
		if(!newLevel)
		str += "'";

		str+=serialization(node->right);
	}
	else {
		str += "/";
	}
	
	return str;
}
Node* deserialization(string str, unsigned int &position) {
	Node* node = new Node("");
	while (position < str.length()) {

		switch (str[position]) {
		case '\'': {node->left = deserialization(str, ++position); break; }
		case '|': {node->right = deserialization(str, ++position); break; }
		case '/': {
			if (node->val.length()!=0) { ++position; 
			return node; }
			++position;
			return NULL; break; }
				 
		}
		if(str[position]!='|'&& position < str.length())
		node->val += str[position++];

	}
		
	return node;
}

int main() {
	
	Node* node =new Node("root", new Node("left", new Node("left.left")),new  Node("right", new Node("right.left"),NULL));
	cout << "The right way:"+serialization(node)<<endl;
	unsigned int position = 0;


	cout <<"The new way:"+ serialization(deserialization(serialization(node),position));


	system("pause");
	return 0;
}

int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{

		if (arr[j] < pivot)
		{
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

		}
	}

	int temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


