#include <iostream>

using namespace std;

int main()
{
    // char a[5][5];
    // int x = 3;
    // int y = 3;
    // char movement;
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         a[i][j] = '.';
    //     }
    //     cout << endl;
    // }
    // while(true) {
    //     system("cls");
    //     for (int i = 0; i < 5; i++) {
    //         for (int j = 0; j < 5; j++) {
    //             if (x == j && y == i)
    //                 cout << '@';
    //             else
    //                 cout << a[i][j];
    //         }
    //         cout << endl;
    //     }
    //     cout<< "Enter move: ";
    //     cin >> movement;
    //     switch(movement) {
    //     case 'w': y--; break;
    //     case 's': y++; break;
    //     case 'd': x++; break;
    //     case 'a': x--; break;
    //     }
    // }
    // return 0;

    char str[256];
    cout << "Enter some string: ";
    cin.getline(str, 256);

    cout << "You entered: " << str << endl;
    cout << "You really entered: " << endl;
    int i=0;
    while (str[i] != 0) {
        cout << str[i] << endl;
        i++;
    }
    cout << endl;
}
