#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int>  vi;
typedef long double ld;
typedef long long ll;
const char *fi ="FIBO.INP";
const char *fo ="";
const int  MAXN = 10000;
const ld EPS = 1e-9;
fstream f;


int main()
{
	freopen("t.txt","r",stdin);

	int x;
	cin>>x;

	int f[MAXN];
	int d=3; f[1]=1;f[2]=2;
	while (1){
        f[d]=f[d-1]+f[d-2];
        if (f[d]>x) { d--;break;}
        d++;
	}
    int l[500][500]={0};

    l[0][0]=1;
    int n=d;

    for (int i=1;i<=n;i++){

        for (int j=1;j<=x;j++){

            if (j>=f[i]){
                if ( l[i-1][j] || l[i-1][j-f[i]] ) l[i][j]=1;
            }
            else{
                l[i][j]=l[i-1][j];
            }

        }
    }

    while (n!=0){

        if (l[n-1][x]!=l[n][x]){
            cout<<f[n]<<" ";
            x-=f[n];
        }
        n--;
        if (x==0) break;
    }





	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
