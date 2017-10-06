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
	freopen("t.txt","r",stdin);
    int fibo[6],n,m;
    cin>>n; for (int i=1;i<=n;i++) cin>>fibo[i];
    cin>>m;
    int l[100][100];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (j>=fibo[i]){
                l[i][j]=max (l[i-1][j-fibo[i]]+1,l[i-1][j]);
            }
            else{
                l[i][j]=l[i-1][j];
            }
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }

    //cout<<l[n][m]<<endl;
    while (n!=0){
        if (l[n][m]!=l[n-1][m]){
            //cout<<fibo[n]<<" ";
            m=m-fibo[n];
        }
        n--;
    }

	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
