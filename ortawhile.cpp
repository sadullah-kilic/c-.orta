/*
// kodları kullanmak için lütfen türkçe harf kütüphanesini ekleyin 
 
utf 8 olduğundan emin olun 
#include <iostream>
   #include <locale.h>
   #ifdef _WIN32
   #include <windows.h>
   #endif


// kullanıcıdan doğru şifre alma +
#include <iostream>
#include <string>
using namespace std;

int main() {
    string dogruSifre = "1234";  
    string girilenSifre;

    // Kullanıcı doğru şifreyi girene kadar döngü devam eder
    while (girilenSifre != dogruSifre) {
        cout << "Sifreyi giriniz: ";
        cin >> girilenSifre;

        if (girilenSifre != dogruSifre) {
            cout << "Yanlis sifre. Tekrar deneyin." << endl;
        }
    }

    cout << "Giris basarili!" << endl;
    return 0;
}
// 0 girene kadar toplama 
#include <iostream>
using namespace std;

int main() {
    int sayi;
    int toplam = 0;

    cout << "Sayi giriniz (Bitirmek icin 0 giriniz): ";

    while (true) {
        cin >> sayi;
        if (sayi == 0) break;      
        toplam += sayi;             
    }

    cout << "Toplam: " << toplam << endl;
    return 0;
}
// Basit tahmin oyunu tekrar oynama seçeneği için ayrı yazacağım 
#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time

using namespace std;

int main() {
    srand(time(0));               // Rastgele sayı üreteciyi başlatıyoruz
    int rastgeleSayi = rand() % 100 + 1;  // 1-100 arası sayı
    int tahmin;

    cout << "1 ile 100 arasinda bir sayi tuttum, tahmin et bakalim!" << endl;

    do {
        cout << "Tahmininiz: ";
        cin >> tahmin;

        if (tahmin < rastgeleSayi) {
            cout << "Daha buyuk bir sayi dene." << endl;
        }
        else if (tahmin > rastgeleSayi) {
            cout << "Daha kucuk bir sayi dene." << endl;
        }

    } while (tahmin != rastgeleSayi);

    cout << "Tebrikler! Dogru sayiyi buldunuz: " << rastgeleSayi << endl;

    return 0;


    #include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

using namespace std;

int main() {
    srand(time(0)); // Rastgele sayılar için başlangıç

    char devam = 'e'; // Oyuna başlamak için
    int maxSayi = 100; // Maksimum sayı
    int puan;
    
    while (devam == 'e' || devam == 'E') {
        int rastgeleSayi = rand() % maxSayi + 1; // 1 ile maxSayi arasında sayı seç
        int tahmin, deneme = 0;
        puan = 100; // Başlangıç puanı
        
        cout << "1 ile " << maxSayi << " arasında bir sayi tuttum, tahmin et!\n";

        do {
            cout << "Tahmininiz: ";
            cin >> tahmin;
            deneme++;

            if (tahmin > rastgeleSayi) {
                cout << "Daha küçük bir sayi deneyin.\n";
            } else if (tahmin < rastgeleSayi) {
                cout << "Daha büyük bir sayi deneyin.\n";
            } else {
                cout << "Tebrikler! " << deneme << " denemede bildiniz.\n";
                puan -= (deneme - 1) * 10;
                if(puan < 0) puan = 0;
                cout << "Puaniniz: " << puan << endl;
            }
        } while (tahmin != rastgeleSayi);

        cout << "Tekrar oynamak ister misiniz? (e/h): ";
        cin >> devam;
    }

    cout << "Oyunu oynadiginiz icin tesekkurler!\n";

    return 0;
}




*/