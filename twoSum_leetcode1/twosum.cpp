#include "twosum.h"
#include <map>

std::vector<int> Solution::twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (target - nums[i] == nums[j]) {
                return vector<int>{i, j};
            }
        }
    }
    return vector<int>{ -1, -1};
}

vector<int> Solution::twoSum_map(vector<int>& nums, int target) {
    map<int, int> table;  //使用map来存储已经访问过的元素
    for (int i = 0; i < nums.size(); i++) {
        //map中是否存在 data = target-nums[i] 的data数据
        map<int, int>::iterator it = table.find(target - nums[i]);
        //如果存在，将其返回，这里不讨论返回顺序
        if (it != table.end()) {
            return vector<int>{it->second, i};
        }
        //如果没找到一个值等于target-nums[i]，则将该元素放入map的键中，将它的索引放入map的值中
        table.insert(map<int, int>::value_type(nums[i], i));
    }
    return vector<int> {-1, -1};
}

int main() {
    Solution s;
    vector<int> vec{ 2, 7, 11, 15 };
    vector<int> v;
    v = s.twoSum(vec, 9);
    for (int i : v) {
        cout << i << endl;
    }
};
