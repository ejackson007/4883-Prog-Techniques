#include <iostream>
#include <string>
#include <vector>

#define endl '\n'

using namespace std;

int main(){
    //create tree with maximum amount of nodes, empty
    int i = 1, leaves = 0, count = 0;
    vector<string> tree;
    string node, value;
    size_t pos;
    //cin first node. If nothing it is end of file
    while(cin >> node){
        //set tree size
        tree.resize(257);
        //() ends trees
        while(node != "()"){
            leaves++;
            //remove ()
            node.erase(node.begin()); 
            node.pop_back();
            //seperate number from movement
            pos = node.find(',');
            //set value, rest will be equal to movement
            value = node.substr(0,pos);
            node.erase(0, pos + 1);
            for(char movement : node){
                if(movement == 'L')
                    i *= 2;
                else
                    i = i*2 + 1;
            }
            tree[i] = value;
            i = 1; //reset iterator
            cin >> node;
        }
        //end of tree. and print
        if(tree[1].length() != 0){
            for(int j = 1; count < leaves; j++){
                if(tree[j].length() != 0){
                    cout << tree[j] << " ";
                    count++;
                }
            }
            cout << endl;
        }
        else{
            cout << "not complete\n";
        }
        //reset values
        leaves = 1;
        count = 0;
        tree.clear();
    }
}