#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <math.h>


std::string processString(std::string inString)
{
	std::string trimmedString;
	int i = 0;
	while(inString[i] == ' ')
		i++;
	trimmedString = inString.substr(i,inString.length());
	return trimmedString;
}



void solve(std::vector<int> times,std::vector<int> distances)
{
	int possibleTimes = 0,answer = 1;
	for(int i = 0;i < times.size();i++)
	{
		possibleTimes = 0;
		for(int j = 0;j < times[i];j++)
		{
			if((times[i] - j)*j > distances[i])
				possibleTimes++;
		}
		answer *= possibleTimes;
	}
	std::cout << answer << "\n";
}



void solve(long time,long distance)
{
        long possibleTimes = 0,answer = 1;
        for(long i = 0;i < time;i++)
        {
                if((time - i)*i > distance)
                	possibleTimes++;
        }
        std::cout << possibleTimes;
}

int main()
{
	long time = 0,distance = 0,power = 0; 
	std::vector< int > times,distances;
	std::string line;
	std::ifstream in("infile6.txt");
	getline(in,line,'\n');
	std::stringstream lineProcess(line);
	getline(lineProcess,line,' ');
	while(getline(lineProcess,line,' '))
	{
		if(!isalnum(line[0]))
		       continue;	
		times.push_back(std::stoi(line));
		power = line.length();
		time = time*std::pow(10,power) + std::stoi(line); 
	}
	power = 0;
	getline(in,line,'\n');
	std::stringstream secondLineProcess(line);
	getline(secondLineProcess,line,' ');
        while(getline(secondLineProcess,line,' '))
	{
		if(!isalnum(line[0]))
			continue;
                distances.push_back(std::stoi(line));
        	power = line.length();
		distance = distance*std::pow(10,power) + std::stoi(line);
	}
	solve(times,distances);
	std::cout << time << " " << distance << " ";
	solve(time,distance);
	return 0;
}
