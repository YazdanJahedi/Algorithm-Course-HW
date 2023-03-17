#include "iostream"
#include "unordered_map"
using namespace std;


int main() {
    string line1;
    string line2;
    getline(cin, line1);
    getline(cin, line2);

    unordered_map<char, char> letter_map;
    int found_chars [128] =  {}; // this marks mapped chars in line2

    for (int i = 0; i < line1.length(); ++i) {
        char c1 = line1[i];
        char c2 = line2[i];

        if (letter_map.find(c1) == letter_map.end()) {
            letter_map[c1] = c2;
            if (found_chars[(int)c2] == 1){
                cout << "false" << endl;
                return 0;
            }
            found_chars[(int)c2] = 1;
        } else {
            if (letter_map[c1] != c2){
                cout << "false" << endl;
                return 0;
            }
        }
    }

    cout << "true" << endl;
    return 0;
}
