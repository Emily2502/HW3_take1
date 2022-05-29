//
// Created by Baraa on 28/05/2022.
//

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H
#include <iostream>


template<class T>
class Queue{

public:

    /**
     * C'tor of Queue class
     *
     * @return
     *      A new instance of Queue.
    */
    Queue() = default;

    /**
     * Copy c'tor of Queue class
     *
     * @param Queue& - Reference to Queue to copy.
     * @return
     *      A new instance of Queue.
     */
    Queue(const Queue&);

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
     *      reference to queue.
    */
    Queue<T>& operator=(const Queue<T>&);

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
     * Changes every member in a given queue according to a given condition
     *
     *
     * @param queue - the queue whose members will be changed.
     * @param condition - condition according to which members will be changed.
     * @return
     *      void
    */
    template<class Condition>
    static void transform(Queue queue, Condition condition);


    /**
     * Iterator class for Queue
    */
    class Iterator;

    /**
     * Beginning iterator for Queue
     * @return
     *      new iterator that points to the start of a given queue
    */
    Iterator begin() const;

    /**
     * End iterator for Queue
     * @return
     *      new iterator that points to the end of a given queue
    */
    Iterator end() const;



    // ToDo: delete
    void print_linked();

private:
    struct Node;
    Node* m_front = NULL;
    Node* m_back = NULL;

    class EmptyQueue : public std::exception{};
};


/**
     * Creates a new queue, from an old one, whose members satisfy a given condition
     *
     *
     * @param queue - the queue which the new one will be created from.
     * @param condition - condition according to which members will be added to the new queue.
     * @return
     *      A new instance of Queue.
    */
template<class T, class Condition>
Queue<T>& filter(const Queue<T>& queue, Condition condition);


/** --------------------------------------------------------------------------------------------------
 * Implementing Node struct:
 * Queue is a linked list with pointers to the front and back and Node is the struct we use to
 * implement said linked list
----------------------------------------------------------------------------------------------------*/

template<class T>
struct Queue<T>::Node
{
    T m_data;
    Node* m_next;
};

/** --------------------------------------------------------------------------------------------------
 * Implementing Iterator class:
 * we provide three operator as requested (*, !=, ++)
----------------------------------------------------------------------------------------------------*/

template<class T>
class Queue<T>::Iterator
{
public:
    T& operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator&);

private:
    Node* m_node;
    explicit Iterator(Node* node) = default;
};

template<class T>
T& Queue<T>::Iterator::operator*() const
{
    return m_node->m_data;
}

template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    m_node = m_node->m_next;
    return *this;
}

template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& iterator)
{
    return m_node != iterator.m_node;
}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin() const
{
    Iterator result(m_front);
    return result;
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end() const
{
    Iterator result(m_back->m_next);
    return result;
}




/** --------------------------------------------------------------------------------------------------
 * Implementing Queue class:
 * at first we implement copy c'tor, d'tor and assignment operator.
 * secondly we implement functions requested.
----------------------------------------------------------------------------------------------------*/

template<class T>
Queue<T>::Queue(const Queue<T>& queue)
{
    Node* nodeToCopy = queue.m_front;
    Node* nodeToChange;

    if (nodeToCopy != NULL)
    {
        nodeToChange = new Node;
        nodeToChange->m_data = nodeToCopy->m_data;
        nodeToCopy = nodeToCopy->m_next;
        m_front = nodeToChange;

        while (nodeToCopy != NULL)
        {
            nodeToChange->m_next = new Node;
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
    Node* tempNode = m_front;
    while(tempNode != NULL)
    {
        Node* toDelete = tempNode;
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
    Node* tempNode = m_front;
    while (tempNode != NULL)
    {
        Node* toDelete = tempNode;
        tempNode = tempNode->m_next;
        delete toDelete;
    }

    Node* nodeToCopy = queue.m_front;
    Node* nodeToChange;

    if (nodeToCopy != NULL)
    {
        nodeToChange = new Node;
        nodeToChange->m_data = nodeToCopy->m_data;
        nodeToCopy = nodeToCopy->m_next;
        m_front = nodeToChange;

        while (nodeToCopy != NULL)
        {
            nodeToChange->m_next = new Node;
            nodeToChange = nodeToChange->m_next;
            nodeToChange->m_data = nodeToCopy->m_data;
            nodeToCopy = nodeToCopy->m_next;
        }
        m_back = nodeToChange;
        m_back->m_next = NULL;
    }
}

template<class T>
void Queue<T>::pushBack(T member)
{
    {
        Node* temp = new Node;
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
    if(m_front==NULL)
    {
        throw EmptyQueue();
    }
    return m_front->m_data;
}


template<class T>
void Queue<T>::popFront()
{
    Node* toDelete = m_front;
    if(m_front != NULL)
    {
        m_front = m_front->m_next;
    }
    delete toDelete;
}


template<class T>
int Queue<T>::size() const
{
    int result = 0;
    Node* tempNode = m_front;
    while (tempNode != NULL)
    {
        ++result;
        tempNode = tempNode->m_next;
    }
    return result;
}


template<class T>
template<class Condition>
void Queue<T>::transform(Queue<T> queue, Condition condition)
{
    Node* tempNode = queue.m_front;
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
    Node *t=m_front;
    while(t!=NULL)
    {
        std::cout << t->m_data << std::endl;
        t=t->m_next;
    }
}

#endif //HW3_QUEUE_H
