//things inside brakcet need to be moved to the beginnning of the string.
//brackets inside of brackets however taken precidence and therefore a stack is needed?

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main(){
    string line, finished;
    vector<char> stack; //main stack to keep track of stuff
    queue<char> b;
    int brackets = 0;

    //while not EOF
    while(getline(cin, line)){
        //loop for every character in string
        for(int i = 0; i < line.length(); i++){
            //not in a bracket
           if(brackets == 0){
               
           }
        }
    }
    return 0;
}