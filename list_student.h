#ifndef LIST_STUDENT_H
#define LIST_STUDENT_H
#include<iostream>
#include<student.h>
#include<node.h>

class list_Student{
public:
    Node*pHead;
    Node*pTail;
    list_Student();
    int Insert(Student s);

    int nof_23olds_DN();

    int nof_20();

    ~list_Student();
};

#endif // LIST_STUDENT_H
