#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

string replaceName(string text, string name) {
    size_t pos = text.find("{name}");
    while (pos != string::npos) {
        text.replace(pos, 6, name);
        pos = text.find("{name}");
    }
    return text;
}

int main() {
    string name;

    cout << "🎓 Student Excuse Generator 🎓\n";
    cout << "Enter your name: ";
    getline(cin, name);

  
    if (name.empty()) {
        cout << "⚠️ Name cannot be empty!\n";
        return 0;
    }

   
    srand(time(0));

    vector<string> excuses = {
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",
        "{name} was about to finish the homework when the Wi-Fi suddenly stopped working.",
        "{name} tried finishing the assignment, but the keyboard stopped working.",
        "{name} completed everything, but the file mysteriously got deleted.",
        "{name} was ready to submit, but the system crashed.",
        "{name} lost track of time while helping a friend with studies.",
        "{name} accidentally saved the file in the wrong format.",
        "{name} had a power cut right before submitting the assignment.",
        "{name} was not feeling well and couldn’t complete the work.",
        "{name} forgot to bring the notebook from home.",
        "{name}’s pet walked over the keyboard and messed everything up."
    };

    
    int index = rand() % excuses.size();

    
    string finalExcuse = replaceName(excuses[index], name);

    cout << "\n📢 Your Excuse:\n";
    cout << finalExcuse << endl;

    return 0;
}