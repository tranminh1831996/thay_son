#include <iostream>
#include <fstream>

using namespace std;

const char * fi = "TONGS.INP";
const char * fo = "TONGS.OUT";
const int MAXN = 10000;
const int MAXS = 10000;

int n ,a[MAXN],S;
bool L[MAXN][MAXS];

fstream f;

void Nhap() {
    f.open(fi, ios::in);
    f >> n >> S;
    int i;
    for (i=1; i<=n; i++)
        f >> a[i] ;
    f.close();
}

void QHD() {
    // Goi L[i][j] la gia tri lon nhat khi chon cac do vat tu 1..i ma tong trong luong khong vuot qua j
    // L[i][j] = max(L[i-1][j], L[i-1][j-W[i]] + V[i])
    // L[0][j] = 0
    int i, j;
    L[0][0]= true;
    for (j=1; j<=S; j++)
        L[0][j] = 0;

    for (i=1; i<=n; i++)
        for (j=0; j<=S; j++) {
            L[i][j]=L[i-1][j];
            if(j>=a[i])
                if (L[i-1][j-a[i]] == true)
                    L[i][j] = true;
        }

}

void TruyVet(int i, int j) {
    if (i == 0) return;
    if (j == 0) return;
    if (j >=  a[i]) {
        if (L[i][j] == L[i-1][j-a[i]]) {
            TruyVet(i-1, j-a[i]);
            f << a[i] << "   ";
        }
        else TruyVet(i-1, j);
    }
        else TruyVet(i-1, j);

}

void InKQ() {
    f.open(fo, ios::out);
    f << L[n][S] << endl;
    if (L[n][S] == true)
        TruyVet(n, S);
    f.close();
}

int main() {
    Nhap();
    QHD();
    InKQ();
}
