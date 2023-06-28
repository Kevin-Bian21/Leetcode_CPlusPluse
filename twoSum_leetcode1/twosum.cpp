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
    map<int, int> table;  //ʹ��map���洢�Ѿ����ʹ���Ԫ��
    for (int i = 0; i < nums.size(); i++) {
        //map���Ƿ���� data = target-nums[i] ��data����
        map<int, int>::iterator it = table.find(target - nums[i]);
        //������ڣ����䷵�أ����ﲻ���۷���˳��
        if (it != table.end()) {
            return vector<int>{it->second, i};
        }
        //���û�ҵ�һ��ֵ����target-nums[i]���򽫸�Ԫ�ط���map�ļ��У���������������map��ֵ��
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
