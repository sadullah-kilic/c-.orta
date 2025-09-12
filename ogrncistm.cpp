#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Ogrenci {
    int id;
    string isim;
    double notOrt;
};

// Öğrenci ekleme
void ogrenciEkle(vector<Ogrenci>& ogrenciler) {
    Ogrenci o;
    cout << "Ogrenci ID: ";
    cin >> o.id;
    cout << "Ogrenci ismi: ";
    cin.ignore();
    getline(cin, o.isim);
    cout << "Not ortalamasi: ";
    cin >> o.notOrt;

    ogrenciler.push_back(o);
    cout << "Ogrenci eklendi.\n";
}

// Listeleme
void ogrenciListele(const vector<Ogrenci>& ogrenciler) {
    for (const auto& o : ogrenciler) {
        cout << "ID: " << o.id << ", Isim: " << o.isim << ", Not Ortalamasi: " << o.notOrt << endl;
    }
}

// Güncelleme
void ogrenciGuncelle(vector<Ogrenci>& ogrenciler) {
    int id;
    cout << "Guncellenecek ogrencinin ID'sini girin: ";
    cin >> id;

    for (auto& o : ogrenciler) {
        if (o.id == id) {
            cout << "Yeni isim: ";
            cin.ignore();
            getline(cin, o.isim);
            cout << "Yeni not ortalamasi: ";
            cin >> o.notOrt;
            cout << "Guncellendi.\n";
            return;
        }
    }
    cout << "Ogrenci bulunamadi.\n";
}

// Silme
void ogrenciSil(vector<Ogrenci>& ogrenciler) {
    int id;
    cout << "Silinecek ogrencinin ID'sini girin: ";
    cin >> id;

    auto it = remove_if(ogrenciler.begin(), ogrenciler.end(), [id](Ogrenci& o) {
        return o.id == id;
    });

    if (it != ogrenciler.end()) {
        ogrenciler.erase(it, ogrenciler.end());
        cout << "Silindi.\n";
    } else {
        cout << "Ogrenci bulunamadi.\n";
    }
}

// Arama
void ogrenciAra(const vector<Ogrenci>& ogrenciler) {
    string aranan;
    cout << "Aranacak ogrenci ismini girin: ";
    cin.ignore();
    getline(cin, aranan);

    for (const auto& o : ogrenciler) {
        if (o.isim.find(aranan) != string::npos) {
            cout << "ID: " << o.id << ", Isim: " << o.isim << ", Not Ortalamasi: " << o.notOrt << endl;
        }
    }
}

// Sıralama
void notSirala(vector<Ogrenci>& ogrenciler) {
    sort(ogrenciler.begin(), ogrenciler.end(), [](Ogrenci& a, Ogrenci& b) {
        return a.notOrt > b.notOrt;
    });
    cout << "Not ortalamasina gore siralandi.\n";
}

// Dosyaya kaydetme  
void dosyayaKaydet(const vector<Ogrenci>& ogrenciler) {
    ofstream dosya("ogrenciler.txt");
    for (const auto& o : ogrenciler) {
        dosya << o.id << "," << o.isim << "," << o.notOrt << endl;
    }
    dosya.close();
    cout << "Dosyaya kaydedildi.\n";
}

// Dosyadan okuma
void dosyadanYukle(vector<Ogrenci>& ogrenciler) {
    ifstream dosya("ogrenciler.txt");
    Ogrenci o;
    ogrenciler.clear();
    string satir;
    while (getline(dosya, satir)) {
        size_t ilkVirgul = satir.find(',');
        size_t ikinciVirgul = satir.find(',', ilkVirgul + 1);
        o.id = stoi(satir.substr(0, ilkVirgul));
        o.isim = satir.substr(ilkVirgul + 1, ikinciVirgul - ilkVirgul - 1);
        o.notOrt = stod(satir.substr(ikinciVirgul + 1));
        ogrenciler.push_back(o);
    }
    dosya.close();
    cout << "Dosyadan yuklendi.\n";
}

// Menü
int main() {
    vector<Ogrenci> ogrenciler;
    int secim;

    while (true) {
        cout << "\n1-Ogrenci Ekle\n2-Listele\n3-Guncelle\n4-Sil\n5-Ara\n6-Not Sirala\n7-Dosyaya Kaydet\n8-Dosyadan Yukle\n0-Cikis\nSecim: ";
        cin >> secim;

        switch (secim) {
            case 1: ogrenciEkle(ogrenciler); break;
            case 2: ogrenciListele(ogrenciler); break;
            case 3: ogrenciGuncelle(ogrenciler); break;
            case 4: ogrenciSil(ogrenciler); break;
            case 5: ogrenciAra(ogrenciler); break;
            case 6: notSirala(ogrenciler); break;
            case 7: dosyayaKaydet(ogrenciler); break;
            case 8: dosyadanYukle(ogrenciler); break;
            case 0: return 0;
            default: cout << "Gecersiz secim.\n";
        }
    }
}   

/*
#include <iostream>
#include <vector>
using namespace std;

struct Ogrenci {
    string isim;
    int yas;
    string bolum;
};

// Yeni ogrenci ekleme fonksiyonu
void ogrenciEkle(vector<Ogrenci> &ogrenciler) {
    Ogrenci yeni;
    cout << "Ogrenci adi: ";
    getline(cin, yeni.isim);
    cout << "Ogrenci yasi: ";
    cin >> yeni.yas;
    cin.ignore(); // satir sonu karakterini temizle
    cout << "Ogrenci bolumu: ";
    getline(cin, yeni.bolum);

    ogrenciler.push_back(yeni);
    cout << "Ogrenci eklendi!" << endl;
}

int main() {
    vector<Ogrenci> ogrenciler;
    char devam;

    do {
        ogrenciEkle(ogrenciler);

        cout << "Baska ogrenci eklemek istiyor musunuz? (e/h): ";
        cin >> devam;
        cin.ignore();
    } while (devam == 'e' || devam == 'E');

    // Eklenen ogrencileri listeleyelim
    cout << "\nKayitli ogrenciler:\n";
    for (auto &o : ogrenciler) {
        cout << "Isim: " << o.isim << ", Yas: " << o.yas << ", Bolum: " << o.bolum << endl;
    }

    return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

struct Ogrenci {
    string isim;
    int numara;
    float notu;
};

int main() {
    Ogrenci ogr;

    cout << "Ogrenci adi: ";
    getline(cin, ogr.isim);

    cout << "Ogrenci numarasi: ";
    cin >> ogr.numara;

    cout << "Ogrenci notu: ";
    cin >> ogr.notu;

    cout << "\nGirilen Bilgiler:" << endl;
    cout << "Isim: " << ogr.isim << endl;
    cout << "Numara: " << ogr.numara << endl;
    cout << "Not: " << ogr.notu << endl;

    return 0;
}

*/