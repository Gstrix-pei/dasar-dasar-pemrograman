#include <iostream>
#include <string>
using namespace std;

const int MAX_BUKU = 100; 

struct Buku {
    int id;
    string judul;
    string pengarang;
    double harga;
};

void tampilkanMenu() {
    cout << "Menu:\n";
    cout << "1. Tambah Buku\n";
    cout << "2. Tampilkan Daftar Buku\n";
    cout << "3. Ubah Data Buku\n";
    cout << "4. Hapus Buku\n";
    cout << "5. Hitung Total Harga Pembelian dengan Diskon\n";
    cout << "6. Keluar\n";
    cout << "Pilih opsi: ";
}

 void tambahBuku(Buku daftarBuku[], int& jumlahBuku) {
    int jumlah;
    cout << "Masukkan jumlah buku yang ingin diinput: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        if (jumlahBuku < MAX_BUKU) {
            cout << "Masukkan ID buku: ";
            cin >> daftarBuku[jumlahBuku].id;
            cin.ignore();
            cout << "Judul Buku: ";
            getline(cin, daftarBuku[jumlahBuku].judul);
            cout << "Nama Pengarang: ";
            getline(cin, daftarBuku[jumlahBuku].pengarang);
            cout << "Harga: ";
            cin >> daftarBuku[jumlahBuku].harga;
            jumlahBuku++;
            cout << "\nBuku berhasil ditambahkan ke daftar.\n";
        } else {
            cout << "Maaf, daftar buku sudah penuh.\n";
            break;
        }
    }
}
void tampilkanDaftarBuku(Buku daftarBuku[], int jumlahBuku) {
    string ok;
    if (jumlahBuku == 0) {
        cout << "Tidak ada buku dalam daftar.\n";
    } else {
        cout << "Daftar Buku:\n";
        for (int i = 0; i < jumlahBuku; i++) {
            cout << "ID Buku: " << daftarBuku[i].id << endl;
            cout << "Judul: " << daftarBuku[i].judul << endl;
            cout << "Pengarang: " << daftarBuku[i].pengarang << endl;
            cout << "Harga: Rp" << daftarBuku[i].harga << endl;
            cout << endl;
        }
    }
    cin.ignore();
    cout << "dah? :";
    cin >> ok;
}

void ubahDataBuku(Buku daftarBuku[], int jumlahBuku) {
    if (jumlahBuku == 0) {
        cout << "Tidak ada buku dalam daftar.\n";
        return;
    }

    int idBuku;
    bool ditemukan = false;
    cout << "Masukkan ID buku yang ingin diubah: ";
    cin >> idBuku;

    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].id == idBuku) {
            ditemukan = true;
            cout << "Judul Baru: ";
            cin.ignore();
            getline(cin, daftarBuku[i].judul);
            cout << "Nama Pengarang Baru: ";
            getline(cin, daftarBuku[i].pengarang);
            cout << "Harga Baru: ";
            cin >> daftarBuku[i].harga;
            cout << "Data berhasil diperbarui.\n";
            break;
        }
    }

    if (!ditemukan) {
        cout << "Buku dengan ID tersebut tidak ditemukan.\n";
    }
}

void hapusBuku(Buku daftarBuku[], int& jumlahBuku) {
    if (jumlahBuku == 0) {
        cout << "Tidak ada buku dalam daftar.\n";
        return;
    }

    int idBuku;
    bool ditemukan = false;
    cout << "Masukkan ID buku yang ingin dihapus: ";
    cin >> idBuku;

    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].id == idBuku) {
            ditemukan = true;
            for (int j = i; j < jumlahBuku - 1; j++) {
                daftarBuku[j] = daftarBuku[j + 1];
            }
            jumlahBuku--;
            cout << "Buku berhasil dihapus.\n";
            break;
        }
    }

    if (!ditemukan) {
        cout << "Buku dengan ID tersebut tidak ditemukan.\n";
    }
}
void hitungTotalHarga(Buku daftarBuku[], int jumlahBuku) {
    if (jumlahBuku == 0) {
        cout << "Tidak ada buku dalam daftar.\n";
        return;
    }

    int jumlahBeli;
    cout << "Masukkan jumlah buku yang ingin dibeli: ";
    cin >> jumlahBeli;

    int idBuku;
    double total = 0.0;
    string pengarangPertama = "";
    int bukuDariPengarangSama = 0;

    for (int i = 0; i < jumlahBeli; i++) {
        cout << "Masukkan ID buku yang ingin dibeli: ";
        cin >> idBuku;

        bool ditemukan = false;
        for (int j = 0; j < jumlahBuku; j++) {
            if (daftarBuku[j].id == idBuku) {
                total += daftarBuku[j].harga;

                // Periksa apakah buku dari pengarang yang sama
                if (i == 0) {
                    pengarangPertama = daftarBuku[j].pengarang;
                } else if (pengarangPertama == daftarBuku[j].pengarang) {
                    bukuDariPengarangSama++;
                }

                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            cout << "ID buku " << idBuku << " tidak ditemukan dalam daftar.\n";
        }
    }

    // Terapkan diskon 5% jika ada 2 atau lebih buku dari pengarang yang sama
    if (bukuDariPengarangSama >= 1) {
        cout << "Diskon 5% diterapkan karena Anda membeli minimal dua buku dari pengarang yang sama.\n";
        total *= 0.95;
    }

    // Memasukkan kode voucher untuk diskon tambahan
    string kodeVoucher;
    cout << "Masukkan kode voucher (Kosongkan jika tidak ada): ";
    cin.ignore();
    getline(cin, kodeVoucher);

    if (kodeVoucher == "JPYUM") {
        cout << "Diskon 10% dari voucher 'JPYUM' diterapkan.\n";
        total *= 0.9;
    }

    // Tampilkan total akhir
    cout << "Total harga setelah diskon (jika ada): Rp" << total << endl;
}


int main() {
    Buku daftarBuku[MAX_BUKU];
    int jumlahBuku = 0;
    int opsi;

    do {
        tampilkanMenu();
        cin >> opsi;
        switch (opsi) {
            case 1:
                tambahBuku(daftarBuku, jumlahBuku);
                break;
            case 2:
                tampilkanDaftarBuku(daftarBuku, jumlahBuku);
                break;
            case 3:
                ubahDataBuku(daftarBuku, jumlahBuku);
                break;
            case 4:
                hapusBuku(daftarBuku, jumlahBuku);
                break;
            case 5:
                hitungTotalHarga(daftarBuku, jumlahBuku);
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Opsi tidak valid. Silakan pilih lagi.\n";
        }
    } while (opsi != 6);

    return 0;
}