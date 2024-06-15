#include <iostream>

using namespace std;

const int ROWS = 10;
const int COLUMNS = 10;

char map[ROWS][COLUMNS]; // Tak delat nelzya :3
                         // No eto primer globalnoy peremennoy :3

struct pos {
    int x;
    int y;
};

void generateMap() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            map[i][j] = '.';
        }
        cout << endl;
    }
}

void drawMap(pos player) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (player.x == j && player.y == i)
                cout << '@';
            else
                cout << map[i][j];
        }
        cout << endl;
    }
}

char askPlayer() {
    char movement;
    cout << "Enter move: ";
    cin >> movement;
    return movement;
}

pos getAction(pos player) {
    switch(askPlayer()) {
    case 'w': player.y--; break;
    case 's': player.y++; break;
    case 'd': player.x++; break;
    case 'a': player.x--; break;
    }
    return player;
}

void drawPyramid(int size) {
    for (int i=0; i < size; i++)
        cout << "*";
    cout << endl;
    if (size > 1)
        drawPyramid(size-1);
    for (int i=0; i < size; i++)
        cout << "*";
    cout << endl;
}

int main()
{
    drawPyramid(5);
    // pos player;
    // player.x = 3;
    // player.y = 3;
    // generateMap();
    // while(true) {
    //     system("cls");
    //     drawMap(player);
    //     player = getAction(player);
    // }
    // return 0;
}
