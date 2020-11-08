#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    //generate table of all fibs needed
    vector<double> fibs;
    double val = 2, max = pow(10,100), a, b;
    int pos = 1, dist = 0;
    fibs.push_back(1);
    fibs.push_back(2);
    //create lookup table
    while(val <= max){
        val += fibs[pos - 1];
        pos++;
        fibs.push_back(val);
    }
    //start program
    cin >> a >> b;
    while(a+b != 0){
        dist = 0;
        pos = 0;
        while(a > fibs[pos]){
            pos++;
        }
        while(b >= fibs[pos]){
            dist++;
            pos++;
        }
        cout << dist << endl;
        //read in new value
        cin >> a >> b;
    }

}