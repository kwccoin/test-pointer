#include<stdio.h>
//#include<conio.h> 
#include<stdlib.h>
 
#define MAX 50
int size;
 
// Defining the stack structure

typedef struct StackTag {
   int arr[MAX];
   int top;
} Stack;

typedef struct StackImplTag {
   //int arr[MAX];
   //int top;
   Stack ss;
   void (*push)(Stack *st, int num); // new and add *
   int (*pop)(Stack *st); 			  // new and add *
   void (*display)(Stack *st);        // new add add *

} StackImpl; 

//Stack2 {
//	Stack;
// 	int (*pop2)(Stack *st); 
//};

void f_push(Stack *st, int num) ; // need declaration
 int f_pop(Stack *st); //
 int f_pop2(Stack *st); //
void f_display(Stack *st) ; //
void f_display2(Stack *st) ; //

