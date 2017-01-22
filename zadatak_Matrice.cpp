#include <iostream>
#include <vector>

using namespace std;

void unos_el(vector<vector<int>> &mat)
{
    for(int i = 0; i < mat.size(); ++i)
        for(int j = 0; j < mat[i].size(); ++j)
            cin >> mat[i][j];
}

void ispis_el(vector<vector<int>> &mat)
{
    for(int i = 0; i < mat.size(); ++i)
    {
        for(int j = 0; j < mat[i].size(); ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> saberi_mat(const vector<vector<int>> &mat1,
                               const vector<vector<int>> &mat2)
{
    vector<vector<int>> rez;

    if(mat1.size() != mat2.size() || mat1[0].size() != mat2[0].size())
        cerr << "Dimenzije matrica se ne slazu!" << endl;
    else
    {

        rez = vector<vector<int>>(mat1.size(),vector<int>(mat1[0].size(),0));

        for(int i = 0; i < mat1.size(); ++i)
            for(int j = 0; j < mat1[0].size(); ++j)
                rez[i][j] = mat1[i][j] + mat2[i][j];
    }

    return rez;
}

vector<vector<int>> oduzmi_mat(const vector<vector<int>> &mat1,
                               const vector<vector<int>> &mat2)
{
    vector<vector<int>> rez;

    if(mat1.size() != mat2.size() || mat1[0].size() != mat2[0].size())
        cerr << "Dimenzije matrica se ne slazu!" << endl;
    else
    {

        rez = vector<vector<int>>(mat1.size(),vector<int>(mat1[0].size(),0));

        for(int i = 0; i < mat1.size(); ++i)
            for(int j = 0; j < mat1[0].size(); ++j)
                rez[i][j] = mat1[i][j] - mat2[i][j];
    }

    return rez;
}

vector<vector<int>> transponovanje(const vector<vector<int>> &mat1)
{
    vector<vector<int>> rez(mat1[0].size(), vector<int>(mat1.size(),0));

    for(int i = 0; i < mat1.size(); ++i)
        for(int j = 0; j < mat1[0].size(); ++j)
            rez[j][i] = mat1[i][j];

    return rez;
}

vector<vector<int>> mnozenje(const vector<vector<int>> &mat1,
                               const vector<vector<int>> &mat2)
{
    vector<vector<int>> rez;
    if(mat1[0].size() != mat2.size())
        cerr << "Gresis, ovaj Gresis grdno decko!" << endl;
    else
    {
        rez = vector<vector<int>>(mat1.size(),vector<int>(mat2[0].size(),0));

        for(int i = 0; i < mat1.size(); ++i)
            for(int j = 0; j < mat2[0].size(); ++j)
                for(int k = 0; k < mat1[0].size(); ++k)
                    rez[i][j] += mat1[i][k] * mat2[k][j];


    }
    return rez;

}

int main()
{
    int N = 2, M = 2;
    vector<vector<int> > A(N, vector<int>(M,0));
    vector<vector<int> > B(2, vector<int>(2,0));

    cout << "Program za rad sa matricama: " << endl;

    cout << "Unesite elemente prve matrice: " << endl;
    unos_el(A);
    cout << "Matrica A: " << endl;
    ispis_el(A);

    cout << "Unesite elemente druge matrice: " << endl;
    unos_el(B);
    cout << "Matrica B: " << endl;
    ispis_el(B);

    vector<vector<int>> C = saberi_mat(A,B);

    cout << "Rezultat Sabiranja: " << endl;

    ispis_el(C);

    cout << "Kraj Programa!" << endl;

    return 0;
}