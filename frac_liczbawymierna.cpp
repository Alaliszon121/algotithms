#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string change(int l, int m) {
    string ans = "";
    long num1 = labs(l), num2 = labs(m);
    long q = num1 / num2;
    long r = num1 % num2;
    ans += to_string(q);
    if (r == 0) return ans;
    ans += '.';
    unordered_map<long, int> mp;
    while (r != 0) {
        if (mp.find(r) != mp.end()) {
            int pos = mp[r];
            ans.insert(pos, "(");
            ans += ')';
            break;
        }
        else {
            mp[r] = ans.length();
            r *= 10;
            q = r / num2;
            r = r % num2;
            ans += to_string(q);
        }
    }
    return ans;
}

int main() {
    int l, m;
    cin >> l >> m;
    string ans = change(l, m);
    cout << ans;
    return 0;
}