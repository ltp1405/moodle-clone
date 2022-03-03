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
};

template<typename T>
void printList(LinkedList<T> &list);

template<typename T>
void addHead(LinkedList<T> &list, const T &item);

template<typename T>
void addTail(LinkedList<T> &list, const T &item);

template<typename T>
bool deleteHead(LinkedList<T> &list);

template<typename T>
bool deleteTail(LinkedList<T> &list);