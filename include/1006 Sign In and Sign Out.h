#include "head_def.h"

void func_1006()
{
    // result
    string log_in, log_out;

    // tmp
    int min = 0, max = 235959;

    // cin
    int log_num = -1;
    cin >> log_num;
    for (int i = 0; i < log_num; i++)
    {
        string id, time_in, time_out;
        cin >> id >> time_in >> time_out;
        time_in.erase(remove(time_in.begin(), time_in.end(), ':'), time_in.end());
        time_out.erase(remove(time_out.begin(), time_out.end(), ':'), time_out.end());
        int in = stoi(time_in);
        int out = stoi(time_out);
        if (i == 0)
        {
            log_in = id;
            log_out = id;
            min = in;
            max = out;
        }
        else
        {
            if (in < min)
            {
                min = in;
                log_in = id;
            }
            if (out > max)
            {
                max = out;
                log_out = id;
            }
        }
    }
    cout << log_in << " " << log_out << endl;
}