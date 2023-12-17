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

std::pair<int,int> setStart(std::vector<std::string> pipesLayout,std::pair<int,int> animalPosition)
{
    std::pair<int,int> position;
    bool unsetPosition = true;
    if( unsetPosition && animalPosition.first+1 < pipesLayout.size())
    {
        if(pipesLayout[animalPosition.first+1][animalPosition.second] == '|' || pipesLayout[animalPosition.first+1][animalPosition.second] == 'J' || pipesLayout[animalPosition.first+1][animalPosition.second] == 'L')
        {
            position = std::make_pair(animalPosition.first+1,animalPosition.second);
            unsetPosition = false;
        }
    }
    if(unsetPosition && animalPosition.first - 1 >= 0)
    {
        if(pipesLayout[animalPosition.first - 1][animalPosition.second] == '|' || pipesLayout[animalPosition.first+1][animalPosition.second] == 'F' || pipesLayout[animalPosition.first+1][animalPosition.second] == '7')
        {
            position = std::make_pair(animalPosition.first-1,animalPosition.second);
            unsetPosition = false;
        }
    }
    if( unsetPosition && animalPosition.second+1 < pipesLayout[0].length() )
    {
        if(pipesLayout[animalPosition.first][animalPosition.second+1] == '-' || pipesLayout[animalPosition.first][animalPosition.second+1] == '7' || pipesLayout[animalPosition.first][animalPosition.second+1] == 'J')
        {
            position = std::make_pair(animalPosition.first,animalPosition.second+1);
            unsetPosition = false;
        }
    }
    if(unsetPosition && animalPosition.second - 1 >= 0)
    {
        if(pipesLayout[animalPosition.first][animalPosition.second-1] == '-' || pipesLayout[animalPosition.first][animalPosition.second-1] == 'F' || pipesLayout[animalPosition.first][animalPosition.second-1] == 'L')
        {
            position = std::make_pair(animalPosition.first,animalPosition.second-1);
            unsetPosition = false;
        }
    }
    return position;
}

int solve(std::vector<std::string> pipesLayout)
{
    int inside = 0,insideCounter=0;
    int visited[pipesLayout.size()][pipesLayout[0].length()] = {{0}};
	int counter = 1;
	std::pair<int,int> position,previousPosition;
	std::pair<int,int> animalPosition = localize(pipesLayout);
	previousPosition = animalPosition;
    position = setStart(pipesLayout,animalPosition);
    std::cout << animalPosition.first << " " << animalPosition.second << "\n";
    visited[animalPosition.first][animalPosition.second] = 3;
    std::cout << position.first << " " << position.second << "\n";
	while(position.first != animalPosition.first || position.second != animalPosition.second)
	{
        visited[position.first][position.second] = 3;
	    //std::cout << pipesLayout[position.first][position.second];
        switch(pipesLayout[position.first][position.second])
        {
            case '|':
                visited[position.first][position.second] = 2;
                if(previousPosition.first < position.first)
                {
                    previousPosition = position;
                    position.first++;
                }
                else
                {
                    previousPosition = position;
                    position.first--;
                }
                break;
            case 'J':
                visited[position.first][position.second] = 2;
                if(previousPosition.first < position.first)
                {
                    previousPosition = position;
                    position.second--;
                }
                else
                {
                    previousPosition = position;
                    position.first--;
                }
                break;
            case 'L':
                visited[position.first][position.second] = 2;
                if(previousPosition.first < position.first)
                {
                    previousPosition = position;
                    position.second++;
                }
                else
                {
                    previousPosition = position;
                    position.first--;
                }
                break;
            case 'F':
                if(previousPosition.first > position.first)
                {
                    previousPosition = position;
                    position.second++;
                }
                else
                {
                    previousPosition = position;
                    position.first++;
                }
                break;
            case '7':
                if(previousPosition.first > position.first)
                {
                    previousPosition = position;
                    position.second--;
                }
                else
                {
                    previousPosition = position;
                    position.first++;
                }
                break;
            case '-':
                if(previousPosition.second < position.second)
                {
                    visited[position.first][position.second] = 3;
                    previousPosition = position;
                    position.second++;
                }
                else
                {
                    previousPosition = position;
                    position.second--;
                }
                break;
            default:
                std::cout << "Something went wrong";
                position = animalPosition;
                break;
        }
		counter++;
	}
    for(int i = 0;i < pipesLayout.size();i++)
    {
        inside = 0;
        for(int j = 0;j < pipesLayout[i].length();j++)
        {
            if(visited[i][j] == 2)
            {

                inside++;
            }
            if(visited[i][j] == 0 && inside % 2 == 1)
            {
                insideCounter++;
                visited[i][j] = 1;
            }
            std::cout << visited[i][j];
        }
        std::cout << "\n";
    }
    position = setStart(pipesLayout,animalPosition);
	std::cout << pipesLayout[position.first][position.second] << "\n";
	std::cout << insideCounter << " ";
	return counter/2;
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
