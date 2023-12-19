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
            if(i%2!=1)
            {
                symmetry=false;
            }
            // Check until it breaks, if not, we have a pattern
            for(int j=i;j >= (i+1)/2;j--)
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
            if((volcanicMap.size()-1-i)%2!=1)
            {
                symmetry=false;
            }
            // Check until it breaks, if not, we have a pattern
            for(int j=0;j <= (volcanicMap.size()-i)/2;j++)
            {
                if(volcanicMap[i+j] != volcanicMap[volcanicMap.size()-j-1])
                    symmetry=false;
            }
            if(symmetry)
            {
                symmetriesVertical = (volcanicMap.size()-i)/2+i;
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
        //std::cout << i << " " << verticalMirror[0] << " " << verticalMirror[i] << "\n";
        if(verticalMirror[0]==verticalMirror[i] && i != 0)
        {
            symmetry=true;
            if(i%2!=1)
            {
                symmetry = false;
            }
            for(int j = i;j >= (i+1)/2;j--)
            {
            //std::cout << i << " " << verticalMirror[i-j] << " " << verticalMirror[j] << "\n";
                if(verticalMirror[i-j] != verticalMirror[j])
                {
                    symmetry=false;
                }
            }
            if(symmetry)
            {
                symmetriesHorizontal = (i+1)/2;
                break;
            }
        }
        //std::cout << verticalMirror[verticalMirror.size()-1] << " " << verticalMirror[i] << "\n";
        if(verticalMirror[verticalMirror.size()-1]==verticalMirror[i] && i != verticalMirror.size()-1)
        {
            symmetry=true;
            if((verticalMirror.size()-i-1)%2!=1)
            {
                symmetry = false;
            }
            for(int j = 0;j < (verticalMirror.size()-i)/2;j++)
            {
                if(verticalMirror[i+j] != verticalMirror[verticalMirror.size()-j-1])
                {
                    symmetry=false;
                }
            }
            if(symmetry)
            {
            symmetriesHorizontal = (verticalMirror.size()-i)/2+i;
            break;
            }
        }
    }
    std::cout << symmetriesHorizontal << " " << symmetriesVertical << "\n";
    return symmetriesHorizontal;
}

int solveMap2(std::vector<std::string> volcanicMap)
{
    int symmetriesHorizontal = 0, symmetriesVertical = 0;
    std::map<std::string,short> entries;
    std::string vertical;
    bool symmetry,Smudge=false;
    std::vector<std::string> verticalMirror;
    for(int i = 0;i < volcanicMap.size();i++)
    {
        std::cout << volcanicMap[0] << " " << volcanicMap[i] << "\n";
        if(i != 0)
        {
            Smudge=false;
            symmetry=true;
            if(i%2!=1)
            {
                symmetry=false;
            }
            // Check until it breaks, if not, we have a pattern
            for(int j=i;j >= (i+1)/2;j--)
            {
                if(volcanicMap[i-j] != volcanicMap[j])
                {
                    for(int k = 0;k < volcanicMap[j].length();k++)
                    {
                        if(!Smudge && volcanicMap[i-j][k] != volcanicMap[j][k])
                        {
                            Smudge = true;
                        }
                        else if(Smudge && volcanicMap[i-j][k] != volcanicMap[j][k])
                        {
                            symmetry = false;
                            break;
                        }
                    }
                }
                if(!symmetry)
                {
                    break;
                }
            }
            if(symmetry && Smudge)
            {
                std::cout << volcanicMap[0] << " a " << volcanicMap[i] << "\n";
                symmetriesVertical = (i+1)/2;
                break;
            }
        }
        if(i != volcanicMap.size()-1)
        {
            Smudge=false;
            symmetry=true;
            if((volcanicMap.size()-1-i)%2!=1)
            {
                symmetry=false;
            }
            // Check until it breaks, if not, we have a pattern
            std::cout << " J \n";
            for(int j=0;j <= (volcanicMap.size()-i)/2;j++)
            {
                std::cout << volcanicMap[i+j] << " c " << volcanicMap[volcanicMap.size()-j-1] << "\n";
                if(volcanicMap[i+j] != volcanicMap[volcanicMap.size()-j-1])
                {                    
                    for(int k = 0;k < volcanicMap[i+j].length();k++)
                    {
                        std::cout << volcanicMap[i+j][k] << " b " << volcanicMap[volcanicMap.size()-j-1][k] << "\n";
                        if(!Smudge && volcanicMap[i+j][k] != volcanicMap[volcanicMap.size()-j-1][k])
                        {
                            std::cout << "Smudged";
                            Smudge = true;
                        }
                        else if(Smudge && volcanicMap[i+j][k] != volcanicMap[volcanicMap.size()-j-1][k])
                        {
                            std::cout << " Disqualified ";
                            symmetry = false;
                            break;
                        }
                    }  
                    if(!symmetry)
                    {
                        break;
                    }
                }
            }
            if(symmetry && Smudge)
            {

                symmetriesVertical = (volcanicMap.size()-i)/2+i;
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
        std::cout << i << " " << verticalMirror[0] << " " << verticalMirror[i] << "\n";
        if(i != 0)
        {
            Smudge = false;
            symmetry=true;
            if(i%2!=1)
            {
                symmetry = false;
            }
            for(int j = i;j >= (i+1)/2;j--)
            {
            //std::cout << i << " " << verticalMirror[i-j] << " " << verticalMirror[j] << "\n";
                if(verticalMirror[i-j] != verticalMirror[j])
                {
                    for(int k = 0;k < verticalMirror[j].length();k++)
                    {
                        if(!Smudge && verticalMirror[j][k] != verticalMirror[i-j][k])
                        {
                            Smudge = true;
                        }
                        else if(Smudge && verticalMirror[i-j][k] != verticalMirror[j][k])
                        {
                            symmetry = false;
                            break;
                        }
                    }  
                }
            }
            if(symmetry)
            {
                symmetriesHorizontal = (i+1)/2;
                break;
            }
        }
        //std::cout << verticalMirror[verticalMirror.size()-1] << " " << verticalMirror[i] << "\n";
        if(i != verticalMirror.size()-1)
        {
            Smudge = false;
            symmetry=true;
            if((verticalMirror.size()-i-1)%2!=1)
            {
                symmetry = false;
            }
            for(int j = 0;j < (verticalMirror.size()-i)/2;j++)
            {
                if(verticalMirror[i+j] != verticalMirror[verticalMirror.size()-j-1])
                {
                    for(int k = 0;k < verticalMirror[i+j].length();k++)
                    {
                        if(!Smudge && verticalMirror[i+j][k] != verticalMirror[verticalMirror.size()-j-1][k])
                        {
                            Smudge = true;
                        }
                        else if(Smudge && verticalMirror[i+j][k] != verticalMirror[verticalMirror.size()-j-1][k])
                        {
                            symmetry = false;
                            break;
                        }
                    }  
                }
            }
            if(symmetry)
            {
            symmetriesHorizontal = (verticalMirror.size()-i)/2+i;
            break;
            }
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
            answer += solveMap2(volcanicMap);
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
    answer += solveMap2(volcanicMap);
    std::cout << answer;
    return 0;
}
