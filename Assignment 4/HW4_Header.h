#define _CRT_SECURE_NO_WARNINGS
#ifndef _HW4_Imp
#define _HW4_Imp
#define Max(a,b) ((a) > (b)? (a): (b))

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Tree *PTree;
typedef enum {FALSE,TRUE} BOOL;
typedef enum { NEUTRAL,EQUAL, GREATER, SMALLER } CMP;
typedef void* Pkey;

typedef CMP(*Cmp_Key)(Pkey,Pkey); // a ptr to a function that will compare the keys.
typedef void (*Print_Key)(Pkey,FILE*); // a ptr to a function that will write the key.
typedef void (*Free_Key)(Pkey); // a ptr to a function that will free the key.

BOOL AddNode(PTree root, Pkey toadd, Cmp_Key cmpdata, Free_Key freedata); //#1
/*
Function name: AddNode
Input: PTree,Pkey,Cmp_Key,freedata
Output: BOOL (true or false) if its true it meants that we added a new node with the new key else, we already have the same key in the tree.
Function Algorithm: we create a new node if its not the first or call or the key is not in the tree, we call CreateNode function to help us allocate the memo
		*/
void PrintInOrder(PTree root,Print_Key printdata, FILE* out); //#2
/*
Function name: PrintInOrder
Input: PTree,Print_Key,FILE*
Output: void
Function Algorithm: we print the whole tree recursively using the pointer to the print/write data so we can print the data type in ADT form.
		*/
int TreeHeight(PTree root); //#3
/*
Function name: TreeHeight
Input: PTree the tree root
Output: int (the height of the tree) always an integer 
Function Algorithm: we return the tree height recursively (defined to be the deepest node in the tree)
		*/
void FindMaxData(PTree root,Print_Key printdata, FILE* out); //#4
/*
Function name: FindMaxData
Input: PTree,Print_Key,FILE*
Output: void 
Function Algorithm: we find the max value with a while loop (because its binary tree we go until we have null in the right tree) and we write it to the output file.
		*/
void PrintkMinData(PTree root, int k, Print_Key printdata, FILE* out); //#5
/*
Function name: PrintkMinData
Input:PTree,int,Print_Key,out
Output: void
Function Algorithm: similar to binary search but we search a sub-tree and not a number that determined by k.
		*/


//General functions add ons
void DeleteTree(PTree root, Free_Key freedata);
/*
Function name: DeleteTree
Input:PTree,Free_Key
Output:void
Function Algorithm:we delete the whole tree recursively.
		*/

PTree CreateNode(Pkey toadd);
/*
Function name:CreateNode
Input:PKey
Output:PTree
Function Algorithm:We allocate memo for a new node, initliaze the node and put the data inside it,
(data is defined to be already allocated so if we return from this function NULL, its means that memo failed) and we will free the memo in the called function.
		*/
int TreeSize(PTree root);
/*
Function name :TreeSize
Input : PTree
Output : int
Function Algorithm : finds the size of the tree (number of elements)
*/

#endif

