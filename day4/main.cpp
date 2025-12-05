#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;

bool check_if_can_lift(int x, int y){
    int count = 0;
    if(x > 0){
        if(grid[x - 1][y] =='@'){
            count++;
        }
    }
    if(y >0){
        if(grid[x][y - 1] =='@'){
            count++;
        }
    }
    if(x < grid.size() - 1){
        if(grid[x + 1][y] =='@'){
            count++;
        }
    }
    if(y < grid[0].size() - 1){
        if(grid[x][y + 1] =='@'){
            count++;
        }
    }
    if(x > 0 && y > 0){
        if(grid[x - 1][y - 1] =='@'){
            count++;
        }
    }
    if(x > 0 && y < grid[0].size() - 1){
        if(grid[x - 1][y + 1] =='@'){
            count++;
        }
    }
    if(x < grid.size() - 1 && y > 0){
        if(grid[x + 1][y - 1] =='@'){
            count++;
        }
    }
    if(x < grid.size() - 1 && y < grid[0].size() - 1){
        if(grid[x + 1][y + 1] =='@'){
            count++;
        }
    }
    if(count < 4){
        return true;
    }
    else{
        return false;
    }
}



int main(){
    ifstream infile("input.txt");
    string line;
    while (getline (infile, line)) {
        // Output the text from the file
        vector<char> row;
        for(char c : line){
            row.push_back(c);
        }
        grid.push_back(row);
      }
    int answer1 = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(check_if_can_lift(i, j) && grid[i][j] == '@'){
                answer1++;
            }
        }
        
    }
    int answer2 = 0;
    while(1){
        bool changed = false;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(check_if_can_lift(i, j) && grid[i][j] == '@'){
                    answer2++;
                    grid[i][j] = '.';
                    changed = true;
                }
            }
            
        }
        if(!changed){
            break;
        }
    }
    cout << "Answer 2: " << answer2 << endl;
    cout << "Answer 1: " << answer1 << endl;
    infile.close();

    return 0;
}