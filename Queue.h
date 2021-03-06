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
     * Iterator class for Queue
    */
    class Iterator;

    /**
     * ConstIterator class for Queue
    */
    class ConstIterator;

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

    class EmptyQueue : public std::exception{};

private:
    struct Node;
    Node* m_front = NULL;
    Node* m_back = NULL;
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
Queue<T> filter(Queue<T>& queue, Condition condition);


/**
     * Changes every member in a given queue according to a given condition
     *
     *
     * @param queue - the queue whose members will be changed.
     * @param condition - condition according to which members will be changed.
     * @return
     *      void
    */
template<class T,class Condition>
void transform(Queue<T>& queue, Condition condition);

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
    class InvalidOperation : public std::exception{};

    T& operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator&) const;

private:
    Node* m_node;
    explicit Iterator(Node* node) : m_node(node) {}
    friend class Queue<T>;
    friend class ConstIterator;
};

template<class T>
T& Queue<T>::Iterator::operator*() const
{
    return m_node->m_data;
}

template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if(m_node == NULL)
    {
        throw InvalidOperation();
    }
    m_node = m_node->m_next;
    return *this;
}

template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& iterator) const
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
    Iterator result(NULL);
    return result;
}

/** --------------------------------------------------------------------------------------------------
 * Implementing ConstIterator class:
 * we provide three operator as requested (*, !=, ++)
----------------------------------------------------------------------------------------------------*/

template<class T>
class Queue<T>::ConstIterator
{
public:
    class InvalidOperation : public std::exception{};

    const T& operator*() const;
    ConstIterator& operator++();
    bool operator!=(const ConstIterator&);
    bool operator!=(const Iterator&);
    ConstIterator& operator=(const Iterator&);
    ConstIterator& operator=(const ConstIterator&);
    ConstIterator(const Iterator& iterator) : m_node(iterator.m_node) {}

private:
    const Node* m_node;
    explicit ConstIterator(const Node* node) : m_node(node) {}
};

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator=(const ConstIterator& iterator)
{
    m_node = iterator.m_node;
    return *this;
}

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator=(const Iterator& iterator)
{
    m_node = iterator.m_node;
    return *this;
}


template<class T>
const T& Queue<T>::ConstIterator::operator*() const
{
    return m_node->m_data;
}

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
    m_node = m_node->m_next;
    return *this;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(const Iterator& iterator)
{
    return m_node != iterator.m_node;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& iterator)
{
    return m_node != iterator.m_node;
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
        try
        {
            nodeToChange = new Node;
        }
        catch (std::bad_alloc &e)
        {
            //std::cerr << "bad_alloc caught: " << ba.what();
        }

        nodeToChange->m_data = nodeToCopy->m_data;
        nodeToCopy = nodeToCopy->m_next;
        m_front = nodeToChange;

        while (nodeToCopy != NULL)
        {

            try
            {
                nodeToChange->m_next = new Node;
                nodeToChange = nodeToChange->m_next;
                nodeToChange->m_data = nodeToCopy->m_data;
                nodeToCopy = nodeToCopy->m_next;
            }
            catch (std::bad_alloc &e)
            {

            }
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
        try
        {
            nodeToChange = new Node;
        }
        catch (std::bad_alloc &e)
        {
            //std::cerr << "bad_alloc caught: " << ba.what();
        }

        nodeToChange->m_data = nodeToCopy->m_data;
        nodeToCopy = nodeToCopy->m_next;
        m_front = nodeToChange;

        while (nodeToCopy != NULL)
        {

            try
            {
                nodeToChange->m_next = new Node;
                nodeToChange = nodeToChange->m_next;
                nodeToChange->m_data = nodeToCopy->m_data;
                nodeToCopy = nodeToCopy->m_next;
            }
            catch (std::bad_alloc &e)
            {

            }
        }
        m_back = nodeToChange;
        m_back->m_next = NULL;
    }
}

template<class T>
void Queue<T>::pushBack(T member)
{
    {
        try{
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
        catch (std::bad_alloc &e)
        {
            //std::cerr << "bad_alloc caught: " << e.what();
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



template<class T,class Condition>
void transform(Queue<T>& queue, Condition condition)
{

    for(typename Queue<T>::Iterator tempNode=queue.begin(); tempNode!=queue.end(); ++tempNode)
    {
        condition(*tempNode);
    }
}


template<class T, class Condition>
Queue<T> filter(Queue<T>& queue, Condition condition)
{
    Queue<T> result;
    Queue<T> temp_queue = queue;
    while (temp_queue.size() > 0)
    {
        if (condition(temp_queue.front()))
        {
            result.pushBack(temp_queue.front());
        }
        temp_queue.popFront();
    }
    return result;
}

#endif //HW3_QUEUE_H
