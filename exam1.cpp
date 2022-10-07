#include<iostream>
using namespace std;
class Cadres{
protected:
    string name;
    int age;
    string sex;
    string address;
public:
    Cadres(string name, int age, string sex, string address){
        this->name =name;
        this->age =age;
        this->sex=sex;
        this->address=address;
    }
    virtual void show_info()=0;
    string getName(){
        return this->name;
    }
    virtual ~Cadres(){};
};
class Worker:public Cadres{
    int degree;
public:
     Worker(string name,int age,string sex, string address, int degree):
     Cadres{name,age,sex,address}{
        if((0<degree) && (degree<=10)){
            this->degree =degree;
        }
        else{
            this->degree = 5;
        }
    }
     void show_info(){
         cout<<name<<"  " <<age<< "  "<<sex<<"  "<<address<<"  "<<degree<<endl;
     }
     ~Worker(){};
};
class Engineer:public Cadres{
    string specialized;
public:
     Engineer(string name,int age,string sex, string address, string specialized):
     Cadres{name,age,sex,address}{
            this->specialized = specialized;
        }
     void show_info(){
         cout<<name<<"  " <<age<< "  "<<sex<<"  "<<address<<"  "<<specialized<<endl;
     }
     ~ Engineer(){};
};
class Employee:public Cadres{
    string work;
public:
     Employee(string name,int age,string sex, string address, string work):
     Cadres{name,age,sex,address}{
            this->work = work;
        }
     void show_info(){
         cout<<name<<"  " <<age<< "  "<<sex<<"  "<<address<<"  "<<work<<endl;
     }
     ~Employee(){};
};
class Node{
public:
    Cadres*cad;
    Node*pnext;
public:
    Node(){
        pnext = NULL;
    }
};

class List_Cadres{
private:
    Node*pHead;
    Node*pTail;
public:
    List_Cadres(){
        pHead =pTail=NULL;
    }
    void Insert_worker(string name,int age,string sex, string address, int degree){
        Node* p =new Node;
        p->cad = new Worker( name, age, sex, address, degree);
        if(this->pHead==NULL){
            this->pHead=this->pTail=p;
        }
        else{
            this->pTail->pnext = p;
            this->pTail=p;
        }
  }
    void Insert_engineer(string name,int age,string sex, string address, string specialized){
        Node* p =new Node;
        p->cad = new Engineer( name, age, sex, address, specialized);
        if(this->pHead==NULL){
            this->pHead=this->pTail=p;
        }
        else{
            this->pTail->pnext = p;
            this->pTail=p;
        }
  }
    void Insert_employee(string name,int age,string sex, string address, string work){
        Node* p =new Node;
        p->cad = new Employee( name, age, sex, address, work);
        if(this->pHead==NULL){
            this->pHead=this->pTail=p;
        }
        else{
            this->pTail->pnext = p;
            this->pTail=p;
        }
  }
    void Search(string name){
        int sum=0;
        for(Node*k= pHead;k!=NULL;k=k->pnext){
            if(k->cad->getName()==name){
                cout<<"Found:  ";
                k->cad->show_info();
                sum++;
        }
    }
        if(sum==0){
            cout<<"Not Found!"<<endl;
        }
    }
    void Show_Info(){
        for(Node*k= pHead;k!=NULL;k=k->pnext){
            k->cad->show_info();
        }
    }
    ~List_Cadres(){
        Node*k;
        while(this->pHead!=NULL){
            k=this->pHead;
            Cadres* leak =k->cad;
            this->pHead=this->pHead->pnext;
            delete leak;
            leak=NULL;
            delete k;
            k=NULL;
        }
    }
};



int main(){
    List_Cadres l;
    l.Insert_worker("ABC",15,"BOY","254 Minh Khai",5);
    l.Insert_worker("ABCD",15,"BOY","254 Minh Khai",8);
    l.Insert_employee("ABCDE",15,"BOY","254 Minh Khai","Programer");
    l.Insert_engineer("ABCDEF",15,"BOY","254 Minh Khai","Mechatronic");
    l.Search("ABCDD");

    l.Show_Info();
    return 0;
}
