#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cstring>

#define MAX 10
using namespace std;
    int minSteps(string s, string t) {
        unordered_map<char,int>m;
        int sum=0;
        for(auto i:s)
            m[i]++;
        for(auto i:t)
            m[i]--;
        for(auto i:m){
            if(i.second<0)
                sum += i.second;
        }
        return abs(sum);
   }
int min_steps(string s, string t)
{
	unordered_map<char, int> mp;
	for (auto i:s) {
		mp[i]++;
	}
	for (auto itr: mp) 
		cout << itr.first <<  " " ;
	cout << endl;
	for (auto itr: mp) {
		cout << itr.second << " ";
	}
	for (auto i:t) {
		mp[i]--;
	}
	cout << endl;
	for (auto itr: mp) 
		cout << itr.first <<  " " ;
	cout << endl;
	for (auto itr: mp) {
		cout << itr.second << " ";
	}
	int steps = 0;
	for (auto itr : mp) {
		if (itr.second < 0) {
			steps +=itr.second;
		}
	}
	return abs(steps);
}
int main()
{
	string s = "leetcode";
	string t = "practice";
	int steps = min_steps(s, t);
	cout << " steps = " << steps << endl;
	return 0;
}
