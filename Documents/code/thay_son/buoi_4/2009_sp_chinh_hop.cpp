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

int n,k,m;
list <int> l;
list <int>::iterator it,it1,it2;

ll ch(int n,int k){

    ll kq=1;
    for (int i=k;i>=0;i--){
        kq*=n-k+i;
    }
    return kq;

}

void init(){
    for (int i=1;i<=n;i++){
        l.push_back(i);
    }
}

int main()
{
	freopen("t.txt","r",stdin);
	cin>>n>>k>>m;
	ll s = ch(n,k);
    ll d,r;
	while (s>0){
        s= s/n;
        d= m/s;
        r= m%s;
        if (r==0){
            it = l.begin();
            advance(it,d);
            cout<<*it;
            l.erase(it);

        }
        else{

        }
	}




	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
