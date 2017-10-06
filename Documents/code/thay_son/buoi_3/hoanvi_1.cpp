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

int n,k;
int a[100];
bool c[100]={false};

void inkq(){
    for (int i=1;i<=k;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void bk(int i){
    if (i==k+1){
        inkq(); return;
    }
    for (int j=1;j<=n;j++){
        if (!c[j]){
            a[i]=j;
            c[j]=true;
            bk(i+1);
            c[j]=false;
        }
    }
}

int main()
{
	//freopen("t.txt","r",stdin);
    cin>>n>>k;
    bk(1);

	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
