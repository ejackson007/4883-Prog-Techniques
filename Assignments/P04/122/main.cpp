//Segmentation error happening before any print, therefore it is in insert or sort


#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm> //sort
#include <set>

#define endl '\n'

using namespace std;

typedef pair<string,int> psi;

int main(){
    //create tree with maximum amount of nodes, empty
    int leaves = 0, count = 0;
    vector<priority_queue<psi, vector<psi>, greater<psi> > > tree;
    vector<int> toPrint;
    set <string> positions;
    string node, value, prev = "";
    size_t pos;
    bool valid = true; //node can exist
    //cin first node. If nothing it is end of file
    while(cin >> node){
        //() ends trees
        tree.resize(256);
        while(node != "()" && valid){
            leaves++;
            //remove ()
            node.erase(node.begin()); 
            node.pop_back();
            //seperate number from movement
            pos = node.find(',');
            //set value, rest will be equal to movement
            value = node.substr(0,pos);
            node.erase(0, pos + 1);
            //check if its a duplicate
            if(positions.find(node) != positions.end()){
                valid = false;
            }
            tree[node.length()].push(make_pair(node, stoi(value)));
            positions.insert(node);
            cin >> node;
        }
        //end of tree. sort by value and print
        tree.shrink_to_fit();
        //sort vector in ascending order by second value in pair
        //https://stackoverflow.com/questions/279854/how-do-i-sort-a-vector-of-pairs-based-on-the-second-element-of-the-pair

        //check if first value is a root. 
        if(valid && tree[0].size() != 0){
            for(vector<pair <int, string> > &sub : tree){
                for (pair<int,string> &child : sub){
                    //checks to see if the current leaf is possible, i.e same line or next one
                    //There may be a way to print and do this at the same time.
                    //only way to "rewrite" current line is /r which just moves cursor and therefore 
                    //does not delete the whole row. Worst case (valid) you have to go through vector twice
                    prev = child.second;
                    if(prev != "")
                        prev.pop_back();

                    if(positions.find(prev) == positions.end()){// what the LLRR stuff would be without the last move
                        valid = false;
                        break;
                    }
                    
                }
            }
        }
        else{
            valid = false;
        }

        if(valid){
            for(vector<pair <int, string> > &sub : tree){
                for (pair<int,string> &child : sub){
                    cout << child.first << " ";
                }
            }
            cout << tree.back().back().first;
        }
        else
            cout << "not complete";
        cout << endl;
        //reset values
        leaves = 1;
        count = 0;
        tree.clear();
        positions.clear();
        valid = true;
        prev = "";
    }
}