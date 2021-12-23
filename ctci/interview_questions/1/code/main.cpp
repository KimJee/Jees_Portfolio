#include <iostream>
#include <string>
#include <unordered_map>

bool solve(std::string s);
bool solve2(std::string s);

int main(int argc, char** argv)
{
	std::string s1 = "Hello World";
	std::string s2 = "Car";
	std::string s3 = "Train";
	std::string s4 = "";


	std::cout << s1 << " | Result: " << solve(s1) << std::endl;
	std::cout << s2 << " | Result: " << solve(s2) << std::endl;
	std::cout << s3 << " | Result: " << solve(s3) << std::endl;
	std::cout << s4 << " | Result: " << solve(s4) << std::endl;


	std::cout << s1 << " | Result: " << solve2(s1) << std::endl;
	std::cout << s2 << " | Result: " << solve2(s2) << std::endl;
	std::cout << s3 << " | Result: " << solve2(s3) << std::endl;
	std::cout << s4 << " | Result: " << solve2(s4) << std::endl;

	return 0;
}

/*
 *	1.1 
 *
 *	Is Unique: Implement an algorithm to determine if a string has all unique characters.
 *	What is you cannot use additional data structures?
 */

bool solve(std::string s)
{
	// Create a hash table
	// Hash each character of the string until we get a collision
	// If there is a collision, then it is not unique
	// Otherwise it is unique
	//
	// Time Complexity: O(n)
	// Space Complexity: O(n)
	
	if (s == "") { return true;}

	std::unordered_map<char, int> freq_map;
	for (int i = 0; i < s.size(); ++i)
	{
		if (freq_map.find(s[i]) == freq_map.end())
		{
			freq_map[s[i]] = 1;
		}
		else
		{
			return false;
		}
	}	
	return true;
}

bool solve2(std::string s)
{
	// The only solution I can think of, if it uses 0 space, is to iterate 
	// --through the entire string and look for a duplicate.
	//
	// Time Complexity O(n^2)
	// Space Complexity O(1)
	if (s == "" || s.size() == 1) {return true;}

	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = i + 1; j < s.size(); ++j)
		{
			if (s[i] == s[j])
			{
				return false;
			}	
		}
	}	
	return true;
}


