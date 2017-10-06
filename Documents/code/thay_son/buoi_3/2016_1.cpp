#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int>  vi;
typedef long double ld;
typedef long long ll;
typedef long  l;
const char *fi ="";
const char *fo ="";
const int  MAXN = 10000;
const ld EPS = 1e-9;
fstream f;




int main()
{
	//freopen("t.txt","r",stdin);
	int n; l t; cin>>n>>t;
	int a[n+1];

	for (int i=1;i<=n;i++){
        cin>>a[i];
	}

	ll temp_s=0,d=0,s=0;
	vector<long long> v;

	for (int i=1;i<=n;i++){
        if (temp_s+a[i]<=t){
            temp_s+=a[i];
            d++;
        }
        else{
            if (a[i]>t){
                temp_s=0; d=0;
            }
            else{
                v.push_back(d);
                temp_s=a[i]; d=1;
            }

        }
        if (i==n){
            v.push_back(d);
        }
	}
	for (int i=0;i<v.size();i++){
        s+=v[i]*(v[i]+1)/2;
	}
	cout<<s;
	return 0;

		//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
