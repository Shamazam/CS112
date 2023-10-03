#pragma once
#include "Data.h"

class Node
{
    friend class List;

    private:
        Data* nData;
        Node* pNext;
        Node* pPrev;
    public:
        Node(Data* data) {
            nData = data;
            pNext = NULL;
            pPrev = NULL;
        }
        Data* getData() { return nData; }
};

