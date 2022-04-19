#pragma once
#include <functional>

template<class T>
struct DNode {
    T data;
    DNode *next, *prev;

    DNode();
    DNode(T data);
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
    DNode<T>* getHead();
    DNode<T>* getTail();
    void printList(std::function<void(T&)> print);
    void addHead(T item);
    void addTail(T item);
    bool deleteHead();
    bool deleteTail();
    DNode<T>* findNode(T &toFind, std::function<bool(T&, T&)>);
    int findIndex(const T &toFind, std::function<bool(T&, T&)>);
    DNode<T>* getNodeAtIndex(int index);
    bool deleteAtX(const T &x, std::function<bool(T&, T&)>);
    bool deleteAtIndex(int index);
    bool updateAtX(const T &x, const T &payload, std::function<bool(T &a, T &b)>);
    bool updateAtIndex(int index, const T &payload);
    DNode<T>* operator[](int index);
};

#include "LinkedList.tpp"
