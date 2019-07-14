#include <vector>
#include <map>

using namespace std;

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> lstResult;
//         vector<int>:: iterator iterBegin = nums.begin();
//         for (vector<int>::iterator iterFirNums = iterBegin; (iterFirNums + 1) != nums.end(); ++iterFirNums)
//         {
//             for (vector<int>::iterator iterSecNums = iterFirNums + 1; iterSecNums != nums.end(); ++iterSecNums)
//             {
//                 if (*iterFirNums + *iterSecNums == target)
//                 {
//                     lstResult.push_back(iterFirNums - iterBegin);
//                     lstResult.push_back(iterSecNums - iterBegin);
//                     return lstResult;
//                 }
//             }
//         }
//         return lstResult;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> lstResult;
        map<int, int> dNums;
        vector<int>::iterator iterBegin = nums.begin();
        for (vector<int>::iterator iterFirNums = iterBegin; iterFirNums != nums.end(); ++iterFirNums)
        {
            int iNowNums = *iterFirNums;
            int iOther = target - iNowNums;
            map<int, int>::iterator iterResult = dNums.find(iOther);
            if (iterResult != dNums.end())
            {
                lstResult.push_back(iterResult->second);
                lstResult.push_back(iterFirNums - iterBegin);
                return lstResult;
            }
            if (dNums.find(iNowNums) != dNums.end())
            {
                continue;
            }
            dNums[iNowNums] = iterFirNums - iterBegin;
        }
        return lstResult;
    }
};
