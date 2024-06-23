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
    v.clear();
    for (int i = 0; i <12; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
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
    vector<vector<vector<int>>> v;
    for (int i =0; i < elist.size(); i++ )
    {
        vector<vector<int>> shp;
            for (int r = 0; r < map.size(); r++ )
                for (int c = 0; c < map.size(); c++ )
                    if ( (map[r][c]) == elist[i])
                    {
                        vector<int> elem {r, c};
                        shp.push_back(elem);
                    }
        v.push_back(shp);
    }
    return v;
}
void printpath(vector<vector<int>> path)
{
    for (int i = 0; i < path.size(); i++)
        cout << path[i][0] <<"-" <<  path[i][1] << "  " ;
    cout << endl;    
}

vector<int> enemy_box_size( vector<vector<vector<int>>> e_shapes )
{
    vector<int> res;
    for (int i = 0; i < e_shapes.size(); i++)
    {
        int r1, r2, c1, c2;
        r1 = e_shapes[i][0][0]; r2 = e_shapes[i][0][0];
        c1 = e_shapes[i][0][1]; c2 = e_shapes[i][0][1];
        for (int j = 1; j < e_shapes[i].size(); j++)
        {
            r1 = ( e_shapes[i][j][0] < r1 ? e_shapes[i][j][0] : r1);
            r2 = ( e_shapes[i][j][0] > r2 ? e_shapes[i][j][0] : r2);
            c1 = ( e_shapes[i][j][1] < c1 ? e_shapes[i][j][1] : c1);
            c2 = ( e_shapes[i][j][1] > c2 ? e_shapes[i][j][1] : c2);
        }
        res.push_back( (r2-r1+1)*(c2-c1+1) );
    }
    return res;
}

int main()
{
    vector<string> map = reading();
    print_out(map);
    vector<char> elist = enemy_list(map);
    // vector<char> elist {'+','%','@', '#'};
    vector<vector<vector<int>>> shp = enemy_shape(map, elist);
    printpath(shp[0]);
    vector<int> boxes_size = enemy_box_size( shp );
    for (auto x : boxes_size)
    cout << " auto " << x ; 
    // detect and remove from map
    for (int i = 0; i < shp.size(); i++)
    {
        // cout << i << " " << shp[i].size() << " " << boxes_size[i] << endl;
        if (shp[i].size() == boxes_size[i])
        {
            for (int k = 0; k < shp[i].size(); k++)
                {
                // cout << "se " <<   shp[i][k][0] << " " <<  shp[i][k][1] << " " << map[shp[i][k][0], shp[i][k][1]] << endl;
                map[ shp[i][k][0] ] [ shp[i][k][1] ] = '.';
                }
        }
    }    
    print_out(map);
    return 0;
}