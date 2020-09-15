#include <iostream>
#include <list>

#define endl '\n'

using namespace std;

int main(){
    string line;
    list<char> completed;

    //while not EOF
    while(getline(cin, line)){
        completed.clear();
        //put cursor at beginning of line
        list<char>::iterator cursor = completed.begin();
        //equivalent to for letters in line in python
        for(char letter : line){
            if(letter == '[')
                cursor = completed.begin(); 
            else if(letter == ']')
                cursor = completed.end(); 
            else
                completed.insert(cursor, letter);
        }
        //print entire list
        for(char l : completed){
            cout << l;
        }
        cout << endl;
    }
    return 0;
}