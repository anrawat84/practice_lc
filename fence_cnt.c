#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
void printmap(unordered_map <int, int> &fc) {
	for (auto itr: fc) {
		cout << itr.first << " " << itr.second << endl;
	}
}

void printv(vector <int> v) {
	cout << "vector =  ";
	for (auto itr: v) {
		cout << itr << "  ";
	}
	cout << endl;
}

int solution(vector<int> &A, int X) {
    if (A.size() < 2) { return 0; }

    // reduce double fences to single array
    std::unordered_map<int, int> fenceCnt;
    for (auto const &a: A) {
        if (fenceCnt.find(a) != fenceCnt.end()) { fenceCnt[a]++; } 
        else { fenceCnt[a] = 1; }
    }
    printmap(fenceCnt);
    vector<int> fence;
    for (auto const &it: fenceCnt) {
        for (int i=0; i<it.second/2; i++) {
            fence.push_back(it.first);
        }
    }
    printv(fence);
    std::sort(fence.begin(), fence.end());

    // count reuseble fence as suffix, e.g., square pen
    int sz = fence.size(); int cntR = 0;
    vector<int> suffixCnt(sz, 0);
    int lastFence = fence[sz-1];
    for (int i=sz-2; i>=0; i--) {
        if (fence[i] == lastFence) { cntR++; }
        suffixCnt[i] = cntR;
        lastFence = fence[i];
    }

    // use BS to find the suitable fence for each
    int ret = 0;
    for (auto it=fence.begin(); it != fence.end(); it++) {
        if ((it != fence.begin()) && (*it == *std::prev(it))) { // skip same length fence
            continue; 
        }
        auto lower = std::lower_bound(std::next(it), fence.end(), (X + *it - 1) / *it);
        if (lower != fence.end()) { // can build area larger than X
            int ind = std::distance(fence.begin(), lower);
            ret += sz - ind - suffixCnt[ind];
            if (ret > 1000000000) { ret = -1; break; }
        }
    }
    return ret;
}

int main()
{
	vector <int> arr = {1,2,5,1,1,2,3,5,1};
//	vector <int> arr = {2,2,2};
	int X = 4;
	int res = solution(arr, X);
	cout << res << endl;
}
