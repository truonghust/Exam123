#include"view.h"
#include<list_student.h>
#include<iomanip>
View::View(){
}
void View::Menu(){
    cout<<setw(50)<<left<<"1. Add new student'data"<<setw(50)<<left<<"2.Show list of student"<<endl;
    cout<<setw(50)<<left<<"3.List of 20-year-old students"<<setw(50)<<left<<"4.Numbers of 23y-DN students"<<endl;
    cout<<setw(50)<<left<<"5.Exit"<<endl;
}

void View::show_info(string name, unsigned int age,string address,int grade){
      cout<<name<<"  "<<age<<"  "<<address<<"  "<<grade<<endl;
}
Student View::Input_Student(){
    cin.ignore();
    string name;
    unsigned int age;
    string address;
    int grade;
    cout<<"Enter information:"<<endl<<"Name:";
    getline(cin,name);
    cout<<endl<<"Age:";
    cin>>age;
    cout<<endl<<"Address:";
    cin.ignore();
    getline(cin,address);
    cout<<endl<<"Grade:";
    cin>>grade;
    return Student(name,age,address,grade);
}
int View::Input(){
    int index;
    try{
    string x;
    cout<<"Scan input:";
    //cin.ignore()
    getline(cin,x);
    //cin>>x;
    while(x.size()>=2||(x[0]>'5')){
        cout<<"Scan input:";
        getline(cin,x);
        //cin>>x;
    }
    index = stoi(x);
    }
    catch(invalid_argument){
        cout<<"Please scanf again!"<<endl;
    }
    return index;
}


void View::show_list_student(list_Student &l){
    if(l.pHead==NULL){
        cout<<"List of student is empty!"<<endl;
    }
    else{
    cout<<"List of student:"<<endl;
    for(Node*k=l.pHead;k!=NULL;k=k->pnext){
        show_info(k->st.get_name(),k->st.get_age(),k->st.get_address(),k->st.get_grade());
    }
    }
}

void View::show_list_20olds(list_Student &l){
    if(l.nof_20()==0){
        cout<<"List of student-20olds is empty!"<<endl;
    }
    else{
    cout<<"List of 20-year-old students:"<<endl;
    for(Node*k=l.pHead;k!=NULL;k=k->pnext){
        if(k->st.get_age()==20){
        show_info(k->st.get_name(),k->st.get_age(),k->st.get_address(),k->st.get_grade());
        }
    }
    }
}
void View::nof_23olds_DaNang(list_Student &l)
{
    cout<<"Numbers of 23y-DaNang students:"<<l.nof_23olds_DN()<<endl;
}

void View::Insert_status(){
    cout<<"Added successfully!"<<endl;
}
