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
     int t_n=0,t_m=0,MAX=0;
     for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i]==b[j]){
                f[i][j]=f[i-1][j-1]+1;

            }
            if (f[i][j]>MAX){
                t_n=i,t_m=j;
                MAX=f[i][j];
            }
        }
     }
     while (t_n!=0 ){
        cout<<a[t_n];
        t_n--;

    }

	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
