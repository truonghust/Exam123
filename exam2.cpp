#include<iostream>
using namespace std;
#include<vector>

class Document{
protected :
    int id;
    string p_company;
    int total;
public:
    Document(int id,string p_company,int total){
        this->id =id;
        this->p_company =p_company;
        this->total=total;
    }
    int get_Id(){
       return id;
    }
    virtual void show_info()=0;
    virtual ~Document(){};
};
class Book:public Document{
    string author;
    int nop;
public:
    Book(int id,string p_company,int total,string author,int nop):Document{id,p_company,total}{
        this->author=author;
        this->nop=nop;
    }
    void show_info(){
        cout<<id<<"  "<<p_company<<"  "<<total<<"  "<<author<<"  "<<nop<<endl;
    }
    ~Book(){};
};
class Magazine:public Document{
    int nof_publish;
    int m_publish;
public:
    Magazine(int id,string p_company,int total,int nof_publish,int m_publish):Document{id,p_company,total}{
        this->nof_publish=nof_publish;
        this->m_publish=m_publish;
    }
    void show_info(){
        cout<<id<<"  "<<p_company<<"  "<<total<<"  "<<nof_publish<<"  "<<m_publish<<endl;
    }
    ~Magazine(){};
};
class News:public Document{
    int day_publish;
public:
    News(int id,string p_company,int total,int day_publish):Document{id,p_company,total}{
        this->day_publish=day_publish;
    }
    void show_info(){
        cout<<id<<"  "<<p_company<<"  "<<total<<"  "<<day_publish<<endl;
    }
    ~News(){};
};
class Node{
public:
    Document* Doc;
    Node*pnext;
    Node(){
        pnext=NULL;
    }
};
class List_Document{
    Node*pHead;
    Node*pTail;
    vector<int> vec;
    void check_id(vector<int> vec,int id){
        for(unsigned int i=0; i<vec.size();i++){
            if(vec[i]==id){
                throw 1;
            }
        }
    }
public:
    List_Document(){
        pHead=pTail=NULL;
    }
    void Insert_Book(int id,string p_company,int total,string author,int nop){
        try {
            check_id(vec,id);
            Node*p =new Node;
            p->Doc=new Book(id,p_company,total,author,nop);
            if(this->pHead==NULL){
                this->pHead=this->pTail=p;
            }
            else{
                this->pTail->pnext = p;
                this->pTail=p;
            }
            vec.emplace_back(id);
        }
        catch (int) {
            cout<<"Please check id of book!"<<endl;
        }
    }
    void Insert_Magazine(int id,string p_company,int total,int nof_publish,int m_publish){

        try{
            check_id(vec,id);
        Node*p =new Node;
        p->Doc=new Magazine(id,p_company,total,nof_publish,m_publish);
        if(this->pHead==NULL){
            this->pHead=this->pTail=p;
        }
        else{
            this->pTail->pnext = p;
            this->pTail=p;
        }
        vec.emplace_back(id);
    }
        catch(int){
            cout<<"Please check id of magazine!"<<endl;
        }
    }
    void Insert_News(int id,string p_company,int total,int day_publish){
        try{
            check_id(vec,id);
        Node*p =new Node;
        p->Doc=new News(id,p_company,total,day_publish);
        if(this->pHead==NULL){
            this->pHead=this->pTail=p;
        }
        else{
            this->pTail->pnext = p;
            this->pTail=p;
        }
        vec.emplace_back(id);
    }
        catch(int){
            cout<<"Please check id of news!"<<endl;
        }
}
    void Find_Document(int id){
        int count=0;
        for(Node*k = this->pHead;k!=NULL;k=k->pnext){
            if(k->Doc->get_Id()==id){
                cout<<"It's:  ";
                k->Doc->show_info();
                count++;
        }
    }
        if(count==0){
            cout<<"Not Found Document with its id"<<endl;
        }
    }
    void Delete_Document(int id){
        try {
            int sum=0;
           vector<int>::iterator it=vec.begin();
           for(it;it!=vec.end();it++){
               if(*it==id){
                   sum++;
                   vec.erase(it);
                   break;
               }
           }
           if(sum==0){
               throw 1;
           }
       if(this->pHead->Doc->get_Id()==id){
            Node*p= this->pHead;
            this->pHead= this->pHead->pnext;
            delete p;
            p=NULL;
        }
        else{
            Node *g;
        for(Node*k = this->pHead;k!=NULL;k=k->pnext){
            if(k->Doc->get_Id()==id){
            sum++;
            g->pnext=k->pnext;
            }
            g=k;
            if(sum==2){
                break;
            }
        }
        if(sum==2){
        delete g;
        g=NULL;
        }
  }
        }
        catch(int){
            cout<<" List has not document with id that you passed to function:"<<endl;
        }
    }

    void show_List(){
        for(Node*k = this->pHead;k!=NULL;k=k->pnext){
            k->Doc->show_info();
        }
    }
    ~List_Document(){
        Node*k;
        while(this->pHead!=NULL){
            k=this->pHead;
            Document* leak =k->Doc;
            this->pHead=this->pHead->pnext;
            delete leak;
            leak=NULL;
            delete k;
            k=NULL;

        }
    }
};

int main(){
    List_Document l;
    l.Insert_Book(15,"Kim Dong",125,"To Hoai",500);
    l.Insert_Book(15,"Giao Duc",125,"To Hoai",500);
    l.Insert_Magazine(25,"Vui Khoe",125,26,9);
    l.Insert_News(50,"24h",125,26);
    l.Insert_News(50,"24h",125,26);
    l.Find_Document(5);
    l.show_List();
    l.Delete_Document(25);
    l.show_List();
    return 0;
}
