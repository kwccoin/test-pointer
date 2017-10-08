//
//  struFPointer.h
//  test-pointer
//
//  Created by blue5 on 8/10/2017.
//  Copyright © 2017 blue5. All rights reserved.
//

#ifndef struFPointer_h
#define struFPointer_h

#include <stdio.h>

typedef struct student_database3 // typedef use name struct not
{
    char name[10];
    int roll;
    int marks;
} Student;

struct student_database2 // typedef use name struct not
{
    char name[10];
    int roll;
    int marks;
} ;

void swap2(struct student_database2 *ptrX, struct student_database2 *ptrY);

void swap3(Student *ptrA, Student *ptrB);


#endif /* struFPointer_h */
