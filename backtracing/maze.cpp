#include <iostream>
#include <limits>
#include <stack>

using namespace std;

struct Position {
    int row, col;
    Position():row(1), col(1) {};   // 初始化为 (1,1)，也就是起点
};


void printMaze(char maze[][16]);
void waitForEnter();


int main()
{
    // start is [1][1] , end is [8][13]
    char maze[10][16] = { "OOOOOOOOOOOOOOO",
                          "O O O OOO O  OO",
                          "O             O",
                          "O O OOOOOOO O O",
                          "O O   O   O   O",
                          "O OOO  OO  OOOO",
                          "O    O O      O",
                          "OO O O O OOO OO",
                          "OO   O   O    O",
                          "OOOOOOOOOOOOOOO" };

    printMaze(maze); //prints unsolved maze
    stack<Position> pos;
    Position here;
    bool done = false;
    

    // depth first search
    while (!done) {
        // Arithmetic problem: if exit is at [8][13], then 10-2 == 8, but
        // 16-2 == ??  :-) 
        if (here.row == 10 - 2 && here.col == 15 - 2) { // I updated the experession to here.col == 15 - 2
            done = true;    // ok, but...
            break;          // ...let's simplify the process ;-)
        }

        if (maze[here.row][here.col + 1] == ' ') {    // checks east
            pos.push(here);
            maze[here.row][here.col] = 'x';
            here.col++;
            // cout << "east\n";
            // printMaze(maze);
            continue;
        }

        if (maze[here.row + 1][here.col] == ' ') {   // checks south
            pos.push(here);
            maze[here.row][here.col] = 'x';
            here.row++;
            // cout << "south\n";
            // printMaze(maze);
            continue;
        }

        if (maze[here.row][here.col - 1] == ' ') {   // checks west
            pos.push(here);
            maze[here.row][here.col] = 'x';
            here.col--;
            // cout << "west\n";
            // printMaze(maze);
            continue;
        }
        
        if (maze[here.row - 1][here.col] == ' ') {   // checks north
            pos.push(here);
            maze[here.row][here.col] = 'x';
            here.row--;
            // cout << "north\n";
            // printMaze(maze);
            continue;
        }
        
        // If we get, here, it means the path was a dead end
        if (!pos.empty()) {
        // if stack is not empty, mark current pos. as d and back track
            maze[here.row][here.col] = 'D';
            here = pos.top();
            pos.pop();
            // cout << "no way\n";
            // printMaze(maze);
            continue;
        }
    }
    printMaze(maze); //prints maze solution

    int steps = 0;  // least steps required from start to end
    for(int i=0; i<10; i++){
        for(int j=0; j<16; j++)
            if(maze[i][j] == 'x')
                ++steps;
    }
    printf("least steps required from (1,1) to (8,13) are %d\n", steps-1);
    waitForEnter();

    return 0;
}


void printMaze(char maze[][16])
{
    for (int i = 0; i <10; i++) {
        for (int j = 0; j < 16; j++) {
            if (j == 15)
                printf("\n");
            printf("%c", maze[i][j]);   // 经过测试，maze[i][15]是空字符'\0'，不输出任何结果
        }
    }
    printf("\n");
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void waitForEnter()
{
    cout << "\nPress ENTER to continue...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}