#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;

class Student{
protected:
    string name;
    unsigned int age;
    string address;
    int grade;
public:
    Student();

    Student(string name,unsigned int age,string address,int grade);

    string get_name();

    unsigned int get_age();

    string get_address();

    int get_grade();

    void set_name(string name);

    void set_age(unsigned age);

    void set_address(string address);

    void set_grade(int grade);

    ~Student();
};
#endif // STUDENT_H
