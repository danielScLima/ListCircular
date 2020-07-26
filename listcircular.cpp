#include "listcircular.h"

ListCircular::ListCircular()
{

}

ListCircular::~ListCircular()
{
    CircularLinkedNode* initialHead = start;
    if (initialHead != nullptr)
    {
        CircularLinkedNode* tmp = initialHead->next;
        delete initialHead;
        while (tmp != initialHead)
        {
            start = tmp->next;
            delete tmp;
            tmp = start;
        }
    }
}

void ListCircular::insertBeforeStart(const std::string& data)
{
    struct CircularLinkedNode* tmp = new CircularLinkedNode(data);

    if (start == nullptr)
    {
        start = tmp;
        start->next = start;
    }
    else if (start->next == start)
    {
        start->next = tmp;
        tmp->next = start;
    }
    else
    {
        CircularLinkedNode* current = start->next;
        while (current->next != start)
            current = current->next;

        current->next = tmp;
        tmp->next = start;
    }
}

void ListCircular::insertAfterStart(const std::string& data)
{
    struct CircularLinkedNode* tmp = new CircularLinkedNode(data);

    if (start == nullptr)
    {
        start = tmp;
        start->next = start;
    }
    else if (start->next == start)
    {
        start->next = tmp;
        tmp->next = start;
    }
    else
    {
        CircularLinkedNode* afterStart = start->next;
        start->next = tmp;
        tmp->next = afterStart;
    }
}

CircularLinkedNode *ListCircular::removeBeforeStart()
{
    if (start == nullptr)
        return nullptr;
    else
    {
        if (start->next == start)
        {
            CircularLinkedNode *tmp = start;
            start = nullptr;
            return tmp;
        }
        else
        {
            CircularLinkedNode *tmp = start;
            while (tmp->next->next != start)
                tmp = tmp->next;

            CircularLinkedNode *bcp = tmp->next;
            tmp->next = tmp->next->next;
            return bcp;
        }
    }
}

CircularLinkedNode *ListCircular::removeAfterStart()
{
    if (start == nullptr)
        return nullptr;
    else
    {
        if (start->next == start)
        {
            CircularLinkedNode *tmp = start;
            start = nullptr;
            return tmp;
        }
        else
        {
            CircularLinkedNode *tmp = start->next;
            CircularLinkedNode *afterTmp = tmp->next;
            start->next = afterTmp;
            return tmp;
        }
    }
}

std::vector<std::string> ListCircular::getElementsAsVector()
{
    std::vector<std::string> vec;

    if (start != nullptr)
    {
        vec.push_back(start->data);

        if (start->next != nullptr)
        {
            CircularLinkedNode* tmp = start->next;
            while (tmp != start)
            {
                vec.push_back(tmp->data);
                tmp = tmp->next;
            }
        }
    }

    return vec;
}
