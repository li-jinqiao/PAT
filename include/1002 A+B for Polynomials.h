#include "head_def.h"

void func_1002()
{
	int a_size = 0, b_size = 0;
	set<int> s;

	cin >> a_size;
	vector<double> vA(1001, 0);
	vector<int> v1;
	for (int i = 0; i < a_size; i++)
	{
		int pos;
		double val;
		cin >> pos >> val;
		vA[pos] = val;
		v1.push_back(pos);
		s.insert(pos);
	}

	cin >> b_size;
	vector<double> vB(1001, 0);
	vector<int> v2;
	for (int i = 0; i < b_size; i++)
	{
		int pos;
		double val;
		cin >> pos >> val;
		vB[pos] = val;
		v2.push_back(pos);
		s.insert(pos);
	}

	cout << s.size();
	for (int i = 1000; i >= 0; i--)
	{
		double val = 0;
		if (!(count(v1.begin(), v1.end(), i) > 0) && !(count(v2.begin(), v2.end(), i) > 0))
			continue;
		val += vA[i];
		val += vB[i];
		cout << " " << i << " ";
		cout << fixed << setprecision(1) << val;
	}
	cout << endl;
}
