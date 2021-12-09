#pragma once

// Node.h : This file contains the Node class. It can hold coordinates as well as directions
//

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node* next;
    Node* prev;

public:
    Node()
    {
        next = NULL;
        prev = NULL;
    };
};
