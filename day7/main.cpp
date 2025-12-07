#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
set<pair<int, int>> visited;
// S - [0,70]

int start(){
    for(int i = 0; i < grid[0].size(); i++){
        if(grid[0][i] =='S'){
            return i;
        }
    }
    return -1;
}

void BFS_1(){
    int y_start = start();
    int first_x = 0;
    int first_y = y_start;
    for(int i = 1; i < grid.size(); i++){
        if(grid[i][y_start] == '^'){
            first_x = i;
            
            break;
        }
        else{
            grid[i][y_start] = '|';
        }
    }
    queue<pair<int, int>> q;
    q.push({first_x, first_y});
    while(!q.empty()){
        pair<int, int> curr = q.front();
        cout  << "Processing: (" << curr.first << ", " << curr.second << ")\n";
        q.pop();
        int x = curr.second;
        int x_left = -1;
        int x_right = -1;
        if (x > 0){
            x_left = x - 1;
        }
        if (x < grid[0].size() - 1){
            x_right = x + 1;
        }
        int y = curr.first;
        int y_left = y;
        int y_right = y;
        if(visited.find({x, y}) != visited.end()){
            continue;
        }
        else{
            visited.insert({x, y});
        }
        // left beam
        while(y_left >= 0 && y_left < grid.size() && x_left >= 0 ){
            if(grid[y_left][x_left] == '^' || grid[y_left][x_left] == '|'){
                if(grid[y_left][x_left] == '^'){
                    
                    q.push({y_left, x_left});
                }
                break;
            }
            else{
                grid[y_left][x_left] = '|';
                y_left++;
            }
        }
        // right beam
        while(y_right >= 0 && y_right < grid.size() && x_right >= 0 && x_right < grid[0].size()){
            if(grid[y_right][x_right] == '^' || grid[y_right][x_right] == '|'){
                if(grid[y_right][x_right] == '^'){
                    
                    q.push({y_right, x_right});
                }
                break;
            }
            else{
                grid[y_right][x_right] = '|';
                y_right++;
            }
        }
        
    }
        
}
// Předpokládám, že tyto proměnné máš globální nebo ve třídě
vector<vector<char>> grid2;
long long answer_2 = 0; // POZOR: Musí být long long!

void BFS_2() {
    // Mapa: Klíč je {y, x}, Hodnota je počet paprsků (timelines) v tomto bodě
    // Mapa se automaticky řadí podle klíče, tedy primárně podle Y (odshora dolů)
    map<pair<int, int>, long long> active_beams;

    // 1. Najdeme start 'S'
    int start_x = 0, start_y = 0;
    // Najdi S v gridu (zjednodušeně, doplň si svou logiku hledání)
    bool found = false;
    for(int y=0; y<grid2.size(); y++) {
        for(int x=0; x<grid2[0].size(); x++){
            if(grid2[y][x] == 'S') {
                start_x = x; start_y = y; found = true; break;
            }
        }
        if(found) break;
    }

    // Začínáme s jedním paprskem na startu
    active_beams[{start_y, start_x}] = 1;
    answer_2 = 0;

    // 2. Hlavní smyčka
    // Díky mapě bereme vždy ten nejhornější aktivní bod
    while(!active_beams.empty()) {
        // Vezmeme první prvek z mapy (ten s nejmenším Y)
        auto it = active_beams.begin();
        int y = it->first.first;
        int x = it->first.second;
        long long count = it->second;
        
        // Smažeme ho, už ho zpracováváme
        active_beams.erase(it);

        // Simulujeme pád dolů ("Gravity")
        int curr_y = y + 1; // Začneme padat o políčko níž
        bool fell_out = true; // Předpoklad: vypadne ven

        while(curr_y < grid2.size()) {
            char cell = grid2[curr_y][x];

            if (cell == '^') {
                // NÁRAZ NA ROZDĚLOVAČ
                fell_out = false; // Nevypadl ven

                // Paprsek se dělí - přičteme AKTUÁLNÍ POČET (count) k novým pozicím
                // 1. Doleva (na úrovni splitteru)
                if (x - 1 >= 0) {
                    active_beams[{curr_y, x - 1}] += count; 
                }
                // 2. Doprava (na úrovni splitteru)
                if (x + 1 < grid2[0].size()) {
                    active_beams[{curr_y, x + 1}] += count;
                }
                
                // Tady tento konkrétní paprsek končí (jeho energie se rozdělila)
                break; 
            }
            
            // Pokud je to prázdno, padáme dál
            curr_y++;
        }

        // Pokud cyklus doběhl až na konec gridu a nenarazil na ^
        if (fell_out) {
            answer_2 += count;
        }
    }

    cout << "Total timelines (Answer): " << answer_2 << endl;
}




int main() {
    ifstream infile("input.txt");
    string line;
    while (getline(infile, line)) {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        grid.push_back(row);
        grid2.push_back(row);
    }

    //BFS_1();
    BFS_2();
    for (int i = 0; i < grid2.size(); i++) {
        for (int j = 0; j < grid2[0].size(); j++) {
            cout << grid2[i][j];
        }
        cout << endl;
    }

    cout <<"Answer 1: " <<visited.size() << endl;
    cout <<"Answer 2: " << answer_2 << endl;
    return 0;
}