//
//  arrayPointer.c
//  test-pointer
//
//  Created by blue5 on 8/10/2017.
//  Copyright © 2017 blue5. All rights reserved.
//

// memory issues different https://stackoverflow.com/questions/18309928/memory-allocation-release-in-c
// int array[30]; auto free
// int * array = (int *)malloc(sizeof(int)*30);  need free(array);

// no malloc calloc ralloc no need of free or stdlib.h ...
// https://stackoverflow.com/questions/21513666/how-to-free-memory-from-char-array-in-c

#include <stdlib.h>

#include "arrayPointer.h"

// void resetPtr(int *X);

int arrayPointer() {
    
    printf("testing pointers understanding! ==arrayPointer start== \n\n");
    
    int a[10]; // , x;
    // int *pa, *pb;
    
    printf("size of a is %lu", sizeof(a)); // size of a is 40 not 10
    printf("size of int is %lu", sizeof(int)); // size of a is 40 not 10
    
    for (int i=0; i < (sizeof(a)/sizeof(int)) ; i++) {
        // you need to divide this otherwise the loop of 40 write over other people memory !!!!
        a[i] = i;
    };
    
    // pa = &a[0];
    // pb = a;
    // x = *pa;
    
    printf("\n-- after init --\n\n");
    printf("a[0]   %i and a[0]  address is %p \n",a[0],   (void *)&a[0]);
    printf("a[9]   %i and a[9]  address is %p \n",a[9],   (void *)&a[9]);
    //printf("pa   %i and pa  address is %p \n",pa,   (void *)&pa);
    //printf("*pa %i and *pa address is %p \n",*pa, (void *)pa);
    //printf("pb   %i and pb  address is %p \n",pb,   (void *)&pb);
    //printf("*pb %i and *pb address is %p \n",*pb, (void *)pb);
    //printf("x   %i  \n",x);
    //printf("x  address is %p \n",(void *)&x);
    
        // cannot do &x strange
        // just x give you 0x0 !!! as x being pass
    printf("***\n");
    
    printf("testing pointers understanding! ==arrayPointer end== \n\n");
    
    printf("****\n");
    
    // cannot free this as pa is not allocated -- resetPtr(pa);
    // resetPtr(pb);
    
    // need to free the memory I think otherwise will be abended ...
    
    return 0;
}

/* error
int myStrlen(char *s)
{ char *p = s;
    
    while (*p != `${\backslash}0$);
    p++;
    return p-s;
}
 */

// https://stackoverflow.com/questions/5350314/free-a-pointer-to-dynamic-array-in-c
/*
void resetPtr(int *myPointer) {
    if (myPointer) {
        free(myPointer);
        *myPointer = NULL;
    }
}
*/
