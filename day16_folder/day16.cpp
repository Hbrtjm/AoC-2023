#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

struct Beam
{
    int zeroCounter = 0;
    int x;
    int y;
    std::pair<int,int> direction;
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
    temp.zeroCounter = 0;
    return temp;
}

void printTable(bool table,int width, int length)
{
}

long long solve(std::vector<std::string> mirrors)
{
    bool visited[mirrors.size()][mirrors[0].length()]; // = {{1}};
    for(int i = 0;i < mirrors.size();i++)
    {
        for(int j = 0;j < mirrors[i].length();j++)
        {
            visited[i][j] = 1;
        }
    }
    long long answer = 1,previousAnswer = 0,breakCounter=0;
    std::vector<Beam> beams;
    Beam temp;
    temp.x = 0;
    temp.y = 0;
    temp.direction = std::make_pair(0,1);
    beams.push_back(temp);
    visited[0][0] = 0;
    int i = 0;
    while(!beams.empty())
    {
        // for(int k = 0;k < mirrors.size();k++)
        // {
        //     for(int j = 0;j < mirrors[0].length();j++)
        //     {
        //         std::cout << (visited[k][j] ? '.' : '#');
        //     }
        //     std::cout << "\n";
        // }
        // for(int k = 0;k < mirrors.size();k++)
        // {
        //     for(int j = 0;j < mirrors[0].length();j++)
        //     {
        //         std::cout << mirrors[k][j];
        //     }
        //     std::cout << "\n";
        // }
        if(i >= beams.size())
        {
            if(previousAnswer == answer)
            {
                breakCounter++;
            }
            else
            {
                breakCounter = 0;
            }
            if(breakCounter == mirrors.size())
            {
                break;
            }
            previousAnswer = answer;
            i = 0;
        }
        answer+=visited[beams[i].x][beams[i].y];
        if(visited[beams[i].x][beams[i].y] == 0)
            beams[i].zeroCounter++;
        else
            beams[i].zeroCounter = 0;
        visited[beams[i].x][beams[i].y] = 0;
        std::cout << answer << " " << beams.size() << " " << i << " " << beams[i].x << " " << beams[i].y << " " << beams[i].direction.first << " " << beams[i].direction.second << " " << mirrors[beams[i].x][beams[i].y] << "\n";
        if(beams[i].zeroCounter == std::max(mirrors.size(),mirrors[0].length()))
            beams.erase(beams.begin()+i);
        switch(mirrors[beams[i].x][beams[i].y])
        {
            case '.':
                if(valid(beams[i],mirrors.size(),mirrors[0].size()))
                {
                    beams[i] = move_(beams[i]);
                    answer+=visited[beams[i].x][beams[i].y];
                    visited[beams[i].x][beams[i].y] = 0;
                }
                else
                {
                    beams.erase(beams.begin() + i);
                }
                break;
            case '-':
                if(beams[i].direction.first == 0)
                {
                    if(valid(beams[i],mirrors.size(),mirrors[0].size()))
                    {
                        beams[i] = move_(beams[i]);
                    }
                    else
                    {
                        beams.erase(beams.begin() + i);
                    }
                }
                else
                {
                    Beam temp;
                    temp.x = beams[i].x;
                    temp.y = beams[i].y;
                    temp.direction = std::make_pair(0,-1);
                    temp.zeroCounter = 0;
                    beams.push_back(temp);
                    beams[i].direction = std::make_pair(0,1);                     
                    if(valid(beams[i],mirrors.size(),mirrors[0].length()))
                    {
                        beams[i] = move_(beams[i]);
                    }
                    if(valid(beams[i+1],mirrors.size(),mirrors[0].length()))
                    {
                        beams[i+1] = move_(beams[i+1]);
                    }
                    answer += visited[beams[i].x][beams[i].y] + visited[beams[i+1].x][beams[i+1].y];
                    visited[beams[i].x][beams[i].y] = 0;
                    visited[beams[i+1].x][beams[i+1].y] = 0;
                    i++;
                }
                break;
            case '|':
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
                        beams.erase(beams.begin() + i);
                    }
                }
                else
                {
                    Beam temp;
                    temp.x = beams[i].x;
                    temp.y = beams[i].y;
                    temp.direction = std::make_pair(-1,0);
                    temp.zeroCounter = 0;
                    beams.push_back(temp);
                    beams[i].direction = std::make_pair(1,0);                     
                    if(valid(beams[i],mirrors.size(),mirrors[0].length()))
                    {
                        beams[i] = move_(beams[i]);
                    }
                    if(valid(beams[i+1],mirrors.size(),mirrors[0].length()))
                    {
                        beams[i+1] = move_(beams[i+1]);
                    }
                    answer += visited[beams[i].x][beams[i].y] + visited[beams[i+1].x][beams[i+1].y];
                    visited[beams[i].x][beams[i].y] = 0;
                    visited[beams[i+1].x][beams[i+1].y] = 0;
                    i++;
                }

                break;
            case '\\':
                if(beams[i].direction.second == 0)
                {
                    if(beams[i].direction.first == 1)
                    {
                        beams[i].direction = std::make_pair(0,1);
                    }
                    else
                    {
                        beams[i].direction = std::make_pair(0,-1);
                    }
                }
                else
                {
                    if(beams[i].direction.second == 1)
                    {
                        beams[i].direction = std::make_pair(1,0);
                    }
                    else
                    {
                        beams[i].direction = std::make_pair(-1,0);
                    }
                }
                if(valid(beams[i],mirrors.size(),mirrors[0].length()))
                {
                    beams[i] = move_(beams[i]);
                }
                break;
            case '/':
                if(beams[i].direction.second == 0)
                {
                    if(beams[i].direction.first == 1)
                    {
                        beams[i].direction = std::make_pair(0,-1);
                    }
                    else
                    {
                        beams[i].direction = std::make_pair(0,1);
                    }
                }
                else
                {
                    if(beams[i].direction.second == 1)
                    {
                        beams[i].direction = std::make_pair(-1,0);
                    }
                    else
                    {
                        beams[i].direction = std::make_pair(1,0);
                    }
                }
                if(valid(beams[i],mirrors.size(),mirrors[0].length()))
                {
                    beams[i] = move_(beams[i]);
                }
                break;
        }
        i++;
    }
    return answer;
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
