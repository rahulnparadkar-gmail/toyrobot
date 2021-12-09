#pragma once

// DLL.h : This file contains the 'DLL' class.
//

#include <iostream>
using namespace std;
#include <string>
#include <map>
#include "Node.h"

template <typename T>
class DLL
{
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current;
    int count;

public:
    DLL()
    {
        head = tail = current = NULL;
    }
    // InitCoordinates function intialises link list for storing x and y coordinates denoting where toy is placed on table
    void InitCoordinates(int size)
    {
        try
        {
            count = size;
            for (int i = 0; i < size; i++)
            {
                Node<T>* temp = new Node<T>();
                temp->data = i;
                if (head == tail && head == NULL)
                {
                    head = tail = temp;
                    head->next = tail->next = NULL;
                    head->prev = tail->prev = NULL;
                }
                else
                {
                    tail->next = temp;
                    temp->prev = tail;
                    tail = temp;
                    head->prev = tail;
                    tail->next = head;
                }
            }
        }
        catch (exception ex)
        {
            cout << "Error occurred while initialising table..." << ex.what() << endl;
        }
    }

    // Print function display content of list, for x & y cordinate it will be from 0 to size-1, for direction it will print N,E,S,W
    // It returns number of element in lists
    // This function is used for testing purpose only
    int Print()
    {
        int n = 0;
        if (head == tail && head == NULL)
        {
            std::cout << "Not Initialise" << std::endl;
        }
        Node<T>* temp = head;
        for (int j = 0; j < count; j++)
        {
            n++;
            std::cout << temp->data;
            temp = temp->next;
        }
        std::cout << std::endl;
        return n;
    }

    // Place function will keep toy robot at specific spot on table
    // This function will be called trice, if you select Place command from command line
    // For setting x-cordinate & y-coordinate and setting direction toy is facing
    void Place(int pos)
    {
        current = head;
        while (1)
        {
            if (current->data == pos)
            {
                break;
            }
            else
            {
                current = current->next;
            }
        }
    }

    // Move funtion will be use to move toy robot one unit forward in direction it is facing
    void Move(char d)
    {
        // if toy is facing North or East, we will increase coordinate, here we make sure it won't cross size-1 number, 4 in our example
        if ((d == 'N' || d == 'E') && current->data != count - 1)
        {
            current = current->next;
        }
        // if toy is facing South or West, we will decrease coordinate, here we make sure it won't cross 0
        else if ((d == 'S' || d == 'W') && current->data != 0)
        {
            current = current->prev;
        }
    }

    // GetCordinate function returns the x or y cordinate, specifying current spot for toy robot
    int GetCoordinate()
    {
        return current->data;
    }

    // GetDirection function returns the direction, toy robot is currently facing
    char GetDirection()
    {
        return current->data;
    }

    // AppendNode is used while initialising linkedlist for storing directions
    void AppendNode(char d)
    {
        Node<char>* newNode = new Node<char>();
        newNode->data = d;

        Node<char>* temp = head;

        if (head == NULL)
        {
            head = tail = newNode;
            head->next = tail->next = NULL;
            head->prev = tail->prev = NULL;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            head->prev = tail;
            tail->next = head;
        }
    }

    // InitiDirection, initialises direction linked list
    void InitDirection()
    {
        count = 4;
        AppendNode('N');
        AppendNode('E');
        AppendNode('S');
        AppendNode('W');
    }

    // Right function, traverse through direction linked list, means toy robot is now turning in 90 degrees towards right
    void Right()
    {
        current = current->next;
    }

    // Left function, traverse through direction linked list, means toy robot is now turning in 90 degrees towards left
    void Left()
    {
        current = current->prev;
    }
};
