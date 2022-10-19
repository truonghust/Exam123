#include "controller.h"
#define Insert_student 1
#define list 2
#define list_20olds 3
#define number_23_DN 4
#define Exit 5
Controller::Controller(){}

int Controller::MVC(){
   view.Menu();
   while(1){
   switch(view.Input()){
   case Insert_student:
   {
       l.Insert(view.Input_Student());
       view.Insert_status();
       break;
   }
   case list:
   {
       view.show_list_student(l);
       break;
   }
   case list_20olds:
   {
       view.show_list_20olds(l);
       break;
   }
   case number_23_DN:
   {
       view.nof_23olds_DaNang(l);
       break;
   }
   case Exit:
   {
      return 0;
   }
   //default:
}
   }
}

