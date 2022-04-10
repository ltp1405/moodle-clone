#include "Class.h"

void importClassTXT(LinkedList<Class>& c)
{
    ifstream fin;
    fin.open("../data/Class.txt",ios::in);
    DNode<Class>* temp=NULL;
    string read;
    fin >> read;
    if(fin)
    {
        temp = new DNode<Class>;
        temp->data.classname=read;
        c.addTail(temp->data);
        delete temp;
    }
    while(!fin.eof())
    {
        fin >> read;
        temp = new DNode<Class>;
        temp->data.classname=read;
        c.addTail(temp->data);
        delete temp;
    }
    fin.close();
}

bool findClass(LinkedList<Class> c, string find)
{
    for(DNode<Class>* temp = c.getHead(); temp; temp=temp->next)
    {
        if(temp->data.classname == find) return true;
    }
    return false;
}