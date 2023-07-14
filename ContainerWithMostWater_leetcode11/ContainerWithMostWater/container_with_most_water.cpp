#include "container_with_most_water.h"
#include <vector>
#include <iostream>
using namespace std;

//笨方法：暴力求解
int container_with_most_water::maxArea( vector<int>& height) {
	int max = 0;
	for (int i = 0; i < height.size(); i++)
	{
		for (int j = i+1; j < height.size(); j++)
		{
			int volume = min(height[i], height[j]) * (j - i);
			max = max > volume ? max : volume;
		}
	}
	return max;
}

//新方法：双指针
int container_with_most_water::maxArea(vector<int>& height) {
	int i = 0;
	int j = height.size() - 1;
	int max = 0;
	while (i < j) {
		int volume = min(height[i], height[j]) * (j - i);
		max = max > volume ? max : volume;
		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return max;
}

int main() {
	container_with_most_water obj;
	vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	cout << obj.maxArea(height) << endl;
	return 0;
}
