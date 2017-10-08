//
//  struFPointer.c
//  test-pointer
//
//  Created by blue5 on 8/10/2017.
//  Copyright © 2017 blue5. All rights reserved.
//

#include "struFPointer.h"

#include <string.h>


int struFPointer(){
    
    Student s1, *s2_fn();
    
    s1 = *s2_fn();

    printf("\n*s2_fn()-name             : %s",s1.name);
    printf("\n*s2_fn()-length           : %lu",strlen(s1.name));
    printf("\n*s2_fn()-Roll Number      : %d",s1.roll);
    printf("\n*s2_fn()-Marks of Student : %d\n",s1.marks);

    
    printf("\ntesting pointers understanding! ==struFPointer start== \n\n");
    
    
    /*    struct student_database
     {
     char name[10];
     int roll;
     int marks;
     }stud1; */
    
    struct student_database2 stud1;
    
    strcpy(stud1.name, "Dennis");
    stud1.roll = 10;
    stud1.marks = 90;
    
    printf("\ndb1-name:\t%s",stud1.name);
    printf("\ndb1-length:\t%lu",strlen(stud1.name));
    
    
    printf("\ndb1-Roll Number : %d",stud1.roll);
    printf("\ndb1-Marks of Student : %d\n",stud1.marks);
    
    struct student_database2 stud2 = {"Pritesh",91,99};
    
    struct student_database2 *ptr;
    ptr = &stud2;
    
    printf("\ndb2-name             : %s",(*ptr).name);
    printf("\ndb2-length           : %lu",strlen((*ptr).name));
    printf("\ndb2-Roll Number      : %d",(*ptr).roll);
    printf("\ndb2-Marks of Student : %d\n",(*ptr).marks);
    
    swap2(&stud1, &stud2);
    
    printf("\n--- after swap now should be Dennis-\n");
    
    
    printf("\ndb2-name             : %s",(*ptr).name);
    printf("\ndb2-length           : %lu",strlen((*ptr).name));
    printf("\ndb2-Roll Number      : %d",(*ptr).roll);
    printf("\ndb2-Marks of Student : %d\n",(*ptr).marks);
    
    
    printf("\n");
    
    printf("\ntesting pointers understanding! ==struFPointer end== \n\n");
    
    
    return 0;
};

void swap2(struct student_database2 *ptrX, struct student_database2 *ptrY)

{ struct student_database2 temp;
    
    temp = *ptrX;
    /* contents of pointer */
    
    *ptrX = *ptrY;
    *ptrY = temp;
}

void swap3(Student *ptrA, Student *ptrB)

{ Student temp;
    
    temp = *ptrA;
    /* contents of pointer */
    
    *ptrA = *ptrB;
    *ptrB = temp;
}


Student *s2_fn() {
    
    printf("\n *s2_fn() start== \n\n");

    
    Student tempStudent1 = {"TypeStud1",101,109};
    Student tempStudent2, tempStudent3;
    
    tempStudent2 = (Student){"TypeStud2",102,110};
    
    strcpy(tempStudent3.name, "TypeStud3");
    tempStudent3.roll = 103;
    tempStudent3.marks = 111;

    Student *ptrStud;
    ptrStud = &tempStudent3;
    
    printf("\ndb3-name             : %s",(*ptrStud).name);
    printf("\ndb3-length           : %lu",strlen((*ptrStud).name));
    printf("\ndb3-Roll Number      : %d",(*ptrStud).roll);
    printf("\ndb3-Marks of Student : %d\n",(*ptrStud).marks);

    swap3(&tempStudent3, &tempStudent2); // swap 2 from 3 before return
    
    printf("\n *s2_fn() end== \n\n");
    
    return ptrStud; // &tempStudent; /* dangerous practice as it returns local address to main */
}
