#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

std::pair<int,int> localize(std::vector<std::string> pipesLayout)
{
	for(int i = 0;i < pipesLayout.size();i++)
	{
		for(int j = 0;j < pipesLayout[i].length();j++)
		{
			if(pipesLayout[i][j] == 'S')
			{
				return std::make_pair(i,j);
			}
		}
	}
	return std::make_pair(0,0);
}

int solve(std::vector<std::string> pipesLayout)
{
	enum class Pipe {
		Vertical = '|',
		Horizontal = '-',
		BendNE = 'L',
		BendNW = 'J',
		BendSW = '6',
		BendSE = 'F',
	};

	std::unordered_map<Pipe, std::pair<int, int>> pipeTranslations = {
		{Pipe::Vertical, {0, 0}},
		{Pipe::Horizontal, {-1, 1}},
		{Pipe::BendNE, {0, 1}},
		{Pipe::BendNW, {0, -1}},
		{Pipe::BendSW, {-2, -1}},
		{Pipe::BendSE, {-2, 1}},
	};
	int counter = 0;
	std::pair<int,int> positionRight, positionLeft;
	std::pair<int,int> animalPosition = localize(pipesLayout);
	while(positionRight.first != positionLeft.first and positionRight.second != positionLeft.second)
	{
		// Moving part is the most tricky
        // First direction
        case(positionRight)
        {

        }
        // Second direction
        case()
        {

        }
		counter++;
	}
	return counter;
}

int main()
{
	std::vector<std::string> pipesLayout;
	std::string line;
	std::ifstream in("infile10.txt");
	while(in >> line)
	{
		pipesLayout.push_back(line);
	}
	std::cout << solve(pipesLayout);
}
