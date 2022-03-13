#include "./LinkedList.h"

using namespace std;

template<class T>
int LinkedList<T>::size() {
    return head;
}

template<class T>
void LinkedList<T>::printList() {
    for (DNode<T> *current = list.head; 
        current != nullptr; 
        current = current->next
    ) {
        cout << current->val << " ";
    }
    cout << endl;
    return;
}

template<class T>
void LinkedList<T>::addHead(const T &item) {
    if (!list.head) {
        list.head = new DNode;
        list.tail = list.head;
    } else {
        list.head->prev = new DNode;
        list.head->prev->next = list.head;
        list.head = list.head->prev;
    }
    list.head->data = item;
    size++;
}

template<class T>
void LinkedList<T>::addTail(const T &item) {
    if (!list.head) {
        list.head = new DNode;
        list.tail = list.head;
    } else {
        list.tail->next = new DNode;
        list.tail->next->prev = list.tail;
        list.tail = list.tail->next;
    }
    list.tail->data = item;
    size++;
}

template<class T>
bool LinkedList<T>::deleteHead() {
    if (!list.head) return false;
    DNode *tmp = list.head;
    list.head = list.head->next;
    list.head->prev = nullptr;
    delete tmp;
    size--;
    return true;
}

template<class T>
bool LinkedList<T>::deleteTail() {
    if (!list.head) return false;
    DNode *tmp = list.tail;
    list.tail = list.tail->prev;
    list.tail->next = nullptr;
    delete tmp;
    size--;
    return true;
}

// Maybe not needed
template<class T>
DNode<T>* LinkedList<T>::findNode(T &toFind, bool (*compare)(const T &a, const T &b)) {
    for (DNode<T> *current = list.head; 
        current != nullptr; 
        current = current->next
    ) {
        if(compare(current->data, toFind))
            return current;
    }
    return nullptr;
}

template<class T>
int LinkedList<T>::findIndex(T &toFind, bool (*compare)(const T &a, const T &b)) {
    int cnt = 0;
    for (DNode<T> *current = list.head; 
        current != nullptr; 
        current = current->next, cnt++
    ) {
        if(compare(current->data, toFind))
            return cnt;
    }
    return -1;
}

template<class T>
bool LinkedList<T>::deleteAtX(T &x, bool (*compare)(const T &a, const T &b)) {
    for (DNode<T> *current = list.head; 
        current != nullptr; 
        current = current->next
    ) {
        if (compare(current->data, toFind)) {
            Node *tmp = current;
            curr = current->next;
            tmp->prev->next = current;
            current->prev = tmp->prev;
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
    for (DNode<T> *current = list.head; 
        current != nullptr; 
        current = current->next, cnt++
    ) {
        if (cnt == index) {
            Node *tmp = current;
            curr = current->next;
            tmp->prev->next = current;
            current->prev = tmp->prev;
            delete tmp;
            size--;
            return true;
        }
    }
    return false;
}