#include "LinkedList.h"
#include <iostream>

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr, tail = nullptr;
    size = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
    while(head) {
        head = head->next;
        delete head->prev;
    }
}

template<class T>
int LinkedList<T>::getSize() {
    return size;
}

template<class T>
void LinkedList<T>::printList(void (*print)(const T &item)) {
    for (DNode<T> *current = head; 
        current != nullptr; 
        current = current->next
    ) {
        print(current->data);
    }
    return;
}

template<class T>
void LinkedList<T>::addHead(const T &item) {
    if (!head) {
        head = new DNode<T>;
        tail = head;
    } else {
        head->prev = new DNode<T>;
        head->prev->next = head;
        head = head->prev;
    }
    head->data = item;
    size++;
}

template<class T>
void LinkedList<T>::addTail(const T &item) {
    if (!head) {
        head = new DNode<T>;
        tail = head;
    } else {
        tail->next = new DNode<T>;
        tail->next->prev = tail;
        tail = tail->next;
    }
    tail->data = item;
    size++;
}

template<class T>
bool LinkedList<T>::deleteHead() {
    if (!head) return false;
    DNode<T> *tmp = head;
    tail = tail == head ? nullptr : head;
    head = head->next;
    head->prev = nullptr;
    delete tmp;
    size--;
    return true;
}

template<class T>
bool LinkedList<T>::deleteTail() {
    if (!head) return false;
    DNode<T> *tmp = tail;
    head = head == tail ? nullptr : head;
    tail = tail->prev;
    tail->next = nullptr;
    delete tmp;
    size--;
    return true;
}

// Maybe not needed
template<class T>
DNode<T>* LinkedList<T>::findNode(T &toFind, bool (*checkEqual)(const T &a, const T &b)) {
    for (DNode<T> *current = head; 
        current != nullptr; 
        current = current->next
    ) {
        if(checkEqual(current->data, toFind))
            return current;
    }
    return nullptr;
}

template<class T>
int LinkedList<T>::findIndex(const T &toFind, bool (*checkEqual)(const T &a, const T &b)) {
    int cnt = 0;
    for (DNode<T> *current = head; 
        current != nullptr; 
        current = current->next, cnt++
    ) {
        if(checkEqual(current->data, toFind))
            return cnt;
    }
    return -1;
}

template<class T>
bool LinkedList<T>::getNodeAtIndex(int index, T &res) {
    int cnt = 0;
    for (DNode<T> *current = head; 
        current != nullptr; 
        current = current->next, cnt++
    ) {
        if (cnt == index) {
            res = current->data;
            return true;
        }
    }
    return false;
}

template<class T>
bool LinkedList<T>::deleteAtX(const T &x, bool (*checkEqual)(const T &a, const T &b)) {
    for (DNode<T> *current = head; 
        current != nullptr; 
        current = current->next
    ) {
        if (checkEqual(current->data, x)) {
            DNode<T> *tmp = current;
            if (head == current) {
                head = current->next;
            } else {
                tmp->prev->next = current->next;
            }
            if (tail == current) {
                tail = current->prev;
            } else {
                current->next->prev = tmp->prev;
            }
            delete tmp;
            size--;
            return true;
        }
    }
    return false;
}

template<class T>
bool LinkedList<T>::deleteAtIndex(int index) {
    int cnt = 0;
    for (DNode<T> *current = head; 
        current != nullptr; 
        current = current->next, cnt++
    ) {
        if (cnt == index) {
            DNode<T> *tmp = current;
            if (head == current) {
                head = current->next;
            } else {
                tmp->prev->next = current->next;
            }
            if (tail == current) {
                tail = current->prev;
            } else {
                current->next->prev = tmp->prev;
            }
            delete tmp;
            size--;
            return true;
        }
    }
    return false;
}

template<class T>
bool LinkedList<T>::updateAtX(const T &x, const T &payload, bool (*checkEqual)(const T &a, const T &b)) {
    for (DNode<T> *current = head; 
        current != nullptr; 
        current = current->next
    ) {
        if (checkEqual(current->data, x)) {
            current->data = payload;
            return true;
        }
    }
    return false;
}

template<class T>
bool LinkedList<T>::updateAtIndex(int index, const T &payload) {
    int cnt = 0;
    for (DNode<T> *current = head; 
        current != nullptr; 
        current = current->next, cnt++
    ) {
        if (cnt == index) {
            current->data = payload;
            return true;
        }
    }
    return false;
}