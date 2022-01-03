#include "HW4_Header.h"


CMP Cmp_Int(Pkey a, Pkey b) {
	if (*(int*)a == *(int*)b)
		return EQUAL;
	
	return(*(int*)a > *(int*)b ? SMALLER : GREATER);

}

void Print_Int(Pkey toprint,FILE* out) {
	
	fprintf(out,"%d ",*(int*)toprint);
}

void Free_Int(Pkey tofree) {
	free(tofree);
}


int main() {

	//vars

	PTree root = NULL;
	FILE* in, * out;
	int k,func_in = 0;
	void* temp_num = NULL;

	//open reading and writing files
	
	in = fopen("instructions.txt", "rt");
	if (in == NULL) {
		printf("We couldn't open the reading file! Error!");
		exit(1);
	}

	out = fopen("output.txt", "wt");
	if (out == NULL) {
		printf("We couldn't open the writing file! Error!");
		exit(1);
	}

	/*
	We are creating the "base" root from the main to have a better control on our tree from the main.
	from this moment on if we exit the program from any reason we must free the tree using the delete tree function.
	*/

   root = CreateNode(temp_num);
   if (root == NULL) {
	   printf("Memo Allocation failed!"); //here there is nothing to free if failed.
	   exit(1);
	}
	
   while (fscanf(in, "%d", &func_in) != EOF) {

	   switch (func_in) {

	   case 1:
		   temp_num = (int*)malloc(sizeof(int)); //we allocate the data type
				if (temp_num == NULL)
				{
					printf("Memo Allocation failed!");
						DeleteTree(root, Free_Int); //if failed we delete the current tree
							exit(1); //to exit and close the text files.
				}


		   fscanf(in, "%d", temp_num);
		   if(AddNode(root, temp_num, Cmp_Int, Free_Int)==FALSE) //function 1 + Case that we already has the same data in the tree
		   {
			   fprintf(out, "we already have %d key in the tree! %d wasn't added!\n", *(int*)temp_num, *(int*)temp_num);
			   Free_Int(temp_num); //we free the useless allocated key
		   }
		   else 
			   fprintf(out, "%d was added to the tree!\n", *(int*)temp_num);

		   break;



	   case 2:
		   PrintInOrder(root, Print_Int, out);
		   fprintf(out, "\n");
		   break;

	   case 3:
		   if (temp_num == NULL) {
			   fprintf(out, "The height of your tree is -1\n", TreeHeight(root));
		   }
		   else
		   fprintf(out, "The height of your tree is %d\n", TreeHeight(root));
		   break;

	   case 4:
		   FindMaxData(root, Print_Int, out);
		   break;

	   case 5:
		   fscanf(in, "%d",&k);
		   PrintkMinData(root, k, Print_Int, out);
		   break;


	   default:
		   fprintf(out, "there is no %d function to call", func_in); //default case for a wrong function number to call
	   }

	}
	DeleteTree(root,Free_Int); //destroy the tree an
	fclose(in);
	fclose(out);
	return 0; 
}