#include "student.h"
#include<iostream>
using namespace std;
Student::Student(){}
Student::Student(string name,unsigned int age,string address,int grade){
    this->name=name;
    this->age=age;
    this->address=address;
    this->grade=grade;
}
string Student:: get_name(){
    return name;
}
unsigned int Student:: get_age(){
    return age;

}
string Student:: get_address(){
    return address;
}
int Student:: get_grade(){
    return grade;
}
void Student:: set_name(string name){
    this->name=name;
}
void Student:: set_age(unsigned age){
    this->age=age;
}
void Student:: set_address(string address){
    this->address=address;
}
void Student:: set_grade(int grade){
    this->grade=grade;
}
Student::~Student(){}




