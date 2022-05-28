//
// Created by baraa on 28/05/2022.
//

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H
#include <iostream>

template<class T>
struct node
{
    T data;
    node *next;
};

template<class T>
class Queue{
private:
    node<T> *head,*tail;
public:

    Queue(){
        head=NULL;
        tail=NULL;
    }
    ~Queue(){
        node<T> *tmp =head;
        node<T> *tmp2;
        while(tmp!=NULL){
            tmp2=tmp->next;
            delete tmp;
            tmp=tmp2;
            std::cout<<"destructor"<<std::endl;
        }
        head=NULL;
    }
    void pushBack(T member);
    void print_linked();


};

template<class T>
void Queue<T>::print_linked(){
    node<T> *t=head;
    while(t!=NULL){
        std::cout<<t->data<<std::endl;
        t=t->next;
    }

}
template<class T>
void Queue<T>::pushBack(T member) {
    {
        node<T> *tmp = new node<T>;
        tmp->data = member;
        tmp->next = NULL;

        if (head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tail->next;   // tail = null.
        }
    }
}
#endif //HW3_QUEUE_H
