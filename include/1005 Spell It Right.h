#include "head_def.h"

void func_1005()
{
    string input;
    cin >> input;

    map<int, string> num_en_map =
        {
            {0, "zero"},
            {1, "one"},
            {2, "two"},
            {3, "three"},
            {4, "four"},
            {5, "five"},
            {6, "six"},
            {7, "seven"},
            {8, "eight"},
            {9, "nine"}};

    int sum = 0;
    for (auto &c : input)
    {
        sum += (int)c - 48;
    }

    vector<string> en_list;

    while (sum)
    {
        en_list.push_back(num_en_map[sum % 10]);
        sum /= 10;
    }

    reverse(en_list.begin(), en_list.end());

    for (int i = 0; i < en_list.size(); i++)
    {
        cout << en_list[i];
        if (i != en_list.size() - 1)
            cout << " ";
    }
    cout << endl;
}