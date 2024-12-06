#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

struct detail_penjualan
{
    string jenis_sepatu;
    int harga;
    int kuantitas;
};

struct penjualan {
    string nama_pembeli;
    int banyak_jenis_sepatu;
    string tanggal_beli;
    detail_penjualan detail[100];
};

penjualan data_penjualan[100];

void menu_1(int &jumlah_penjualan, penjualan data_penjualan[100]);
void menu_2(int jumlah_penjualan, penjualan data_penjualan[100]);

int main()
{
    int choice;
    int jumlah_penjualan = 0;

    do
    {
        cout << "SISTEM PENCATATAN DATA PENJUALAN SEPATU\n";
        cout << "LIST MENU\n";
        cout << "1. Input Data Penjualan\n";
        cout << "2. Lihat Data Penjualan\n";
        cout << "3. Keluar\n";
        cout << "PILIH MENU : ";
        cin >> choice;

        if (choice == 1)
        {
            menu_1(jumlah_penjualan, data_penjualan);
        }
        else if (choice == 2)
        {
            menu_2(jumlah_penjualan, data_penjualan);
        }
        else
        {
            cout << "Program akan keluar\n";
            system("pause");
            system("cls");
            return 0;
        }
    } while (choice != 3);
}

void menu_1(int &jumlah_penjualan, penjualan data_penjualan[100])
{
    cout << "Kasir : Vic Store Veteran" << endl;
    cout << "Masukkan data penjualan yang ingin diinput : ";
    cin >> jumlah_penjualan;
    cin.ignore();

    for (int i = 0; i < jumlah_penjualan; i++)
    {
        cout << "Data Penjualan ke-" << i + 1 << endl;
        cout << "Masukkan Nama Pembeli : ";
        getline(cin, data_penjualan[i].nama_pembeli);
        cout << "Masukkan Jumlah Jenis Sepatu : ";
        cin >> data_penjualan[i].banyak_jenis_sepatu;
        cin.ignore();

        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%d-%m-%Y", ltm);
        data_penjualan[i].tanggal_beli = buffer;

        for (int j = 0; j < data_penjualan[i].banyak_jenis_sepatu; j++)
        {
            cout << "Masukkan Jenis Sepatu ke-" << j + 1 << " : ";
            getline(cin, data_penjualan[i].detail[j].jenis_sepatu);
            cout << "Masukkan Harga Sepatu : ";
            cin >> data_penjualan[i].detail[j].harga;
            cout << "Masukkan Kuantitas Sepatu : ";
            cin >> data_penjualan[i].detail[j].kuantitas;
            cin.ignore();
        }
    }
}

void menu_2(int jumlah_penjualan, penjualan data_penjualan[100])
{
    cout << "Data Penjualan yang telah diinput" << endl;

    int total_harga = 0;
    int total_kuantitas = 0;
    string nama_pembeli;

    for (int i = 0; i < jumlah_penjualan; i++)
    {
        cout << "Data Penjualan ke-" << i + 1 << endl;
        cout << "=====================================" << endl;
        cout << "Nama Pembeli : " << data_penjualan[i].nama_pembeli << endl;
        cout << "Tanggal Beli : " << data_penjualan[i].tanggal_beli << endl;
        cout << "Jumlah Jenis Sepatu : " << data_penjualan[i].banyak_jenis_sepatu << endl;
        cout << "-------------------------------------" << endl;

        for (int j = 0; j < data_penjualan[i].banyak_jenis_sepatu; j++)
        {
            string jenis_sepatu = data_penjualan[i].detail[j].jenis_sepatu;
            int jumlah_membeli = data_penjualan[i].detail[j].kuantitas;
            int total_harga_sepatu = data_penjualan[i].detail[j].harga * jumlah_membeli;

            cout << " - " << jenis_sepatu << endl;
            cout << "  Jumlah Sepatu : " << jumlah_membeli << endl;
            cout << "  Total Harga   : " << total_harga_sepatu << endl;
            cout << "-------------------------------------" << endl;

            total_harga += total_harga_sepatu;
            total_kuantitas += jumlah_membeli;
        }

        nama_pembeli = data_penjualan[i].nama_pembeli;
        cout << "Nama Pembeli : " << nama_pembeli << endl;
        cout << "Rata-rata harga sepatu : " << (float)total_harga / total_kuantitas << endl;
        cout << "-------------------------------------" << endl;
    }

    cout << "Terima Kasih telah membeli di Vic Store Veteran!" << endl;
    cout << "Semoga Anda puas dengan pembelian Anda!" << endl;
    system("pause");
}