#include <iostream>
#include <iomanip>
#define z 3
using namespace std;

void printMatriks(float matriks[z][z], string x);
void transpose(float matriks[z][z]);
void inverse(float matriks[z][z]);

int main()
{
    // Deklarasi Variabel Matriks
    float matriksP[z][z], matriksQ[z][z], matriksHasil[z][z], matriksX[z][z];

    // Pengisian Kedua Matriks sesuai dengan tugas
    // Matriks 1
    matriksP[0][0] = 1;
    matriksP[0][1] = 2;
    matriksP[0][2] = 3;

    matriksP[1][0] = 2;
    matriksP[1][1] = 3;
    matriksP[1][2] = 1;

    matriksP[2][0] = 3;
    matriksP[2][1] = 1;
    matriksP[2][2] = 2;
    // Matriks 2
    matriksQ[0][0] = 4;
    matriksQ[0][1] = 3;
    matriksQ[0][2] = 6;

    matriksQ[1][0] = 5;
    matriksQ[1][1] = 6;
    matriksQ[1][2] = 3;

    matriksQ[2][0] = 6;
    matriksQ[2][1] = 4;
    matriksQ[2][2] = 5;

    printMatriks(matriksP, "Matriks P");
    printMatriks(matriksQ, "Matriks Q");

    cout << "Matriks R = (3 * Q)^T - ((Q^-1)*(P^-1))^T" << endl
         << endl;

    // (3*Q)
    for (int x = 0; x < z; x++)
    {
        for (int j = 0; j < z; j++)
            matriksX[x][j] = matriksQ[x][j] * 3;
    }
    printMatriks(matriksX, "Matriks (3*Q)");

    // (3*Q)^T = Transpose
    transpose(matriksX);
    printMatriks(matriksX, "Matriks (3*Q)^T");

    // (Q^-1) = Inverse
    inverse(matriksQ);
    printMatriks(matriksQ, "Matriks (Q^-1)");

    // (P^-1) = Inverse
    inverse(matriksP);
    printMatriks(matriksP, "Matriks (P^-1)");

    // ((Q^-1)*(P^-1)) = Perkalian Matriks
    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < z; j++)
        {
            matriksHasil[i][j] = 0;
            for (int k = 0; k < z; k++)
                matriksHasil[i][j] += matriksQ[i][k] * matriksP[k][j];
        }
    }

    printMatriks(matriksHasil, "Matriks (Q^-1)*(P^-1)");

    // ((Q^-1)*(P^-1))^T = Transpose
    transpose(matriksHasil);
    printMatriks(matriksHasil, "Matriks ((Q^-1)*(P^-1))^T");

    // (3 * Q)^T - ((Q^-1)*(P^-1))^T" = Pengurangan Matriks
    for (int x = 0; x < z; x++)
    {
        for (int j = 0; j < z; j++)
            matriksHasil[x][j] = matriksX[x][j] - matriksHasil[x][j];
    }

    // Hasil Akhir
    printMatriks(matriksHasil, "Matriks R");

    return 0;
}

void transpose(float matriks[z][z])
{
    for (int x = 0; x < z; x++)
    {
        for (int j = x + 1; j < z; j++)
        {
            float temp = matriks[x][j];
            matriks[x][j] = matriks[j][x];
            matriks[j][x] = temp;
        }
    }
}

void inverse(float matriks[z][z])
{
    float temp, ratio;
    int i, j, k;

    // Membuat matriks identitas
    float inverse[z][z];
    for (i = 0; i < z; i++)
    {
        for (j = 0; j < z; j++)
        {
            if (i == j)
                inverse[i][j] = 1;
            else
                inverse[i][j] = 0;
        }
    }

    // Mengeliminasi matriks ke bentuk segitiga atas
    for (i = 0; i < z; i++)
    {
        for (j = 0; j < z; j++)
        {
            if (i != j)
            {
                ratio = matriks[j][i] / matriks[i][i];
                for (k = 0; k < z; k++)
                {
                    matriks[j][k] -= ratio * matriks[i][k];
                    inverse[j][k] -= ratio * inverse[i][k];
                }
            }
        }
    }

    // Membuat diagonal utama menjadi 1
    for (i = 0; i < z; i++)
    {
        temp = matriks[i][i];
        for (j = 0; j < z; j++)
        {
            matriks[i][j] /= temp;
            inverse[i][j] /= temp;
        }
    }

    // Hasil invers disimpan ke matriks asli
    for (i = 0; i < z; i++)
    {
        for (j = 0; j < z; j++)
        {
            matriks[i][j] = inverse[i][j];
        }
    }
}

void printMatriks(float matriks[z][z], string x)
{
    cout << x << endl;
    for (int a = 0; a < 3; a++)
    {
        cout << '[' << ' ';

        for (int b = 0; b < 3; b++)
        {
            if (matriks[a][b] == (int)matriks[a][b])
            {
                cout << matriks[a][b] << " ";
            }
            else
            {
                cout << fixed << setprecision(3) << matriks[a][b] << " ";
            }
        }
        cout << ']' << endl;
    }
    cout << endl;
}