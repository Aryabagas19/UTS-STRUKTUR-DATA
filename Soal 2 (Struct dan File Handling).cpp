#include <iostream>
#include <fstream>
#include <string>

struct Peralatan {
    std::string kode;
    std::string nama;
    int jumlah;
    std::string kondisi;
};

// Fungsi untuk menambah peralatan
void tambahPeralatan(const std::string& kode, const std::string& nama, int jumlah, const std::string& kondisi) {
    Peralatan alat = {kode, nama, jumlah, kondisi};
    
    // Membuka file untuk menambahkan data
    std::ofstream file("inventaris.txt", std::ios::app);
    if (file.is_open()) {
        file << alat.kode << "," << alat.nama << "," << alat.jumlah << "," << alat.kondisi << std::endl;
        file.close();
        std::cout << "Data peralatan berhasil ditambahkan." << std::endl;
    } else {
        std::cerr << "Gagal membuka file untuk menulis." << std::endl;
    }
}

// Fungsi untuk menampilkan peralatan
void tampilkanPeralatan() {
    std::ifstream file("inventaris.txt");
    if (!file.is_open()) {
        std::cerr << "Gagal membuka file untuk membaca." << std::endl;
        return;
    }
    
    std::string line;
    std::cout << "Daftar Peralatan:" << std::endl;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

int main() {
    int pilihan;

    do {
        // Menampilkan menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Tambah Peralatan\n";
        std::cout << "2. Tampilkan Daftar Peralatan\n";
        std::cout << "3. Keluar\n";
        std::cout << "Pilih opsi (1-3): ";
        std::cin >> pilihan;

        // Menangani pilihan
        switch (pilihan) {
            case 1: {
                std::string kode, nama, kondisi;
                int jumlah;
                
                std::cout << "Masukkan Kode Peralatan: ";
                std::cin >> kode;
                std::cout << "Masukkan Nama Peralatan: ";
                std::cin.ignore();
                std::getline(std::cin, nama);
                std::cout << "Masukkan Jumlah: ";
                std::cin >> jumlah;
                std::cout << "Masukkan Kondisi (Baik/Rusak): ";
                std::cin.ignore();
                std::getline(std::cin, kondisi);
                
                tambahPeralatan(kode, nama, jumlah, kondisi);
                break;
            }
            case 2:
                tampilkanPeralatan();
                break;
            case 3:
                std::cout << "Keluar dari program." << std::endl;
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi." << std::endl;
        }
    } while (pilihan != 3);

    return 0;
}
