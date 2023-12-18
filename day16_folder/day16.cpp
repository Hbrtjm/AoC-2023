#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

struct Beam
{
    int x;
    int y;
    pair<int,int> direction;
};

bool valid(Beam beam, int n,int m)
{
    return ( beam.x + beam.direction.first >= 0 && beam.x + beam.direction.first < n ) && ( beam.y + beam.direction.second >= 0 && beam.y + beam.direction.second < m );
}

Beam move_(Beam beam)
{
    Beam temp;
    temp.x = beam.x + beam.direction.first;
    temp.y = beam.y + beam.direction.second;
    temp.direction = beam.direction;
    return temp;
}

long long solve(std::vector<std::string> mirrors)
{
    bool visited[mirrors.size()][mirrors[0].length()] = {{1}};
    long long answer = 1;
    vector<Beam> beams;
    Beam temp;
    temp.x = 0;
    temp.y = 0;
    temp.direction = std::make_pair(1,0);
    beams.push_back(temp);
    visited[0][0] = 0;
    while(!beams.empty())
    for(int i = 0;i < beams.size();i++)
    {
        switch(mirrors[beams[i].x][beams[i].y])
        {
            case '.':
                if(valid(beams[i],mirrors.size(),mirrors[0].size()))
                {
                    beams[i] = move_(beams[i]);
                    answer += visited[beams[i].x][beams[i].y];
                    visited[beams[i].x][beams[i].y] = 0;
                }
                else
                {
                    beams.erease(beams.begin() + i);
                }
                break;
            case '-':
                if(beams[i].direction.second == 0)
                {
                    if(valid(beams[i],mirrors.size(),mirrors[0].size()))
                    {
                        beams[i] = move_(beams[i]);
                        answer += visited[beams[i].x][beams[i].y];
                        visited[beams[i].x][beams[i].y] = 0;
                    }
                    else
                    {
                        beams.erease(beams.begin() + i);
                    }
                }
                else
                {

                }
                break;
        }
    }
}

int main()
{
    std::string line;
    std::ifstream in("infile16.txt");
    std::vector<std::string> mirrorsLayout;
    while(getline(in,line))
    {
        mirrorsLayout.push_back(line);
    }
    std::cout << solve(mirrorsLayout);
    return 0;
}
