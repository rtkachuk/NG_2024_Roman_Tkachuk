#include <iostream>

using namespace std;

int main()
{
    // int chislo = 0;
    // int mnojitel = 0;

    // cout << "Vvedi chislo: " << endl;
    // cin >> chislo;
    // cout << "Vvedi mnojitel: " << endl;
    // cin >> mnojitel;

    // int index = 1;
    // while ( index < mnojitel+1 ) {
    //     cout << chislo << "*" << index << "=" << chislo * index << endl;
    //     index = index + 1;
    // }

    for (int row = 0; row < 10; row++){
        for (int index = 0; index < 10; index++) {
            if (row > index)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    system("pause");
}
