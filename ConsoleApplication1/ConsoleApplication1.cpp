/****************************************************************************
**					           SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				         BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				           PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI....:3
**				ÖĞRENCİ ADI......:YAVUZHAN ALBAYRAK
**				ÖĞRENCİ NUMARASI.:G201210008
**				DERS GRUBU.......:A
****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>

using namespace std;
int main(int argc, char* argv[])
{
    //Giriş için gerekli tanımlamalar.
    string kullanici_adi = "admin";
    int sifre = 12345;

    ofstream kullanici("kullanici.txt");
    kullanici << kullanici_adi << " " << sifre << endl;
    kullanici.close();


    string cevap;
    int islem;
    string id;
    int parola;
    //okuyucu.txt için gerekli tanımlamalar.
    int okuyucu_tc;
    string okuyucu_adi;
    string okuyucu_soyadi;
    int okuyucu_no;
    int okuyucu_telefon;
    int okuyucu_dogum;
    string okuyucu_gorevi;
    int okuyucu_kitapsayisi;
    //kitap.txt için gerekli tanımlamalar.
    int kitap_isbn;
    string kitap_ismi;
    string kitap_yazaradi;
    string kitap_yazarsoyadi;
    string kitap_konu;
    string kitap_tur;
    int kitap_sayfasayisi;
    //odunc.txt için gerekli tanımlamalar
    int odunc_isbn;
    int odunc_tc;
    int odunc_tarihi;
    int odunc_dönüstarihi;



    //kullanıcı bilgileri kontrol edilip doğru ise uygulama başlatılıyor.
    do {
        cout << "Kullanici adi giriniz: "; cin >> id;
        cout << "Sifre giriniz: "; cin >> parola;

        if (kullanici_adi != id || sifre != parola) {
            cout << "Kullanici adi veya sifre hatali..." << endl;
        }

    } while (kullanici_adi != id || sifre != parola);
    //giriş tarihi kaydediliyor.
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "Giris saati: " << dt << endl;
    //menü.
    cout << "yapmak istediginiz islemi seciniz: " << endl;
    cout << "1- Okuyucu kaydi" << endl;
    cout << "2- Okuyucu kaydi guncelleme" << endl;
    cout << "3- Okuyucu silme" << endl;
    cout << "4- Okuyucu uzerindeki kitaplar listesi" << endl;
    cout << "5- kitap odunc alma" << endl;
    cout << "6- kitap geri dondurme" << endl;
    cout << "7- Kitap ekleme" << endl;
    cout << "8- Kitap silme" << endl;
    cout << "9- Kitap duzeltme" << endl;
    cout << "10- Cikis" << endl;
    cout << "Islem giriniz: ";
    cin >> islem;
    //okuyucu kaydı yapılıyor.
    if (islem == 1) {
        ofstream setokuyucu("okuyucu.txt", ios::app);
        do {
            cout << "Okuyucunun adini giriniz: "; cin >> okuyucu_adi;
            cout << "Okuyucunun soyadini giriniz: "; cin >> okuyucu_soyadi;
            cout << "Okuyucunun tc'sini giriniz: "; cin >> okuyucu_tc;
            cout << "Okuyucunun numarasini giriniz: "; cin >> okuyucu_no;
            cout << "Okuyucunun telefon numarasini giriniz: "; cin >> okuyucu_telefon;
            cout << "Okuyucunun dogum tarihini giriniz: "; cin >> okuyucu_dogum;
            cout << "Okuyucunun gorevini giriniz: "; cin >> okuyucu_gorevi;
            cout << "Okuyucunun alabilecegi kitap sayisini giriniz: "; cin >> okuyucu_kitapsayisi;

            setokuyucu << okuyucu_adi << " " << okuyucu_soyadi << " " << okuyucu_tc << " " << okuyucu_no << " "
                << okuyucu_telefon << " " << okuyucu_dogum << " " << okuyucu_gorevi << " " << okuyucu_kitapsayisi << " " << endl;
            cout << "Baska kayit girmek ister misiniz? (e/h)" << endl;
            cin >> cevap;

        } while (cevap == "e");
        setokuyucu.close();
        cout << "Kayit islemi tamamlandi." << endl;
    }
    //okuyucu kaydı güncelleme.
    if (islem == 2) {
        int aranan_tc;
        cout << "Guncellemek istediginiz kisinin tc'si: "; cin >> aranan_tc;
        ifstream getokuyucu("okuyucu.txt");
        ofstream setokuyucu("okuyucu.tmp");

        while (!getokuyucu.eof()) {

            getokuyucu >> okuyucu_adi >> okuyucu_soyadi >> okuyucu_tc >> okuyucu_no
                >> okuyucu_telefon >> okuyucu_dogum >> okuyucu_gorevi >> okuyucu_kitapsayisi;

            if (getokuyucu.eof()) {
                break;
            }

            if (aranan_tc == okuyucu_tc) {
                cout << "Duzeltilecek kisinin bilgileri: " << endl;
                cout << okuyucu_adi << endl;
                cout << okuyucu_soyadi << endl;
                cout << okuyucu_tc << endl;
                cout << okuyucu_no << endl;
                cout << okuyucu_telefon << endl;
                cout << okuyucu_dogum << endl;
                cout << okuyucu_gorevi << endl;
                cout << okuyucu_kitapsayisi << endl;

                cout << "Okuyucunun adini giriniz: "; cin >> okuyucu_adi;
                cout << "Okuyucunun soyadini giriniz: "; cin >> okuyucu_soyadi;
                cout << "Okuyucunun tc'sini giriniz: "; cin >> okuyucu_tc;
                cout << "Okuyucunun numarasini giriniz: "; cin >> okuyucu_no;
                cout << "Okuyucunun telefon numarasini giriniz: "; cin >> okuyucu_telefon;
                cout << "Okuyucunun dogum tarihini giriniz: "; cin >> okuyucu_dogum;
                cout << "Okuyucunun gorevini giriniz: "; cin >> okuyucu_gorevi;
                cout << "Okuyucunun alabilecegi kitap sayisini giriniz: "; cin >> okuyucu_kitapsayisi;

                setokuyucu << okuyucu_adi << ' ' << okuyucu_soyadi << ' ' << okuyucu_tc << ' ' << okuyucu_no << ' '
                    << okuyucu_telefon << ' ' << okuyucu_dogum << ' ' << okuyucu_gorevi << ' ' << okuyucu_kitapsayisi << "\n";
            }
            else {
                setokuyucu << okuyucu_adi << ' ' << okuyucu_soyadi << ' ' << okuyucu_tc << ' ' << okuyucu_no << ' '
                    << okuyucu_telefon << ' ' << okuyucu_dogum << ' ' << okuyucu_gorevi << ' ' << okuyucu_kitapsayisi << "\n";
            }

        }
        setokuyucu.close();
        getokuyucu.close();
        remove("okuyucu.txt");
        rename("okuyucu.tmp", "okuyucu.txt");
    }
    //okuyucu silme.
    if (islem == 3) {
        int aranan_tc;
        cout << "Silmek istediginiz kisinin tc'si: "; cin >> aranan_tc;
        ifstream getokuyucu("okuyucu.txt");
        ofstream setokuyucu("okuyucu.tmp");



        while (!getokuyucu.eof()) {

            getokuyucu >> okuyucu_adi >> okuyucu_soyadi >> okuyucu_tc >> okuyucu_no
                >> okuyucu_telefon >> okuyucu_dogum >> okuyucu_gorevi >> okuyucu_kitapsayisi;

            if (getokuyucu.eof()) {
                break;
            }

            if (aranan_tc == okuyucu_tc) {
                cout << "Silinecek kisinin bilgileri: " << endl;
                cout << okuyucu_adi << endl;
                cout << okuyucu_soyadi << endl;
                cout << okuyucu_tc << endl;
                cout << okuyucu_no << endl;
                cout << okuyucu_telefon << endl;
                cout << okuyucu_dogum << endl;
                cout << okuyucu_gorevi << endl;
                cout << okuyucu_kitapsayisi << endl;


            }
            else {
                setokuyucu << okuyucu_adi << ' ' << okuyucu_soyadi << ' ' << okuyucu_tc << ' ' << okuyucu_no << ' '
                    << okuyucu_telefon << ' ' << okuyucu_dogum << ' ' << okuyucu_gorevi << ' ' << okuyucu_kitapsayisi << endl;
            }

        }
        setokuyucu.close();
        getokuyucu.close();
        remove("okuyucu.txt");
        rename("okuyucu.tmp", "okuyucu.txt");

        //okuyucu ile birlikte ödünç kitaplar da siliniyor.

        ifstream getodunc("odunc.txt");
        ofstream setodunc("odunc.tmp");
        while (!getodunc.eof()) {
            getodunc >> odunc_tc >> odunc_isbn >> odunc_tarihi >> odunc_dönüstarihi;

            if (getodunc.eof()) {
                break;
            }

            if (aranan_tc == odunc_tc) {
                cout << "Kitaplar geri donduruldu.";
            }
            else {
                setodunc << odunc_tc << " " << odunc_isbn << "" << odunc_tarihi << " " << odunc_dönüstarihi << endl;
            }
        }
        setodunc.close();
        getodunc.close();
        remove("odunc.txt");
        rename("odunc.tmp", "odunc.txt");
    }
    //kişilere ait kitapların listesi.
    if (islem == 4) {
        int aranan_tc;
        cout << "Kitap listesine ulasmak istediginiz kisinin tc'si: "; cin >> aranan_tc;
        ifstream getodunc("odunc.txt");
        while (!getodunc.eof()) {
            getodunc >> odunc_tc >> odunc_isbn >> odunc_tarihi >> odunc_dönüstarihi;

            if (getodunc.eof()) {
                break;
            }

            if (aranan_tc == odunc_tc) {
                cout << "Odunc verilen kitabin isbn'si: " << odunc_isbn << endl;

            }
        }
        getodunc.close();
    }

    //kitap ödünç verme.
    if (islem == 5) {
        ofstream setodunc("odunc.txt");
        do {
            cout << "Odunc verilecek kisinin tc'si: "; cin >> odunc_tc;
            cout << "Odunc verilecek kitabin isbn'si: "; cin >> odunc_isbn;
            cout << "Odunc verilen tarih: "; cin >> odunc_tarihi;
            cout << "Odunc verilecek kitabin donus tarihi: "; cin >> odunc_dönüstarihi;

            setodunc << odunc_tc << " " << odunc_isbn << " " << odunc_tarihi << " " << odunc_dönüstarihi << endl;

            cout << "Baska kayit girmek ister misiniz? (e/h)" << endl;
            cin >> cevap;

        } while (cevap == "e");
        setodunc.close();
        cout << "Odunc islemi tamamlandi.";
    }
    //ödünç silme
    if (islem == 6) {
        int aranan_isbn;
        cout << "Silinecek odunc kitabin isbn'sini gir: "; cin >> aranan_isbn;
        ifstream getodunc("odunc.txt");
        ofstream setodunc("odunc.tmp");
        while (!getodunc.eof()) {

            getodunc >> odunc_tc >> odunc_isbn >> odunc_tarihi >> odunc_dönüstarihi;

            if (getodunc.eof()) {
                break;
            }

            if (aranan_isbn == odunc_isbn) {
                cout << "Silinecek oduncun bilgileri:  " << endl;
                cout << odunc_tc << endl;
                cout << odunc_isbn << endl;
                cout << odunc_tarihi << endl;
                cout << odunc_dönüstarihi << endl;
            }
            else {
                setodunc << odunc_tc << " " << odunc_isbn << "" << odunc_tarihi << " " << odunc_dönüstarihi << endl;
            }
        }
        setodunc.close();
        getodunc.close();
        remove("odunc.txt");
        rename("odunc.tmp", "odunc.txt");
    }
    //kitap ekle.
    if (islem == 7) {
        ofstream setkitap("kitap.txt", ios::app);
        do {
            cout << "Kitap adini giriniz: "; cin >> kitap_ismi;
            cout << "Kitabin isbn'sini giriniz: "; cin >> kitap_isbn;
            cout << "Kitabin konusunu giriniz: "; cin >> kitap_konu;
            cout << "Kitabin sayfa sayisini giriniz: "; cin >> kitap_sayfasayisi;
            cout << "Kitabin turunu giriniz: "; cin >> kitap_tur;
            cout << "Kitabin yazarinin adini giriniz: "; cin >> kitap_yazaradi;
            cout << "Kitabin yazarinin soyadini giriniz: "; cin >> kitap_yazarsoyadi;


            setkitap << kitap_ismi << " " << kitap_isbn << " " << kitap_konu << " " << kitap_sayfasayisi << " "
                << kitap_tur << " " << kitap_yazaradi << " " << kitap_yazarsoyadi << endl;

            cout << "Baska kayit girmek ister misiniz? (e/h)" << endl;
            cin >> cevap;

        } while (cevap == "e");
        setkitap.close();
        cout << "Kayit islemi tamamlandi." << endl;
    }

    //kitap sil.
    if (islem == 8) {
        int aranan_isbn;
        cout << "Silmek istediginiz kitabin isbn'si: "; cin >> aranan_isbn;
        ifstream getkitap("kitap.txt");
        ofstream setkitap("kitap.tmp");

        while (!getkitap.eof()) {

            getkitap >> kitap_ismi >> kitap_isbn >> kitap_konu >> kitap_sayfasayisi
                >> kitap_tur >> kitap_yazaradi >> kitap_yazarsoyadi;

            if (getkitap.eof()) {
                break;
            }

            if (aranan_isbn == kitap_isbn) {
                cout << "Silinecek kitabin bilgileri: " << endl;
                cout << kitap_isbn << endl;
                cout << kitap_ismi << endl;
                cout << kitap_konu << endl;
                cout << kitap_sayfasayisi << endl;
                cout << kitap_tur << endl;
                cout << kitap_yazaradi << endl;
                cout << kitap_yazarsoyadi << endl;



            }
            else {
                setkitap << kitap_ismi << " " << kitap_isbn << " " << kitap_konu << " " << kitap_sayfasayisi << " "
                    << kitap_tur << " " << kitap_yazaradi << " " << kitap_yazarsoyadi << endl;
            }

        }
        setkitap.close();
        getkitap.close();
        remove("kitap.txt");
        rename("kitap.tmp", "kitap.txt");
    }
    //kitap değiştir.
    if (islem == 9) {
        int aranan_isbn;
        cout << "Duzenlemek istediginiz kitabin isbn'si: "; cin >> aranan_isbn;
        ifstream getkitap("kitap.txt");
        ofstream setkitap("kitap.tmp");

        while (!getkitap.eof()) {

            getkitap >> kitap_ismi >> kitap_isbn >> kitap_konu >> kitap_sayfasayisi
                >> kitap_tur >> kitap_yazaradi >> kitap_yazarsoyadi;

            if (getkitap.eof()) {
                break;
            }

            if (aranan_isbn == kitap_isbn) {
                cout << "Duzenlenecek kitabin bilgileri: " << endl;
                cout << kitap_ismi << endl;
                cout << kitap_isbn << endl;
                cout << kitap_konu << endl;
                cout << kitap_sayfasayisi << endl;
                cout << kitap_tur << endl;
                cout << kitap_yazaradi << endl;
                cout << kitap_yazarsoyadi << endl;

                cout << "Kitap adini giriniz: "; cin >> kitap_ismi;
                cout << "Kitabin isbn'sini giriniz: "; cin >> kitap_isbn;
                cout << "Kitabin konusunu giriniz: "; cin >> kitap_konu;
                cout << "Kitabin sayfa sayisini giriniz: "; cin >> kitap_sayfasayisi;
                cout << "Kitabin turunu giriniz: "; cin >> kitap_tur;
                cout << "Kitabin yazarinin adini giriniz: "; cin >> kitap_yazaradi;
                cout << "Kitabin yazarinin soyadini giriniz: "; cin >> kitap_yazarsoyadi;


                setkitap << kitap_ismi << " " << kitap_isbn << " " << kitap_konu << " " << kitap_sayfasayisi << " "
                    << kitap_tur << " " << kitap_yazaradi << " " << kitap_yazarsoyadi << endl;



            }
            else {
                setkitap << kitap_ismi << " " << kitap_isbn << " " << kitap_konu << " " << kitap_sayfasayisi << " "
                    << kitap_tur << " " << kitap_yazaradi << " " << kitap_yazarsoyadi << endl;
            }

        }
        setkitap.close();
        getkitap.close();
        remove("kitap.txt");
        rename("kitap.tmp", "kitap.txt");
    }
    //çıkış tarihi.
    time_t end = time(0);
    char* dt1 = ctime(&end);
    cout << "Cikis saati: " << dt1 << endl;
    return 0;
}


