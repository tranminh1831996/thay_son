#include<bits/stdc++.h>
#define base 1000000007
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int>  vi;
typedef long double ld;
typedef long long ll;
const char *fi ="";
const char *fo ="";
const int  MAXN = 10000;
const int MOD = 1e9+7;
const ll oo = 1e9;
const ld EPS = 1e-9;

ll p[40];
ll f[30010][40]={0};
map<ll,int> cnt,e;
int n,k;

bool check (int len){

    cnt.clear();
    for (int i=1;i<=n;i++){
        e.clear();
        for (int j=len;j<=30;j++){

            ll temp=
            (f[i][j]-f[i][j-len] * p[len] +MOD +MOD )%MOD;
            if (!e[temp]){

                cnt[temp]++;
                if (cnt[temp]==k) return true;
                e[temp]=1;
            }

        }

    }
    return false;
}

int main()
{
	//freopen("t.txt","r",stdin);
	cin>>n>>k;
    p[0]=1;
    for (int i=1;i<=30;i++) p[i]=(p[i-1]*26) %MOD;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=30;j++){
            char c; cin>>c;
            f[i][j]=(f[i][j-1]*26+ c-'a')%MOD;
        }
    int l=1,r=30,kq=-1;
    while (l<=r){
        int mid = (l+r)/2;
        if (check(mid)) { kq=mid;l= mid+1;}
        else r=mid-1;
    }
    cout<<kq;
	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
