#include "LinkedList.h"
#include <iostream>

template<class T> 
DNode<T>::DNode() {
    this->next = nullptr, this->prev = nullptr;
}

template<class T> 
DNode<T>::DNode(T data) {
    this->data = data;
    this->next = nullptr, this->prev = nullptr;
}

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr, tail = nullptr;
    size = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
    for (DNode<T>* current = head; head != nullptr; current = head) {
        head = current->next;
		delete current;
	}
}

template<class T>
int LinkedList<T>::getSize() {
    return size;
}

template<class T>
void LinkedList<T>::printList(std::function<void(T&)> print) {
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
        head = new DNode<T>(item);
        tail = head;
    } else {
        head->prev = new DNode<T>(item);
        head->prev->next = head;
        head = head->prev;
    }
    size++;
}

template<class T>
void LinkedList<T>::addTail(const T &item) {
    if (!head) {
        head = new DNode<T>(item);
        tail = head;
    } else {
        tail->next = new DNode<T>(item);
        tail->next->prev = tail;
        tail = tail->next;
    }
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
DNode<T>* LinkedList<T>::findNode(T &toFind, std::function<bool(T &a, T &b)> checkEqual) {
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
int LinkedList<T>::findIndex(const T &toFind, std::function<bool(T&, T&)>) {
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
DNode<T>* LinkedList<T>::getNodeAtIndex(int index) {
    int cnt = 0;
    for (DNode<T> *current = head; 
        current != nullptr; 
        current = current->next, cnt++
    ) {
        if (cnt == index)
            return current;
    }
    return nullptr;
}

template<class T>
bool LinkedList<T>::deleteAtX(const T &x, std::function<bool(T&, T&)> checkEqual) {
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
bool LinkedList<T>::updateAtX(const T &x, const T &payload, std::function<bool(T &a, T &b)>) {
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

template<class T>
DNode<T>* LinkedList<T>::operator[](int index) {
    int cnt = 0;
    for (DNode<T> *current = head; 
        current != nullptr; 
        current = current->next, cnt++
    ) {
        if (cnt == index)
            return current;
    }
    return nullptr;
}