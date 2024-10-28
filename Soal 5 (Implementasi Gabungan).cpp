#include <iostream>
#include <queue>
#include <stack>
#include <string>

struct Buku {
    std::string ISBN;
    std::string judul;
    std::string pengarang;
    int tahun;
};

class Perpustakaan {
private:
    std::queue<Buku> antrianPeminjaman;
    std::stack<Buku> riwayatPeminjaman;
public:
    // Fungsi untuk menambah buku (dalam konteks menambah ke koleksi perpustakaan)
    void tambahBuku(const Buku& buku) {
        std::cout << "Buku \"" << buku.judul << "\" oleh " << buku.pengarang << " ditambahkan ke perpustakaan.\n";
    }
    
    // Fungsi untuk meminjam buku, menambahnya ke antrian peminjaman
    void pinjamBuku(const Buku& buku) {
        antrianPeminjaman.push(buku);
        std::cout << "Buku \"" << buku.judul << "\" dipinjam.\n";
    }

    // Fungsi untuk mengembalikan buku dari antrian peminjaman ke riwayat peminjaman
    void kembalikanBuku() {
        if (!antrianPeminjaman.empty()) {
            Buku buku = antrianPeminjaman.front();
            antrianPeminjaman.pop();
            riwayatPeminjaman.push(buku);
            std::cout << "Buku \"" << buku.judul << "\" dikembalikan.\n";
        } else {
            std::cout << "Tidak ada buku yang sedang dipinjam.\n";
        }
    }

    // Fungsi untuk menampilkan riwayat peminjaman
    void tampilkanRiwayat() {
        if (riwayatPeminjaman.empty()) {
            std::cout << "Riwayat peminjaman kosong.\n";
        } else {
            std::stack<Buku> temp = riwayatPeminjaman;
            std::cout << "Riwayat Peminjaman Buku:\n";
            while (!temp.empty()) {
                Buku buku = temp.top();
                std::cout << "- " << buku.judul << " (" << buku.tahun << ") oleh " << buku.pengarang << "\n";
                temp.pop();
            }
        }
    }

    // Fungsi untuk menampilkan daftar antrian peminjaman saat ini
    void tampilkanAntrianPeminjaman() {
        if (antrianPeminjaman.empty()) {
            std::cout << "Tidak ada buku dalam antrian peminjaman.\n";
        } else {
            std::queue<Buku> temp = antrianPeminjaman;
            std::cout << "Daftar Buku dalam Antrian Peminjaman:\n";
            while (!temp.empty()) {
                Buku buku = temp.front();
                std::cout << "- " << buku.judul << " oleh " << buku.pengarang << "\n";
                temp.pop();
            }
        }
    }

    // Fungsi untuk menampilkan buku yang sedang dipinjam
    void tampilkanBukuDipinjam() {
        if (!antrianPeminjaman.empty()) {
            Buku buku = antrianPeminjaman.front();
            std::cout << "Buku yang sedang dipinjam:\n";
            std::cout << "- " << buku.judul << " (" << buku.tahun << ") oleh " << buku.pengarang << "\n";
        } else {
            std::cout << "Tidak ada buku yang sedang dipinjam.\n";
        }
    }
};

int main() {
    Perpustakaan lib;
    int pilihan;
    
    do {
        std::cout << "\nMenu Perpustakaan:\n";
        std::cout << "1. Tambah Buku ke Koleksi\n";
        std::cout << "2. Pinjam Buku\n";
        std::cout << "3. Kembalikan Buku\n";
        std::cout << "4. Tampilkan Buku yang Sedang Dipinjam\n";
        std::cout << "5. Tampilkan Riwayat Peminjaman\n";
        std::cout << "6. Tampilkan Daftar Antrian Peminjaman\n";
        std::cout << "7. Keluar\n";
        std::cout << "Pilih opsi (1-7): ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1: {
                std::string ISBN, judul, pengarang;
                int tahun;
                std::cout << "Masukkan ISBN: ";
                std::cin >> ISBN;
                std::cout << "Masukkan Judul Buku: ";
                std::cin.ignore();
                std::getline(std::cin, judul);
                std::cout << "Masukkan Pengarang: ";
                std::getline(std::cin, pengarang);
                std::cout << "Masukkan Tahun Terbit: ";
                std::cin >> tahun;

                Buku buku = {ISBN, judul, pengarang, tahun};
                lib.tambahBuku(buku);
                break;
            }
            case 2: {
                std::string ISBN, judul, pengarang;
                int tahun;
                std::cout << "Masukkan ISBN Buku yang Dipinjam: ";
                std::cin >> ISBN;
                std::cout << "Masukkan Judul Buku: ";
                std::cin.ignore();
                std::getline(std::cin, judul);
                std::cout << "Masukkan Pengarang: ";
                std::getline(std::cin, pengarang);
                std::cout << "Masukkan Tahun Terbit: ";
                std::cin >> tahun;

                Buku buku = {ISBN, judul, pengarang, tahun};
                lib.pinjamBuku(buku);
                break;
            }
            case 3:
                lib.kembalikanBuku();
                break;
            case 4:
                lib.tampilkanBukuDipinjam();
                break;
            case 5:
                lib.tampilkanRiwayat();
                break;
            case 6:
                lib.tampilkanAntrianPeminjaman();
                break;
            case 7:
                std::cout << "Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 7);

    return 0;
}
