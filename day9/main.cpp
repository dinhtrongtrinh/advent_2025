#include <bits/stdc++.h>
using namespace std;


struct Position{
    long long x;
    long long y;
    bool operator<(const Position& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
    }
};
vector<Position> positions;


void Part_1(){
    // fuck it, brute force 
    unsigned long long largest_area = 0;
    for(int i = 0; i < positions.size(); i++){
        for(int j = i + 1; j < positions.size(); j++){
            // cauculate area
            unsigned long long a = abs(positions[i].x - positions[j].x) + 1;
            unsigned long long b = abs(positions[i].y - positions[j].y) + 1;
            unsigned long long area = a * b;
            largest_area = max(area, largest_area);
        }
    }
    cout << largest_area << '\n'; 
}



int main(){
    ifstream infile("input.txt");
    string line;
    while(getline(infile, line)){
        Position pos;
        sscanf(line.c_str(), "%lld,%lld", &pos.x, &pos.y);
        positions.push_back(pos);
    }
    for(int i = 0; i < positions.size(); i++){
        cout << positions[i].x <<","<<positions[i].y << '\n';
    }
    Part_1();
    return 0;
}