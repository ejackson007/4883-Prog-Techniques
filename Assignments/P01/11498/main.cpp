#include <iostream>

using namespace std;

int main()
{
    int k, n, m, x, y;
    bool run = true;
    cin >> k;
    while (run)
    {
        cin >> n >> m;
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            if (x > n && y > m)
                cout << "NE\n";
            else if (x > n && y < m)
                cout << "SE\n";
            else if (x < n && y < m)
                cout << "SO\n";
            else if (x < n && y > m)
                cout << "NO\n";
            else
                cout << "divisa\n";
        }
        cin >> k;
        if (k == 0)
            run = false;
    }
}