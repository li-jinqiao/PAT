#include "head_def.h"

void func_1004()
{
	// 结点数量，非叶结点数量
	int node_count = -1, parent_count = -1;
	cin >> node_count >> parent_count;

	// 非叶结点及其孩子列表的映射
	map<int, vector<int>> par_childs_map;

	// 获取输入
	for (int i = 0; i < parent_count; i++)
	{
		int par_idx = -1, child_count = -1;
		vector<int> vec;

		string _par_id;				
		cin >> _par_id >> child_count;
		par_idx = stoi(_par_id);

		for (int j = 0; j < child_count; j++)
		{
			string c;
			cin >> c;
			vec.push_back(stoi(c));
		}
		par_childs_map[par_idx] = vec;
	}

	// 结果
	vector<int> ret;

	// 广度遍历
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int leaf_count = 0;
		int count = q.size();
		while (count--)
		{
			int node = q.front();
			q.pop();
			if (par_childs_map.find(node) == par_childs_map.end())
				leaf_count++;
			else
			{
				for (auto child : par_childs_map[node])
					q.push(child);
			}
			if (count == 0)
				ret.push_back(leaf_count);
		}
	}

	for (int i = 0; i < ret.size(); i++)
	{
		if (i != ret.size() - 1)
			cout << ret[i] << " ";
		else
			cout << ret[i] << endl;
	}
}
