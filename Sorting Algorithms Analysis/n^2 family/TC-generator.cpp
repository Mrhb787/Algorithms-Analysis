#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int main()
{
    while (1)
    {
        cout << "Press 1 for Best Case | ";
        cout << "Press 2 for Worst Case | ";
        cout << "Press 3 for Random Case \n";
        int f;
        cin >> f;
        if (f == 1)
        {
            ofstream output;
            output.open("best-case.txt");
            if (!output.is_open())
                cout << "Please Generate a file named 'best-case.txt' \n";

            else
            {
                for (int i = 0; i < 5000000; i++)
                    output << i << " ";
                cout << "\n Test Cases Generated Successfully \n";
                output.close();
            }
            break;
        }
        if (f == 2)
        {
            ofstream output;
            output.open("worst-case.txt");
            if (!output.is_open())
                cout << "Please Generate a file named 'worst-case.txt' \n";

            else
            {
                for (int i = 0; i < 5000000; i++)
                    output << (5000000 - i) << " ";
                cout << "\n Test Cases Generated Successfully \n";
                output.close();
            }
            break;
        }
        if (f == 3)
        {
            ofstream output;
            output.open("random-case.txt");
            if (!output.is_open())
                cout << "Please Generate a file named 'random-case.txt' \n";

            else
            {
                srand(time(0));
                for (int i = 0; i < 5000000; i++)
                    output << rand() << " ";
                cout << "\n Test Cases Generated Successfully \n";
                output.close();
            }
            break;
        }
        else
            cout << "Wrong input Plase try again....\n";
    }
    return 0;
}
