#include<stdio.h>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_map<char, int> lookup; // 记录出现过的字符

        for (int left = 0, right = 0; right < s.length(); ++right) {
            // 如果当前右指针指向的字符出现过，则左指针向右移动
            if (lookup.count(s[right])) {
                left = max(left, lookup[s[right]] + 1); // 左指针向右移动，直接移动到出现过的字符的下一个位置
                                                        // 但是需要避免上一次出现的位置在 left 之前的情况，避免 left 指针回溯
                                                        // 使用 max 函数来确保 left 是不会回溯的
            }
            lookup[s[right]] = right; // 记录当前右指针指向的字符所在的最新的位置
            result = max(result, right - left + 1); // 计算当前子串的长度，也就是右指针减去左指针的长度 + 1
                                                    // max 求历史以来各个子串的最大值
        }
        return result;
    }
};