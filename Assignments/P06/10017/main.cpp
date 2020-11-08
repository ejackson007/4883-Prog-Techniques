#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > hanoi(3);
int step = 0, m;

void printTowers(){
    //print A
    if(hanoi[0].size() > 0){
        cout << "A=>   ";
        for(auto &num : hanoi[0]){
            cout << num << " ";
        }
        cout << endl;
    }
    else{
        cout << "A=>" << endl;
    }
    //print B
    if(hanoi[1].size() > 0){
        cout << "B=>   ";
        for(auto &num : hanoi[1]){
            cout << num << " ";
        }
        cout << endl;
    }
    else{
        cout << "B=>" << endl;
    }
    //print C
    if(hanoi[2].size() > 0){
        cout << "C=>   ";
        for(auto &num : hanoi[2]){
            cout << num << " ";
        }
        cout << endl;
    }
    else{
        cout << "C=>" << endl;
    }
}

void moveTower(int from, int to){
    hanoi[to].push_back(hanoi[from].back());
    hanoi[from].pop_back();
    cout << endl;
    printTowers();
}

void hanoiFunc(int n, int from, int to, int aux){
    if(step == m)
        return;
    
    if(n >= 1){
        hanoiFunc(n-1, from, aux, to);
        if(step == m)
            return;
        step++;
        moveTower(from, to);
        hanoiFunc(n-1, aux, to, from);
    }
}

int main(){
    int n, prob = 0;
    cin >> n >> m;
    //start tower
    while(n + m != 0){
        prob++;
        for(int i = n; i > 0; i--){
            hanoi[0].push_back(i);
        }
        cout << "Problem #" << prob << "\n\n";
        printTowers();
        hanoiFunc(n, 0, 2, 1);
        //get ready for next go
        hanoi[0].clear();
        hanoi[1].clear();
        hanoi[2].clear();
        cout << endl;
        step = 0;
        cin >> n >> m;
    }
    return 0;
}
