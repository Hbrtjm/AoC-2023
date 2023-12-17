#include <iostream>
#include <fstream>
#include <vector>
#include <map>
int solveMap(std::vector<std::string> volcanicMap)
{
    int symmetriesHorizontal = 0, symmetriesVertical = 0;
    std::map<std::string,short> entries;
    std::string vertical;
    bool symmetry;
    std::vector<std::string> verticalMirror;
    for(int i = 0;i < volcanicMap.size();i++)
    {
        //std::cout << volcanicMap[0] << " " << volcanicMap[i] << "\n";
        if(volcanicMap[0]==volcanicMap[i] && i != 0)
        {
            symmetry=true;
            // Check until it breaks, if not, we have a pattern
            for(int j=i;j >= i/2;j--)
            {
                if(volcanicMap[i-j] != volcanicMap[j])
                    symmetry=false;
            }
            if(symmetry)
            {
                symmetriesVertical = (i+1)/2;
                break;
            }
        }
        if(volcanicMap[volcanicMap.size()-1]==volcanicMap[i] && i != volcanicMap.size()-1)
        {
            symmetry=true;
            // Check until it breaks, if not, we have a pattern
            for(int j=0;j < i/2;j++)
            {
                if(volcanicMap[i+j] != volcanicMap[volcanicMap.size()-j-1])
                    symmetry=false;
            }
            if(symmetry)
            {
                symmetriesVertical = (volcanicMap.size()-1)/2+i;
                break;
            }
        }
    }
    if(symmetriesVertical!=0)
    {
        std::cout << symmetriesHorizontal << " " << symmetriesVertical << "\n";
        return symmetriesVertical * 100;
    }
    for(int j = 0;j < volcanicMap[0].length();j++)
    {
        vertical = "";
        for(int i = 0;i < volcanicMap.size();i++)
        {
            vertical = vertical + volcanicMap[i][j];
        }
        verticalMirror.push_back(vertical);
    }
    for(int i = 0;i < verticalMirror.size();i++)
    {
        //std::cout << verticalMirror[0] << " " << verticalMirror[i] << "\n";
        if(verticalMirror[0]==verticalMirror[i] && i != 0)
        {
            symmetry=true;
            for(int j = i;j >= i/2;j--)
            {
                if(verticalMirror[i-j] != verticalMirror[j])
                {
                    symmetry=false;
                }
            }
            if(symmetry)
            {
                symmetriesHorizontal = (i+1)/2+1;
                break;
            }
        }
        //std::cout << verticalMirror[verticalMirror.size()-1] << " " << verticalMirror[i] << "\n";
        if(verticalMirror[verticalMirror.size()-1]==verticalMirror[i] && i != verticalMirror.size()-1)
        {
            symmetry=true;
            for(int j = 0;j <= i/2;j++)
            {
                if(verticalMirror[i+j] != verticalMirror[verticalMirror.size()-j-1])
                {
                    symmetry=false;
                }
            }
            symmetriesHorizontal = (verticalMirror.size()-i)/2+i;
            break;
        }
    }
    std::cout << symmetriesHorizontal << " " << symmetriesVertical << "\n";
    return symmetriesHorizontal;
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
