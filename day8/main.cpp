#include <bits/stdc++.h>
using namespace std;
struct Position{
    unsigned long long x;
    unsigned long long y;
    unsigned long long z;
    bool operator<(const Position& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
};
vector<Position> positions;


void Part1(){
    vector<pair<unsigned long long, pair<Position,Position>>> distance_pairs; 
    
    map<Position, int> postion_on_group;
    vector<set<Position>> connected;


    // cacl the distences
    for(int i = 0; i < positions.size(); i++){
        for(int j = i+1; j < positions.size(); j++){
            long long x = positions[i].x - positions[j].x;
            long long y = positions[i].y - positions[j].y;
            long long z = positions[i].z - positions[j].z;
            // Oprava:
            unsigned long long distSq = (unsigned long long)x*x + (unsigned long long)y*y + (unsigned long long)z*z;
            // Ukládej distSq místo odmocniny
            distance_pairs.push_back({distSq, {positions[i], positions[j]}});
            cout << "Distance between (" << positions[i].x << "," << positions[i].y << "," << positions[i].z << ") and ("
                 << positions[j].x << "," << positions[j].y << "," << positions[j].z << ") is " << distSq << endl;
            
        }
    }
    sort(distance_pairs.begin(), distance_pairs.end());
    for(int i = 0; i < 1000; i++){
        unsigned long long d = distance_pairs[i].first;
        Position p1 = distance_pairs[i].second.first;
        Position p2 = distance_pairs[i].second.second;
        cout << "Processing distance " << d << " between (" << p1.x << "," << p1.y << "," << p1.z << ") and ("
             << p2.x << "," << p2.y << "," << p2.z << ")\n";
        bool found1 = false;
        bool found2 = false;
        if (postion_on_group.find(p1) != postion_on_group.end()){
            found1 = true;
        }
        if (postion_on_group.find(p2) != postion_on_group.end()){
            found2 = true;
        }
        if(found1 && found2){
            int group1 = postion_on_group[p1];
            int group2 = postion_on_group[p2];
            if(group1 != group2){
                //merge groups
                for(Position pos : connected[group2]){
                    connected[group1].insert(pos);
                    postion_on_group[pos] = group1;
                }
                connected[group2].clear();
            }
        } else if(found1 || found2){
            Position existing = found1 ? p1 : p2;
            Position newp = found1 ? p2 : p1;
            int group = postion_on_group[existing];
            connected[group].insert(newp);
            postion_on_group[newp] = group;
        } else {
            //new group
            set<Position> newgroup;
            newgroup.insert(p1);
            newgroup.insert(p2);
            connected.push_back(newgroup);
            int new_group_id = connected.size() - 1; // Bezpečnější než externí počítadlo
            postion_on_group[p1] = new_group_id;
            postion_on_group[p2] = new_group_id;
        }
    }
    vector<unsigned long long> sizes;
    for(set<Position> group : connected){
        cout << "Size of group: " << group.size();
        for(Position pos : group){
            cout << "(" << pos.x << "," << pos.y << "," << pos.z << ") ";
        }
        sizes.push_back(group.size());
        cout << "\n";
    }
    sort(sizes.begin(), sizes.end(), greater<unsigned long long>());
    cout << "Top 3 sizes:\n";
    for(int i = 0; i < 3 && i < sizes.size(); i++){
        cout << sizes[i] << "\n";
    }
    unsigned long long answer = sizes[0] * sizes[1] * sizes[2];
    cout << "Answer: " << answer << "\n";
}
void Part2(){
    vector<pair<unsigned long long, pair<Position,Position>>> distance_pairs; 
    
    map<Position, int> postion_on_group;
    vector<set<Position>> connected;


    // cacl the distences
    for(int i = 0; i < positions.size(); i++){
        for(int j = i+1; j < positions.size(); j++){
            long long x = positions[i].x - positions[j].x;
            long long y = positions[i].y - positions[j].y;
            long long z = positions[i].z - positions[j].z;
            // Oprava:
            unsigned long long distSq = (unsigned long long)x*x + (unsigned long long)y*y + (unsigned long long)z*z;
            // Ukládej distSq místo odmocniny
            distance_pairs.push_back({distSq, {positions[i], positions[j]}});
            cout << "Distance between (" << positions[i].x << "," << positions[i].y << "," << positions[i].z << ") and ("
                 << positions[j].x << "," << positions[j].y << "," << positions[j].z << ") is " << distSq << endl;
            
        }
    }
    int postion_count = positions.size();
    sort(distance_pairs.begin(), distance_pairs.end());
    for(int i = 0; i < distance_pairs.size(); i++){
        unsigned long long d = distance_pairs[i].first;
        Position p1 = distance_pairs[i].second.first;
        Position p2 = distance_pairs[i].second.second;
        cout << "Processing distance " << d << " between (" << p1.x << "," << p1.y << "," << p1.z << ") and ("
             << p2.x << "," << p2.y << "," << p2.z << ")\n";
        bool found1 = false;
        bool found2 = false;
        if (postion_on_group.find(p1) != postion_on_group.end()){
            found1 = true;
        }
        if (postion_on_group.find(p2) != postion_on_group.end()){
            found2 = true;
        }
        if(found1 && found2){
            int group1 = postion_on_group[p1];
            int group2 = postion_on_group[p2];
            if(group1 != group2){
                //merge groups
                for(Position pos : connected[group2]){
                    connected[group1].insert(pos);
                    postion_on_group[pos] = group1;
                }
                connected[group2].clear();
                postion_count -= 1;
            }
        } else if(found1 || found2){
            Position existing = found1 ? p1 : p2;
            Position newp = found1 ? p2 : p1;
            int group = postion_on_group[existing];
            connected[group].insert(newp);
            postion_on_group[newp] = group;
            postion_count -= 1;
        } else {
            //new group
            set<Position> newgroup;
            newgroup.insert(p1);
            newgroup.insert(p2);
            connected.push_back(newgroup);
            int new_group_id = connected.size() - 1; // Bezpečnější než externí počítadlo
            postion_on_group[p1] = new_group_id;
            postion_on_group[p2] = new_group_id;
            postion_count -= 1;
        }
        if(postion_count == 1){
            int x1 = p1.x;
            int x2 = p2.x;
            unsigned long long ans = (unsigned long long)p1.x * (unsigned long long)p2.x;
            cout << "Answer: " << ans << "\n";
            break;
        }

    }
}



int main(){
    ifstream infile("input.txt");
    string line;
    while(getline(infile, line)){
        Position pos;
        sscanf(line.c_str(), "%lld,%lld,%lld", &pos.x, &pos.y, &pos.z);
        positions.push_back(pos);
    }
    //Part1();
    Part2();
    return 0;
}
