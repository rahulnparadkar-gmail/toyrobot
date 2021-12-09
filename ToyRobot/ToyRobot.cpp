// ToyRobot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <string>
#include <map>
#include "Node.h"
#include "DLL.h"
#include "Helper.cpp"
#include <algorithm>


int main()
{
    int xaxis, yaxis, start, end;
    int size = 5;
    char d;
    string input;
    char delimiter = ' ';
    bool isInit = false;

    try
    {
        DLL<int>* x = new DLL<int>();
        DLL<int>* y = new DLL<int>();
        DLL<char>* direction = new DLL<char>(); 

        DisplayMenu();
        register_commands();

        while (1)
        {
            cout << "\nEnter your choice : ";
            getline(cin, input);
            string token = input.substr(0, input.find(delimiter));
            transform(token.begin(), token.end(), token.begin(), ::tolower);

            switch (commands[token])
            {
            case Menu:
                DisplayMenu();
                break;
            
            case Place:
                input.erase(remove(input.begin(), input.end(), ' '), input.end());
                if (input == token)
                {
                    cout << "Please provide command in correct format 'Place x-cordinate, y-cordonate, Direction'";
                    break;
                }
                start = token.length();
                end = input.find(',', start);
                xaxis = stoi(input.substr(start, end - start));
                
                start = end + 1;
                if (start == 0)
                {
                    cout << "Please provide command in correct format 'Place x-cordinate, y-cordonate, Direction'";
                    break;
                }
                end = input.find(',', start);
                yaxis = stoi(input.substr(start, end - start));
                
                start = end + 1;
                if (start == 0)
                {
                    cout << "Please provide command in correct format 'Place x-cordinate, y-cordonate, Direction'";
                    break;
                }
                end = input.find(',', start);
                d = input.substr(start, end - start)[0];
                if (d == '\0')
                {
                    cout << "Please provide command in correct format 'Place x-cordinate, y-cordonate, Direction'";
                    break;
                }

                cout << xaxis << " " << yaxis << " " << d << endl;

                if (xaxis < size && yaxis < size && xaxis >=0 && yaxis >= 0)
                {
                    x->InitCoordinates(size);
                    y->InitCoordinates(size);
                    
                    x->Place(xaxis);
                    y->Place(yaxis);
                }
                else
                {
                    cout << "X and/or Y coordinate should be between 0 and " << size << endl;
                    break;
                }

                if (d == 'N' || d == 'E' || d == 'S' || d == 'W')
                {
                    direction->InitDirection();
                    direction->Place(d);
                }
                else
                {
                    cout << "Please enter valid direction - N or E or S or W " << endl;
                    break;
                }
                isInit = true;
                break;
            case Right:
                if (isInit)
                    direction->Right();
                break;
            case Left:
                if (isInit)
                    direction->Left();
                break;
            case Move:
                if (isInit)
                {
                    d = direction->GetDirection();
                    std::cout << d << std::endl;
                    if (d == 'N' || d == 'S')
                    {
                        y->Move(d);
                    }
                    else if (d == 'E' || d == 'W')
                    {
                        x->Move(d);
                    }
                }
                break;
            case Report:
                if (isInit)
                {
                    xaxis = x->GetCoordinate();
                    yaxis = y->GetCoordinate();
                    d = direction->GetDirection();
                    std::cout << xaxis << ", " << yaxis << ", " << d << std::endl;
                }
                break;
            case Rules:
                DisplayRules();
                break;
            case Exit:
                exit(1);
            default:
                cout << "\nWrong choice. Please enter one of following command.\n";
                DisplayMenu();
                break;
            }
        }
    }
    catch (invalid_argument ex)
    {
        cout << "\nInvalid argument." << ex.what() << endl << "Exiting...";
        return 0;
    }
    catch (...)
    {
        cout << "\nError occured " << endl << "Exiting...";
        return 0;
    }
    return 0;
}
