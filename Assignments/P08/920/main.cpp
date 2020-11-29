#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point{
    int x, y;
};

//Euclidean distance bewtween points

double distance(Point a, Point b){
    return sqrt((double)(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool comparePoint(const Point &a, const Point &b){
    return b.x < a.x;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        int n;
        cin >> n;
        vector<Point> points;
        for (int i = 0; i < n; i++){
            Point temp;
            cin >> temp.x >> temp.y;
            points.push_back(temp);
        }
        //sort points in descending order by x
        sort(points.begin(),points.end(),comparePoint);

        int maxY = 0;
        double length = 0;
        for (int i = 1; i < points.size(); i++){
            if(points[i].y > maxY){
                length += distance(points[i], points[i-1]) * (points[i].y - maxY) / (points[i].y - points[i-1].y);
            }
        }

        cout << setprecision(2) << setiosflags(ios::fixed) << length << endl;
    }
}