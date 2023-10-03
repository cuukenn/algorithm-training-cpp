// https://leetcode.cn/problems/reverse-string-ii/description/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0, size = s.length(), k2 = k << 1; i < size; i += k2)
        {
            reverseStr(s, i, min(i + k - 1, size - 1));
        }
        return s;
    }

private:
    void reverseStr(string &s, int start, int end)
    {
        while (start < end)
        {
            int tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
    }
};
int main(int args, char *argv[])
{
    Solution solution;
    cout << solution.reverseStr("abcdefg", 2) << endl;
    cout << solution.reverseStr("abcd", 2) << endl;
    cout << solution.reverseStr("ab", 3) << endl;
    cout << solution.reverseStr("a", 2) << endl;
    return 0;
}