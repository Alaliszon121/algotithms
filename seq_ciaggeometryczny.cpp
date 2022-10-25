#include <iostream>

using namespace std;

int ciag(double* arr) {
    int l = 1, lM = 1;
    double q = 0;
    for (int i = 0; i < sizeof(*arr); ++i) {
        q = *(arr + i + 1) / *(arr + i);
        if (*(arr + i + 2) / *(arr + i + 1) == q) {
            l++;
            if (lM < l) {
                lM = l;
            }
        }
        else {
            l = 1;
        }
    }
    return lM + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l1, l2, res;
    cin >> n;

    double* tab;
    tab = (double*)calloc(n, sizeof(double));
    for (int i = 0; i < n; ++i) {
        cin >> l1 >> l2;
        double item = (double)l1 / (double)l2;
        *(tab + i) = item;
    }
    res = ciag(tab);
    free(tab);
    if (res > 2) {
        cout << res;
    }
    else {
        cout << "BRAK";
    }
    return 0;
}