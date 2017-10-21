// https://stackoverflow.com/questions/351733/can-you-write-object-oriented-code-in-c#_=_
#include<stdio.h>

struct foobarbaz{
    int one;
    int two;
    int three;
    int (*exampleMethod)(int, int);
};

int addTwoNumbers(int a, int b){
    return a+b;
}

int main()
{
    // Define the function pointer
    int (*pointerToFunction)(int, int) = addTwoNumbers;

    // Let's make sure we can call the pointer
    int test = (*pointerToFunction)(12,12);
    printf ("test: %u \n",  test);

    // Now, define an instance of our struct
    // and add some default values.
    struct foobarbaz fbb;
    fbb.one   = 1;
    fbb.two   = 2;
    fbb.three = 3;

    // Now add a "method"
    fbb.exampleMethod = addTwoNumbers;

    // Try calling the method
    int test2 = fbb.exampleMethod(13,36);
    printf ("test2: %u \n",  test2);

    printf("\nDone\n");
    return 0;
}
