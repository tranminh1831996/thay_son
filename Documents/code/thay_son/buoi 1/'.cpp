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

int n,l[100][100],s,a[100];


int main()
{
	freopen("t.txt","r",stdin);
	cin>>n>>s;
	for (int i=1;i<=n;i++) cin>>a[i];
	 l[0][0]=1;
	for (int j=1;j<=s;j++) l[0][j]=0;

	for (int i=1;i<=n;i++){
        for (int j=1;j<=s;j++){
            l[i][j]=l[i-1][j];
            if (j>=a[i]&& )
        }
	}


	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
