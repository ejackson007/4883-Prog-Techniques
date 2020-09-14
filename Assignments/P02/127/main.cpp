#include <iostream>
#include <vector>
#include <string>

#define endl '\n'

using namespace std;

int main()
{
    vector<vector<string> > deck(52);
    string card;
    bool run = true;

    //while not eof
    while(run){
        //cin second half of cards
        for(int i = 0; i < 52; i++){
            cin >> card;
            if(card == "#"){
                run = false;
                i = 52;
            }
            else
                deck[i].push_back(card);
            
        }
        if(!run)
            break;
        //for cards in deck
        for(int i = 1; i < deck.size(); i++){
            //prioritize left most move
            if(i > 2 && (deck[i].back().at(0) == deck[i-3].back().at(0) ||
            deck[i].back().at(1) == deck[i-3].back().at(1))){
                deck[i-3].push_back(deck[i].back());
                deck[i].pop_back();
                if(deck[i].empty())
                    deck.erase(deck.begin() + i, deck.begin() + (i+1));
                i -= 4;
            }
            if(i > 0 && (deck[i].back().at(0) == deck[i-1].back().at(0) ||
            deck[i].back().at(1) == deck[i-1].back().at(1))){
                deck[i-1].push_back(deck[i].back());
                deck[i].pop_back();
                if(deck[i].empty())
                    deck.erase(deck.begin() + i, deck.begin() + (i+1));
                i -= 2;
            }
        }
        if(deck.size() == 1)
            cout << "1 pile remaining: 52\n";
        else{
            cout << deck.size() << " piles remaining:";
            for(int i = 0; i < deck.size(); i++)
                cout << " " << deck[i].size();
            cout << endl;
        }
        //prepare for next time
        deck.clear();
        deck.resize(52);
    }
    return 0;
}