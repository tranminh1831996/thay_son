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
const ll oo = 1e9;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;

ll L,n;

ll mod_pow (ll a, ll b){
    ll kq =1;
    a = a % MOD;
    while (b>0){
        if (b%2==1)
            kq = (kq*a)%MOD;
        b= b>>1;
        a = (a*a) % MOD;
    }
    return kq;
}

int main()
{
	//freopen("t.txt","r",stdin);
	cin>>n>>L;
	ll ans =1;
	if (n<2){

	}
	else{
        ans = L*L%MOD * ( (mod_pow(4,n+1) - 1)%MOD ) / ( mod_pow(3,n-2) %MOD );
        ans = ans %MOD;
        cout<< ans;
	}
	//cout<<ans;
	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
