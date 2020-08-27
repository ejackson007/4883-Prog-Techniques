#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int t, e1, e2, e3;
    priority_queue<int> pq; //avoids sorting
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> e1 >> e2 >> e3;
        pq.push(e1);
        pq.push(e2);
        pq.push(e3);
        pq.pop();
        printf("Case %d: %d\n", i + 1, pq.top());
        pq.pop();
        pq.pop();
    }
}