 
 #include <iostream>
#include <vector>
#include <string>
#include <algorithm> // transform

using namespace std;

struct Word {
    string english;
    string turkish;
};

// Kelimeyi küçük harfe çeviren fonksiyon
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    vector<Word> dictionary;
    int choice;
    string eng, tur, search;
    bool found;

    do {
        cout << "\n1. Add word\n";
        cout << "2. Search word\n";
        cout << "3. Show all\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "English: ";
            cin >> eng;
            cout << "Turkish (no special chars): ";
            cin >> tur;
            dictionary.push_back({eng, tur});
        }

        else if (choice == 2) {
            cout << "Search English word: ";
            cin >> search;
            search = toLower(search);
            found = false;


 for (auto w : dictionary) {
                if (toLower(w.english) == search) {
                    cout << "Meaning: " << w.turkish << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Not found.\n";
        }

        else if (choice == 3) {
            for (auto w : dictionary)
                cout << w.english << " - " << w.turkish << endl;
        }

    } while (choice != 0);

    return 0;
}
 /* 
 #include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Word {
    string english;
    string turkish;
};

int main() {
    vector<Word> dictionary;
    int choice;
    string eng, tur, search;
    bool found;

    do {
        cout << "\n1. Add word\n";
        cout << "2. Search word\n";
        cout << "3. Show all\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "English: ";
            cin >> eng;
            cout << "Turkish (no special chars): ";
            cin >> tur;
            dictionary.push_back({eng, tur});
        }

        else if (choice == 2) {
            cout << "Search English word: ";
            cin >> search;
            found = false;
            for (auto w : dictionary) {
                if (w.english == search) {
                    cout << "Meaning: " << w.turkish << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Not found.\n";
        }

        else if (choice == 3) {
            for (auto w : dictionary)cout << w.english << " - " << w.turkish << endl;
        }

    } while (choice != 0);

    return 0;
}
    */