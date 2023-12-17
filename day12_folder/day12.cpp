#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

long long solve(std::string springs,std::vector<int> brokenInfo,int brokenSum,int currentSpring = 0,int currentInfo = 0)
{
    int answer = 0;
    if(brokenSum == 0)
    {
        return 1;
    }
    for(int i = 0;i < brokenInfo.size();i++)
    {

    }
    return answer = 0;
}

int main()
{
    int brokenSum = 0;
    long long answer = 0;
    std::string line,springs,broken,number;
    std::ifstream in("infile12.txt");
    std::vector<int> brokenInfo;
    while(getline(in,line))
    {
        std::stringstream spaceSeparator(line);
        spaceSeparator >> springs >> broken;
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
