#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    //create tree with maximum amount of nodes, empty
    int i = 1;
    vector<string> tree;
    string node, temp, value;
    size_t pos;
    //cin first node. If nothing it is end of file
    while(cin >> node){
        //set tree size
        tree.resize(257);
        //() ends trees
        while(node != "()"){
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
        //end of tree. 
    }

}