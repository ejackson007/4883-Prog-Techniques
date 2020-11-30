#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct dnaCount{
    string dna;
    int swaps = 0;
};

bool compareSwaps(const dnaCount &a, const dnaCount &b){
    return b.swaps > a.swaps;
}
bool compareDna(const dnaCount &a, const dnaCount &b){
    return b.dna > a.dna;
}

int bubblesort(string dna){
    int swaps = 0;
    int swapped = 0;
    int i,j;
    bool sorted = false;
    while(!sorted){
        swapped = 0;
        for(i=0,j=1;i<dna.length()-1;i++,j++){
            if(dna[j]<dna[i]){
                ++swaps;
                char temp = dna[i];
                dna[i] = dna[j];
                dna[j] = temp;
                swapped = 1;
            }
        }
        if(!swapped){
            sorted = true;
        }
    }
    return swaps;
}

int main() {
    int sets, group, size;
    vector<dnaCount> dnas;

    cin >> sets;
    while(sets--){
        cin >> size >> group;
        dnas.resize(group);
        for(int i = 0; i < group; i++){
            cin >> dnas[i].dna;
            dnas[i].swaps = bubblesort(dnas[i].dna);
        }
        
        //sort(dnas.begin(),dnas.end(),compareDna);
        //sort(dnas.begin(),dnas.end(),compareSwaps);
        
        //sorting uses quick sort, which does not retain initial order of inserting
        //to get around this, i will instead iterate through the vector and print
        int prints = 0, val = 0;
        while(prints < dnas.size()){
            for(int i = 0; i < group; i++){
                if(dnas[i].swaps == val){
                    cout << dnas[i].dna << endl;
                    prints++;
                }
            }
            val++;
        }
        if(sets != 0){cout << endl;}
        dnas.clear();
    }
    return 0;
}