// amend http://www.c4learn.com/c-programs/c-program-to-perform-stack-operations-using-pointer.html
// to use object 
// from c4learn to Mac OS X
// some warning on Darwin Null

// seems stru on stru not ok
// seems https://embeddedgurus.com/state-space/tag/c/ stru to typedef struct is not ok as well
// only works on static members !!!
// now work but one has to seperate data Stack and data+metho StackImpl

#include "stack-obj-type-pointer.h"
 
// Initializing the stack(i.e., top=-1)
void init_stk(StackImpl *stImp) { // constructor 
   stImp->ss.top = -1;
   stImp->push = f_push; // add dynamic func members, not using v_tab
   stImp->pop = f_pop; // add dynamic func members, not using v_tab
   stImp->display = f_display; // add dynamic func members, not using v_tab
   
}

//void init_stk2(Stack2 *st2) { // constructor 
//   st2->top = -1;
//   st2->push = f_push; // add dynamic func members, not using v_tab
//   st2->pop = f_pop; // add dynamic func members, not using v_tab
//   st2->display = f_display; // add dynamic func members, not using v_tab
//   
//}
 
// Entering the elements into stack
void f_push(Stack *st, int num) { // ? need to add f_ ??
   if (st->top == size - 1) {
      printf("\nStack overflow(i.e., stack full).");
      return;
   }
   st->top++;
   st->arr[st->top] = num;
}
 
//Deleting an element from the stack.
int f_pop(Stack *st) { // ? need to add f_ ??
   int num;
   if (st->top == -1) {
      printf("\nStack underflow(i.e., stack empty).");
      return NULL; // return int expected ???!!!
   }
   num = st->arr[st->top];
   st->top--;
   return num;
}

int f_pop2(Stack *st) { // ? need to add f_ ??
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
 
void f_display(Stack *st) { // ? need to add f_ ??
   int i;
   for (i = st->top; i >= 0; i--)
      printf("\n%d", st->arr[i]);
}

void f_display2(Stack *st) { // ? need to add f_ ??
   int i;
   for (i = st->top; i >= 0; i--)
      printf("display2a: %d\n", st->arr[i]);
}
 
int main() {
   int element, opt, val;
   StackImpl ptrImpl;
   init_stk(&ptrImpl);
   ptrImpl.display = f_display2; // you can change the method - dynamic method ... not encouraged
   // Stack2 ptr2;
   // init_stk2(&ptr2);
   // ptr2.pop2 = f_pop2; // you can change the method - dynamic method ... not encouraged
   // cannot inherence?? ptr2.display = f_display2; // you can change the method - dynamic method ... not encouraged
   printf("\nEnter Stack Size :");
   scanf("%d", &size);
   while (1) {
      printf("\n\n\tSTACK PRIMITIVE OPERATIONS");
      printf("\n\t1.PUSH");
      printf("\n\t2.POP");
      printf("\n\t3.DISPLAY");
      printf("\n\t4.QUIT");
      printf("\n");
      printf("\n\tEnter your option : ");
      scanf("%d", &opt);
      switch (opt) {
      case 1:
         printf("\n\tEnter the element into stack:");
         scanf("%d", &val);
         ptrImpl.push(&ptrImpl.ss, val); // change the way to call but not -> assume pointer but .
         break;
      case 2:
         element = ptrImpl.pop(&ptrImpl.ss);
         printf("\n\tThe element popped from stack is : %d", element);
         break;
      case 3:
         printf("\n\tThe current stack elements are: \n\n");
         ptrImpl.display(&ptrImpl.ss);
         break;
      case 4:
         exit(0);
      default:
         printf("\n\tEnter correct option!Try again.");
      }
   }
   return (0);
}
 