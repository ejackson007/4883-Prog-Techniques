#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int count;
    string temp;
    string sequence;
    vector<char> stack;
    bool valid;

    /*
    get line allows for an empty input, however if cin is used, and then getline is used, the iterator
    is not fixed, therefore it reads the first line again. getline with a temp string makes it a bit simpler
    to implement, rather than moving the iterator. 
    */
    getline(cin, temp);
    count = stoi(temp);

    for (int i = 0; i < count; i++)
    {
        getline(cin, sequence);
        valid = true;
        for (int j = 0; j < sequence.length(); j++)
        {
            if (sequence[j] == '(' || sequence[j] == '[')
            {
                stack.push_back(sequence[j]);
            }
            else
            {
                // if popping and stack is empty
                if (stack.size() == 0)
                {
                    valid = false;
                    break;
                }
                //check matching cases
                else if (sequence[j] == ')' && stack.back() == '(')
                    stack.pop_back();
                else if (sequence[j] == ']' && stack.back() == '[')
                    stack.pop_back();
                //if doesnt match
                else
                {
                    valid = false;
                    break;
                }
            }
        }
        //after trying all cases or break
        if (valid && stack.size() == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
        stack.clear();
    }
}