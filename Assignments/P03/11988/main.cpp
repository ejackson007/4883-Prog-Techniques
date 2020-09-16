/*
I initially tired to use a string with concatenation, just for UVA to say it took to long,
which led me to research efficiency in strings in c++. String concatenation is linear, which
means that for huge strings that will also have lots of concatenations, this is extremely
slow. This led me to implement a method which would allow me to move the cursor and write out the
string as it is coming it saving memory allocation. A list also allows me to iterate through adding
in values without explicitly knowing where they are going, just that they are next.
*/
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
        //id assume that looping with address would be faster, however UVA disagrees
        for(char letter : line){
            //move cursor to HOME
            if(letter == '[')
                cursor = completed.begin(); 
            //move cursor to END
            else if(letter == ']')
                cursor = completed.end(); 
            //insert letter at current cursor
            else
                completed.insert(cursor, letter);
        }
        //print entire list. Loop by address to save from making a copy
        for(const char &l : completed){
            cout << l;
        }
        cout << endl;
    }
    return 0;
}