#include <iostream>

using namespace std;

bool is_permutation(string s1, string s2);

int main(int argc, char** argv)
{
	string s1 = "abbac";
	string s2 = "bbcaa";
	// string s3 = "a";
	// string s4 = "ab";
	// string s5 = "ba";
	cout << s1 << " | " << s2 << " | " << is_permutation(s1, s2) << endl;
	// cout << s1 << " | " << s3 << " | " << is_permutation(s1, s3) << endl;
	// cout << s4 << " | " << s5 << " | " << is_permutation(s4, s5) << endl;
	return 0;
}

/*
 * 1.2
 * 	Check Permutation:
 * 	Given two strings, write a method to decide if one is a permulation of the other.
 */

bool is_permutation(string s1, string s2)
{
	/*
	 * Hmm.. this might be tricky.
	 * I know one is called a permutation, iff they have the same number of
	 * characters, just rearranged in a different order. (excluding the same)
	 *
	 * So perhaps I just make a frequency map, and check to see if
	 * both string count up to the same frequency?
	 *
	 * (1) Put string s1 and s2 into frequency map O(n+m)
	 * (2) Verify that the two maps have the same frequency O(n*m)
	 * (3) Return true if they're the same
	 *
	 * Idea 2:
	 * 	What if we looked at both strings, and we looked at one character from s1
	 * 	Then we look for that character in s2, if we find it, we 'delete' that letter
	 * 	We repeat until s1 is empty, if s2 is empty, then it is a permutation.
	 * 	Otherwise it isn't a permutation. 
	 *
	 * This idea is better because it has the same runtime, and doesn't use more space.
	 *
	 * And it's a little bit better because we're deleting the string as we go on.
	 * But a simple solution is just to check if every letter in one is within the other. 
	 *
	 *  Memory: Recursive calls on the stack. But essentially O(N)
	 *  Time: O(N^2) 
	 *
	 *  Idea 3:
	 *  	Sort both of the strings O(nlogn) and see if they match up
	 */
	if (s1.size() != s2.size())
	{
		return false;
	}	

	if (s1 == "" && s2 == "")
	{
		return true;
	}	
	else if (s1 == "" && s2 != "")
	{
		return false;
	}	
	else if (s2 == "" && s1 != "")
	{
		return false;
	}
	else
	{
		// Checks if the character is found in any
		char current_char = s1[0];
		size_t index = s2.find(current_char); // Takes O(n) time
	        if(index == string::npos)
		{
			return false;
		}
		// Erases the character from the other string
		string begin_string = s2.substr(0, index);
		string end_string = s2.substr(index + 1);
		string other_string = begin_string + end_string;	

		// Recursive call into the end
		return is_permutation(s1.substr(1), other_string);
	}

	return false;
}
