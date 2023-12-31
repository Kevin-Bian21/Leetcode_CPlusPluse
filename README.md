LeetCode

1. 两数之和: 

   ```
   使用HashMap降低时间复杂度，只做一次循环。
   ```

2. 两数相加

   ```
   链表的反转，需要用到三个指针 pre cur next
   本位和和进位的处理
   ```

3. 无重复字符的最长字串

   ```
   使用滑动窗口，滑动窗口相当于一个队列，将满足的元素入队，将不满足的元素出队。不满足的元素想要出队需要将该元素之前的全都先出队。
   滑动窗口需要用到两个指针，用来窗口的头和尾
   ```

4. 寻找两个正序数组的中位数

   ```
   笨办法：开辟一个可以容纳这两个数组的新数组，将元素按照正序放入，奇数取 num[length / 2],偶数则取 (num[(length/2)-1] +num[length / 2]) / 2
   目前还没研究明白聪明的做法
   ```

5. 最长回文字串

   ```
   笨办法：列出所有的子串，判断是否为回文，记录最长的回文串长度
   新办法：使用中心扩散法，要判断回文长度为奇数还是偶数这两种情况，为奇数则 i = index-1， j = index+1; 为偶数则i=index，j=index+1。index为判断中心。
   ```

6.  N字型变换

   ```
   找规律即可， 例如 numRows 为4的话，则原来字符串中每个字符所对在的行数就为 1234321234，变换过后第一行的元素则是行数为1的所有元素
   ```

7. 反转int整数

   ```
   题目条件要求不能用long，所以要判断溢出需要特殊处理。
   if (num > 214748364 || num == 214748364 && num[i] > 7)
   ```

8. 字符串转换成整数

   ```
   去掉空格 -> 判断正负号 -> 读取数字 -> 遇到非数字或者字符串结尾则结束
   多读几遍题，多测边界值
   ```


10. 正则表达式匹配

    ```
    
    ```

11. 盛最多水的容器

    ```
    方法一：暴力循环，时间复杂度 O(n^2)
    方法二：双指针，i和j分别指向首元素和尾元素，当底的长度确定时，容量的大小只跟最短的高有关。所以判断height[i]和height[j]的大小，那边小则挪动那边的指针。只有挪动高度小的那个指针，后面的面积才可能变大。
    ```

12. 整数转罗马数字

    ```
    方法一：分情况判断每一种情况，尤其是对于4，9，40，90，400，900这种特殊组合的情况
    方法二：对于罗马数字它总共有13种表示形式，只需使用映射关系将这十三种可能和阿拉伯数字的十三种情况相互对应，这样可以减少方法一中的大量判断条件。
    ```

    ```c++
    string rom[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int arr[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    ```


14. 最长公共前缀

    ```
    找到数组中最短的字符串
    遍历数组中的所有字符串对应位置处的字符
    ```

15. 三数之和 

    ```
    本题中强调了需要排除重复的元组，所以不建议使用暴力法，且暴力法容易超时
    排序 + 双指针 + 去重 将时间复杂度降低为O(N^2)  
    ```

17. 电话号码的字母组合

    ```c++
    n个for循环问题（使用回溯法）
    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }
        int digit = digits[index] - '0'; //获取digits在index位置处的数字
        string leeter = phoneStr[digit];
        for (int i = 0; i < leeter.size(); i++) {
            s.push_back(leeter[i]);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }
    ```

18. 四数之和

    ```c++
    排序 + 双指针 + 去重 + 防溢出  将时间复杂度降低为O(N^3)  
    关键去重位置;
    for (int j = i + 1; j < lenght - 2; j++) {
        if (j > i+1 && nums[j] == nums[j - 1]) {  //j > i+1 关键点
            continue;
        }
    }
    ```


19. 删除链表倒数第N个数

    ```
    快慢指针 ， 如果快指针直接走到尾，慢指针还没走，说明要删除的是头节点
    需要注意的是删除的是头节点的情况
    ```


20. 有效的括号

    ```
    用栈进行匹配
    ```

21. 合并两个有序链表

    ```c++
    迭代法和递归法
    //递归算法
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ```

22. 括号生成

    ```c++
    // 回溯递归
    void backTracking(vector<string> &v, string s, int left, int right) {
        //递归出口
        if (left == 0 && right == 0) {
            v.push_back(s);
            return;
        }
        if (left == 0) {
            backTracking(v, s + ")", left, right - 1);
        }
        else if (left == right) {
            backTracking(v, s + "(", left - 1, right);
        }
        else if (left < right) {
            backTracking(v, s + "(", left - 1, right);
            backTracking(v, s + ")", left, right - 1);
        }
    }
    ```

    
