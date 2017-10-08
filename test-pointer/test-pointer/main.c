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

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("testing pointers understanding! Main\n\n");
    
    // not sure why you have this issue of declaration of function; function call ok but ...
    
    // printf("integerPointer() return code is %i", integerPointer());
    // printf("floatInteger()   return code is %i", floatPointer());
    printf("pointerStru()   return code is %i", struPointer());
     /* test git commited via Xcode*/
    
    return 0;

};


