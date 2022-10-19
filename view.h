#ifndef VIEW_H
#define VIEW_H

#include<iostream>
using namespace std;
#include<student.h>
#include<list_student.h>
class View
{
public:
   View();
   void Menu();
   void show_info(string name, unsigned int age,string address,int grade);
   void show_list_student(list_Student &l);
   void show_list_20olds(list_Student &l);
   Student Input_Student();
   int Input();
   void Insert_status();
   void nof_23olds_DaNang(list_Student &l);
};

#endif // VIEW_H
