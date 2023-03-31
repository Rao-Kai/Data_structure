//
// Created by KAI on 2023/3/30.
//
#include<iostream>
using namespace std;
#include "vector"
#include<map>
#include<unordered_map>

class Solution {
private:
// unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;
    //用bool是因为只需要找到一个行程就可以返回
    bool backtracking(int ticketNum, vector<string>& result) {
        if (result.size() == ticketNum + 1) {
            return true;
        }
        //这种循环的写法意思就是对targets中每个pair<const string, int>结构进行循环查找
        for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
            if (target.second > 0 ) { // 记录到达机场是否飞过了
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        vector<string> result;
        //这种循环的写法意思就是对tickets中每个vector<string>结构进行循环查找
        for (const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++; // 记录映射关系
        }
        result.push_back("JFK"); // 起始机场
        backtracking(tickets.size(), result);
        return result;
    }
};

int main(){
    vector<string> v1;
    v1.push_back("JFK");
    v1.push_back("KUL");
    vector<string> v2;
    v2.push_back("JFK");
    v2.push_back("NRT");
    vector<string> v3;
    v3.push_back("NRT");
    v3.push_back("JFK");

    vector<vector<string>> tickets;
    tickets.push_back(v1);
    tickets.push_back(v2);
    tickets.push_back(v3);

    Solution s;
    vector<string> res = s.findItinerary(tickets);
    return 0;
}
