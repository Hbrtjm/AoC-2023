#include <iostream>
#include <fstream>
#include <vector>

long long solve(std::vector<std::string> rocks)
{
    long long answer = 0;
    int placement[rocks.size()]; // = {0};
    for(int i = 0;i < rocks.size();i++)
    {
        placement[i] = 0;
    }
    for(int i = 0;i < rocks.size();i++)
    {
        for(int j = 0;j < rocks[i].length();j++)
        {
            if(rocks[i][j] == 'O')
            {
                answer += rocks.size()-placement[j];
                placement[j] += 1;
                rocks[i][j] = '.';
                std::cout << i << " " << j << " " << placement[j] << "\n";
                rocks[placement[j]-1][j] = 'O';
            }
            if(rocks[i][j] == '#')
            {
                placement[j] = i+1;
            }
        }
    }
    for(std::string line : rocks)
    {
        std::cout << line << "\n";
    }
    return answer;
}

int main()
{
    std::string line;
    std::vector<std::string> rocks;
    std::ifstream in("infile14.txt");
    while(in >> line)
    {
        rocks.push_back(line);
        std::cout << rocks[rocks.size()-1]<<"\n";
    }
    std::cout << solve(rocks);
    return 0;
}
