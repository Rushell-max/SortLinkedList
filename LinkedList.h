#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "Node.h"

#include <iostream>

class LinkedList{
    private:

        int size;
        Node* head;

    public:

    //CONSTRUCTORES
        LinkedList();
        ~LinkedList();

    //SETTERS
        void setSize(int _size){
            size = _size;
        }
        void setHead(Node* _head){
            head = _head;
        }
        
    //GETTERS
        int getSize() const {
            return size;
        }
        Node* getHeat() const {
            return head;
        }

    //FUNCIONES COMPLEMENTARIAS
        void insertar(int _elem);
        void remove_pos(int _pos);
        void clear();
        Node* iterador(int _pos);
        Node* juntar(Node* _head, Node* _aux,  int pos);

    //SOBRECARGAR OPERADOR <<
        friend std:: ostream &operator<<(std::ostream &o, const LinkedList &_LinkedList);
};

LinkedList* createLinkedList(Node* _head){
    LinkedList* temp = new (class LinkedList);
    temp->setHead(_head);
    temp->setSize(0);

    return temp;
}

LinkedList::LinkedList(){
    head = NULL;
    size = 0;
}

LinkedList::~LinkedList() {
    delete head;
}

void LinkedList::insertar(int _elem){
    Node* _Node = new Node(_elem);
    int size_aux = size;
    if(head == NULL){
        head = _Node;
        size++;
    }else if(_elem <= head->getElem()){
        _Node->setNext(this->head);
        head = _Node;
        size++;
    }else{
        Node* aux = head;
        int contador=0;
        do{
            if(_elem <= aux->getElem()){
                _Node->setNext(aux);
                head = juntar(head, _Node, contador);
                size++;
            }else if(_elem >= aux->getElem()){
                if(aux->getNext() == NULL){
                    aux->setNext(_Node);
                    head = juntar(head, aux, contador);
                    size++;
                }
                aux = aux->getNext();
                contador++;
            }
        }while(size_aux+1 != size && aux != NULL);
        
    }
}

void LinkedList::remove_pos(int _pos){
    int size_aux = size;
    if(head == NULL){
        std::cout<<"\n LISTA VACIA! \n";
    }else if(_pos == 0){
        setHead(head->getNext());
        size--;
    }else{
        Node* aux = head;
        do{
            for(int i=0; i<=_pos; i++){
                aux = aux->getNext();
            }head = juntar(head, aux, _pos);
            size--;
        }while(size_aux-1 != size && aux != NULL);
    }
}

void LinkedList::clear(){
    int size_aux=size;
    for(int i=0; i<size_aux; i++){
        remove_pos(0);
    }
}

Node* LinkedList::iterador(int _pos){
    Node* aux = head;
    for(int i=0; i<_pos; i++){
        aux = aux->getNext();
    }return aux;
}

Node* LinkedList::juntar(Node* _head, Node* _aux,  int pos){
    Node* temp = _head;Node* temp1 = _head;
    LinkedList* LLtemp = createLinkedList(temp);
    if(_aux==NULL){
        for(int i=1; i<pos; i++){
            temp = temp->getNext();
        }temp->setNext(NULL);
    }else{
        for(int i=1; i<pos; i++){
            temp = temp->getNext();
        }
        if(_aux->getNext()==NULL){
            temp->setNext(_aux);
            temp1 = temp1->getNext();
            _aux = _aux->getNext();       
        }else{
            while(_aux->getNext()!=NULL){
                temp->setNext(_aux);
                temp1 = temp1->getNext();
                _aux = _aux->getNext();
            }
        }
    }
    temp = LLtemp->getHeat();
    return temp;
}

std::ostream &operator <<(std::ostream &o, const LinkedList &_LinkedList){
    if(_LinkedList.head!=NULL){
        Node* aux = _LinkedList.head;
        do{
            o <<" -> "<< aux->getElem();
            aux = aux->getNext();
        }while(aux != NULL);
    }else{
        o<<" LISTA VACIA! \n";
    }
    return o;
}

#endif