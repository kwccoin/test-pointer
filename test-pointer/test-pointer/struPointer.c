//
//  struPointer.c
//  test-pointer
//
//  Created by blue5 on 8/10/2017.
//  Copyright © 2017 blue5. All rights reserved.
//
// http://www.c4learn.com/c-programming/c-pointer-to-structures/
// http://www.cs.nyu.edu/courses/spring05/V22.0201-001/c_tutorial/classes/String.html

#include "struPointer.h"
#include <string.h>


struct student_database // this is not a typedef ... 
{
    char name[10];
    int roll;
    int marks;
};

void swap(struct student_database *ptrX, struct student_database *ptrY);

int struPointer(){
 
    printf("\ntesting pointers understanding! ==struPointer start== \n\n");

    
/*    struct student_database
    {
        char name[10];
        int roll;
        int marks;
    }stud1; */

    struct student_database stud1;
    
    strcpy(stud1.name, "Dennis");
    stud1.roll = 10;
    stud1.marks = 90;
    
    printf("\ndb1-name:\t%s",stud1.name);
    printf("\ndb1-length:\t%lu",strlen(stud1.name));
    
    
    printf("\ndb1-Roll Number : %d",stud1.roll);
    printf("\ndb1-Marks of Student : %d\n",stud1.marks);

    struct student_database stud2 = {"Pritesh",91,99};
    
    struct student_database *ptr;
    ptr = &stud2;

    printf("\ndb2-name             : %s",(*ptr).name);
    printf("\ndb2-length           : %lu",strlen((*ptr).name));
    printf("\ndb2-Roll Number      : %d",(*ptr).roll);
    printf("\ndb2-Marks of Student : %d\n",(*ptr).marks);

    swap(&stud1, &stud2);

    printf("\n--- after swap now should be Dennis-\n");

    
    printf("\ndb2-name             : %s",(*ptr).name);
    printf("\ndb2-length           : %lu",strlen((*ptr).name));
    printf("\ndb2-Roll Number      : %d",(*ptr).roll);
    printf("\ndb2-Marks of Student : %d\n",(*ptr).marks);

    
    printf("\n");
    
    printf("\ntesting pointers understanding! ==struPointer end== \n\n");

    
    return 0;
};

void swap(struct student_database *ptrX, struct student_database *ptrY)

{ struct student_database temp;
    
    temp = *ptrX;
    /* contents of pointer */
    
    *ptrX = *ptrY;
    *ptrY = temp;
}
