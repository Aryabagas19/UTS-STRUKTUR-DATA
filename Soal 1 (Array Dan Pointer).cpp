#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Mahasiswa {
    string NIM;
    string nama;
    float IPK;
};

void tambahMahasiswa(Mahasiswa* mhs[], int& jumlah, const string& nim, const string& nama, float ipk) {
    if (jumlah < 10) {
        mhs[jumlah] = new Mahasiswa{nim, nama, ipk};
        jumlah++;
    } else {
        cout << "Data penuh!" << endl;
    }
}

void hapusMahasiswa(Mahasiswa* mhs[], int& jumlah, const string& nim) {
    for (int i = 0; i < jumlah; i++) {
        if (mhs[i]->NIM == nim) {
            delete mhs[i];
            for (int j = i; j < jumlah - 1; j++) {
                mhs[j] = mhs[j + 1];
            }
            jumlah--;
            cout << "Data mahasiswa dengan NIM " << nim << " dihapus." << endl;
            return;
        }
    }
    cout << "Mahasiswa dengan NIM tersebut tidak ditemukan." << endl;
}

void tampilkanMahasiswa(Mahasiswa* mhs[], int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada data mahasiswa." << endl;
        return;
    }
    for (int i = 0; i < jumlah; i++) {
        cout << "NIM: " << mhs[i]->NIM << ", Nama: " << mhs[i]->nama << ", IPK: " << mhs[i]->IPK << endl;
    }
}

void urutkanMahasiswa(Mahasiswa* mhs[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (mhs[j]->IPK < mhs[j + 1]->IPK) {
                swap(mhs[j], mhs[j + 1]);
            }
        }
    }
    cout << "Data mahasiswa telah diurutkan berdasarkan IPK." << endl;
}

int main() {
    Mahasiswa* mhs[10] = {nullptr}; // Array untuk menyimpan pointer ke mahasiswa
    int jumlah = 0; // Jumlah mahasiswa yang ada
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Hapus Mahasiswa\n";
        cout << "3. Tampilkan Mahasiswa\n";
        cout << "4. Urutkan Mahasiswa Berdasarkan IPK\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nim, nama;
                float ipk;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan IPK: ";
                cin >> ipk;
                tambahMahasiswa(mhs, jumlah, nim, nama, ipk);
                break;
            }
            case 2: {
                string nim;
                cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
                cin >> nim;
                hapusMahasiswa(mhs, jumlah, nim);
                break;
            }
            case 3:
                cout << "Data Mahasiswa:\n";
                tampilkanMahasiswa(mhs, jumlah);
                break;
            case 4:
                urutkanMahasiswa(mhs, jumlah);
                cout << "Data Mahasiswa Setelah Diurutkan Berdasarkan IPK:\n";
                tampilkanMahasiswa(mhs, jumlah);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    for (int i = 0; i < jumlah; i++) {
        delete mhs[i];
    }

    return 0;
}
