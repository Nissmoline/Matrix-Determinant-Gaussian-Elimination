#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int n = 3;
double A[n][n] = {
    {3.1, 2.8, 1.9},
    {1.9, 3.1, 2.1},
    {7.5, 3.8, 4.8}
};

void printMatrix() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) << setprecision(3) << A[i][j] << " ";
        }
        cout << endl;
    }
}

double determinant() {
    double det = 1.0;
    for (int i = 0; i < n; ++i) {
        int maxIdx = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(A[k][i]) > abs(A[maxIdx][i])) {
                maxIdx = k;
            }
        }

        if (abs(A[maxIdx][i]) < 1e-9) {
            return 0;
        }

        if (i != maxIdx) {
            for (int j = 0; j < n; ++j) {
                swap(A[i][j], A[maxIdx][j]);
            }
            det *= -1;
        }

        det *= A[i][i];

        for (int k = i + 1; k < n; ++k) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < n; ++j) {
                A[k][j] -= factor * A[i][j];
            }
        }

        cout << "Intermediate matrices " << i + 1 << ":" << endl;
        printMatrix();
    }
    return det;
}
int main() {
    setlocale(LC_ALL, "");
    cout << "Original matrix:" << endl;
    printMatrix();
    double det = determinant();
    cout << "\nDeterminant value: " << det << endl;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
}