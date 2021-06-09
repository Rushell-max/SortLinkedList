#ifndef _NODE_H
#define _NODE_H

#include <iostream>

class Node{
    private:
    
        int elem;
        Node* next;

    public:

    //CONSTRUCTORES
        Node(int _elem);
        ~Node();

    //SETTERS
        void setElem(int _elem){
            elem = _elem;
        }
        void setNext(Node* _next){
            next = _next;
        }

    //GETTERS
        int getElem() const {
            return elem;
        }
        Node* getNext() const{
            return next;
        }

    //SOBRECARGAR OPERADOR <<
        friend std::ostream &operator<<(std::ostream &o, const Node &_Node);
};

Node::Node(int _elem){
    elem=_elem;
    next=NULL;
}

Node::~Node(){
}

std::ostream &operator <<(std::ostream &o, const Node &_Node){
    o << _Node.elem ;
    return o;
}

#endif