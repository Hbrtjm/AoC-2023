#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int predict(std::vector<long long> values)
{
	bool allZeroes = false;
	int length = values.size() - 2;
	std::reverse(values.begin(),values.end());
	// Assuming values have at least length of 2
	// std::cout << length << "\n";
	while(!allZeroes && length >= 0)
	{
		allZeroes = true;
		for(int i = 0;i <= length;i++)
		{
			values[i] =  values[i] - values[i+1];
			if(values[i] != 0)
				allZeroes = false;
			std::cout << values[i] << " ";
		}
		std::cout << "\n";
		std::cout << " Current Length: " << length << "\n";	
		length--;
	}
	length++;
	for(int i = 0;length < values.size();length++)
	{
		if(length >= 0)
			values[length] = values[length] - values[length-1];
		// std::cout << " : " << values[length] << " : ";
	}
	// std::cout << " : " << values[length-1] << " : ";
	return values[length-1];
}
int main()
{
	long long answer = 0;
	std::vector<long long> values;
	std::string line,number;
	std::ifstream in("infile9.txt");
	while(getline(in,line))
	{
		std::stringstream lineParser(line);
		while(getline(lineParser,number,' '))
		{
			values.push_back(std::stoi(number));
		}
		
		answer += predict(values);
		values.clear();
	}
	std::cout << answer;
	return 0;
}
