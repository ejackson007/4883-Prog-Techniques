#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
#define EPS 1e-9
#define PI acos(-1.0)

struct point { double x, y;   // only used if more precision is needed
    point() { x = y = 0.0; }                      // default constructor
    point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
    bool operator == (point other) const {
            return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); 
    } 
};

struct vec { 
    double x, y;  // name: `vec' is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {} 
};



vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; 
}

double angle(point a, point o, point b) {  // returns angle aob in rad
  vec oa = toVec(o, a), ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); 
}

// returns the area, which is half the determinant
double area(const vector<point> &P) {
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size()-1; i++) {
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0; 
}

vector<point> CH(vector<point> P) {   // the content of P may be reshuffled
    int i, j, n = (int)P.size();
    if (n <= 3)
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
    return P;                           // special case, the CH is P itself
}

bool inPolygon(point pt, const vector<point> &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0;    // assume the first vertex is equal to the last vertex
    for (int i = 0; i < (int)P.size()-1; i++) {
        if (ccw(pt, P[i], P[i+1]))
                sum += angle(P[i], pt, P[i+1]);                   // left turn/ccw
        else sum -= angle(P[i], pt, P[i+1]); 
    }                 // right turn/cw
    return fabs(fabs(sum) - 2*PI) < EPS; 
}

int main(){
    vector<vector<point> > kingdoms;
    vector<point> missles;
    int N, x, y;
    double a;
    cin >> N;
    //cin all kingdoms
    do{
        vector<point> k;
        for(int i = 0; i < N; i++){
            cin >> x >> y;
            k.push_back(point(x, y));
        }
        //define kingdom walls
        kingdoms.push_back(CH(k));
        cin >> N;
    }while(N != -1);
    //cin missles
    while(cin >> x >> y){
        missles.push_back(point(x, y));
    }
    //launch missles
    for(int i = 0; i < missles.size(); i++){
        for(int j = 0; j < kingdoms.size(); j++){
            if(inPolygon(missles[i], kingdoms[j])){
                kingdoms.erase(kingdoms.begin() + j); //remove kingdom
            }
        }
    }
    //calculate 
    for(auto &k : kingdoms){
        a += area(k);
    }
    cout << a;
}