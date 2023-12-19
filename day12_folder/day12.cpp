#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

long long solve(std::string springs,std::vector<int> brokenInfo,int brokenSum,int currentSpring = 0,int currentInfo = 0,bool insideOfPlacement = false)
{
    int answer = 0;
    std::cout << currentSpring << " " << currentInfo << " " << insideOfPlacement << " ";
    // Checking if recursively data makes sense

    if(currentSpring >= springs.length() || currentInfo >= brokenInfo.size())
    {
        return 0;
    }
    if(brokenInfo[currentInfo] < 0)
    {
        return 0;
    }
    if(currentSpring > 1000 + springs.length())
    for(int i = 0;i < brokenInfo.size();i++)
    {
        if(brokenInfo[i] != 0)
            return 0;
    }

    // If everything works and sum is 0, means that we fould a possibility

    if(brokenSum == 0)
    {
        return 1;
    }
    while(currentSpring < springs.length())
    {
        if(springs[currentSpring]=='?')
        {
            break;
        }
        if(springs[currentSpring] == '#')
        {
            insideOfPlacement = true;
            brokenInfo[currentInfo]--;
            if(brokenInfo[currentInfo] < 0)
            {
                return 0;
            }
            brokenSum--;
        }
        else if(springs[currentSpring] == '.' && insideOfPlacement)
        {
            currentInfo++;
            insideOfPlacement = false;
        }
        currentSpring++;
    }

    // After going through the list until the first '?', check if everything make sense

    if(currentSpring >= springs.length() || currentInfo >= brokenInfo.size())
    {
        return 0;
    }

    // That shouldn't happen, but could be the case when test case is broken

    if(brokenInfo[currentInfo] < 0)
    {
        return 0;
    }

    // Analyzing the possibilities

    bool moved = false;
    if (springs[currentSpring] == '?' && brokenInfo[currentInfo] >= 0)
    {
        if(insideOfPlacement)
        {
            currentInfo++;
            insideOfPlacement = false;
            moved = true;
        }
        springs[currentSpring] = '.';
        // Here we place .
        answer += solve(springs,brokenInfo,brokenSum,currentSpring+1,currentInfo,insideOfPlacement);
        // Here we place #
        if(moved)
        {
            currentInfo--;
        }
        std::cout << " Dot done \n ";
        if(brokenInfo[currentInfo] > 0)
        {
            insideOfPlacement = true;
            springs[currentSpring] = '#';
            brokenInfo[currentInfo]--;
            answer += solve(springs,brokenInfo,brokenSum-1,currentSpring+1,currentInfo,insideOfPlacement);
        }
        springs[currentSpring] = '?';
        std::cout << " Hash Done \n";
    }
    if(currentSpring >= springs.length() || currentInfo >= brokenInfo.size())
    {
        return 0;
    }
    if(brokenInfo[currentInfo] < 0)
    {
        return 0;
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
        brokenSum = 0;
        brokenInfo.clear();
        std::cout << springs << broken << "\n";
        std::stringstream commaSeparator(broken);
        while(getline(commaSeparator,number,','))
        {
            brokenSum += std::stoi(number);
            brokenInfo.push_back(std::stoi(number));
        }
        answer += solve(springs,brokenInfo,brokenSum);
    }
    std::cout << answer;
    return 0;
}


