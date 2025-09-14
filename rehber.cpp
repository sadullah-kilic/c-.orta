
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Kisi {
    string ad;
    string numara;
};

void kisiEkle(vector<Kisi>& rehber) {
    Kisi yeni;
    cout << "Isim: ";
    cin >> yeni.ad;
    cout << "Numara: ";
    cin >> yeni.numara;
    rehber.push_back(yeni);
    cout << "Kisi eklendi.\n";
}

void kisileriListele(const vector<Kisi>& rehber) {
    cout << "---- Rehber ----\n";
    for (const auto& kisi : rehber) {
        cout << "Isim: " << kisi.ad << ", Numara: " << kisi.numara << endl;
    }
}

void kisiAra(const vector<Kisi>& rehber) {
    string aranan;
    cout << "Aranacak ismi girin: ";
    cin >> aranan;
    for (const auto& kisi : rehber) {
        if (kisi.ad == aranan) {
            cout << "Bulundu - Numara: " << kisi.numara << endl;
            return;
        }
    }
    cout << "Kisi bulunamadi.\n";
}

void kisiSil(vector<Kisi>& rehber) {
    string silinecek;
    cout << "Silinecek ismi girin: ";
    cin >> silinecek;
    for (size_t i = 0; i < rehber.size(); ++i) {
        if (rehber[i].ad == silinecek) {
            rehber.erase(rehber.begin() + i);
            cout << "Kisi silindi.\n";
            return;
        }
    }
    cout << "Kisi bulunamadi.\n";
}

int main() {
    vector<Kisi> rehber;
    int secim;

    do {
        cout << "\n--- Telefon Rehberi ---\n";
        cout << "1. Kisi Ekle\n2. Kisileri Listele\n3. Kisi Ara\n4. Kisi Sil\n0. Cikis\nSecim: ";
        cin >> secim;

        switch (secim) {
            case 1: kisiEkle(rehber); break;
            case 2: kisileriListele(rehber); break;
            case 3: kisiAra(rehber); break;
            case 4: kisiSil(rehber); break;
            case 0: cout << "Cikis yapiliyor...\n"; break;
            default: cout << "Gecersiz secim.\n"; break;
        }
    } while (secim != 0);

    return 0;
}