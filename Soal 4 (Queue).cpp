#include <iostream>
#include <queue>
#include <string>

struct Pelanggan {
    int nomor;
    int waktu_layanan;
};

class Queue {
private:
    std::queue<Pelanggan> q;
    int total_waktu_layanan = 0; // Menyimpan total waktu layanan untuk statistik
public:
    void enqueue(Pelanggan p) {
        q.push(p);
        total_waktu_layanan += p.waktu_layanan;
        std::cout << "Pelanggan nomor " << p.nomor << " telah masuk ke antrian dengan waktu layanan " << p.waktu_layanan << " menit.\n";
    }

    void dequeue() {
        if (!q.empty()) {
            Pelanggan p = q.front();
            total_waktu_layanan -= p.waktu_layanan;
            std::cout << "Pelanggan nomor " << p.nomor << " selesai dilayani.\n";
            q.pop();
        } else {
            std::cout << "Antrian kosong.\n";
        }
    }

    bool isEmpty() {
        return q.empty();
    }

    Pelanggan front() {
        return q.front();
    }

    int getTotalWaktuLayanan() {
        return total_waktu_layanan;
    }

    int getJumlahPelanggan() {
        return q.size();
    }

    double getRataRataWaktuLayanan() {
        if (q.size() > 0) {
            return static_cast<double>(total_waktu_layanan) / q.size();
        } else {
            return 0;
        }
    }
};

int main() {
    Queue layanan;
    int pilihan;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Tambah Pelanggan ke Antrian\n";
        std::cout << "2. Layani Pelanggan\n";
        std::cout << "3. Tampilkan Statistik Antrian\n";
        std::cout << "4. Keluar\n";
        std::cout << "Pilih opsi (1-4): ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int nomor, waktu_layanan;
                std::cout << "Masukkan nomor pelanggan: ";
                std::cin >> nomor;
                std::cout << "Masukkan waktu layanan (dalam menit): ";
                std::cin >> waktu_layanan;

                layanan.enqueue({nomor, waktu_layanan});
                break;
            }
            case 2:
                layanan.dequeue();
                break;
            case 3:
                std::cout << "\nStatistik Antrian:\n";
                std::cout << "Jumlah Pelanggan dalam Antrian: " << layanan.getJumlahPelanggan() << "\n";
                std::cout << "Total Waktu Layanan yang Tersisa: " << layanan.getTotalWaktuLayanan() << " menit\n";
                std::cout << "Rata-rata Waktu Layanan per Pelanggan: " << layanan.getRataRataWaktuLayanan() << " menit\n";
                break;
            case 4:
                std::cout << "Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}
