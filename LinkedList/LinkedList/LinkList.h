#pragma once
template<typename T>
class LinkList
{
public:
    LinkList();
    LinkList(const LinkList<T>& value)=default;
    ~LinkList();
    void push_back(T data);
    void push_front(T data);
    void insert(T data, int index);
    void pop_front();
    void pop_back();
    void removeat(const int index);
    void clear();
    int GetSize() { return this->Size; };
    T& operator[](int index);
private:
    template<typename T1>
    class Node
    {
    public:
        T1 data;
        Node* pNext;
        Node* pPrevious;
        Node(T1 data = 0, Node* pNext = nullptr, Node* pPrevious = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrevious = pPrevious;
        }
    };
    int Size;
    Node<T>* head;
    Node<T>* tail;
};

template<typename T>
inline LinkList<T>::LinkList()
{
    head = new Node<T>();
    tail = new Node<T>();
    Size = 0;
}

template<typename T>
inline LinkList<T>::~LinkList()
{
    clear();
}

template<typename T>
void LinkList<T>::push_back(T data)
{
    if (Size == 0)
    {
        head = new Node<T>(data);
        tail = head;
    }
    else
    {
        Node<T>* temp = head;
        while (temp->pNext != nullptr)
        {
            temp = temp->pNext;
        }
        temp->pNext = new Node<T>(data);
        temp->pNext->pPrevious = temp;
        tail = temp->pNext;
        tail->pNext = nullptr;
    }
    Size++;
}

template<typename T>
void LinkList<T>::push_front(T data)
{
    Node<T>* temp = head;
    if (Size == 0)
    {
        tail = head;
    }
    temp->pPrevious = new Node<T>(data);
    temp = temp->pPrevious;
    if (head->pNext == nullptr)
    {
        temp->pNext = tail;
        tail->pNext = nullptr;
    }
    else
    {
        temp->pNext = head;
    }
    temp->pPrevious = nullptr;
    head = temp;
    Size++;
}

template<typename T>
void LinkList<T>::insert(T data, int index)
{
    if (index == Size - 1)
    {
        push_back(data);
    }
    else if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T>* temp = nullptr;
        int value = 0;
        if (index <= Size / 2)
        {
            temp = head;
            value = 0;
        }
        else
        {
            temp = tail;
            value = Size - 1;
        }
        while (value != index)
        {
            if (index <= Size / 2)
            {
                temp = temp->pNext;
                value++;
            }
            else
            {
                temp = temp->pPrevious;
                value--;
            }
        }
        Node<T>* newTemp = new Node<T>(data, temp->pPrevious->pNext, temp->pPrevious);
        temp->pPrevious->pNext = newTemp;
        temp->pPrevious = newTemp;
        Size++;
    }
}

template<typename T>
void LinkList<T>::pop_front()
{
    if (Size == 1)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        Size--;
    }
    else
    {
        Node<T>* temp = head->pNext;
        if (temp->pPrevious != nullptr)
        {
            temp->pPrevious = nullptr;
        }
        delete head;
        head = temp;
        Size--;
    }
}

template<typename T>
void LinkList<T>::pop_back()
{
    if (Size == 1)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
        Size--;
    }
    else
    {
        Node<T>* temp = tail->pPrevious;
        temp->pNext = nullptr;
        delete tail;
        tail = temp;
        Size--;
    }
}

template<typename T>
void LinkList<T>::removeat(const int index)
{
    if (index == Size - 1)
    {
        pop_back();
    }
    else if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* temp = nullptr;
        int value;
        if (index <= Size / 2)
        {
            temp = head;
            value = 0;
        }
        else
        {
            temp = tail;
            value = Size - 1;
        }
        while (value != index)
        {
            if (index <= Size / 2)
            {
                temp = temp->pNext;
                value++;
            }
            else
            {
                temp = temp->pPrevious;
                value--;
            }
        }
        temp->pPrevious->pNext = temp->pNext;
        temp->pNext->pPrevious = temp->pPrevious;
        delete temp;
        Size--;
    }
}

template<typename T>
void LinkList<T>::clear()
{
    while (Size != 0)
    {
        pop_front();
    }
}

template<typename T>
T& LinkList<T>::operator[](int index)
{
    Node<T>* temp = nullptr;
    int value = 0;
    if (index <= (Size / 2))
    {
        temp = head;
        value = 0;
    }
    else
    {
        temp = tail;
        value = Size - 1;
    }

    while (value != index)
    {
        if (index <= (Size / 2))
        {
            temp = temp->pNext;
            value++;
        }
        else
        {
            temp = temp->pPrevious;
            value--;
        }
    }
    return temp->data;
}




