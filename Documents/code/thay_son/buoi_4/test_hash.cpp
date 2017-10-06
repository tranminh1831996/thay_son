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
const ld EPS = 1e-9;
const ll MOD = 1e9+7;

ll pow[MAXN];
ll hash_s[MAXN];

ll get_hash(int i,int j){
    return (hash_s[j]-hash_s[i-1]*pow[j-i+1]+MOD+MOD)%MOD;
}

int main()
{
	//freopen("t.txt","r",stdin);
	string s; cin>>s;
	s= "0"+s;
	int n=s.length()-1;
	pow[0]=1;
	hash_s[0]=0;
	for (int i=1;i<=n;i++){
        pow[i]=(pow[i-1]*26)%MOD;
	}
	for (int i=1;i<=n;i++){
        hash_s[i]=(hash_s[i-1]*26+s[i]-'a') %%MOD;
	}

	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
