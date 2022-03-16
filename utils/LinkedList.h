#pragma once

template<class T>
struct DNode {
    T data;
    DNode *next = nullptr, *prev = nullptr;
};

template<class T>
class LinkedList {
private:
    DNode<T> *head, *tail;
    int size;
public:
    LinkedList();
    ~LinkedList();
    int getSize();
    void printList(void (*print)(const T &item));
    void addHead(const T &item);
    void addTail(const T &item);
    bool deleteHead();
    bool deleteTail();
    DNode<T>* findNode(T &toFind, bool (*checkEqual)(const T &a, const T &b));
    int findIndex(const T &toFind, bool (*checkEqual)(const T &a, const T &b));
    bool getNodeAtIndex(int index, T &res);
    bool deleteAtX(const T &x, bool (*checkEqual)(const T &a, const T &b));
    bool deleteAtIndex(int index);
    bool updateAtX(const T &x, const T &payload, bool (*checkEqual)(const T &a, const T &b));
    bool updateAtIndex(int index, const T &payload);
};

#include "LinkedList.tpp"
