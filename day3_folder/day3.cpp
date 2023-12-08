#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

bool number(char a)
{
	return a >= '0' && a <= '9';
}

bool valid(int a,int n)
{
        return a < n && a >= 0;
}

int scan(int x, int y,vector<string> engine)
{
	int left = 0,placement = y,ans = 0;
	ans = engine[x][y] - '0';
	left++;
	while(number(engine[x][placement+1]))
	{
		if(!valid(placement++,engine[x].length()))
			break;
		left++;
		ans *= 10;
		ans += engine[x][placement] - '0';
	}
	while(number(engine[x][y-1]))
	{
		if(!valid(y--,engine[x].length()))
			break;
		ans += (engine[x][y] - '0') * pow(10,left);
		left++;
	}
	return ans;
}

int solve_1(vector<string> engine)
{
	bool to_scan = true;
	int ans = 0,number_of_ratios = 0,ans_ratio = 0,ratios[8] = {1,0,0,0,0,0,0,0};
	for(int i = 0;i < engine.size();i++)
	{
		for(int j = 0;j < engine[i].length();j++)
		{
			if(engine[i][j] != '.')
			{
				if(number(engine[i][j]))
					continue;
				else if(engine[i][j] == '*')
				{
					number_of_ratios = 0;
					for(int o = 0;o < 3;o++)
					{
						for(int p = 0;p < 3;p++)
						{
							if(valid(i+o-1,engine.size()) && valid(j+p-1,engine[i].length()))
							{
								if(!(number(engine[i+o-1][j+p-1])))
								{
									to_scan = true;
								}
								if(to_scan && number(engine[i+o-1][j+p-1]))
								{
									if(ratios[number_of_ratios])
										number_of_ratios++;
									ratios[number_of_ratios] = scan(i+o-1,j+p-1,engine);
									to_scan = false;
									cout << scan(i+o-1,j+p-1,engine) << " " << i+o-1 << " " << j+p-1 << "\n";
									ans += scan(i+o-1,j+p-1,engine);
								}
							}
						}
						to_scan = true;
					}
					cout << "dsadasdS" << number_of_ratios << "\n";
					if(number_of_ratios == 2)
					{
						cout << ratios[1] << " " << ratios[2] << "\n";
						ans_ratio += ratios[1] * ratios[2];
					}
				}
			}
		}
	}
	return ans_ratio;
}

int main()
{	
	string s;
	vector<string> engine;
	ifstream in("infile32.txt");
	while(in >> s)
	{
		engine.push_back(s);
	}
	cout << solve_1(engine) << "\n";
	return 0;
}
