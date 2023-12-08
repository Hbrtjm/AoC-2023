#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>

struct line
{
	long firstSet;
	long secondSet;
	long interval;
};

std::vector<long> process(std::vector<line> table, std::vector<long> originals)
{

	for(int i = 0;i < originals.size();i++)
	{
		for(int j = 0;j < table.size();j++)
		{
			//std::cout << "Original " << originals[i] << " " << table[j].secondSet << " " << table[j].secondSet + table[j].interval - 1 << "\n";
			if(table[j].secondSet <= originals[i] && originals[i] <= table[j].secondSet + table[j].interval - 1 )
			{
				std::cout << "Changed: " << originals[i] << " to ";
				originals[i] = (originals[i] - table[j].secondSet) + table[j].firstSet; 
				std::cout << originals[i] << "\n";
				break;
			}
		}
	}
	return originals;
}

bool isChar(char character)
{
	return (('a' <= character && character <= 'z') || ('A' <= character && character <= 'Z') || ('0' <= character && character <= '9'));
}

int main()
{
	long answer = LONG_MAX;
	line singleLine;
	std::vector<line> nums;
	std::vector<long> originals;
	std::string inString,tempString;
	std::ifstream in("infile5.txt");
	getline(in,inString,'\n');
	std::stringstream originalsLine(inString);
	getline(originalsLine,tempString,' ');
	while(getline(originalsLine,tempString,' '))
	{
		originals.push_back(std::stol(tempString));
	}
	while(getline(in,inString,'\n'))
	{
		if(isChar(inString[0]))
		{
			while(getline(in,inString,'\n') && isChar(inString[0]))
			{		

				std::stringstream devided(inString);
				devided >> singleLine.firstSet >> singleLine.secondSet >> singleLine.interval;
				nums.push_back(singleLine);		
			}
			originals = process(nums,originals);
			for(int i = 0;i < 3;i++)
				nums.clear();
		}
		std::cout << "\n";
	}
	for(int i = 0;i < originals.size();i++)
	{
		std::cout << originals[i] << "\n";
		answer = std::min(originals[i],answer);
	}
	std::cout << answer;
	return 0;	
}
