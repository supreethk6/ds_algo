#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

// Map class
class Map {
public:
    const static int mapWidth = 6;
    const static int mapHeight = 5;
    vector<vector<int> > grid = {
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 0 }
    };
};

// Planner class
class Planner : Map {
public:
    int start[2] = { 0, 0 };
    int goal[2] = { mapHeight - 1, mapWidth - 1 };
    int cost = 1;

    string movements_arrows[4] = { "^", "<", "v", ">" };
    vector<vector<int> > movements{
        { -1, 0 },
        { 0, -1 },
        { 1, 0 },
        { 0, 1 }
    };
};

// Template function to print 2D vectors of any type
template <typename T>
void print2DVector(T Vec)
{
    for (int i = 0; i < Vec.size(); ++i) {
        for (int j = 0; j < Vec[0].size(); ++j) {
            cout << Vec[i][j] << ' ';
        }
        cout << endl;
    }
}

/*#### TODO: Code the search function which will generate the expansion list ####*/
// You are only required to print the final triplet values
void search(Map map, Planner planner)
{
    vector<vector<int>> open_list = {{0,0,0}};
    vector<int> cell_picked = {0,0,0};
    vector<vector<int>> finished_list;
    int expansion = 0;
    int x,y; //next coordinates
    
    
    while(!open_list.empty()){
        for(int i = 0; i < planner.movements.size() ; i++ ){
            
            x = cell_picked[1] + planner.movements[i][0];
            y = cell_picked[2] + planner.movements[i][1];
            if(x >= 0 && x <= 4 && y >=0 && y <= 5){
                for(int j = 0; j <finished_list.size(); j++){
                    vector<int> neighbor = {expansion, x, y};
                    if(neighbor != finished_list[j] && map.grid[x][y] !=1 ){
                        open_list.push_back(neighbor);
                    }
                }
            }
        }
        cell_picked = open_list[0];
        open_list.erase(open_list.begin());
        for (int i : cell_picked) {
            cout << i << " ";
        }
        cout << endl;
        if(cell_picked[1] == planner.goal[0] && cell_picked[2]==planner.goal[1]){
            for (int i : cell_picked) {
                cout << i << " ";
            }
            cout << endl;
            break;
        }
        expansion ++;

        finished_list.push_back(cell_picked);
    }
}

int main()
{
    // Instantiate map and planner objects
    Map map;
    Planner planner;

    // Search for the expansions
    search(map, planner);

    return 0;
}
