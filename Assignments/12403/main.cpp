#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int t, donate, total = 0;
    string command;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> command;
        if (command == "donate")
        {
            cin >> donate;
            total += donate;
        }
        //the problem states that we can assume the only two options are donate
        //threfore I do not need to check if the string is equal to the other
        else
        {
            cout << total << endl;
        }
    }
}