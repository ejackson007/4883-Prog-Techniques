#include <iostream>

using namespace std;

int main()
{
    int items, w, h, d;
    bool fits;
    cin >> items;
    for (int i = 0; i < items; i++)
    {
        cin >> w >> h >> d;
        fits = (w <= 20) * (h <= 20) * (d <= 20);
        if (fits)
            printf("Case %d: good\n", i + 1);
        else
            printf("Case %d: bad\n", i + 1);
    }
}