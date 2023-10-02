// co_ca_ro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "display.h"
using namespace std;
int main()
{
    DisplayTable test;
    test.displayTable();
    string in;
    int num;
    while (1)
    {

        cout << "This is X's turn" << endl;
        do {
            cout << "Please go in right location" << endl;
            cin >> in;
            num = stoi(in);
            test.tick(num, 1);
        } while (test.getErrTick());
        test.displayTable();
        test.checkWin(1);
        if (test.getWinFlag())
        {
            cout << "X is win" << endl;
            cout << "please type Y to continue" << endl;
            string prompt = "";
            while (prompt.compare("Y"))
            {
                cin >> prompt;
            }
            test.resetTable();
            test.displayTable();
            continue;
        }
            
        cout << "This is O's turn" << endl;
        do {
            cout << "Please go in right location" << endl;
            cin >> in;
            num = stoi(in);
            test.tick(num, 0);
        } while (test.getErrTick());
        test.displayTable();
        test.checkWin(0);
        if (test.getWinFlag())
        {
            cout << "O is win" << endl;
            cout << "please type Y to continue" << endl;
            string prompt = "";
            while (prompt.compare("Y"))
            {
                cin >> prompt;
            }
            test.resetTable();
            test.displayTable();
            continue;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
