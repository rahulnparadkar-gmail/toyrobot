# toyrobot
simple console application prepared as part of hiring process

Rules:
1. All commands will be discarded until a valid PLACE command has been executed. In other words, one should start with 'Place' command.
2. 'PLACE will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST.
3. 'Move' will move the toy robot one unit forward in the direction it is currently facing.
4. 'Move' command will be ignored if that move can cause toy robot fall off from table.
5. 'Right' and 'Left' will rotate the robot 90 degrees in the specified direction without changing the position of the robot.
6. 'Report command will display current position of toy.

Assumption:
1. Table is of size 5*5
2. South West corner is considered as 0,0; which implies North East corner is 4,4
3. User will provide input on console

Commands:
1. Menu
2. Place
3. right
4. Left
5. Move
6. Report
7. Rules
8. Exit

Unit tests:
12 units tests are included. 
2 to check if linked list are initailised. 
2 to check if place method is working fine. 
4 to test toy is moving in all 4 directions. 
2 to ensure toy is not falling off the table. 
2 to turn toy either left or right 
