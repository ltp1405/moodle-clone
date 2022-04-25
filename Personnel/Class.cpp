#include "Class.h"
#include <string>

void importClassTXT(LinkedList<Class*>& c)
{
    std::ifstream fin;
    fin.open("data/Class.txt", std::ios::in);
    int n;
    fin >> n;
    if (!fin)
        return;
    fin.ignore(100, '\n');
    for (int i = 0; i < n; i++) {
        string read;
        std::getline(fin, read);
        // std::cout << read << std::endl;

        Class *temp = new Class;
        temp->classname=read;
        c.addTail(temp);
    }
    fin.close();
}

Class *findClass(LinkedList<Class*> &c, string find)
{
    for(DNode<Class*>* temp = c.getHead(); temp; temp=temp->next)
    {
        if(temp->data->classname == find) return temp->data;
    }
    return nullptr;
}
