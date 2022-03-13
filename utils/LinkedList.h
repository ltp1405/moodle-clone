#pragma once

template<class T>
struct DNode {
    T data;
    DNode *next = nullptr, *prev = nullptr;
};

template<class T>
class LinkedList {
private:
    DNode<T> *head = nullptr, *tail = nullptr;
    int size = 0;
public:
    int size();
    void printList();
    void addHead(const T &item);
    void addTail(const T &item);
    bool deleteHead();
    bool deleteTail();
    DNode<T>* findNode(T &toFind, bool (*compare)(const T &a, const T &b));
    int findIndex(T &toFind, bool (*compare)(const T &a, const T &b));
    bool deleteAtX(T &x, bool (*compare)(const T &a, const T &b));
    bool deleteAtIndex(int index);
};
