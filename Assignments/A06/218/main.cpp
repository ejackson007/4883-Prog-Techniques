#include <iostream>
#include <vector>
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
double dist(point p1, point p2) {                // Euclidean distance
    return hypot(p1.x - p2.x, p1.y - p2.y); 
}

vector<point> CH(vector<point> P) {   // the content of P may be reshuffled
    int i, j, n = (int)P.size();
    if (n <= 3)
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
    return P;                           // special case, the CH is P itself
}
double perimeter(const vector<point> &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size()-1; i++)  // remember that P[0] = P[n-1]
        result += dist(P[i], P[i+1]);
    return result; 
}

int main(){
    vector<point> poly;
    int polySize, iterations = 1;
    double x, y, peri;
    cin >> polySize;
    while(polySize != 0){
        poly.resize(polySize);
        for(int i = 0; i < polySize; i++){
            cin >> x >> y; 
            poly[i] = point(x,y);
        }
        cout << poly.size() << endl;
        //define which points are on perimiter. 
        poly = CH(poly); //i think this might not be working
        cout << poly.size() << endl;
        peri = perimeter(poly);
        //print
        printf("Region #%d\n", iterations);
        for (int i = 0; i < poly.size()-1; i++){
            printf("(%f,%f)-", poly[i].x, poly[i].y);
        }
        printf("(%f,%f)\nPerimeter length = %f\n\n", poly.back().x, poly.back().y, peri);
        //get ready for next polygon
        poly.clear();
        iterations++;
        cin >> polySize;
    }
}