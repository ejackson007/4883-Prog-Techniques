//Current checks to see if it is has a child, as well as if its trying to duplicate a position. Input5 fails because int 
//cannot hold a number big enough to represent the level value. testing says that a long long int is also too small.....
//i will revists lol

//By adding values, order does not matter, hence LR == LL if L = 1 and R = 2.
//Multiplication would make the values too big
//LLLLLLLR and LRLLLLLLL how to make these two different? (earlier rights should have a larger difference).
//by knowing the length of the string, you can take into account position? decriment backwards and add value so that the leftmost has the gretest values

//LLLLLL = 27
//LLLLR = 20

//LLLLLLRL = 45
//LLLLLRLL = 45 //oof

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //sort
#include <set>

#define endl '\n'

using namespace std;

int main(){
    //create tree with maximum amount of nodes, empty
    int leaves = 0, count = 0;
    vector<vector<pair <int, string> > > tree;
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
            tree[node.length()].push_back(make_pair(stoi(value), node));
            positions.insert(node);
            cin >> node;
        }
        //end of tree. sort by value and print

        //sort vector in ascending order by second value in pair
        //https://stackoverflow.com/questions/279854/how-do-i-sort-a-vector-of-pairs-based-on-the-second-element-of-the-pair
        for(vector<pair <int, string> > &sub : tree){
            sort(sub.begin(), sub.end(), [](const pair<int,string> &left, const pair<int,string> &right) {
                return left.second < right.second;});
        }

        //check if first value is a root. 
        if(valid && tree[0].size() != 0){
            tree.shrink_to_fit();
            for(vector<pair <int, string> > &sub : tree){
                for (pair<int,string> &child : sub){
                    //checks to see if the current leaf is possible, i.e same line or next one
                    //There may be a way to print and do this at the same time.
                    //only way to "rewrite" current line is /r which just moves cursor and therefore 
                    //does not delete the whole row. Worst case (valid) you have to go through vector twice
                    if(child.second != "" && positions.find(prev) == positions.end()){
                        valid = false;
                        break;
                    }
                    prev = child.second;
                    prev.pop_back(); // what the LLRR stuff would be without the previous one
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