//things inside brakcet need to be moved to the beginnning of the string.
//brackets inside of brackets however taken precidence and therefore a stack is needed?

#include <iostream>
#include <string>

using namespace std;

int main(){
    string line, temp, finished = "";
    bool front = false;

    //while not EOF
    while(getline(cin, line)){
        //while more lines
        for(int i = 0; i < line.length(); i++){
            //push current letters and move cursor to front
            if(line[i] == '['){
                if(front){
                    finished = temp + finished;
                    temp = "";
                    front = true;
                }
                else{
                    finished = finished + temp;
                    temp = "";
                    front = true;
                }
            }
            //push current letters and move cursor to back
            else if(line[i] == ']'){
                if(front){
                    finished = temp + finished;
                    temp = "";
                    front = false;
                }
                else{
                    finished = finished + temp;
                    temp = "";
                    front = false;
                }
            }
            //not home or end, therefore add to current string to add
            else{
                temp += line[i];
            }
        }
        //no more letters in input. Push rest of letters at cursor
        //and then print
        if(front){
            finished = temp + finished;
            temp = "";
            front = false;
        }
        else{
            finished = finished + temp;
            temp = "";
        }
        cout << finished << endl;
        finished = "";
    }
    return 0;
}