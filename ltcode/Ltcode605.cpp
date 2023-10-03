// https://leetcode.cn/problems/can-place-flowers
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int actual = 0;
        for (size_t i = 0, size = flowerbed.size(); i < size; i++)
        {
            bool flag = (flowerbed[i] == 0) && (i < 1 || flowerbed[i - 1] == 0) && ((i + 1) >= size || flowerbed[i + 1] == 0);
            if (flag)
            {
                flowerbed[i] = 1;
                actual++;
            }
        }
        return actual >= n;
    }
};
int main(int args, char *argv[])
{
    Solution solution;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    cout << solution.canPlaceFlowers(flowerbed, 1) << endl;
    flowerbed = {1, 0, 0, 0, 1};
    cout << solution.canPlaceFlowers(flowerbed, 2) << endl;
    flowerbed = {1, 0, 0, 0, 0, 0, 1};
    cout << solution.canPlaceFlowers(flowerbed, 2) << endl;
    flowerbed = {1, 0, 0, 0, 1, 0, 0};
    cout << solution.canPlaceFlowers(flowerbed, 2) << endl;
    return 0;
}