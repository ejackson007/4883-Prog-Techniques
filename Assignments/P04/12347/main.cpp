#include <iostream>
#include <vector>

#define maxval 1000000 //maximum is 10^6
#define endl '\n'

using namespace std;

void postOrder(vector<int> pre, int min, int max, int& index){
    //if array is traversed, return
    if (index == pre.size())
        return;
    //If element is not in current subtree
    if(pre[index] < min || pre[index] > max)
        return;
    //get current value and incriment for right and left subs
    int val = pre[index];
    index++;

    //all values for left sub tree
    postOrder(pre, min, val, index);
    //all elements for right sub tree
    postOrder(pre, val, max, index);

    cout << val << endl;
}

int main(){
    vector<int> pre;
    int node, index = 0;
    while(cin >> node){
        pre.push_back(node);
    }
    postOrder(pre, 0, maxval, index);
    return 0;
}