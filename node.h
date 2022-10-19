#ifndef NODE_H
#define NODE_H
#include<student.h>
class Node{
public:
    Student st;
    Node*pnext;
    Node();
    ~Node();
};
#endif // NODE_H
