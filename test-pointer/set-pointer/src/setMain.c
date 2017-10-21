// https://www.cs.colorado.edu/~kena/classes/5448/f12/presentation-materials/gatchell.pdf

#include <assert.h>

#include <stdio.h>

#include "new.h" 
#include "Object.h" 
#include "Set.h"

int setMain(){
    
	void * s = new(Set);
	void * a = add(s, new(Object)); 
	void * b = add(s, new(Object)); 
	void * c = new(Object);

	if (contains(s, a) && contains(s, b))
		 puts("\n 1 ok s has a and s has b\n");
	else
		 puts("?problem 1?\n");


	if (contains(s, c))
		 puts("?contains?\n");
	else
		 puts("2 ok s no c but c has to exist !!!! not deleted\n");

		 
	void * d = add(s,c);

	if (contains(s, c))
		 puts("3 ok after add c to s, now s should have c !\n");
	else
		 puts("?s should have c but not?\n");

    if (contains(s, a))
        puts("3b ok after try a in c and it should be ok !\n");
    else
        puts("?s should have a but not?\n");

    

	if (differ(a, add(s, a)))
		 puts("?a differ add a to s return a?\n");
	else
		 puts("4 ok a same as add a to s return a\n");

	if (contains(s, drop(s, a)))
		 puts("?drop a hence a should not have a?\n");
	else 
		puts("5 ok after drop a s should not hae a\n");

	printf("6a  before drop b pointer is %p  contain %i\n",   (void *) b, b);

	delete(drop(s, b)); 
	
	puts("6b ok after  drop b from s but problem now if contain/find check\n");
	
	printf("6c  after  drop b pointer is %p contain %i \n\n",   (void *) b, b);

    if (contains(s, b))
        puts("?problem as after drop b got b ?\n");
    else
        puts("8 ok after drop b, s has no b\n");
    
	
	printf("7a  before drop c pointer is %p  contain %i\n",   (void *) c, c);

	delete(drop(s, c)); 
	
	puts("7b ok after  drop c from s but problem now if contain/find check\n");
	
	printf("7c  after  drop c pointer is %p contain %i \n\n",   (void *) c, c);
	


    if (contains(s, c))
        puts("?problem as after drop b got c ?\n");
    else
        puts("9 ok after drop c, s has no c\n");

    puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    puts("cannot assert the element .... ?????????? after delete as item -> 0               ");
    puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    
	return 0;
}

#if ! defined MANY || MANY < 1 
#define MANY 10 
#endif

static int heap [MANY]; 

void * new (const void * type, ...) {
	int * p; /* & heap[1..] */
	
	for (p = heap + 1; p < heap + MANY; ++ p) 
		if (! * p) break;  // not 0 should be 10  then p is assigned and not break!!!
	// strange loop above but now understand ... 
	
	assert(p < heap + MANY);
	* p = MANY;  // and the content of the p is 10 or p point to 10
	
	printf("\n=== heap ===\n"); 

	printf("heap       -%p-\n",     (void *) &heap); 
	
	printf("heap[0]    -%p-\n",     (void *) &heap[0]); 
	printf("heap[MANY] -%p-\n",  (void *) &heap[MANY]); 
	
	// printf("MANY -%p- \n",  (void *) &MANY); * p = MANY but MANY is an int 10!!!!
	printf("* &p is  -%p-\n",   (void *) &p);
    printf("*  p is  -%p-\n",   (void *)  p);
    printf("   p has -%i-\n",   (void *) *p);
    printf("=== heap ===\n\n"); 

	
	return p;
}

void delete (void * _item) {
	int * item = _item;
	
	if (item)
		{ assert(item > heap && item < heap + MANY);
		* item = 0;  // once delete the items point to 0 not null pointer but then you cannot assert ... drop/delete
		}
}

void * add (void * _set, const void * _element) {
	int * set = _set;
	const int * element = _element;

	assert(set > heap && set < heap + MANY); //
	assert(* set == MANY); //Make sure the set does not belong to another set
	assert(element > heap && element < heap + MANY);

	if (* element == MANY)
		* (int *) element = set - heap;   // if MANY meant it was new or dropped
                                          // if it is in the set it was set to set - heap
	else
		assert(* element == set - heap);

	return (void *) element;
}

void * find (const void * _set, const void * _element) {

	const int * set = _set;
	const int * element = _element;
	
    printf("\n");
    printf("  find func -> set    pointer is %p \n",   (void *) _set);
    printf("  find func -> set    has %i \n",    _set);
    printf("  find func -> elment pointer is %p \n",   (void *) _element);
    printf("  find func -> set    has %i \n",    _element);
    printf("  find func -> heap   pointer is %p \n\n", (void *) &heap);
	
	assert(set > heap && set < heap + MANY); 
	assert(* set == MANY);
	assert(element > heap && element < heap + MANY); 
	
	if (element) {
        // ?????????? DOES NOT WORK AFTER Delete ????????????????????????????????????
		// assert(* element);  // problem with this statement as it could be after delete!!!
        // after drop *element  is 0 not 1 or 10 like other cases
		return * element == set - heap ? (void *) element : 0;}
	else {
		return 0;
	};
}

int contains (const void * _set, const void * _element) //Converts the result of find into a Truth value
{
	return find(_set, _element) != 0;
}

void * drop (void *_set, const void * _element) {
	int * element =find(_set, _element);
	
	if (element)
    	* element = MANY;
	
	return element;
}

int differ (const void * a, const void * b)
{
return a != b;
}

const void * Set;
const void * Object;
