#include <iostream>
using namespace std;

void printArea(char arr[]) {
    cout << "|"<<arr[0]<<"  | "<<arr[1]<<" | "<<arr[2] << " | "<< endl;
    cout << "|"<<arr[3]<<"  | "<<arr[4]<<" | "<<arr[5] << " | "<< endl;
    cout << "|"<<arr[6]<<"  | "<<arr[7]<<" | "<<arr[8] << " | "<< endl; 
}

char checkGame(char arr[]) {

    if (arr[0] == arr[1] && arr[1] == arr[2] && arr[0] != char(0)) {
        return arr[0];
    }
    else if (arr[3] == arr[4] && arr[4] == arr[5] && arr[3] != char(0)) {
        return arr[3];
    }
    else if (arr[6] == arr[7] && arr[7] == arr[8] && arr[6] != char(0)) {
        return arr[6];
    }
    else if (arr[0] == arr[4] && arr[4] == arr[8] && arr[0] != char(0)) {
        return arr[0];
    }
    else if (arr[2] == arr[4] && arr[4] == arr[6] && arr[2] != char(0)) {
        return arr[2];
    }
    else if (arr[0] == arr[3] && arr[3] == arr[6] && arr[0] != char(0)) {
        return arr[0];
    }
    else if (arr[1] == arr[4] && arr[4] == arr[7] && arr[1] != char(0)) {
        return arr[1];
    }
    else if (arr[2] == arr[5] && arr[5] == arr[8] && arr[2] != char(0)) {
        return arr[2];
    }
    else {
        return char(0);
    }
}

int main()
{
    int p = 1;
    setlocale(0, "rus");
    int number, kletki;
    char znak;
    char arr[9] = { 0 };
    int x, o;
    while (true)
    {
        printArea(arr);
        cout <<endl<< "Введите номер клетки(от 0 до 8) = "; cin >> kletki;

       
        if ( p % 2 == 1)
        {
            cout << "Введите x" << endl; cin >> znak;
            if (znak != 'x') {
                cout << "Введите x" << endl;
                continue;
            }
        }
        else
        {
            cout << "Введите o" << endl; cin >> znak;
            if (znak != 'o') {
                cout << "Введите o" << endl;
                continue;
            }
        }
            if (kletki >= 0 && kletki <= 8) {
            if (arr[kletki] == (char)0) {
                arr[kletki] = znak;
            }
        }
        char flag = checkGame(arr);
        if (flag != char(0)) {
            if (flag == 'x') cout << "Первый игрок победил";
            else cout << "Второй игрок победил";
            break;
        }
        p++;
    
    }
}

