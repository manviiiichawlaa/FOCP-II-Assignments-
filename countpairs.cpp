#include <iostream>
using namespace std;

const int MAXN = 10000000;

int spf[MAXN + 1];        // smallest prime factor
int distinctPF[MAXN + 1]; // number of distinct prime factors

void sieve() {
    // initialize spf
    for (int i = 1; i <= MAXN; i++) {
        spf[i] = i;
    }

    // sieve for smallest prime factor
    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    distinctPF[1] = 0;

    // count distinct prime factors
    for (int i = 2; i <= MAXN; i++) {
        int x = i;
        int prev = -1;
        int count = 0;

        while (x > 1) {
            int p = spf[x];
            if (p != prev) count++;
            prev = p;
            x /= p;
        }

        distinctPF[i] = count;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int k = distinctPF[n];
        cout << (1 << k) << "\n"; // 2^k
    }

    return 0;
}