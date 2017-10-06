#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int>  vi;
typedef long double ld;
typedef long long ll;
const char *fi ="";
const char *fo ="";
const int  MAXN = 10000;
const ld EPS = 1e-9;
fstream f;




int main()
{
	//freopen("t.txt","r",stdin);
    string a = " ABXYZ";
    string b = " ZYXAB";

    int f[100][100]={0};
    int n= a.length()-1;
    int m= b.length()-1;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i]==b[j]){
                f[i][j]=f[i-1][j-1]+1;
            }
            else{
                f[i][j]= max(f[i-1][j],f[i][j-1]);
            }
        }
    }

     for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
           cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    while (n!=0 || m!=0){

        if (a[n]==b[m]){
            cout<<a[n];
            n--;m--;
        }
        else
        {
            if (f[n][m]==f[n-1][m]){
                n--;
            }
            if (f[n][m]==f[n][m-1]){
                m--;
            }
        }

    }

	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
