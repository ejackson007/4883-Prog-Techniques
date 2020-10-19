//Railway
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#define point pair<int,int>

using namespace std;

pair<double, double> closestPoint(point a, point b, point p){
    point ap = make_pair(p.first - a.first, p.second - a.second);
    point ab = make_pair(b.first - a.first, b.second - a.second);

    double abSquare = pow(ab.first, 2) + pow(ab.second, 2);
    double dotProd = ap.first * ab.first + ap.second * ab.second;

    double t = dotProd / abSquare;
    return(make_pair(a.first + ab.first*t, a.second + ab.second*t));
}

double distance(point a, point b){
    //pythagorean
    return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

int main(){
    ifstream input;
    input.open("input");


    point M, temp;
    pair<double, double> out;
    int N, closest, dis;
    vector<pair<int, int> > segments;
    while(input >> M.first){
        input >> M.second;
        input >> N;
        for(int i = 0; i < N + 1; i++){
            input >> temp.first >> temp.second;
            segments.push_back(temp);
        }
        // printf("Origin: (%i,%i)\n", M.first, M.second);
        // for(auto a : segments){
        //     printf("(%i,%i)\n", a.first, a.second);
        // }
        // cout << endl;

        //find closest point
        closest = INT_MAX;
        for(int i = 0; i < segments.size(); i++){
            dis = distance(segments[i], M);
            if(dis < closest){
                closest = dis;
            }
        }
        out = closestPoint(segments[closest*2], segments[closest*2 + 1], M);
        cout << out.first << endl << out.second << endl;
        segments.clear();
    }
}