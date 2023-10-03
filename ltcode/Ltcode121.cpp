// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxprofit = 0, minprice = 1e9;
        for (int i = 0, size = prices.size(); i < size; i++)
        {
            maxprofit = max(prices[i] - minprice, maxprofit);
            minprice = min(prices[i], minprice);
        }
        return maxprofit;
    }
};
int main(int args, char *argv[])
{
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << solution.maxProfit(prices) << endl;
    prices = {7, 6, 4, 3, 1};
    cout << solution.maxProfit(prices) << endl;
    return 0;
}