#include <iostream>

using namespace std;

int main()
{
    int t, left, right;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> left >> right;
        if (left < right)
            cout << "<\n";
        else if (left > right)
            cout << ">\n";
        else
            cout << "=\n";
    }
}