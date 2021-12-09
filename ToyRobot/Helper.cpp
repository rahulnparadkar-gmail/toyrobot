#pragma once

// Helper.cpp : This file contains the helper methods like printing rules and menu.
//

#include <iostream>
using namespace std;
#include <string>
#include <map>

// Declarations
enum command { Menu = 1, Place = 2, Right = 3, Left = 4, Move = 5, Report = 6, Rules = 7, Exit = 8 };
map<string, command> commands;

// Maps commands
void register_commands()
{
    commands["menu"] = Menu;
    commands["place"] = Place;
    commands["right"] = Right;
    commands["left"] = Left;
    commands["move"] = Move;
    commands["report"] = Report;
    commands["rules"] = Rules;
    commands["exit"] = Exit;
}

// Displays all rules on console
void DisplayRules()
{
    std::cout << "\n\t1. All commands will be discarded until a valid PLACE command has been executed. In other words, one should start with 'Place' command." << std::endl;
    std::cout << "\n\t2. 'PLACE will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST" << endl;
    std::cout << "\n\t3. 'Move' will move the toy robot one unit forward in the direction it is currently facing." << endl;
    std::cout << "\n\t4. 'Move' command will be ignored if that move can cause toy robot fall off from table." << endl;
    std::cout << "\n\t5. 'Right' and 'Left' will rotate the robot 90 degrees in the specified direction without changing the position of the robot." << std::endl;
    std::cout << "\n\t6. 'Report command will display current position of toy." << std::endl;
}

// Displays menu on console
void DisplayMenu()
{
    cout << "Commands" << endl;
    cout << "\tMenu" << endl;
    cout << "\tPlace x-coordinate, y-coordinate, direction" << endl;
    cout << "\tRight" << endl;
    cout << "\tLeft" << endl;
    cout << "\tMove" << endl;
    cout << "\tReport" << endl;
    cout << "\tRules" << endl;
    cout << "\tExit" << endl;
}
