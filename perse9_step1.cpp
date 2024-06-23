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
}

vector<char> enemy_list(std::vector<std::string> map)
{
    vector<char> enlist;
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
    // vector<char> elist = enemy_list(map);
    vector<char> elist {'+','%','@', '#'};
    vector<vector<vector<int>>> shp = enemy_shape(map, elist);
    vector<int> boxes_size = enemy_box_size( shp );
    // detect and remove from map
    print_out(map);
    return 0;
}