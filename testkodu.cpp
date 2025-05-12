#include <iostream>
#include <vector>
using namespace std;

//matris toplama fonksiyonu
vector<vector<int>> add_matrix(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2){
    int n = matrix1.size();
    vector<vector<int>> result(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        result[i][j] = matrix1[i][j] + matrix2[i][j];
    return result;

}

//matris cikarma fonksiyonu
vector<vector<int>>  sub_matrix(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2){
    int n =matrix1.size();
    vector<vector<int>> result(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        result[i][j] = matrix1[i][j] - matrix2[i][j];
    return result;
}

//klasik matris carpimi (strassen degil)
vector<vector<int>> classic_matrix_multiplication(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2){
    int n = matrix1.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
                result[i][j] += matrix1[i][k] * matrix2[k][j]; //matris carpimi yapilacak
    return result;
}

//matris karsilastirma fonksiyonu
bool matrices_equal(const vector<vector<int>> &matrix1, const vector<vector<int>> matrix2){
    int n = matrix1.size();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(matrix1[i][j] != matrix2[i][j])
                return false;
    return true;
}

//test sonuclarini yazdiran fonksiyon
void print_test_result(const string &test_name, bool passed){
    cout << "[ " << (passed ? "GECTI?" : "KALDI") << " ] "<<test_name<<endl;

}

//***************************TEST FONKSIYONLARI**************************************
void test_matrix_addition() {
    vector<vector<int>> matrix1 = {{1, 2}, {3, 4}};
    vector<vector<int>> matrix2 = {{5, 6}, {7, 8}};
    vector<vector<int>> expected = {{6, 8}, {10, 12}};
    auto result = add_matrix(matrix1, matrix2);
    print_test_result("Matris Toplama Testi", matrices_equal(result, expected));
}
void test_matrix_subtraction(){
    vector<vector<int>> matrix1 = {{1, 2},{3, 4}};
    vector<vector<int>> matrix2 = {{5, 6},{7, 8}};
    vector<vector<int>> expected = {{-4, -4},{-4, -4}};
    auto result = sub_matrix(matrix1, matrix2);
    print_test_result("Matris Cikarma Testi", matrices_equal(result, expected));
}

void test_classic_multiplication() {
    vector<vector<int>> matrix1 = {{1, 2}, {3, 4}};
    vector<vector<int>> matrix2 = {{5, 6}, {7, 8}};
    vector<vector<int>> expected = {{19, 22}, {43, 50}};
    auto result = classic_matrix_multiplication(matrix1, matrix2);
    print_test_result("Matris Carpimi Testi", matrices_equal(result, expected));
}

void test_identity_multiplication() {
    vector<vector<int>> identity = {{1, 0},{0, 1}};
    vector<vector<int>> matrix1 = {{9, 8},{7, 6}};
    vector<vector<int>> expected = {{9, 8},{7, 6}};
    auto result = classic_matrix_multiplication(identity, matrix1);
    print_test_result("Birim Matris ile Carpim Testi", matrices_equal(result, expected));
}

//************************ANA FONKSIYON*************************************
int main() {
    cout << "--------Matris Islemleri Test Baslangici-------\n" << endl;
    test_matrix_addition();
    test_matrix_subtraction();
    test_classic_multiplication();
    test_identity_multiplication();

    cout << "\n---------Tum Testler Tamamlandi--------" << endl;
    return 0 ;
    }
















