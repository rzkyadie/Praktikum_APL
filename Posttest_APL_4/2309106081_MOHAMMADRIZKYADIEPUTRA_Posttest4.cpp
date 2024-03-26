// Mohammad Rizky Adie putra
// 2309106081
// B"23

#include <iostream>
#include <string>

using namespace std;

// Struktur untuk data tanggal penjualan
struct Tanggal
{
    int hari;
    int bulan;
    int tahun;
};

// Struktur untuk data penjualan laptop
struct Laptop
{
    string merk;
    string harga;
};

// Struktur utama untuk data penjualan
struct Penjualan
{
    Laptop dataLaptop;
    Tanggal tanggalPenjualan;
};

// Deklarasi fungsi
bool login(string namaBenar, string nimBenar);
void tambahData(Penjualan data[], int &jumlahData, int max_data);
void tampilkanData(Penjualan data[], int jumlahData);
void hapusData(Penjualan data[], int &jumlahData);
int menu();

// Fungsi utama
int main()
{
    int max_data = 100;
    Penjualan data[max_data];
    int jumlahData = 0;
    int pilihan;

    string namaBenar = "MohammadRizkyAdiePutra";
    string nimBenar = "2309106081";

    if (!login(namaBenar, nimBenar))
    {
        cout << "Anda telah salah memasukkan nama dan nim sebanyak 3 kali. Program berhenti." << endl;
        return 0;
    }

    do
    {
        pilihan = menu();
        switch (pilihan)
        {
        case 1:
            tambahData(data, jumlahData, max_data);
            break;
        case 2:
            tampilkanData(data, jumlahData);
            break;
        case 3:
            hapusData(data, jumlahData);
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

// Fungsi login
bool login(string namaBenar, string nimBenar)
{
    string nama, nim;
    for (int i = 0; i < 3; ++i)
    {
        cout << "\nMasukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        if (nama == namaBenar && nim == nimBenar)
        {
            cout << "Login berhasil." << endl;
            return true;
        }
        else
        {
            if (i < 2)
                cout << "Login gagal. Silakan coba lagi." << endl;
        }
    }
    return false;
}

// Prosedur untuk menambahkan data penjualan laptop
void tambahData(Penjualan data[], int &jumlahData, int max_data)
{
    if (jumlahData < max_data)
    {
        cout << "Masukkan Merk Laptop: ";
        cin.ignore();
        getline(cin, data[jumlahData].dataLaptop.merk);
        cout << "Masukkan Harga Laptop: ";
        getline(cin, data[jumlahData].dataLaptop.harga);
        cout << "Masukkan Tanggal Penjualan (DD MM YYYY): ";
        cin >> data[jumlahData].tanggalPenjualan.hari >> data[jumlahData].tanggalPenjualan.bulan >> data[jumlahData].tanggalPenjualan.tahun;
        jumlahData++;
        cout << "\nData penjualan laptop berhasil ditambahkan." << endl;
    }
    else
    {
        cout << "Kapasitas penyimpanan data sudah penuh." << endl;
    }
}

// Prosedur untuk menampilkan data penjualan laptop
void tampilkanData(Penjualan data[], int jumlahData)
{
    if (jumlahData > 0)
    {
        cout << "\n===== DATA PENJUALAN LAPTOP =====" << endl;
        for (int i = 0; i < jumlahData; ++i)
        {
            cout << "Merk: " << data[i].dataLaptop.merk << ", Harga: " << data[i].dataLaptop.harga;
            cout << ", Tanggal Penjualan: " << data[i].tanggalPenjualan.hari << "/" << data[i].tanggalPenjualan.bulan << "/" << data[i].tanggalPenjualan.tahun << endl;
        }
    }
    else
    {
        cout << "Belum ada data penjualan laptop yang tersedia." << endl;
    }
}

// Prosedur buat menghapus data penjualan laptop
void hapusData(Penjualan data[], int &jumlahData)
{
    if (jumlahData > 0)
    {
        string merk;
        cout << "Masukkan Merk Laptop yang Ingin Dihapus: ";
        cin.ignore();
        getline(cin, merk);
        bool ditemukan = false;
        for (int i = 0; i < jumlahData; ++i)
        {
            if (data[i].dataLaptop.merk == merk)
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
    else
    {
        cout << "Tidak ada data yang bisa dihapus karena belum ada data yang tersedia." << endl;
    }
}

// Fungsi untuk menampilkan menu dan mengembalikan pilihan
int menu()
{
    int pilihan;
    cout << "\n       ===== MENU =====" << endl;
    cout << "1. Tambah Data Penjualan" << endl;
    cout << "2. Tampilkan Data Penjualan" << endl;
    cout << "3. Hapus Data Penjualan" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
    return pilihan;
}