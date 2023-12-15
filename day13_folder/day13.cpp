#include <iostream>
#include <fstream>
#include <vector>
#include <map>
int solveMap(std::vector<std::string> volcanicMap)
{
    int symmetriesHorizontal = 0, symmetriesVertical = 0;
    std::map<std::string,short> entries;
    std::string vertical;
    for(int i = 0;i < volcanicMap.size();i++)
    {
        if(volcanicMap[0]==volcanicMap[i])
        {
            symmetriesVertical = i/2;
            break;
        }
        if(volcanicMap[volcanicMap.size()-1]==volcanicMap[i])
        {
            symmetriesVertical = (volcanicMap.size()-i)/2+i;
            break;
        }
    }
    std::cout << symmetriesHorizontal << " " << symmetriesVertical << "\n";
    return symmetriesHorizontal + symmetriesVertical * 100;
}

int main()
{
    int answer = 0;
    std::ifstream in("infile13.txt");
    std::string line;
    std::vector<std::string> volcanicMap;
    while(std::getline(in,line))
    {
        if(line == "")
        {
            answer += solveMap(volcanicMap);
            for(const std::string& mapLine : volcanicMap)
            {
            //    std::cout << mapLine << "\n";
            }
            //std::cout << "\n";
            volcanicMap.clear();
            continue;
        }
        volcanicMap.push_back(line);
    }
    answer += solveMap(volcanicMap);
    std::cout << answer;
    return 0;
}
