//currently failing because of flawed check. It does check to see if it is legitemately on the next level
//however this does not account to see if the tree has a possible parent. instead of checking for level
//there needs to be a check if its parent exists. This is possible by determining if its a left or right
//child, dividing by 2, and then searching for the presence of that value
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //sort
#include <set>

#define endl '\n'

using namespace std;

int main(){
    //create tree with maximum amount of nodes, empty
    int i = 1, leaves = 0, count = 0, prev = 0;
    vector<pair <int, int> > tree;
    set <int> positions;
    string node, value;
    size_t pos;
    bool valid = true; //node can exist
    //cin first node. If nothing it is end of file
    while(cin >> node){
        //() ends trees
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
            for(char movement : node){
                if(movement == 'L')
                    i *= 2;
                else
                    i = i*2 + 1;
            }
            //check if its a duplicate
            if(positions.find(i) != positions.end()){
                valid = false;
            }
            tree.push_back(make_pair(stoi(value), i));
            positions.insert(i);
            i = 1; //reset iterator
            cin >> node;
        }
        //end of tree. sort by value and print

        //sort vector in ascending order by second value in pair
        //https://stackoverflow.com/questions/279854/how-do-i-sort-a-vector-of-pairs-based-on-the-second-element-of-the-pair
        sort(tree.begin(), tree.end(), [](const pair<int,int> &left, const pair<int,int> &right) {
            return left.second < right.second;});

        //check if first value is a root. 
        if(valid && tree[0].second == 1){
            for (pair<int,int> &child : tree){
                //checks to see if the current leaf is possible, i.e same line or next one
                //There may be a way to print and do this at the same time.
                //only way to "rewrite" current line is /r which just moves cursor and therefore 
                //does not delete the whole row. Worst case (valid) you have to go through vector twice
                if(child.second != 1 && positions.find(child.second / 2) == positions.end()){
                    valid = false;
                    break;
                }
                prev = child.second;
            }
        }
        else{
            valid = false;
        }

        if(valid){
            for(int j = 0; j < tree.size() - 1; j++){
                cout << tree[j].first << " ";
            }
            cout << tree.back().first;
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
        prev = 0;
    }
}