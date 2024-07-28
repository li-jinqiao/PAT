#include "head_def.h"

/*
* 5 6 0 2
* 1 2 1 5 3
* 0 1 1
* 0 2 2
* 0 3 1
* 1 2 1
* 2 4 1
* 3 4 1
*/

map<int, int> city_teamcount_map;
map<pair<int, int>, int> road_length_map;
vector<vector<int>> path_vec;

void lengthFromA2B(int A, int B, vector<vector<int>>& path_vec)
{
	if (A == B)
		return;
	bool del = true;
	for (const auto& p : road_length_map)
	{
		if (p.first.first == A)
		{
			del = false;
			bool exist = false;
			for (auto& path : path_vec)
			{
				if (*path.rbegin() == A)
				{
					exist = true;
					path.push_back(p.first.second);
					lengthFromA2B(p.first.second, B, path_vec);
				}
			}
			if (!exist)
			{
				path_vec.push_back({ p.first.first,p.first.second });
				lengthFromA2B(p.first.second, B, path_vec);
			}
		}
	}
	if (del)
	{
		for (auto it = path_vec.begin(); it != path_vec.end();)
		{
			if (*it->rbegin() == A)
				it = path_vec.erase(it);
			else
				it++;
		}
	}
}

void func_1003()
{
	int city_count = -1, road_count = -1, cur_city_idx = -1, dest_city_idx = -1;
	cin >> city_count >> road_count >> cur_city_idx >> dest_city_idx;

	for (int i = 0; i < city_count; i++)
	{
		int team_count = -1;
		cin >> team_count;
		city_teamcount_map[i] = team_count;
	}

	int min_length = 0;
	for (int i = 0; i < road_count; i++)
	{
		int city_1 = -1, city_2 = -1, length = -1;
		cin >> city_1 >> city_2 >> length;
		min_length += length;
		road_length_map[{city_1, city_2}] = length;
	}

	lengthFromA2B(cur_city_idx, dest_city_idx, path_vec);

	int method_count = 0, max_teams = 0;
	for (const auto& path : path_vec)
	{
		int len_sum = 0;
		int teams = 0;
		for (int i = 0; i < path.size() - 1; i++)
		{
			len_sum += road_length_map[{path[i], path[i + 1]}];
			teams += city_teamcount_map[i];
			if (i == path.size() - 2)
				teams += city_teamcount_map[i + 1];
		}
		if (len_sum < min_length)
		{
			min_length = len_sum;
			method_count = 1;
			max_teams = teams;
		}
		else if (len_sum == min_length)
		{
			method_count++;
			max_teams = max_teams < teams ? teams : max_teams;
		}
	}

	cout << method_count << " " << max_teams;
}