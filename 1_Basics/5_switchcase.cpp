#include<iostream>
using namespace std;

int main(){
    int day;

    cout << "Enter a day number (1-7): ";
    cin >> day;

    switch (day) {
    default: // Default placed first for demonstration
        cout << "Not a valid weekday." << endl;
        break;
    case 1:
        cout << "It's Monday!" << endl;
        break;
    case 2:
        cout << "It's Tuesday!" << endl;
        break;
    case 3:
        cout << "It's Wednesday!" << endl;
        break;
    case 4:
        cout << "It's Thursday!" << endl;
        break;
    case 5:
        cout << "It's Friday!" << endl;
        break;
    case 6:
        cout << "It's Saturday!" << endl;
        break;
    case 7:
        cout << "It's Sunday!" << endl;
        break;
    }
}
