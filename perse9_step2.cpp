#include <iostream>
#include <vector>
using namespace std;

vector<string> reading()
{
    std::vector<std::string> v = { 
        "...#........",
        ".###........",
        ".###........",
        "+++++.......",
        "+...+...@@..",
        "+++++...@@..",
        "........@@..",
        "............",
        "............",
        "...&&&&&....",
        ".......&....",
        ".......&...."      
    };
    return v;
}

void print_out(vector<string> res)
{
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
}

vector<char> enemy_list(std::vector<std::string> map)
{
    vector<char> enlist;
    for (int i = 0; i < map.size(); i++)
        for (int j = 0; j < map[i].size(); j++)
        if ( (map[i][j]) != '.')
            {
                bool check = true;
                    for (int k = 0; k < enlist.size(); k++)
                        if ((map[i][j]) == enlist[k])
                            check = false;
                if (check) enlist.push_back(map[i][j]);
            }
    return enlist;
}

vector<vector<vector<int>>> enemy_shape(std::vector<std::string> map, vector<char> elist)
{
    vector<vector<vector<int>>> v = { { {1,2}} };
    return v;
}

vector<int> enemy_box_size( vector<vector<vector<int>>> enemy_shape )
{
    vector<int> v = { 1, 2, 3};
    return v;
}

int main()
{
    vector<string> map = reading();
    print_out(map);
    vector<char> elist = enemy_list(map);
    // vector<char> elist {'+','%','@', '#'};
    vector<vector<vector<int>>> shp = enemy_shape(map, elist);
    vector<int> boxes_size = enemy_box_size( shp );
    // detect and remove from map
    return 0;
}