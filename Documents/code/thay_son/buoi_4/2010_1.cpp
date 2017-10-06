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

long rev (long n){
    long r,d,kq;
    kq= n%10;
    n=n/10;
    while (n>0){
        kq=kq*10;
        kq+=n%10;
        n/=10;
    }
    return kq;
}
bool check (int n){

    for (int i=2;i<=sqrt(n);i++){
        if (n%i==0) return false;
    }

    return true;
}

int main()
{
	//freopen("t.txt","r",stdin);
	long a,b,c=0;
	cin>>a>>b;

	for (long i=a;i<=b;i++){
        if (check(i) && i==rev(i) ){
            c++;
        }
	}
    cout<<c;
	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
