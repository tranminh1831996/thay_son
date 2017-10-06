#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int>  vi;
typedef long double ld;
typedef long long ll;
const char *fi ="";
const char *fo ="";
const int  MAXN = 5200;
const ld EPS = 1e-9;
fstream f;

int l[MAXN][MAXN]={0};


int main()
{
	freopen("t.txt","r",stdin);
	int n;
    cin>>n;

    string s; cin>>s;
    string t;
    t=s;
    reverse(t.begin(),t.end());
     s=" "+s;
     t=" "+t;


    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (s[i]==t[j]){
                l[i][j]=l[i-1][j-1]+1;
            }
            else{
                l[i][j]=max (l[i-1][j],l[i][j-1]);
            }
        }
    }
    cout<<n-l[n][n];
	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
