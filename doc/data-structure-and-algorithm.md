说明：本文总结C/C++后端服务器开发的知识点。每个点遵循3w2h（what where why how）。 

## 数据结构与算法 ##

##第一部分：基础知识##

1.快排的思想？

答：

2.实现快排？

答:

	int partion(vector<int> &arr, int start, int end)
	{
		if (end - start < 1) return start;
		int temp = arr[start];
		int j = start;
		for (int i = start +1; i <= end; i++)
		{
			if (arr[i] < temp)
			{
				j++;
				swap(arr[i], arr[j]);
			}
		}
	 
		swap(arr[start], arr[j]);
		return j;
	}
	void _quickSort(vector<int> &arr, int start, int end)
	{
		if (end - start < 1) return;
		int p = partion(arr, start, end);
		_quickSort(arr, start, p);
		_quickSort(arr, p + 1, end);
		
	}
	void quickSort(vector<int> &arr, int n)
	{
		_quickSort(arr, 0 ,n - 1);
	}

3.快排的时间复杂度分析，怎么优化？

答：

4.怎么判断链表上存在环？

答：快慢指针

5.数组和链表的区别？

答：数组内存空间连续，链表不连续

6.两个栈怎么实现一个队列？

答：一个栈入队，另外一个出对

7.写一个反转链表？

答：pre,cur,next指针

8.怎么按层打印二叉树？

答：使用队列

9.怎么找出数组的第二大数？

答：哈希表

10.怎么找出字符串中不重复的第二个字符？

答：哈希表

11.怎么检测括号的正确性？

答：栈

    class Solution {
    public:
    bool isValid(string s) {
       stack<char> ss;
    for(auto i:s)
    {
    if(i == '(' || i == '[' || i == '{')
    ss.push(i);
    else
    {
    if(ss.empty() || (i == ')' && ss.top() != '(') || (i == ']' && ss.top() != '[') || (i == '}' && ss.top() != '{'))
    return false;
    else ss.pop();
    }
    }
    if(!ss.empty()) return false;
    return true;
    }
    };
    /*
    1.如果为左括号，压入栈
    2.如果为右括号，和栈顶元素比较：（1）栈为空，返回fasle;(2)和栈顶元素不相等，返回false;(3)和栈顶元素不相等,弹出栈顶元素。
    3.循环结束，看栈是否为空？不为空，返回fasle。
    4.跨过以上坎坷，返回true。
    
    */

12.两个队列实现一个栈？

答：总空出来一个队列来存下次操作

13.求链表倒数第k个元素？

答：双指针

14.哈希冲突怎么解决？

答：拉链法

15.“Z”字形打印二叉树？

答：栈/队列

16.实现归并排序？

答：

    void mmerge(vector<int> &arr, int start, int mid, int end)
    {	
    	int i = 0;
    	vector<int> temp;//先将数组复制一份
    	while (i <= end - start)
    	{
    		temp.push_back(arr[i + start]);
    		i++;
    	}
    	for (int i = start, j = 0, k = mid + 1 - start; i <= end; i++)
    	{
    		if (j > mid - start)
    		{
    			arr[i] = temp[k++];
    		}
    		else if(k > end - start)
    		{
    			arr[i] = temp[j++];
    		}
    		else if (temp[j] <= temp[k])
    		{
    			arr[i] = temp[j++];
    		}
    		else
    		{
    			arr[i] = temp[k++];
    		}
    	}
     
    }
     
    void _mergeSort(vector<int> &arr, int start, int end)
    {
    	if (end - start < 1) return;
    	int mid = (end + start) / 2;
    	_mergeSort(arr, start, mid);
    	_mergeSort(arr, mid+1, end);
    	mmerge(arr, start, mid, end);
    }
    void mergeSort(vector<int> &arr, int n)
    {
    	_mergeSort(arr, 0, n - 1);
    }
    

17.实现堆排序？

答：

    void max_heapify(int arr[], int start, int end) {
    //建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { //若子节点指标在范围内才做比较
    if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
    son++;
    if (arr[dad] > arr[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
    return;
    else { //否则交换父子内容再继续子节点和孙节点比较
    swap(arr[dad], arr[son]);
    dad = son;
    son = dad * 2 + 1;
    }
    }
    }
     
    void heap_sort(int arr[], int len) {
    //初始化，i从最後一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--)
    max_heapify(arr, i, len - 1);
    //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
    for (int i = len - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    max_heapify(arr, 0, i - 1);
    }
    }

18.稳定排序有哪些？不稳定的排序有哪些？

答：稳定有冒泡、插入，归并；不稳定有选择、快排

19.最快的排序算法是哪个？

答：不同的场景

20.sort底层使用了什么排序算法？

答：STL的sort算法，数据量大时采用QuickSort快排算法，分段归并排序。一旦分段后的数据量小于某个门槛（16），为避免QuickSort快排的递归调用带来过大的额外负荷，就改用Insertion Sort插入排序。如果递归层次过深，还会改用HeapSort堆排序。

21.反转二叉树？

答：

    class Solution {
    public:
    TreeNode* invertTree(TreeNode* root) {
	    if(root == NULL)
	    	return root;
	    TreeNode* tmp = root->left;
	    root->left = root->right;
	    root->right = tmp;
	    invertTree(root->left);
	    invertTree(root->right);
	    return root;
   	 }
    };
    //非递归
    class Solution {
    public:
    TreeNode* invertTree(TreeNode* root) {
    if(root == NULL) return root;
    queue<TreeNode*>q;//引入队列，使用栈也是一样，无非从右到左交换，不影响最终结果
    q.push(root);
	    while(!q.empty()){
		    TreeNode* p = q.front();
		    q.pop();
		    TreeNode* tmp = p->left;
		    p->left = p->right;
		    p->right = tmp;
		    if(p->left)
		    	q.push(p->left);
		    if(p->right)
		    	q.push(p->right);  
	    }
   		return root;
   	 }
    };


22.合并两个有序的链表？

答：

    class Solution {
    public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL || l2 == NULL)
    	return l1 ? l2 = l1 : l2;
    ListNode *cur = l1->val > l2->val ? l2 : l1;
    if(l1->val >l2->val)
    	l2 = l2->next;
    else
    	l1 = l1->next;
    ListNode *head = cur;
    while(l1 != NULL && l2 != NULL){
	    if(l1->val >l2->val){
	     	cur->next = l2;
	    	l2 = l2->next;
	    }
		else{
	     		cur->next = l1;
	    		l1 = l1->next;
	    	}   
	    cur = cur->next;
	    }
	    if(l1) cur->next = l1;
	    if(l2) cur->next = l2;
	    return head;
	    
	    }
    };

23.求最长不重复字串的长度？

答：

24.求两个字符串的公共字串？

答：

25.斐波那契数列的计算？

答：
    
    int Fibonacci1(int n)
    {
	if (n <= 1)
		return n;
	int last_one = 1;
	int last_two = 0;
	int ret = 0;
	for (int i = 2; i <= n; ++i)
	{
		ret = last_one + last_two;
		last_two = last_one;
		last_one = ret;	 
	}
	return ret;
    }

26.根据二叉树的前序和中序，重建二叉树？

答：

27.求二进制数中1的个数？

答：

    int BinaryBit(int n)
    {
	int cnt = 0;
	unsigned int tmp = 1;
	while (tmp)
	{
		if (n & tmp)
			++cnt;
		tmp <<= 1;
	}
	return cnt;
    }

28.写出pow的实现？

答：

29.实现一个含min的栈，要求时间复杂度位O(1)？

答：

	template<typename T> class minstack {
	public:
		minstack() {}
		~minstack() {}
		void push(const T &val);
		void pop();
		const T& top()const;
		const T& min()const;
		bool empty();
		size_t size();//unsigned int
	private:
		std::stack<T> m_data;
		std::stack<T> m_min;//存放最小值
	};
	template<typename T> void minstack<T>::push(const T &val)
	{
		m_data.push(val);
		if (m_min.empty() || val <= m_min.top())
			m_min.push(val);
		else
			m_min.push(m_min.top());
	}
	template<typename T> void minstack<T>::pop()
	{
		m_data.pop();
		m_min.pop();
	}
	template<typename T> const T& minstack<T>::top()const
	{
		return m_data.top();
	}
	template<typename T> const T& minstack<T>::min()const
	{
		return m_min.top();
	}
	template<typename T> bool minstack<T>::empty()
	{
		return m_data.empty();
	}
	template<typename T> size_t minstack<T>::size()
	{
		return m_data.size();
	}

30.写出序列化和反序列化二叉树的函数？

答：

31.求连续子数组的最大和？

答：

32.1~n整数中1出现的次数？

答：

33.给出mxn的棋盘，从左上角走到右下角，求最大值？

答：

    int MaxGift(std::vector<std::vector<int>> &grid)
    {
	int m = grid.size(), n;
	if (m == 0)
		return 0;
	else
		n = grid[0].size();
	std::vector<std::vector<int>> dp(m, std::vector<int>(n));//m行，n列
	//初值
	dp[0][0] = grid[0][0];
	for (int i = 1; i < m; ++i) dp[i][0] = grid[i][0] + dp[i - 1][0];
	for (int i = 1; i < n; ++i) dp[0][i] = grid[0][i] + dp[0][i - 1];
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			dp[i][j] = grid[i][j] + std::max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	return dp[m - 1][n - 1];
    }

34.第一个只出现一次的字符？

答：

35.二叉树的深度？

答：

    int TreeDepth(TreeNode<int>* root)
    {
		if (root == nullptr)
			return 0;
		return TreeDepth(root->left) > TreeDepth(root->right) ? TreeDepth(root->left) + 1 : TreeDepth(root->right) + 1;
    }


36.二叉搜索树的第k大节点？

答：

    class Solution {
    public:
    int count=0;//计数器  注意设置成全局，避免放入递归调用栈
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL)
            return NULL;
        {
            TreeNode* left=KthNode(pRoot->left,k);
            if(left!=NULL)
                return left;
            count++;
            if(count==k)
                return pRoot;
            TreeNode* right=KthNode(pRoot->right,k);
            if(right!=NULL)
                return right;  
        }
        return NULL;//没有找到，可能是K过大
    } 

};

37.反转字符串？

答：

38.股票的最大利润？

答：

    int MaxProfit(std::vector<int> &prices)
    {
	int ret = 0, buy = INT_MAX;
	for (int i = 0; i < prices.size(); ++i)
	{
		buy = std::min(buy, prices[i]);
		ret = std::max(ret, prices[i] - buy);
	}
	return ret;
    }

39.实现atoi？

答：

40.树中两个节点的最低公共祖先？

答：

41.怎么实现LRU算法？

答：

    class LRUCache {
    public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end())
            return -1;
        l.splice(l.begin(), l , it->second);
        return it->second->second;
        
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end())
        {
            l.erase(it->second);
        }
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if(m.size() > size)
        {
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
        
    }
    int size;
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m;
    };

42.如何根据年龄给100万的员工排序？

答：

43.如何快速找到top10的热门词？

答：

44.红黑树的5个特性？

答：

    （1）每个节点或者是黑色，或者是红色。
    （2）根节点是黑色。
    （3）每个叶子节点（NIL）是黑色。 [注意：这里叶子节点，是指为空(NIL或NULL)的叶子节点！]
    （4）如果一个节点是红色的，则它的子节点必须是黑色的。
    （5）从一个节点到该节点的子孙节点的所有路径上包含相同数目的黑节点。[这里指到叶子节点的路径]

45.红黑树都应用在哪些场景？

答：

46.红黑树的左旋和右旋操作？

答：

47.kmp？

答：

    void cal_next(char *str, int *next, int len)
    {
	    next[0] = -1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
	    int k = -1;//k初始化为-1
	    for (int q = 1; q <= len-1; q++)
	    {
	   	 	while (k > -1 && str[k + 1] != str[q])//如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。
	    	{
	    		k = next[k];//往前回溯
	    	}
		    if (str[k + 1] == str[q])//如果相同，k++
		    {
		    	k = k + 1;
		    }
		    	next[q] = k;//这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]
		    }
    }
    
48.mysql的索引是怎么实现的？

答：

49.布隆过滤器的原理？

答：

50.2亿个整数，怎么快速找到第50大数？

答：针对top K类问题，通常比较好的方案是分治+Trie树/hash+小顶堆（就是上面提到的最小堆），即先将数据集按照Hash方法分解成多个小数据集，然后使用Trie树或者Hash统计每个小数据集中的query词频，之后用小顶堆求出每个数据集中出现频率最高的前K个数，最后在所有top K中求出最终的top K。

51.O(n)时间复杂度找出数组第k大元素？

答：快排思想

52.怎么给URL去重？

答：布隆过滤器

53.万亿级别的两个 URL 文件 A 和 B，如何求出 A 和 B 的差集 C？

答：

54.二叉树给出根节点和目标节点，找出从根节点到目标节点的路径？

答：

    bool specialPath(Node *pRoot,Node *pNode,vector<int> &v)
    {
	if(pRoot==NULL)
	{
		return false;
	}
	v.push_back(pRoot->m_value);
	bool found=false;
	if(pRoot==pNode)//还是比较指针稳妥，节点值有可能重复
	{
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<" ";
		cout<<endl;
		return true;
	}
	if(!found && pRoot->m_pLeft)
	{
		found=specialPath(pRoot->m_pLeft,pNode,v);
	}
 
	//一旦左子树中找到节点，就不需要再遍历右子树
	if(!found && pRoot->m_pRight)
	{
		found=specialPath(pRoot->m_pRight,pNode,v);
	}
	if(!found)
		v.pop_back();
	return found;

##第二部分：编程实战（LeetCode）##

1.反转链表,递归和非递归都需要掌握。(206)[https://leetcode-cn.com/problems/reverse-linked-list/](https://leetcode-cn.com/problems/reverse-linked-list/ "https://leetcode-cn.com/problems/reverse-linked-list/")

2.两两交换链表中的节点。（24）[https://leetcode-cn.com/problems/swap-nodes-in-pairs/](https://leetcode-cn.com/problems/swap-nodes-in-pairs/ "https://leetcode-cn.com/problems/swap-nodes-in-pairs/")

3.给定一个链表，判断链表中是否有环。（141）[https://leetcode-cn.com/problems/linked-list-cycle/](https://leetcode-cn.com/problems/linked-list-cycle/ "https://leetcode-cn.com/problems/linked-list-cycle/")

4.给定一个链表，返回链表开始入环的第一个节点。（142）[https://leetcode-cn.com/problems/linked-list-cycle-ii/](https://leetcode-cn.com/problems/linked-list-cycle-ii/ "https://leetcode-cn.com/problems/linked-list-cycle-ii/")

5.给你一个链表，每 k 个节点一组进行翻转。（25）[https://leetcode-cn.com/problems/reverse-nodes-in-k-group/](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/ "https://leetcode-cn.com/problems/reverse-nodes-in-k-group/")

6.给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。（20）[https://leetcode-cn.com/problems/valid-parentheses/description/](https://leetcode-cn.com/problems/valid-parentheses/description/ "https://leetcode-cn.com/problems/valid-parentheses/description/")

7.用栈实现队列。（232）[https://leetcode-cn.com/problems/implement-queue-using-stacks/description/](https://leetcode-cn.com/problems/implement-queue-using-stacks/description/ "https://leetcode-cn.com/problems/implement-queue-using-stacks/description/")

8.用队列实现栈。（225）[https://leetcode-cn.com/problems/implement-stack-using-queues/description/](https://leetcode-cn.com/problems/implement-stack-using-queues/description/ "https://leetcode-cn.com/problems/implement-stack-using-queues/description/")

9.数据流中的第K大元素。（703）[https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/](https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/ "https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/")

10.滑动窗口最大值。（239）[https://leetcode-cn.com/problems/sliding-window-maximum/](https://leetcode-cn.com/problems/sliding-window-maximum/ "https://leetcode-cn.com/problems/sliding-window-maximum/")

11.有效的字母异位词。（242）[https://leetcode-cn.com/problems/valid-anagram/submissions/](https://leetcode-cn.com/problems/valid-anagram/submissions/ "https://leetcode-cn.com/problems/valid-anagram/submissions/")

12.两数之和。（1）[https://leetcode-cn.com/problems/two-sum/](https://leetcode-cn.com/problems/two-sum/ "https://leetcode-cn.com/problems/two-sum/")

13.三数之和。（15）[https://leetcode-cn.com/problems/3sum/](https://leetcode-cn.com/problems/3sum/ "https://leetcode-cn.com/problems/3sum/")

14.验证二叉搜索树。（98）[https://leetcode-cn.com/problems/validate-binary-search-tree/](https://leetcode-cn.com/problems/validate-binary-search-tree/ "https://leetcode-cn.com/problems/validate-binary-search-tree/")

15.二叉搜索树的最近公共祖先。（235）[https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/ "https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/")

16.二叉树的最近公共祖先。（236）[http://https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/](http://https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/ "https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/")