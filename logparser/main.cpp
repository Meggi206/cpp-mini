#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <filename> <keyword>" << endl;
        return 1;
    }

    string filename = argv[1];
    string keyword = argv[2];
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return 1;
    }

    string line;
    int matchCount = 0;
    while (getline(file, line)) {
        if (line.find(keyword) != string::npos) {
            cout << line << endl;
            matchCount++;
        }
    }
    file.close();

    cout << "\nTotal matches: " << matchCount << endl;
    return 0;
}
