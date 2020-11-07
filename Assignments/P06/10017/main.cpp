#include <iostream>
#include <vector>

using namespace std;

void printTowers(vector<vector<int> > hanoi){
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

void hanoiFunc(int n, int from, int to, int aux, vector<vector<int> > hanoi){
    if (n == 1){
        //move number
        hanoi[to].push_back(hanoi[from].back());
        hanoi[from].pop_back();
        cout << endl;
        printTowers(hanoi);
        return;
    }
    hanoiFunc(n-1, from, aux, to, hanoi);
    //move numbers
    hanoi[to].push_back(hanoi[from].back());
    hanoi[from].pop_back();
    cout << endl;
    printTowers(hanoi);
    hanoiFunc(n-1, aux, to, from, hanoi);
}

int main(){
    vector<vector<int> > hanoi(3);
    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;
    //start tower
    for(int i = n; i > 0; i--){
        hanoi[0].push_back(i);
    }
    printTowers(hanoi);
    hanoiFunc(n, 0, 2, 1, hanoi);
    return 0;
}
