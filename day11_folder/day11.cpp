#include <iostream>
#include <fstream>
#include <vector>

long long solve(std::vector<std::string> sky)
{
	long long answer = 0;
	int counter = 0;
	bool empty = true;
	std::vector< std::pair<int,int> > stars;
	std::pair<int,int> addMap[sky.size()][sky[0].length()] = {std::make_pair(0,0)};
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
                std::cout << stars[stars.size()-1].first << " " << stars[stars.size()-1].second << "\n";
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
    long long expantionValue = 0;
	for(int i = 0;i < stars.size();i++)
	{
		for(int j = i + 1;j < stars.size();j++)
		{
		    //std::cout << i << " " << j << " X diff " << std::abs(stars[i].first - stars[j].first) << " Expand x diff " << std::abs(addMap[stars[i].first][stars[i].second].first - addMap[stars[j].first][stars[j].second].first) << " Y diff " << std::abs(stars[i].second - stars[j].second) << " expand Y diff " << std::abs(addMap[stars[i].first][stars[i].second].second - addMap[stars[j].first][stars[j].second].second) << "\n";
			answer += std::abs(stars[i].first - stars[j].first) + 1000000*std::abs(addMap[stars[i].first][stars[i].second].first - addMap[stars[j].first][stars[j].second].first) + std::abs(stars[i].second - stars[j].second) + std::abs(addMap[stars[i].first][stars[i].second].second - addMap[stars[j].first][stars[j].second].second)*1000000;
            // We already start at the given star, so we don't have to take 2 additional steps we count
            expantionValue += std::abs(addMap[stars[i].first][stars[i].second].first - addMap[stars[j].first][stars[j].second].first) +  std::abs(addMap[stars[i].first][stars[i].second].second - addMap[stars[j].first][stars[j].second].second);
		}
	}
	std::cout << expantionValue << "\n";
	return answer - expantionValue;
}

int main()
{
        std::vector<std::string> sky;
        std::string line;
        std::ifstream in("infile11.txt");
        while(in >> line)
        {
                sky.push_back(line);
                std::cout << sky[sky.size()-1] << "\n";
        }
	std::cout << solve(sky);
	return 0;
}
