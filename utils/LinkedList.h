#pragma once

template<typename T>
struct DNode {
    T data;
    DNode *next = nullptr, *prev = nullptr;
};

template<typename T>
struct LinkedList {
    DNode<T> *head = nullptr, *tail = nullptr;
    int size = 0;

    void printList(LinkedList<T> &list);
    void addHead(LinkedList<T> &list, const T &item);
    void addTail(LinkedList<T> &list, const T &item);
    bool deleteHead(LinkedList<T> &list);
    bool deleteTail(LinkedList<T> &list);
    bool findNode(LinkedList<T> &list, T &toFind, DNode<T> &result, bool (*compare)(const T &a, const T &b));
};
