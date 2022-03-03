#include "LinkedList.h"

using namespace std;

template<typename T>
void printList(LinkedList<T> &list) {
    for (DNode<T> *current = list.head; 
        current != nullptr; 
        current = current->next
    ) {
        cout << current->val << " ";
    }
    cout << endl;
    return;
}

template<typename T>
void addHead(LinkedList<T> &list, const T &item) {
    if (list.head == nullptr) {
        list.head = new DNode;
        list.tail = list.head;
    } else {
        list.head->prev = new DNode;
        list.head->prev->next = list.head;
        list.head = list.head->prev;
    }
    list.head->data = item;
}

template<typename T>
void addTail(LinkedList<T> &list, const T &item) {
    if (list.head == nullptr) {
        list.head = new DNode;
        list.tail = list.head;
    } else {
        list.tail->next = new DNode;
        list.tail->next->prev = list.tail;
        list.tail = list.tail->next;
    }
    list.tail->data = item;
}