#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

const struct zero_t {
    int z[0x10000];
    zero_t() {
        for (int i = 1; i < 0x10000; ++i) z[i] = (i & 1) ? 0 : 1 + z[i >> 1];
    }
} trail;
inline bool isprob(unsigned nr, unsigned base) {
    unsigned u = 1, odd = nr - 1, sh = (odd & 0xFFFF)
        ? trail.z[odd & 0xFFFF] : 16 + trail.z[odd >> 16];
    for (odd >>= sh; odd > 0; odd >>= 1) {
        if ((odd & 1)) u = (ull(u) * base) % nr;
        base = (ull(base) * base) % nr;
    }
    if (u == 1) return true;
    while (sh-- > 0) {
        if (u == nr - 1) return true;
        u = (ull(u) * u) % nr;
    }
    return false;
}
bool isprime(unsigned nr) {
    static const unsigned p[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
    for (int i = 0; i < 8; ++i) {
        if (p[i] * p[i] > nr) return nr > 1;
        if (nr % p[i] == 0) return false;
    }
    return isprob(nr, 2) && isprob(nr, 3) && isprob(nr, 5) && isprob(nr, 7) && isprob(nr, 13) && isprob(nr, 17) && isprob(nr, 19) && isprob(nr, 23);
}

bool order(string str)
{
    int temp = 0;

    for (int i = 1; i < str.length(); i++)
    {
        if (str[i - 1] > str[i])
        {
            return false;
        }
    }

    return true;
}

long long range(int a)
{
    long long i = ((long long)a % 9 + 1) * pow(10, ((long long)a / 9)) - 1;
    return i;
}

int sum(string str)
{
    int sum = 0;

    for (int i = 0; i < str.length(); i++)
        sum = sum + str[i] - 48;

    return sum;
}

int count(int n)
{
    unsigned long long a = range(n);
    if (n < 60)
    {
        for (unsigned long long i = a; i < 1844674407370955; i++)
        {
            if (isprime(i))
            {
                string ans = to_string(i);
                if (order(ans))
                {
                    if (sum(ans) == n)
                    {
                        cout << i;
                        return n;
                    }
                }
            }
        }
    }
    else
    {
        for (unsigned long long i = a; i < 1844674407370955; i += 100000)
        {
            if (isprime(i))
            {
                string ans = to_string(i);
                if (order(ans))
                {
                    if (sum(ans) == n)
                    {
                        cout << i;
                        return n;
                    }
                }
            }
        }
    }
    return n;
}

int main() {
    int n;
    cin >> n;

    if (n != 3 && n % 3 == 0)
    {
        cout << "BRAK";
    }
    else
    {
        count(n);
    }

    return 0;
}