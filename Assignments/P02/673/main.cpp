//UVA 673

#include <iostream>
#include <stack>

using namespace std;

int main(){
    int lines;
    string useCase;
    bool works = true;
    stack<char> stackInput;

    cin >> lines;
    for(int i = 0; i < lines; i++){
        cin >> useCase;
        if(useCase.length() % 2 != 0){
            works = false;
            break;
        }
        else{
            for(int j = 0; j < useCase.length(); j++){
                while(works){
                    switch(useCase[j]) {
                        case '(': 
                            stackInput.push('(');
                            break;
                        case ')':
                            if(stackInput.empty())
                                works = false;
                            else{
                                char temp = stackInput.top();
                                stackInput.pop();
                                if(temp == '('){
                                    break;
                                }
                                else{
                                    works = false;
                                    break;
                                }
                            }
                        case '[': 
                            stackInput.push('[');
                            break;
                        case ']':
                            if(stackInput.empty())
                                works = false;
                            else{
                                char temp = stackInput.top();
                                stackInput.pop();
                                if(temp == '['){
                                    break;
                                }
                                else{
                                    works = false;
                                    break;
                                }
                            }
                    }
                }
            }
        }
        if(works)
            cout << "Yes\n";
        else
            cout << "No\n";
        
        works = true;
    }
}