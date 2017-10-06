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
const ld EPS = 1e-9;
fstream f;




int main()
{
	freopen("t.txt","r",stdin);
	int n; cin>>n; int a[n+1];
	for (int i=1;i<=n;i++) cin>>a[i];
	vector<int> l;
	int pos[100];

    pos[1]=1;
	l.push_back(a[1]);

	for (int i=2;i<=n;i++){
         if (a[i]>l.back())   {
            l.push_back(a[i]);
            pos[i]=l.size();
             for (int i=0;i<l.size();i++) cout<<l[i]<<" ";
                cout<<endl;

         }
         else{
            pos[i]=lower_bound(l.begin(),l.end(),a[i]) -l.begin() + 1;
                 *lower_bound(l.begin(),l.end(),a[i]) =a[i];
                for (int i=0;i<l.size();i++) cout<<l[i]<<" ";
                cout<<endl;
         }


	}






	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
