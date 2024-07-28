#include "head_def.h"

/*
* -1000000 9
* -999,991
*/

void func_1001()
{
    int a = 0, b = 0;
    cin >> a >> b;
    int c = a + b;

    if (c == 0)
    {
        cout << '0' << endl;
        return;
    }

    bool is_negative = c < 0;
    c = abs(c);

    string ret;
    int sign = 0;

    while (c)
    {
        if (sign == 3)
        {
            ret.push_back(',');
            sign = 0;
        }
        ret.push_back(c % 10 + 48);
        sign++;
        c /= 10;
    }

    if (is_negative)
        ret.push_back('-');

    reverse(ret.begin(), ret.end());

    cout << ret << endl;
}