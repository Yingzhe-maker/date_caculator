# include "Date.h"
# include <iostream>
using namespace std;

int main() {
    cout << "DateCaculator" << endl;
    cout << "author: He Yingzhe\nversion: 1.0\nmail: heyingzhe@outlook.com" << endl;
    cout << "This program can calculate the date after or before the input date." << endl;
    cout << "This program is written in C++." << endl;
    
    Date date1(1, 1, 1);
    cout << "" << endl;
    cout << "Please input the date, for example '2024 8 9' '2012 12 9'." << endl;
    cout << "Write here -->";
    int year1, month1, day1;
    cin >> year1 >> month1 >> day1;
    date1.set(year1, month1, day1);

    cout << "Backward or forward from the date? (Input 'B' or 'F')" << endl;
    char choice;
    cout << "Write here --> ";
    cin >> choice;
    
    if (choice == 'B'){
        cout << "How many days?" << endl;
        int days;
        cout << "Write here --> ";
        cin >> days;
        increment(date1, days);
    } else if (choice == 'F'){
        cout << "How many days?" << endl;
        int days;
        cout << "Write here --> ";
        cin >> days;
        decrement(date1, days);
    } else {
        cout << "Invalid input!" << endl;
        exit(0);
    }
    
    cout << "The result is: ";
    date1.showDate();

    system("pause");
    return 0;
}