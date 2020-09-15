#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

void main(){
    string line, temp, finished = "";
    bool front = false;

    //while not EOF
    while(getline(cin, line)){
        //while more lines
        for(int i = 0; i < line.length(); i++){
            switch(line[i]){
                case '[':
                    if(front){
                        finished = temp + finished;
                        temp = "";
                    }
                    else{
                        finished = finished + temp;
                        temp = "";
                        front = false;
                    }
                    break;
                case ']':
                    if(front){
                        finished = temp + finished;
                        temp = "";
                        front = false;
                    }
                    else{
                        finished = finished + temp;
                        temp = "";
                    }
                    break;
                default:
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
}