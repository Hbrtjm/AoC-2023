#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

long long solve(std::string springs,std::vector<int> brokenInfo,int brokenSum,int currentSpring = 0,int currentInfo = 0,bool insideOfPlacement = false)
{
    int answer = 0;
    if(brokenSum == 0)
    {
        return 1;
    }
    for(int i = currentSpring;i < brokenInfo.size();i++)
    {
        if(springs[i] == '#')
        {
            insideOfPlacement = true;
            if(brokenInfo[currentInfo] == 0)
                currentInfo++;
            brokenInfo[currentInfo]--;
            brokenSum--;
        }
        else if(springs[i] == '.' && insideOfPlacement)
        {
            currentInfo++;
            insideOfPlacement = false;
        }
        else if(springs[i] == '?')
        {
            insideOfPlacement = true;
            if(brokenInfo[currentInfo] == 0)
                currentInfo++;
            // Here we place .
            answer += solve(springs,brokenInfo,brokenSum,i+1,currentInfo,insideOfPlacement);
            // Here we place #
            brokenInfo[currentInfo]--;
            if(brokenInfo[currentInfo] == 0)
                currentInfo++;
            answer += solve(springs,brokenInfo,brokenSum-1,i+1,currentInfo,1+insideOfPlacement);
        }
    }
    if(brokenSum == 0)
    {
        answer++;
    }
    return answer;
}

int main()
{
    int brokenSum = 0;
    long long answer = 0;
    std::string line,springs,broken,number;
    std::ifstream in("infile12.txt");
    std::vector<int> brokenInfo;
    while(in >> springs >> broken)
    {
        std::cout << springs << broken << "\n";
        std::stringstream commaSeparator(broken);
        while(getline(commaSeparator,number,','))
        {
            brokenSum += std::stoi(number);
            brokenInfo.push_back(std::stoi(number));
        }
        answer += solve(springs,brokenInfo,brokenSum);
        brokenInfo.clear();
    }
    std::cout << answer;
    return 0;
}
