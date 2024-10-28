#include <iostream>
#include <stack>
#include <string>
#include <cmath>

class Stack {
private:
    std::stack<double> s;
public:
    void push(double val) { s.push(val); }
    void pop() { if (!s.empty()) s.pop(); }
    double top() { return s.top(); }
    bool isEmpty() { return s.empty(); }
};

// Fungsi untuk mengevaluasi ekspresi postfix
double evaluatePostfix(const std::string& expr) {
    Stack stack;
    for (char c : expr) {
        if (isdigit(c)) {
            stack.push(c - '0'); // Konversi karakter angka ke nilai numeriknya
        } else {
            double op2 = stack.top(); stack.pop();
            double op1 = stack.top(); stack.pop();
            switch (c) {
                case '+': stack.push(op1 + op2); break;
                case '-': stack.push(op1 - op2); break;
                case '*': stack.push(op1 * op2); break;
                case '/': stack.push(op1 / op2); break;
                case '^': stack.push(pow(op1, op2)); break;
                default: 
                    std::cerr << "Operator tidak dikenali: " << c << std::endl;
                    return 0;
            }
        }
    }
    return stack.top();
}

int main() {
    int pilihan;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Evaluasi Ekspresi Postfix\n";
        std::cout << "2. Keluar\n";
        std::cout << "Pilih opsi (1-2): ";
        std::cin >> pilihan;

        if (pilihan == 1) {
            std::string expr;
            std::cout << "Masukkan ekspresi postfix: ";
            std::cin >> expr;

            double hasil = evaluatePostfix(expr);
            std::cout << "Hasil evaluasi: " << hasil << std::endl;
        } else if (pilihan == 2) {
            std::cout << "Keluar dari program.\n";
        } else {
            std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 2);

    return 0;
}
