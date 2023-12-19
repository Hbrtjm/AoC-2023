#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

int solveDynamic(std::vector<std::string> cityMap)
{
    int dynamicTable[cityMap.size()][cityMap[0].size()]; // = {{INT_MAX}};
    for(int i = 0;i < cityMap.size();i++)
    {
        for(int j = 0;j < cityMap[i].length();j++)
        {
            dynamicTable[i][j] = INT32_MAX; 
        }
    }
    for(int i = 0;i < cityMap.size();i++)
    {
        for(int j = 0;j < cityMap[i].length();j++)
        {
            for(int k = 0;k < 3;k++)
            {
                // Here the previous moves need to be considered
                // We cannot expand beyond 3 moves to the left if they
                // Have already been made, so the condition is to
                if(j+k < cityMap[0].length())
                    dynamicTable[i][j+k] = std::min(dynamicTable[i][j+k],dynamicTable[i][j+k-1]);
                if(i+k < cityMap.size())
                    dynamicTable[i+k][j] = std::min(dynamicTable[i+k-1][j],dynamicTable[i+k][j]);
                if(i-k >= 0)
                    dynamicTable[i-k][j] = std::min(dynamicTable[i-k][j],dynamicTable[i-k+1][j]);
                if(j-k >= 0)
                    dynamicTable[i][j-k] = std::min(dynamicTable[i][j-k],dynamicTable[i][j-k+1]);
            }
        }
    }
    for(int i = 0;i < cityMap.size();i++)
    {
        for(int j = 0;j < cityMap[i].length();j++)
        {
            std::cout << dynamicTable[i][j] << " ";
        }
        std::cout << "\n";
    }
    return dynamicTable[cityMap.size()][cityMap[cityMap.size()-1].length()];
}

int main()
{
    std::string line;
    std::vector<std::string> cityMap;
    std::ifstream in("infile17.txt");
    while(in >> line)
    {
        cityMap.push_back(line);
    }
    std::cout << solveDynamic(cityMap);
    return 0;
}
