#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    vector<int> valid;

    
    for (auto &it : freq) {
        int val = it.first;
        int count = min(2, it.second);
        for (int i = 0; i < count; i++) {
            valid.push_back(val);
        }
    }

    
    sort(valid.rbegin(), valid.rend());

    long long alex = 0, bob = 0;

    for (int i = 0; i < valid.size(); i++) {
        if (i % 2 == 0)
            alex += valid[i];
        else
            bob += valid[i];
    }

    if (alex > bob)
        cout << "Alex\n";
    else
        cout << "Bob\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}