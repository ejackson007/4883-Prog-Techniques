#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int main(){
    int t, team_size, member, s = 1;
    string command;
    priority_queue<int> q;
    cin >> t;
    while(t != 0){
        cout << "Scenario #" << s << endl;
        //create teams in team members.
        //this is important as a priority queue sorts into teams, it does not 
        //take into account groups that are already there
        for(int i = 0; i < t; i++){
            cin >> team_size;
            for(int j = 0; j < team_size; j++){
                cin >> member;
            }
        }
        //being reading in commands
        cin >> command;
        while(command != "STOP"){
            if(command == "ENQUEUE"){
                cin >> member;
                q.push(member);
            }
            else{
                cout << q.top() << endl;
                q.pop();
            }
            cin >> command;
        }
        q.empty();
        s += 1;
        cin >> t;
        cout << endl;
    }
}