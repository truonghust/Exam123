#include<iostream>
#include<vector>
using namespace std;

class Student{
    string name;
    int id;
    string address;
    int priority;
    char block;
public:
    Student(){};
    Student(string name,int id,string address,int priority,char block){
        this->name=name;
        this->id=id;
        this->address=address;
        this->priority=priority;
        this->block=block;
        }
    int get_Id(){
        return id;
    }
    void show_info(){
        cout<<name<<"  "<<id<<"  "<<address<<"  "<<priority<<"  "<<block<<endl;
    }
    ~Student(){};
};
class Node{
public:
    Student st;
    Node*pnext;
public:
    Node(){
        pnext=NULL;
    }
};
class Admissions{
    Node*pHead;
    Node*pTail;
    vector<int> vec;
    void check_id(int id){
        for(unsigned int i=0;i<vec.size();i++){
            if(vec[i]==id){
                throw 1;
            }
        }
    }
public:
    Admissions(){
        pHead=pTail=NULL;
    }
    void Insert(string name,int id,string address,int priority,char block){
        try {
        check_id(id);
        vec.emplace_back(id);
        Node*p =new Node;
        p->st = Student(name,id,address,priority,block);
        if(this->pHead==NULL){
            this->pHead=this->pTail=p;
        }
        else{
            this->pTail->pnext=p;
            this->pTail=p;
        }
    }
        catch(int){
            cout<<"Please check argument id !"<<endl;
        }
    }

    void show_info(){
        for(Node*k=this->pHead;k!=NULL;k=k->pnext){
            k->st.show_info();
        }
    }
    void Find_Student(int id){
        Node*k =this->pHead;
        while((k->st.get_Id())!=id && k!=NULL){
          k=k->pnext;
        }
        if(k!=NULL){
            cout<<"Found a student with id is:"<<id<<endl;
            k->st.show_info();
        }
        else{
            cout<<"Not found any student with id that you passed"<<endl;
        }
    }
    ~Admissions(){
        Node*k;
      while(this->pHead!=NULL){
          k=this->pHead;
          this->pHead=this->pHead->pnext;
          delete k;
      }
    }

};


int main(){
    Admissions l;
    l.Insert("Vu Thanh Dat",2008,"Khanh Mau",2, 'A');
    l.Insert("Le Quang Minh",2006,"Khanh Mau",2, 'B');
    l.Insert("Thanh Thao",2007,"Khanh Mau",2, 'C');
    l.Insert("PV Duong",2008,"Khanh Mau",2, 'A');
    l.show_info();
    //l.Find_Student(2008);
    //l.show_info();
    l.Find_Student(2008);
    return 0;
}
