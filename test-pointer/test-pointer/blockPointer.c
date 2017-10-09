//
//  blockPointer.c
//  test-pointer
//
//  Created by blue5 on 9/10/2017.
//  Copyright © 2017 blue5. All rights reserved.
//

// https://en.wikipedia.org/wiki/Blocks_%28C_language_extension%29
// source: http://thirdcog.eu/pwcblocks/

#include "blockPointer.h"

#include <stdio.h>
#include <Block.h>

typedef int  (^IntBlock)();  // ^ is like a pointer *; define a type of Block that return int
typedef void (^Block)   ();  // a general Block that take no parameter and return nothing

/* not allow -> myblock1 = ^ int (void) { return 3; }; */

IntBlock threeBlock = ^ {
    return 3;
};
// not allow int three = threeBlock();  error compiler not constant something ???


IntBlock MakeThree() {
    __block ;
    
    return Block_copy(
                      
                      threeBlock
                      );
    
    // note the Block is a literal like a string that is fixed during compile time - lexical scope
    // from ^ ... }
}


IntBlock MakeCounter1(int start, int increment) {
    __block int i = start;
    
    return Block_copy(
                      
      ^(void) {  // what is that void should it be int (void ) i.e. no input parameter but return int ???
        int ret = i;
        i += increment;
        return ret;
           // it returns an int but what is the above void thing
           // multiple return meant must return same type as it is a literal
      }
                      );
    
    // note the Block is a literal like a string that is fixed during compile time - lexical scope
    // from ^ ... }
}

typedef struct {
    IntBlock forward;
    IntBlock backward;
} Counter;

Counter MakeCounter(int start, int increment) {
    Counter counter;
    
    __block int i = start;
    
    counter.forward = Block_copy( ^ {
        i += increment;
        return i;
    });
    counter.backward = Block_copy( ^ {
        i -= increment;
        return i;
    });
    
    return counter;
    
}

int blockPointer(void) {

    IntBlock mycounter = MakeCounter1(5, 2);
    
    printf("\nFirst call: %d\n", mycounter());
    printf("Second call: %d\n", mycounter());
    printf("Third call: %d\n", mycounter());
    
    printf("\njust three: %d\n", threeBlock());
    
    /* because it was copied, it must also be released */
    Block_release(mycounter);
    
    Counter counter = MakeCounter(15, 12);
    printf("\n\nForward one: %d\n", counter.forward());
    printf("Forward one more: %d\n", counter.forward());
    printf("Forward one more: %d\n", counter.forward());
    printf("Forward one more: %d\n", counter.forward());
    printf("\nBackward one: %d\n", counter.backward());
    printf("Backward one more: %d\n", counter.backward());
    
    printf("\n\nmycounter        address is %p\n", &mycounter);
    printf("threeBlock       address is %p <seems in heap 0x100003138> \n", &threeBlock);    /* in heap !!! */
    printf("counter.forward  address is %p\n", &counter.forward);
    printf("counter.backward address is %p\n", &counter.backward);
    
    Block_release(counter.forward);
    Block_release(counter.backward);

    
    
    return 0;
}
