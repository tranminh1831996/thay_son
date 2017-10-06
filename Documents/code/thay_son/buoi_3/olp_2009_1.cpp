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
const ll INF = 1e15+7;
const ld EPS = 1e-9;
fstream f;




int main()
{
	//freopen("t.txt","r",stdin);
    int n; cin>>n;
    ll a[n+1],f1[n+1],f2[n+1];
    for (int i=1;i<=n;i++) cin>>a[i];
    ll temp_MAX=a[1];

    for (int i=1;i<=n;i++){
        if (a[i]>temp_MAX){
            temp_MAX=a[i];

        }
        f1[i]=temp_MAX;
    }

    temp_MAX=a[n];
    for (int i=n;i>=1;i--){
        if (a[i]>temp_MAX){
            temp_MAX=a[i];
        }
        f2[i]=temp_MAX;
    }
    ll MAX=-INF;
    for (int i=2;i<n;i++){
        MAX= max (f1[i-1]+2*a[i]+3*f2[i+1],MAX);
    }
    cout<<MAX;


	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
