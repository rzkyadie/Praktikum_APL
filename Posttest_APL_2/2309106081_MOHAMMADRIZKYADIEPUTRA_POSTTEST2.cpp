// Mohammad Rizky Adie Putra
// 2309106081
// B'23

#include <iostream>
#include <string>

using namespace std;

// Struktur buat data penjualan laptop
struct Laptop
{
    string merk;
    string harga;
};

// Fungsi utama
int main()
{
    const int max_data = 100;
    Laptop data[max_data];
    int jumlahData = 0;
    int pilihan;
    string nama, nim;

// Menu login
    string namaBenar = "MohammadRizkyAdiePutra";
    string nimBenar = "2309106081";
    for (int i = 0; i < 3; ++i)
    {
        cout << "\nMasukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        if (nama == namaBenar && nim == nimBenar)
        {
            cout << "Login berhasil." << endl;
            break;
        }
        else
        {
            if (i < 2)
                cout << "Login gagal. Silakan coba lagi." << endl;
            else
            {
                cout << "Anda telah salah memasukkan nama dan nim sebanyak 3 kali. Program berhenti." << endl;
                return 0;
            }
        }
    }

    do
    {

// Menampilkan menu-menu Data
        cout << "       ===== MENU =====" << endl;
        cout << "1. Tambah Data Penjualan" << endl;
        cout << "2. Tampilkan Data Penjualan" << endl;
        cout << "3. Hapus Data Penjualan" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            if (jumlahData < max_data)
            {
                cout << "Masukkan Merk Laptop: ";
                cin.ignore();
                getline(cin, data[jumlahData].merk);
                cout << "Masukkan Harga Laptop: ";
                getline(cin, data[jumlahData].harga);
                jumlahData++;
                cout << "\nData penjualan laptop berhasil ditambahkan." << endl;
            }
            else
            {
                cout << "Kapasitas penyimpanan data sudah penuh." << endl;
            }
            break;
        case 2:
            cout << "\n===== DATA PENJUALAN LAPTOP =====" << endl;
            for (int i = 0; i < jumlahData; ++i)
            {
                cout << "Merk: " << data[i].merk << ", Harga: " << data[i].harga << endl;
            }
            break;

        case 3:
        {
            string merk;
            cout << "Masukkan Merk Laptop yang Ingin Dihapus: ";
            cin.ignore();
            getline(cin, merk);
            bool ditemukan = false;
            for (int i = 0; i < jumlahData; ++i)
            {
                if (data[i].merk == merk)
                {
                    for (int j = i; j < jumlahData - 1; ++j)
                    {
                        data[j] = data[j + 1];
                    }
                    jumlahData--;
                    ditemukan = true;
                    cout << "Data penjualan laptop dengan merk " << merk << " berhasil dihapus." << endl;
                    break;
                }
            }
            if (!ditemukan)
            {
                cout << "Data penjualan laptop dengan merk " << merk << " tidak ditemukan." << endl;
            }
        }
        break;

        case 4:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan pilih menu lain." << endl;
        }
    } while (pilihan != 4);

    return 0;
}