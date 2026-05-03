#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string replaceName(string roast, string name) {
    size_t pos = roast.find("{name}");
    while (pos != string::npos) {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}");
    }
    return roast;
}

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "Please enter a valid name!" << endl;
        return 0;
    }

    vector<string> roasts = {
        "{name} writes code so slow even a turtle got promoted.",
        "If laziness had a CEO, it would be {name}.",
        "{name}'s debugging style is just staring at the screen.",
        "{name} doesn't fix bugs, they adopt them.",
        "{name}'s code has more issues than a soap opera.",
        "{name} thinks 'Ctrl+C' is coding.",
        "{name} writes code like it's a horror story.",
        "{name}'s logic disappeared like my motivation.",
        "{name} opens IDE just to stare at it.",
        "{name} compiles code and prays for miracles."
    };

    srand(time(0));

    
    int index = rand() % roasts.size();

    string finalRoast = replaceName(roasts[index], name);

    cout << "\n🔥 Roast: " << finalRoast << endl;

    return 0;
}