#include <iostream>
using namespace std;

int main()
{
    cout << "Selamat datang" << endl;
    cout << "silahkan login" << endl;
    string nama, nim;
    int check = 0;
    cout << "masukan nama dan nim" << endl;
    
    do
    {
        cout << "masukkan nama : ";
        cin >> nama;
        cout << "masukkan nim  : ";
        cin >> nim;
        if (nama == "pei" && nim == "153")
        {
            cout << "Login Berhasil" << endl;
            break;
        }
    check++;
    } while (check < 3);
    if (check >= 3)
    {
        cout << "Login Gagal" << endl;
        return 0;
    }
    string menu1, menu2;
    int pilihanmenu;
    cout << "\nMenu" << endl;
    cout << "1. Game Tebak Angka" << endl;
    cout << "2. Keluar" << endl;
    cout << "_____________________________" << endl;
    cout << "Pilih menu di atas: ";
    cin >> pilihanmenu;



    if (pilihanmenu == 1)
    {
    int angka_tebak;
    int angka_benar = 5;
    cout << "selamat Datang Di Permainan angka " << endl;

    do
    {
    cout << "Tebak Angka dari (1-10) : ";
    cin >> angka_tebak;
    if (angka_tebak > angka_benar)
    {
        cout << "kebesaran cuy" << endl;
    }
    else if (angka_tebak < angka_benar)
    {
        cout << "kekecilan inimah " << endl;
    }
    else 
    {
        cout << "anjay bisa nebak " << endl;
        break;

    }
    } while (angka_tebak != angka_benar);

    return 0;
}
else if (pilihanmenu == 2)
{
    cout << "keluar dari program" << endl;
    return 0;
}
else
{
    cout << "ga bener ah" << endl;
    return 0;
}
}

