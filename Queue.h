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
    Queue() = default;

    /**
     * Copy c'tor of Queue class
     *
     * @param //ToDo: comment
     */
    Queue(const Queue& queue);

    /**
     * D'tor of Queue class
     *
     * @return
     *      void
    */
    ~Queue();

    /**
     * Assignment operator of Queue class
     *
     * @return
     *      //ToDo: comment
    */
    Queue<T>& operator=(const Queue<T>& queue);

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
     * //ToDo: comment
     *
     * @return
     *
    */
    template<class Condition>
    friend void transform(Queue queue, Condition condition);

    // ToDo: delete
    void print_linked();

private:
    Node<T>* m_front = NULL;
    Node<T>* m_back = NULL;
};

template<class T, class Condition>
Queue<T>& filter(const Queue<T>& queue, Condition condition);


template<class T>
Queue<T>::Queue(const Queue<T>& queue)
{
    Node<T>* nodeToCopy = queue.m_front;
    Node<T>* nodeToChange;

    if (nodeToCopy != NULL)
    {
        nodeToChange = new Node<T>;
        nodeToChange->m_data = nodeToCopy->m_data;
        nodeToCopy = nodeToCopy->m_next;
        m_front = nodeToChange;

        while (nodeToCopy != NULL)
        {
            nodeToChange->m_next = new Node<T>;
            nodeToChange = nodeToChange->m_next;
            nodeToChange->m_data = nodeToCopy->m_data;
            nodeToCopy = nodeToCopy->m_next;
        }
        m_back = nodeToChange;
        m_back->m_next = NULL;
    }
}


template<class T>
Queue<T>::~Queue()
{
    Node<T>* tempNode = m_front;
    while(tempNode != NULL)
    {
        Node<T>* toDelete = tempNode;
        tempNode = tempNode->m_next;
        delete toDelete;
    }
}


template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T> &queue)
{
    if (this == &queue)
    {
        return *this;
    }
    Node<T>* tempFront1 = m_front;
    while (tempFront1 != NULL)
    {
        Node<T>* toDelete = tempFront1;
        tempFront1 = tempFront1->m_next;
        delete toDelete;
    }
    //ToDo: copy linked list to *this
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
void transform(Queue<T> queue, Condition condition)
{
    Node<T>* tempNode = queue.m_front;
    while (tempNode != NULL)
    {
        tempNode->m_data=condition(tempNode->m_data);
        tempNode=tempNode->m_next;
    }

}


template<class T, class Condition>
Queue<T>& filter(const Queue<T>& queue, Condition condition)
{
    Queue<T> result;
    Queue<T> temp_queue = queue;
    while (temp_queue.size() > 0)
    {
        if (condition(temp_queue.front()))
        {
            result.pushBack(queue.front());
        }
        temp_queue.popFront();
    }
    return result;
}


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
#endif //HW3_QUEUE_H
