#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s = "2016-09-15 01:00:04.002 2.0s";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ':' || s[i] == '-')
        {
            s[i] = ' ';
        }
    }

    double num = 0;

    stringstream stream1;

    stream1.str(s);

    while (stream1 >> num)
    {
        cout << "num : " << num << endl;
    }

    return 0;
}