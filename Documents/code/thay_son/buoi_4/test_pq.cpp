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

int main()
{
	freopen("t.txt","r",stdin);
	int n; cin>>n;
	int a[n+1];
	priority_queue <int, vector<int>, greater<int> > pq;
	for (int i=1;i<=n;i++){
        cin>>a[i];
        pq.push(a[i]);
	}
	sort (a+1,a+n+1,greater<int>());
	//for (int i=1;i<=n;i++) cout<<a[i]<<" ";
	while (!pq.empty()){
        int t= pq.top();
        cout<<t;
        pq.pop();
	}

	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
