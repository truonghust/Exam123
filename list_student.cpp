#include "list_student.h"
#include<iostream>
using namespace std;

list_Student:: list_Student(){
    this->pHead=this->pTail=NULL;
}

int list_Student:: Insert(Student s){
        if(this->pHead==NULL){
        Node*p =new Node;
        p->st = s;
        this->pHead=this->pTail=p;
        return 1;
        }
        else{
            Node*p =new Node;
            p->st = s;
            this->pTail->pnext=p;
            this->pTail=p;
            return 1;
        }
    }
int list_Student:: nof_20(){
        int sum=0;
        for(Node*k=this->pHead;k!=NULL;k=k->pnext){
            if(k->st.get_age()==20){
            sum++;
            }
        }
        return sum;
    }
int list_Student:: nof_23olds_DN(){
        int sum=0;
        for(Node*k=this->pHead;k!=NULL;k=k->pnext){
            if((k->st.get_age()==23)&&k->st.get_address()=="Da Nang"){
            sum++;
            }
        }
        return sum;
    }
list_Student::~list_Student(){
        Node*k;
        while(this->pHead!=NULL){
            k=this->pHead;
            this->pHead= this->pHead->pnext;
            delete k;
            k=NULL;
        }
    }
