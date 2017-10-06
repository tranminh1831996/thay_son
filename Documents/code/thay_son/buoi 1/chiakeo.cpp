#include<bits/stdc++.h>
using namespace std;
//http://www.spoj.com/KSTN/problems/CANDY25/
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
    int n,s;
    int l[50000]={0};
    int d[500]={0},a[500];
    cin>>n>>s;
    for (int i=1;i<=n;i++) cin>>a[i];
    l[0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=s;j>=a[i];j--) {
            if ( l[j] == 0 && l[j-a[i]]==1 ) {
                    l[j]=1;

            }
        }
    }



    if (l[s]==0) cout<<"0";
    else{
        cout<<"1"<<endl;
        for (int i=1;i<=n;i++)
        {
            if (l[s-a[i]]==1 && d[i]==0 ) {
                s-=a[i];
                d[i]=1;
            }
            if (s==0) break;
        }
        for (int i=1;i<=n;i++)
        cout<<d[i]<<" ";
    }
	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
