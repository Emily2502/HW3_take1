//
// Created by baraa on 28/05/2022.
//

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H
#include <iostream>

template<class T>
struct Node
{
    T m_data;
    Node* m_next;
};

template<class T>
class Queue{

public:

    Queue()
    {
        m_head=NULL;
        m_tail=NULL;
    }

    ~Queue()
    {
        Node<T>* tmp =m_head;
        Node<T>* tmp2;
        while(tmp != NULL)
        {
            tmp2 = tmp->m_next;
            delete tmp;
            tmp = tmp2;
        }
        m_head = NULL;
    }
    void pushBack(T member);
    T& front();
    void popFront();
    int size();

    // ToDo: delete
    void print_linked();

private:
    Node<T>* m_head;
    Node<T>* m_tail;
};


// ToDo: delete
template<class T>
void Queue<T>::print_linked(){
    Node<T> *t=m_head;
    while(t!=NULL){
        std::cout << t->m_data << std::endl;
        t=t->m_next;
    }
}


template<class T>
void Queue<T>::pushBack(T member)
{
    {
        Node<T>* tmp = new Node<T>;
        tmp->m_data = member;
        tmp->m_next = NULL;

        if (m_head == NULL)
        {
            m_head = tmp;
            m_tail = tmp;
        }
        else
        {
            m_tail->m_next = tmp;
            m_tail = m_tail->m_next;   // tail = null.
        }
    }
}

template<class T>
T& Queue<T>::front()
{
    return m_head->m_data;
}


template<class T>
void Queue<T>::popFront()
{
    Node<T>* toDelete = m_head;
    m_head = m_head->m_next;
    delete toDelete;
}

template<class T>
int Queue<T>::size()
{
    int result = 0;
    Node<T>* tempNode = m_head;
    while (tempNode != NULL)
    {
        ++result;
        tempNode = tempNode->m_next;
    }
    return result;
}
#endif //HW3_QUEUE_H
