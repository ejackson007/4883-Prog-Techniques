//Railway
#include <iostream>
#include <vector>

using namespace std;

int main(){
    pair<int, int> M, temp;
    int N;
    vector<pair<int, int> > segments;
    while(cin >> M.first){
        cin >> M.second;
        cin >> N;
        for(int i = 0; i < N + 1; i++){
            cin >> temp.first >> temp.second;
            segments.push_back(temp);
        }
        for(auto a : segments){
            printf("(%i,%i)\n", a.first, a.second);
        }
        cout << endl;
    }
}