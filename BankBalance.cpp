#include <iostream>
#include <unordered_map>
using namespace std;

class Bank {
private:
    unordered_map<int, long long> accounts; 

public:
    bool create(int userID, long long amount) {
        if (accounts.find(userID) != accounts.end()) {
            
            accounts[userID] += amount;
            return false;
        }
        
        accounts[userID] = amount;
        return true;
    }

    bool debit(int userID, long long amount) {
        if (accounts.find(userID) == accounts.end() || accounts[userID] < amount) {
            return false;
        }
        accounts[userID] -= amount;
        return true;
    }

    bool credit(int userID, long long amount) {
        if (accounts.find(userID) == accounts.end()) {
            return false;
        }
        accounts[userID] += amount;
        return true;
    }

    long long balance(int userID) {
        if (accounts.find(userID) == accounts.end()) {
            return -1;
        }
        return accounts[userID];
    }
};

int main() {
    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.create(X, Y) ? "true" : "false") << "\n";
        } else if (query == "DEBIT") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.debit(X, Y) ? "true" : "false") << "\n";
        } else if (query == "CREDIT") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.credit(X, Y) ? "true" : "false") << "\n";
        } else if (query == "BALANCE") {
            int X;
            cin >> X;
            cout << bank.balance(X) << "\n";
        }
    }

    return 0;
}