#include <stdio.h>
#include <stdbool.h>

#define W (8) /* labyrinth width */
#define H (8) /* labyrinth height */

void printMaze(char maze[W][H]) {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            printf("%c ", maze[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

bool findPath(char maze[W][H], int x, int y) {
    maze[x][y] = '!';
    //printMaze(maze);
    if (x == W - 1 && y == H - 1) return true;
    if (x + 1 < W && maze[x + 1][y] == ' ') 
        if (findPath(maze, x + 1, y)) return true;
    if (x - 1 >= 0 && maze[x - 1][y] == ' ')
        if (findPath(maze, x - 1, y)) return true;
    if (y + 1 < H && maze[x][y + 1] == ' ') 
        if (findPath(maze, x, y + 1)) return true;
    if (y - 1 >= 0 && maze[x][y - 1] == ' ')
        if (findPath(maze, x, y - 1)) return true;
    maze[x][y] = ' ';
    return false;
}


int main(void) {
    char maze[W][H] = {
        {' ', ' ', ' ', 'x', 'x', 'x', 'x', 'x'},
        {' ', 'x', ' ', ' ', 'x', 'x', 'x', 'x'},
        {' ', 'x', 'x', ' ', 'x', 'x', 'x', 'x'},
        {' ', 'x', ' ', ' ', ' ', 'x', 'x', 'x'},
        {'x', 'x', ' ', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', ' ', ' ', ' ', ' ', ' ', ' '},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', ' '},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', ' '},
    };
    printMaze(maze);
    if (findPath(maze, 0, 0)) {
        printf("Maze completed!\n");
        printMaze(maze);
    } else {
        printf("No path found!");
    }
}
