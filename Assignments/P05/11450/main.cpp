//To see maximum value
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, m, c, items, value, largest;
    bool possible = true;
    vector<priority_queue<int> > slist;
    cin >> n;
    //loop for all tries
    for (int _ = 0; _ < n; _++){
        cin >> m >> c;
        slist.resize(c);
        //read in all values for current list
        for(int i = 0; i < c; i++){
            cin >> items;
            //fill in each queue
            for(int j = 0; j < items; j++){
                cin >> value;
                slist[i].push(value);
            }
        }

    }
}