#include "head_def.h"

void func_1008()
{
    // result
    int sec = 0;

    // cin
    int count = 0;
    vector<int> stop_list;
    cin >> count;
    while (count--)
    {
        int where = 0;
        cin >> where;
        stop_list.push_back(where);
    }

    for (int i = 0; i < stop_list.size(); i++)
    {
        if (i == 0)
            sec += stop_list[i] * 6;
        else
        {
            int time = stop_list[i] > stop_list[i - 1] ? 6 : 4;
            sec += abs(stop_list[i] - stop_list[i - 1]) * time;
        }
    }
    sec += stop_list.size() * 5;
    cout << sec << endl;
}