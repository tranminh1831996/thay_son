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
//fstream f;




int main()
{
	//freopen("t.txt","r",stdin);
	int n; cin>>n;
	int a[n+1];
	for (int i=1;i<=n;i++) cin>>a[i];

	sort (a+1,a+1+n);

	int f[n+1];
        f[1]=a[1],
        f[2]=a[2],
        f[3]=a[1]+a[2]+a[3]
        ;
    for (int i=4;i<=n;i++){
        f[i]= min( a[1]+a[i]+f[i-1], a[1]+a[2]*2+f[i-2]+a[i]  );
    }
    cout<<f[n];

    //return 0;
	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
