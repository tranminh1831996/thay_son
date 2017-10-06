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

int f[50][50],n,m,k;

int main()
{
	freopen("t.txt","r",stdin);
	cin>>n>>k>>m;
	// xay dung tam giac pascal;

	for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            if (i==0||j==0)
                f[i][j]=1;
            else
                f[i][j]= f[i][j-1]+f[i-1][j];
        }
	}
	int t_n=n,d=0;



    int i=n-k,j=k,t=0;
    //cout<<"f:"<<f[i][j]<<endl;
	for (int i1=1;i1<=t_n;i1++){

        if (d+f[i][j-1]<m){
            d+=f[i][j-1];
            //cout<<"f:"<<f[i][j-1]<<endl;
            //cout<<"d:"<<d<<endl;
            i--;

        }
        else{
            cout<<i1<<" ";
            //cout<<"d:"<<d<<endl;

            m-=(i1-1)*(f[i][j]);
            //cout<<"m:"<<m<<endl;
            //cout<<f[i][j]<<endl;
            d=0;
            j--;

        }

	}



	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
