#include <iostream>
#include <fstream>
#include <vector>

long long solve(std::vector<std::string> sky)
{
	long long answer = 0;
	int counter = 0;
	bool empty = true;
	std::vector< std::pair<int,int> > stars;
	std::pair<int,int> addMap[sky.size()][sky[0].length()];
	for(int i = 0;i < sky.size();i++)
	{
		empty = true;
		for(int j = 0;j < sky[i].length();j++)
		{
			addMap[i][j].first = counter;
			if(sky[i][j] != '.')
			{
				empty = false;
				stars.push_back(std::make_pair(i,j));
			}
		}	
		if(empty)
		{
			counter++;
		}
	}
	counter = 0;
        for(int i = 0;i < sky[0].length();i++)
        {
        	empty = true;
		for(int j = 0;j < sky[i].size();j++)
                {
                        if(sky[j][i] != '.')
                        {
				addMap[j][i].second = counter;
                                empty = false;
                        }
                }
		if(empty)
		{
			counter++;
		}
        }
	for(int i = 0;i < stars.size();i++)
	{
		for(int j = i + 1;j < stars.size();j++)
		{
			answer += std::abs(stars[i].first - stars[j].first) + std::abs(addMap[stars[i].first][stars[i].second].first - addMap[stars[j].first][stars[j].second].first) + std::abs(stars[i].second - stars[j].second) + std::abs(addMap[stars[i].first][stars[i].second].second - addMap[stars[j].first][stars[j].second].second);
		}
	}
	return answer;
}

int main()
{
        std::vector<std::string> sky;
        std::string line;
        std::ifstream in("infile11.txt");
        while(in >> line)
        {
                sky.push_back(line);
        }
	std::cout << solve(sky);
}
