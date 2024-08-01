#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<double>> Matrix;

// Function to perform LU Decomposition
void LUDecomposition(const Matrix& A, Matrix& L, Matrix& U) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        // Upper Triangular
        for (int k = i; k < n; ++k) {
            double sum = 0;
            for (int j = 0; j < i; ++j)
                sum += (L[i][j] * U[j][k]);
            U[i][k] = A[i][k] - sum;
        }

        // Lower Triangular
        for (int k = i; k < n; ++k) {
            if (i == k)
                L[i][i] = 1;  // Diagonal as 1
            else {
                double sum = 0;
                for (int j = 0; j < i; ++j)
                    sum += (L[k][j] * U[j][i]);
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(const Matrix& M) {
    int n = M.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Matrix A = {{4, 3},
                {6, 3}};

    int n = A.size();
    Matrix L(n, vector<double>(n, 0));
    Matrix U(n, vector<double>(n, 0));

    LUDecomposition(A, L, U);

    cout << "Lower Triangular Matrix L:" << endl;
    printMatrix(L);

    cout << "Upper Triangular Matrix U:" << endl;
    printMatrix(U);

    return 0;
}
