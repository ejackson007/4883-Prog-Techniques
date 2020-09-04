#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int count;
    string sequence;
    vector<char> stack;
    bool valid;

    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> sequence;
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
        if (valid)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}