#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

int main(void)
{
    int m, n;
    double num;

    while (cin >> m >> n >> num)
    {
        if (m == 0 && n == 0)
            cout << 0 << endl;
        else
        {
            cout << setw(m) << setfill('0') << int(num);
            if (n != 0)
            {
                ostringstream os;
                os << setiosflags(ios_base::fixed);
                os << fixed << setprecision(n+1) << num - int(num);
                os << setiosflags(ios_base::fixed);
                string str = os.str();
                for (int i = 1; i <= n+1; i++)
                    cout << str[i];
            }
            cout << endl;
        }
    }

    return 0;
}