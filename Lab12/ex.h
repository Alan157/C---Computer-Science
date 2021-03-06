#ifndef _ HEADER_H
#define _ HEADER_H

#include <stdio.h>
#include <stdlib.h>

typedef BOOL (*compare_func)(void*, void*);
typedef void (*print_func)(void*);
typedef void (*free_func)(void*);

typedef  struct ListNode* PNode;
typedef enum{FALSE,TRUE} BOOL;

/***********************************************/
/*       public interface:                      */

/* inserting a new element.*/
BOOL insertEntry(PNode* head, PNode* tail, void *data,
 compare_func func);

/* deleting an element,pointered by todel*/
BOOL deleteNode(PNode* head, PNode* tail, void *todel,
 compare_func func1, free_func func2);

/* print the elements in the list */
void printAll(PNode head, print_func func);

/* deleting the entire list */
void freeAll(PNode* head, free_func func);

#endif
