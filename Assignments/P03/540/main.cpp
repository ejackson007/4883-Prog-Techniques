//Each team will have its own sub line. 

//How to check if a value is in a team? Map implementation will probably be the most efficcient and easiest.
//Value : Team format. How do we know the index of the team line though? A class?
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>

#define endl '\n'

using namespace std;

void clear(queue<int> &q){
    queue<int> empty;
    swap(q, empty);
}

int main(){
    int t, team_size, member, s = 1;
    string command;
    //This will control the order. Instead of reordering the the entire line, a sperate
    //queue will keep track of what teams have which order. a set will assure no duplicates
    vector<queue<int> > q;
    queue<int> line;
    set<int> exists;

    unordered_map<int,int> teams;
    cin >> t;
    while(t != 0){
        //create line size
        q.resize(t);
        cout << "Scenario #" << s << endl;
        //Creates a look up table so we can identify what teams
        //each number is on. unordered_map makes this O(1)
        for(int i = 0; i < t; i++){
            cin >> team_size;
            for(int j = 0; j < team_size; j++){
                cin >> member;
                teams[member] = i;
            }
        }
        //being reading in commands
        cin >> command;
        while(command != "STOP"){
            //How do i know which queue to put it into?
            if(command == "ENQUEUE"){
                cin >> member;
                //check if team is in set, if not add to queue, otherwise toss
                if(exists.find(teams[member]) == exists.end()){
                    exists.insert(teams[member]);
                    line.push(teams[member]);
                }
                
                //push member onto respective team stack
                q[teams[member]].push(member);
            }
            else{
                cout << q[line.front()].front() << endl;
                q[line.front()].pop();
                //if the line is empty, it looses its place in line
                if(q[line.front()].empty()){
                    exists.erase(line.front());
                    line.pop();
                }
            }
            cin >> command;
        }
        q.clear();
        exists.clear();
        clear(line);
        s += 1;
        cin >> t;
        cout << endl;
    }
}