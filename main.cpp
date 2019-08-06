#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

// https://leetcode.com/problems/valid-palindrome-ii/submissions/

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool checkPal(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    bool validPalindrome(string s) {
        bool deleted = false;
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            } else {
                // delete one
                return checkPal(s, i + 1, j) || checkPal(s, i, j - 1);
            }
        }
        return true;
    }
};

void test1() {
    string s = "aba";

    cout << "1 ? " << Solution().validPalindrome(s) << endl;
    s = "abca";
    cout << "1 ? " << Solution().validPalindrome(s) << endl;

}

void test2() {

}

void test3() {

}