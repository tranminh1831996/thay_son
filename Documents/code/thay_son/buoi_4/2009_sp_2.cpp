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

struct dt {
    int id, num;

};

bool compare(dt a, dt b){
    if (a.num>b.num) return true;
    return false;
}

int main()
{
	freopen("t.txt","r",stdin);
	int n; cin>>n;
	dt d[n+69];
	for (int i=1;i<=n;i++){
        int t; cin>>t;
        d[i].id= i;
        d[i].num=t;
	}
    sort (d+1,d+n+1,compare);
    int i=1;

    int adj[222][222]={0};

    for (int i=1;i<n;i++){
        for (int j=i+1;j<=n;j++){
            if (d[i].num!=0 && d[j].num!=0){
                d[i].num--;
                d[j].num--;
                adj[d[i].id][d[j].id]=1;
                cout<<d[i].id<<" "<<d[j].id<<endl;
            }
        }

    }



	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
