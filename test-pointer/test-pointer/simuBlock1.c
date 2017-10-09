//
//  simuBlock1.c
//  test-pointer
//
//  Created by blue5 on 9/10/2017.
//  Copyright © 2017 blue5. All rights reserved.
//

#include "simuBlock1.h"
/* no <callback.h> in App
#include <callback.h>
#include <stdio.h>
static void incrementer_(int *in) {
    ++*in;
}
static void emitter_(int *in) {
    printf("%d\n", *in);
}
int main() {
    int in1 = 10, in2 = 20;
    int (*incrementer1)() = alloc_callback(&incrememnter_, &in1);
    int (*emitter1)() = alloc_callback(&emitter_, &in1);
    int (*incrementer2)() = alloc_callback(&incrememnter_, &in2);
    int (*emitter2)() = alloc_callback(&emitter_, &in2);
    incrementer1();
    incrementer2();
    emitter1();
    emitter2();
    free_callback(incrementer1);
    free_callback(incrementer2);
    free_callback(emitter1);
    free_callback(emitter2);
}
*/
