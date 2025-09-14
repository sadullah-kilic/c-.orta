#include <iostream>
#include <string>
using namespace std;

// Karakterleri kaydırarak şifreleme yapan fonksiyon
string sifrele(string metin, int anahtar) {
    string sonuc = "";

    for (char c : metin) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + anahtar) % 26 + base;
        }
        sonuc += c;
    }

    return sonuc;
}

// Karakterleri geri kaydırarak şifre çözme yapan fonksiyon
string coz(string metin, int anahtar) {
    return sifrele(metin, 26 - (anahtar % 26));
}

int main() {
    string metin;
    int anahtar;
    int secim;

    cout << "1- Sifrele\n2- Sifre Coz\nSeciminiz: ";
    cin >> secim;
    cin.ignore(); // getline'dan önceki boşluğu temizler

    cout << "Metni girin: ";
    getline(cin, metin);

    cout << "Anahtari girin (ornek: 3): ";
    cin >> anahtar;

    if (secim == 1)
        cout << "Sifreli metin: " << sifrele(metin, anahtar) << endl;
    else if (secim == 2)
        cout << "Cozulmus metin: " << coz(metin, anahtar) << endl;
    else
        cout << "Gecersiz secim!" << endl;

    return 0;
}