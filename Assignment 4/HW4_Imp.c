#include "HW4_Header.h"

struct Tree
{
	Pkey data;
	struct Tree *left;
	struct Tree *right;
};

BOOL AddNode(PTree root, Pkey toadd, Cmp_Key cmpdata,Free_Key freedata) {
	CMP stat=NEUTRAL;
	PTree new=NULL,q=root,prev=NULL;


	/*
	Because we send the allocated memo of to add into this function 
	we want to return false when we already have the same pkey in the tree
	if we have the same pkey in the tree we will free the memo of the "temp" allocated data in the main. 
	*/
if (root->data == NULL) { //this is for the first NODE that we are making we wanna make sure that we are not allocating another node beacuse we have done it in the main for the base root.
		root->data = toadd;
			return TRUE;
	}

	while (q != NULL) {
		stat=cmpdata(q->data, toadd); //we put the returned value of cmp into stat
		if (stat == EQUAL) //case that a node with the same data already exists
			return FALSE;

		prev = q; //we save the prev node to indicate the previous node so we can link them.

		if (stat == GREATER) { //if we need to go right
			q = q->right;

		}
		else q = q->left; //else we need to go left

	}
	//once we got here we know that if stat=greater it indicates that we need to link the new node to prev->right else prev->left
	new = CreateNode(toadd);
	if (new == NULL) {
		DeleteTree(root, freedata);
		printf("Memo Allocation Failed!");
		exit(1);
	}

	if (stat == GREATER)
		prev->right = new;

	else prev->left = new;

	return TRUE;
	
	
}

void PrintInOrder(PTree root, Print_Key printdata, FILE* out) {

	if (root == NULL)
		return;
	PrintInOrder(root->left, printdata, out);
	printdata(root->data, out); //when we reach a node with left son null it means that we need to print it and keep go right.
	PrintInOrder(root->right, printdata, out);

}
int TreeHeight(PTree root)// returns the Height of a given tree #3
{
	if (root == NULL) return -1; 
	return Max(TreeHeight(root->left) + 1, TreeHeight(root->right) + 1); //we have a max function defined, because of the tree height definition that the tree height determined by the deepest node.
}
void FindMaxData(PTree root, Print_Key printdata, FILE* out) {
	PTree q = root;
	while (q ->right!= NULL) { //when the q->right is null the q->data is our max (binary tree only)
		q = q->right;
	}
	fprintf(out, "The maximum is ");
	printdata(q->data, out);
	fprintf(out, "\n");
}
void PrintkMinData(PTree root, int k, Print_Key printdata, FILE* out) {

	PTree q = root, p = NULL;
	int leftsize = 0, rightsize = 0, totalsize = 0, n = k;
	totalsize = TreeSize(root);
	
	if (n <= 0) //case for n that is not positive
	{
		fprintf(out, "We must have a positive number of elements to print!\n");
		return;
	}
	if (totalsize < n) { //case that tree size is less then n
		fprintf(out, "There are no %d elements in this tree!\n", k);
		return;
	}


	fprintf(out, "The are %d small elements in this tree: ", k);
	while (n > 0) { //logarithm similar to binary search
		totalsize = TreeSize(root);
		leftsize = TreeSize(q->left);
		rightsize = TreeSize(q->right);
		
		if (totalsize == n) { //print the whole tree/sub tree so far
			PrintInOrder(q, printdata, out);
			fprintf(out, "\n");
			return;
		}
		if (n >= leftsize + 1) { //we want to find out if we need to print the whole left tree + the root
			if(q->left!=NULL)
				PrintInOrder(q->left, printdata, out); //make sure that the left size is not empty, if its not empty print the whole left tree

			printdata(q->data, out); //print the base root data
			q = q->right; //and our new base root is the right size.
			n = n - leftsize - 1; //we reduce the n to save the amount of keys left to print.
		}
		else if (n == leftsize) { //if we don't need to print the root only the left size
			PrintInOrder(q->left, printdata, out);
			fprintf(out, "\n");
			return;
		}
		else q = q->left; //it means that the left tree size is bigger then our n.
	}

	fprintf(out, "\n");
}


void DeleteTree(PTree root, Free_Key freedata) {

	if (root == NULL)
		return;
	DeleteTree(root->left,freedata);
	DeleteTree(root->right, freedata);
	freedata(root->data); //free the memo allocated data type outside
	free(root);
	root = NULL; //we wanna make sure that the tree will keep its structure so we can keep the delete processes
	
}
PTree CreateNode(Pkey toadd) {
	PTree node;

	node = (PTree)malloc(sizeof(struct Tree));
	if (node == NULL)
		return NULL; // we handle the case of memo failed outside this function.
	//initialize
	node->left = NULL;
	node->right= NULL;
	node->data = toadd; 

	return node;
}
int TreeSize(PTree root) {
	if (root == NULL)
		return 0;
	else return(TreeSize(root->left) + 1 + TreeSize(root->right));
	
}



