#include <iostream>
#include <fstream>

using namespace std;

const char * fi = "CAITUI.INP";
const char * fo = "CAITUI.OUT";
const int MAXN = 1000;
const int MAXW = 10000;

int n, W[MAXN], W0;
double V[MAXN];
double L[MAXN][MAXW];
fstream f;

void Nhap() {
    f.open(fi, ios::in);
    f >> n >> W0;
    int i;
    for (i=1; i<=n; i++)
        f >> W[i] >> V[i];
    f.close();
}

void QHD() {
    // Goi L[i][j] la gia tri lon nhat khi chon cac do vat tu 1..i ma tong trong luong khong vuot qua j
    // L[i][j] = max(L[i-1][j], L[i-1][j-W[i]] + V[i])
    // L[0][j] = 0
    int i, j;
    for (j=0; j<=W0; j++)
        L[0][j] = 0;

    for (i=1; i<=n; i++)
        for (j=0; j<=W0; j++) {
            L[i][j] = L[i-1][j];
            if (j - W[i] >= 0)
                L[i][j] = max(L[i-1][j], L[i-1][j-W[i]] + V[i]);
        }

}

void TruyVet(int i, int j) {
    if (i==0) return;
    if (j == 0) return;
    if (j >= W[i]) {
            if (L[i][j] == L[i-1][j-W[i]] + V[i]) {
                TruyVet(i-1, j-W[i]);
                f << "Chon do vat thu " << i << " co trong luong la " << W[i] << " va gia tri la " << V[i] << endl;
            }
            else TruyVet(i-1, j);
    }
    else TruyVet(i-1, j);

}

void InKQ() {
    f.open(fo, ios::out);
    f << L[n][W0] << endl;
    TruyVet(n, W0);
    f.close();
}

int main() {
    Nhap();
    QHD();
    InKQ();
}
