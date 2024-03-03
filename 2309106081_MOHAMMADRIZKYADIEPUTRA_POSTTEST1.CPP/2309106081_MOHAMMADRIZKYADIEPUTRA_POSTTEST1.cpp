// MOHAMMAD RIZKY ADIE PUTRA
// NIM : 2309106081
// KELAS : B'23

#include <iostream>
#include <string>

using namespace std;

// Tipe data adalah fungsi
typedef float (*FungsiKonversi)(float);

// Fungsi-fungsi konversi kecepatan
float kmKeCmPerDetik(float kecepatan) {
    return kecepatan * 100000 / 3600;
}

float kmKeMPerDetik(float kecepatan) {
    return kecepatan * 1000 / 3600;
}

float kmKeMilPerJam(float kecepatan) {
    return kecepatan * 0.621371;
}

float cmKeKmPerJam(float kecepatan) {
    return kecepatan / 100000 * 3600;
}

float cmKeMPerDetik(float kecepatan) {
    return kecepatan / 100;
}

float cmKeMilPerJam(float kecepatan) {
    return kecepatan * 0.0223694;
}

float mKeKmPerJam(float kecepatan) {
    return kecepatan / 1000 * 3600;
}

float mKeCmPerDetik(float kecepatan) {
    return kecepatan * 100;
}

float mKeMilPerJam(float kecepatan) {
    return kecepatan * 2.23694;
}

float milKeKmPerJam(float kecepatan) {
    return kecepatan * 1.60934;
}

float milKeCmPerDetik(float kecepatan) {
    return kecepatan * 44.704;
}

float milKeMPerDetik(float kecepatan) {
    return kecepatan * 0.44704;
}

int main() {
// Array dari fungsi konversi Di Atas
    FungsiKonversi fungsiKonversi[] = {
        kmKeCmPerDetik, kmKeMPerDetik, kmKeMilPerJam,
        cmKeKmPerJam, cmKeMPerDetik, cmKeMilPerJam,
        mKeKmPerJam, mKeCmPerDetik, mKeMilPerJam,
        milKeKmPerJam, milKeCmPerDetik, milKeMPerDetik
    };

    string nama, nim;
    int pilihan, salah_login = 0;
    float kecepatan;

// Loop pada login
    do {
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nama != "MohammadRizkyAdiePutra" || nim != "2309106081") {
            salah_login++;
            cout << "Nama atau NIM salah. Silakan coba lagi." << endl;
            if (salah_login == 3) {
                cout << "Anda salah memasukkan nama atau NIM sebanyak 3 kali. Program akan berhenti." << endl;
                return 0;
            }
        }
    } while (nama != "MohammadRizkyAdiePutra" || nim != "2309106081");
    cout << "\nSelamat datang, " << nama << "!\n";

// Menu - menu konversi kecepatan
    do {
        cout << "\nPilih jenis konversi kecepatan:\n";
        cout << "1. Kilometer/jam\n";
        cout << "2. Sentimeter/detik\n";
        cout << "3. Meter/detik\n";
        cout << "4. Mil/jam\n";
        cout << "0. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        if (pilihan == 0) {
            cout << "Terima kasih telah menggunakan program konversi kecepatan.\n";
            break;
        }
        else if (pilihan < 1 || pilihan > 4) {
            cout << "Pilihan tidak valid. Program berhenti.\n";
            break;
        }
        
// Input Kecepatannya
        cout << "Masukkan kecepatan: ";
        cin >> kecepatan;
        if (cin.fail()) {
            cout << "Masukan tidak valid. Program berhenti." << endl;
        return 0;
        }

        int indeksFungsi = (pilihan - 1) * 3;
        cout << "\nHasil konversi:\n";
        cout << "Sentimeter/detik: " << fungsiKonversi[indeksFungsi](kecepatan) << endl;
        cout << "Meter/detik: " << fungsiKonversi[indeksFungsi + 1](kecepatan) << endl;
        cout << "Mil/jam: " << fungsiKonversi[indeksFungsi + 2](kecepatan) << endl;

    } while (pilihan != 0);

    return 0;
}