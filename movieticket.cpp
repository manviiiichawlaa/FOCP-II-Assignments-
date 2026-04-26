#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class MovieTicket {
private:
    unordered_map<int, int> availableTickets;        
    unordered_map<int, unordered_set<int>> bookings; 

public:
    bool book(int customerID, int movieID) {
        
        if (availableTickets.find(movieID) == availableTickets.end()) {
            availableTickets[movieID] = 100;
        }

        
        if (bookings[movieID].count(customerID) || availableTickets[movieID] == 0) {
            return false;
        }

        bookings[movieID].insert(customerID);
        availableTickets[movieID]--;
        return true;
    }

    bool cancel(int customerID, int movieID) {
        
        if (!bookings[movieID].count(customerID)) {
            return false;
        }

        bookings[movieID].erase(customerID);
        availableTickets[movieID]++;
        return true;
    }

    bool isBooked(int customerID, int movieID) {
        return bookings[movieID].count(customerID) > 0;
    }

    int availableTicketsCount(int movieID) {
        if (availableTickets.find(movieID) == availableTickets.end()) {
            return 100;
        }
        return availableTickets[movieID];
    }
};

int main() {
    int Q;
    cin >> Q;

    MovieTicket mt;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.book(X, Y) ? "true" : "false") << "\n";
        } else if (query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.cancel(X, Y) ? "true" : "false") << "\n";
        } else if (query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.isBooked(X, Y) ? "true" : "false") << "\n";
        } else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << mt.availableTicketsCount(Y) << "\n";
        }
    }

    return 0;
}