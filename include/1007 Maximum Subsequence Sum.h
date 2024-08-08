#include "head_def.h"

void func_1007()
{
    // cin
    int count = 0;
    vector<int> sequence;
    cin >> count;
    bool all_negative = true;
    while (count--)
    {
        int num = 0;
        cin >> num;
        if (num >= 0)
            all_negative = false;
        sequence.push_back(num);
    }

    if (all_negative)
    {
        cout << 0 << " " << sequence[0] << " " << sequence[sequence.size() - 1] << endl;
        return;
    }

    // result
    int max = sequence[0];
    int begin = 0, end = 0;
    int sum = max;
    for (int i = 1, j = 0; i < sequence.size() && j <= i; i++)
    {
        sum += sequence[i];
        if (sequence[i] > sum)
        {
            j = i;
            sum = sequence[i];
        }
        if (sum > max)
        {
            begin = j;
            end = i;
            max = sum;
        }
    }
    cout << max << " " << sequence[begin] << " " << sequence[end] << endl;
}