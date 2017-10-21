// from c4learn to Mac OS X
// some warning on Darwin Null

// seems stru on stru not ok


#include<stdio.h>
//#include<conio.h> 
#include<stdlib.h>
 
#define MAX 50
int size;
 
// Defining the stack structure
struct stack {
   int arr[MAX];
   int top;
   void (*push)(struct stack *st, int num); // new and add *
   int (*pop)(struct stack *st); 			  // new and add *
   void (*display)	(struct stack *st);        // new add add *

}; 

//struct stack2 {
//	struct stack;
// 	int (*pop2)(struct stack *st); 
//};

void f_push(struct stack *st, int num) ; // need declaration
 int f_pop(struct stack *st); //
 int f_pop2(struct stack *st); //
void f_display(struct stack *st) ; //
void f_display2(struct stack *st) ; //


 
// Initializing the stack(i.e., top=-1)
void init_stk(struct stack *st) { // constructor 
   st->top = -1;
   st->push = f_push; // add dynamic func members, not using v_tab
   st->pop = f_pop; // add dynamic func members, not using v_tab
   st->display = f_display; // add dynamic func members, not using v_tab
   
}

//void init_stk2(struct stack2 *st2) { // constructor 
//   st2->top = -1;
//   st2->push = f_push; // add dynamic func members, not using v_tab
//   st2->pop = f_pop; // add dynamic func members, not using v_tab
//   st2->display = f_display; // add dynamic func members, not using v_tab
//   
//}
 
// Entering the elements into stack
void f_push(struct stack *st, int num) { // ? need to add f_ ??
   if (st->top == size - 1) {
      printf("\nStack overflow(i.e., stack full).");
      return;
   }
   st->top++;
   st->arr[st->top] = num;
}
 
//Deleting an element from the stack.
int f_pop(struct stack *st) { // ? need to add f_ ??
   int num;
   if (st->top == -1) {
      printf("\nStack underflow(i.e., stack empty).");
      return NULL; // return int expected ???!!!
   }
   num = st->arr[st->top];
   st->top--;
   return num;
}

int f_pop2(struct stack *st) { // ? need to add f_ ??
   int num;
   if (st->top == -1) {
      printf("\nStack underflow(i.e., stack empty).");
      return NULL; // return int expected ???!!!
   }
   num = st->arr[st->top];
   num = st->arr[st->top];
   st->top--;
   st->top--;
   return num;
}
 
void f_display(struct stack *st) { // ? need to add f_ ??
   int i;
   for (i = st->top; i >= 0; i--)
      printf("\n%d", st->arr[i]);
}

void f_display2(struct stack *st) { // ? need to add f_ ??
   int i;
   for (i = st->top; i >= 0; i--)
      printf("display2: \n%d", st->arr[i]);
}
 
int main() {
   int element, opt, val;
   struct stack ptr;
   init_stk(&ptr);
   ptr.display = f_display2; // you can change the method - dynamic method ... not encouraged
   // struct stack2 ptr2;
   // init_stk2(&ptr2);
   // ptr2.pop2 = f_pop2; // you can change the method - dynamic method ... not encouraged
   // cannot inherence?? ptr2.display = f_display2; // you can change the method - dynamic method ... not encouraged
   printf("\nEnter Stack Size :");
   scanf("%d", &size);
   while (1) {
      printf("\n\ntSTACK PRIMITIVE OPERATIONS");
      printf("\n1.PUSH");
      printf("\n2.POP");
      printf("\n3.DISPLAY");
      printf("\n4.QUIT");
      printf("\n");
      printf("\nEnter your option : ");
      scanf("%d", &opt);
      switch (opt) {
      case 1:
         printf("\nEnter the element into stack:");
         scanf("%d", &val);
         ptr.push(&ptr, val); // change the way to call but not -> assume pointer but .
         break;
      case 2:
         element = ptr.pop(&ptr);
         printf("\nThe element popped from stack is : %d", element);
         break;
      case 3:
         printf("\nThe current stack elements are:");
         ptr.display(&ptr);
         break;
      case 4:
         exit(0);
      default:
         printf("\nEnter correct option!Try again.");
      }
   }
   return (0);
}
 