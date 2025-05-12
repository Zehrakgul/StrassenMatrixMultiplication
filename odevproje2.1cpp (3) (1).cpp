#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//matris aciklaniyor
void print_matrix(vector<vector<int>> &matrix) {
    for (auto &row : matrix) {
        for (auto &col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}
//matrislerin toplamini yapan fonksiyon
vector<vector<int>> add_matrix(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    int row = matrix1.size();
    int col = matrix1[0].size();
    vector<vector<int>> result(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0 ; j < col; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}
//matrislerin cikarilmasini yapan fonksiyon
vector<vector<int>> sub_matrix(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    int row = matrix1.size();
    int col = matrix1[0].size();
    vector<vector<int>> result(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0 ; j < col; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}
//Strassen algoritmasiyla matris carpimi yapan fonksiyon
vector<vector<int>> strassen_matrix_multiplication(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    int row = matrix1.size();
    int col = matrix1[0].size();
    vector<vector<int>> result(row, vector<int>(col, 0));

//matris boyutu 1*1 ise dogrudan carpma islemini gerceklestirecek olan kod
    if (row == 1 && col == 1) {
        result[0][0] = matrix1[0][0] * matrix2[0][0];
        return result;
    }

//matrisleri 4 alt parcaya bolebilmek icin yeni boyutlar
    int new_row = row / 2;
    int new_col = col / 2;


//8 küçük matris olusturuluyor
    vector<vector<int>> a(new_row, vector<int>(new_col, 0));
    vector<vector<int>> b(new_row, vector<int>(new_col, 0));
    vector<vector<int>> c(new_row, vector<int>(new_col, 0));
    vector<vector<int>> d(new_row, vector<int>(new_col, 0));
    vector<vector<int>> e(new_row, vector<int>(new_col, 0));
    vector<vector<int>> f(new_row, vector<int>(new_col, 0));
    vector<vector<int>> g(new_row, vector<int>(new_col, 0));
    vector<vector<int>> h(new_row, vector<int>(new_col, 0));

//matrisleri alt matrislere bölme islemi
     for (int i = 0; i < new_row; i++) {
        for (int j = 0; j < new_col; j++) {
            a[i][j] = matrix1[i][j];
            b[i][j] = matrix1[i][j + new_col];
            c[i][j] = matrix1[i + new_row][j];
            d[i][j] = matrix1[i + new_row][j + new_col];
            e[i][j] = matrix2[i][j];
            f[i][j] = matrix2[i][j + new_col];
            g[i][j] = matrix2[i + new_row][j];
            h[i][j] = matrix2[i + new_row][j + new_col];
        }
    }

//Strassen algoritmasinin ozel kombinasyonlari
    vector<vector<int>> ts1 = sub_matrix(f, h);
    vector<vector<int>> ts2 = add_matrix(a, b);
    vector<vector<int>> ts3 = add_matrix(c, d);
    vector<vector<int>> ts4 = sub_matrix(g, e);
    vector<vector<int>> ts5 = add_matrix(a, d);
    vector<vector<int>> ts6 = add_matrix(e, h);
    vector<vector<int>> ts7 = sub_matrix(b, d);
    vector<vector<int>> ts8 = add_matrix(g, h);
    vector<vector<int>> ts9 = sub_matrix(a, c);
    vector<vector<int>> ts10 = add_matrix(e, f);

//Strassen carpimi
    vector<vector<int>> p1 = strassen_matrix_multiplication(a,ts1);
    vector<vector<int>> p2 = strassen_matrix_multiplication(ts2,h);
    vector<vector<int>> p3 = strassen_matrix_multiplication(ts3,e);
    vector<vector<int>> p4 = strassen_matrix_multiplication(d,ts4);
    vector<vector<int>> p5 = strassen_matrix_multiplication(ts5,ts6);
    vector<vector<int>> p6 = strassen_matrix_multiplication(ts7,ts8);
    vector<vector<int>> p7 = strassen_matrix_multiplication(ts9,ts10);

//alt matrisleri birlestirme
    vector<vector<int>> tempA1 = add_matrix(p5,p4);
    vector<vector<int>> tempA2 = sub_matrix(tempA1,p2);
    vector<vector<int>> c11 = add_matrix(tempA2,p6);
    vector<vector<int>> c12 = add_matrix(p1,p2);
    vector<vector<int>> c21 = add_matrix(p3,p4);
    vector<vector<int>> tempA3 = add_matrix(p5,p1);
    vector<vector<int>> tempA4 = sub_matrix(tempA3,p3);
    vector<vector<int>> c22 = sub_matrix(tempA4,p7);

// 4 kücük matrisi birlestirerek sonucu olusturur
    for (int i = 0; i < new_row; i++) {
        for (int j = 0; j < new_col; j++) {
            result[i][j] = c11[i][j];
            result[i][j + new_col] = c12[i][j];
            result[i + new_row][j] = c21[i][j];
            result[i + new_row][j + new_col] = c22[i][j];
        }
    }
    return result;
}
int main(void) {


//girdi alma,islem yapma ve sonucu yazdirma
    int n;
    cout << "matrix boyutunu giriniz: "<< endl;
    cin >> n;

//n*n boyutunda 2 matris olustur
    vector<vector<int>> matrix1(n, vector<int>(n, 0));
    vector<vector<int>> matrix2(n, vector<int>(n, 0));

//1. matris girdisi
     cout << "matrix1 giriniz: " << endl;
    for (auto &row : matrix1) {
        for (auto &col : row) {
            cin >> col;
        }
    }
//2. matris girdisi
cout << "matrix2 giriniz: " << endl;
    for (auto &row : matrix2) {
        for (auto &col : row) {
            cin >> col;
        }
    }
//Strassen algoritmasiyla carpma ve sonucu yazdirma
   vector<vector<int>> result = strassen_matrix_multiplication(matrix1, matrix2);

    cout << "result: " << endl;
    print_matrix(result);
    return 0;
}
