#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// Simple frequency counter class
class FrequencyCounter {
public:
    // Load counts from an input file and also write frequency.dat
    bool Load(const string& inputFile, const string& backupFile) {
        ifstream in(inputFile);
        if (!in) {
            cerr << "ERROR: Could not open input file: " << inputFile << endl;
            return false;
        }

        counts.clear();

        string word;
        while (in >> word) {
            ++counts[word];
        }
        in.close();

        // Write the backup frequency.dat
        ofstream out(backupFile);
        if (!out) {
            cerr << "ERROR: Could not write backup file: " << backupFile << endl;
            return false;
        }
        for (const auto& kv : counts) {
            out << kv.first << " " << kv.second << "\n";
        }
        out.close();

        return true;
    }

    // Return the frequency for a single item
    int GetCount(const string& item) const {
        auto it = counts.find(item);
        if (it == counts.end()) return 0;
        return it->second;
    }

    // Print every item and its count
    void PrintAll() const {
        for (const auto& kv : counts) {
            cout << kv.first << " " << kv.second << "\n";
        }
    }

    // Print a histogram using asterisks
    void PrintHistogram() const {
        for (const auto& kv : counts) {
            cout << left << setw(14) << kv.first << " ";
            for (int i = 0; i < kv.second; ++i) cout << '*';
            cout << "\n";
        }
    }

private:
    map<string, int> counts;
};

static void PrintMenu() {
    cout << "\n====== Corner Grocer ======\n"
         << "1. Search for an item count\n"
         << "2. Print all item counts\n"
         << "3. Print histogram\n"
         << "4. Exit\n"
         << "Enter choice: ";
}

int main() {
    const string INPUT_FILE  = "CS210_Project_Three_Input_File.txt";
    const string BACKUP_FILE = "frequency.dat";

    FrequencyCounter counter;
    if (!counter.Load(INPUT_FILE, BACKUP_FILE)) {
        cerr << "Make sure the input file is in the same folder as the executable.\n";
        return 1;
    }

    while (true) {
        PrintMenu();
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            cout << "Enter item name: ";
            string item;
            cin >> item;
            cout << counter.GetCount(item) << "\n";
        }
        else if (choice == 2) {
            counter.PrintAll();
        }
        else if (choice == 3) {
            counter.PrintHistogram();
        }
        else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
