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

    /**
     * C'tor of Queue class
     *
     * @return
     *      void
    */
    Queue()
    {
        m_front = NULL;
        m_back = NULL;
    }

    /**
     * D'tor of Queue class
     *
     * @return
     *      void
    */
    ~Queue()
    {
        Node<T>* tempNode = m_front;
        while(tempNode != NULL)
        {
            Node<T>* toDelete = tempNode;
            tempNode = tempNode->m_next;
            delete toDelete;
        }
    }

    /**
     * Adds a new member to the back of a given queue
     *
     * @return
     *      void
    */
    void pushBack(T member);

    /**
     * Returns a reference to the first member of a given queue
     *
     * @return
     *      reference to the first member of tha given queue
    */
    T& front();

    /**
     * Deletes the first member of a given queue
     *
     * @return
     *      void
    */
    void popFront();

    /**
     * Returns the size of a given queue
     *
     * @return
     *      the size of a given queue
    */
    int size() const;

    /**
     * Returns the size of a given queue
     *
     * @return
     *      the size of a given queue
    */
    template<class Condition>
    friend Queue& filter(Queue<T> queue, Condition condition);


    // ToDo: delete
    void print_linked();

private:
    Node<T>* m_front;
    Node<T>* m_back;
};


// ToDo: delete
template<class T>
void Queue<T>::print_linked()
{
    Node<T> *t=m_front;
    while(t!=NULL)
    {
        std::cout << t->m_data << std::endl;
        t=t->m_next;
    }
}


template<class T>
void Queue<T>::pushBack(T member)
{
    {
        Node<T>* temp = new Node<T>;
        temp->m_data = member;
        temp->m_next = NULL;

        if (m_front == NULL)
        {
            m_front = temp;
            m_back = temp;
        }
        else
        {
            m_back->m_next = temp;
            m_back = m_back->m_next;
        }
    }
}


template<class T>
T& Queue<T>::front()
{
    return m_front->m_data;
}


template<class T>
void Queue<T>::popFront()
{
    Node<T>* toDelete = m_front;
    m_front = m_front->m_next;
    delete toDelete;
}


template<class T>
int Queue<T>::size() const
{
    int result = 0;
    Node<T>* tempNode = m_front;
    while (tempNode != NULL)
    {
        ++result;
        tempNode = tempNode->m_next;
    }
    return result;
}


template<class T, class Condition>
Queue<T>& filter(Queue<T> queue, Condition condition)
{
    Queue<T> temp;
    return temp;
}
#endif //HW3_QUEUE_H
