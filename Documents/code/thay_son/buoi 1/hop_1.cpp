#include<bits/stdc++.h>
#define ll long long
#define MAX_N 200005

#include <fstream>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int>  vi;

const int MAXN = 10000;
const char * fi = "BOTRIPH.INP";
const char * fo = "BOTRIPH.OUT";

fstream f;
int n, a[MAXN], L[MAXN], b[MAXN] , Truoc[MAXN];

void Nhap() {
    f.open(fi, ios::in);
    f >> n;
    int i;
    for (i=1; i<=n; i++) f >> a[i] >> b[i];
    f.close();
}

void SapXep() {
    int i, j;
    for (i=1; i<=n-1; i++)
        for (j=i+1; j<=n; j++)
            if (b[i] > b[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
}


void QHD() {
    L[1] = 1;
    memset(Truoc, 0, sizeof(Truoc));
    int i, j;
    for (i=2; i<=n; i++) {
        L[i] = 1;
        for (j=1; j<i; j++)
            if (b[j] <= a[i])
                if (L[i] < L[j] + 1) {
                    L[i] = L[j] + 1;
                    Truoc[i] = j;
                }
    }
}

void TruyVet(int i) {
    if (Truoc[i] == 0) f << a[i] << "   " << b[i];
        else {
            TruyVet(Truoc[i]);
            f << endl << a[i] << "   " << b[i];
        }
}

void InKQ() {
    f.open(fo, ios::out);
    int max = -1;
    int i, k;
    for (i=1; i<=n; i++)
        if (L[i] > max) {
            max = L[i];
            k = i;
        }
    f << max << endl;
    TruyVet(k);
    f.close();
}

int main() {
    Nhap();
    QHD();
    InKQ();


  	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
