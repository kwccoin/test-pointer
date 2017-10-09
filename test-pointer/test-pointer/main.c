//
//  main.c
//  test-pointer
//
//  Created by blue5 on 8/10/2017.
//  Copyright © 2017 blue5. All rights reserved.
//
// https://users.cs.cf.ac.uk/Dave.Marshall/C/node10.html
//
// a better *ip print is to use C99 standard but not here : https://stackoverflow.com/questions/9053658/correct-format-specifier-to-print-pointer-address


#include <stdio.h>
#include "integerPointer.h"
#include "floatPointer.h"
#include "struPointer.h"  // strange it still function without htis include statement ???
#include "struFPointer.h"
#include "arrayPointer.h"

int xM = 88; /* in heap? address is 0x100003038  */

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int yM = 99; /* in stack? address is 0x7fff5fbff69c */
    
    printf("testing pointers understanding! Main -- start -- \n\n");
    
    // not sure why you have this issue of declaration of function; function call ok but ...
    
    // printf("integerPointer() return code is %i", integerPointer());
    // printf("floatPointer()   return code is %i", floatPointer());
    // printf("struPointer()   return code is %i", struPointer());
    // printf("struFPointer()   return code is %i", struFPointer());
    // printf("arrayPointer()   return code is %i", arrayPointer());
    // simuBlock1 does not work as there is no callback.h
       printf("blockPointer()   return code is %i", blockPointer());
       printf("blockPointer()   return code is %i", blockPointer());

    printf("\n\nxM  %i and xM  address is %p \n",xM,   (void *)&xM);
    printf("\nyM  %i and yM  address is %p \n\n",yM,   (void *)&yM);

    
    printf("testing pointers understanding! Main --end-- \n\n");
    
    /* test git commited via Xcode*/
    
    return 0;

};


