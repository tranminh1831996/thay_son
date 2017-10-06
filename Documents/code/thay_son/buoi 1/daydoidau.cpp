#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int>  vi;
typedef long double ld;
typedef long long ll;
const char *fi ="DAYDOIDAU.INP";
const char *fo ="";
const int  MAXN = 10000;
const ld EPS = 1e-9;
fstream f;
int n,a[MAXN],U,l,L[MAXN],P[MAXN],truocL[MAXN],truocP[MAXN],jl,jp;



void truyvet (int i, int *t)
{
    if (t[i]==0) { cout<<a[i]; return; }
    if (a[t[i]]<a[i])
    {
        truyvet(t[i],truocP);
        cout<<endl<<a[i];
    }
    else
    {
        truyvet(t[i],truocL);
        cout<<endl<<a[i];
    }
}

int main()
{
	//freopen("t.txt","r",stdin);
    f.open(fi,ios::in);
	f>>n>>l>>U;
	for (int i=1;i<=n;i++) f>>a[i];
    L[1]=1;
    P[1]=1;
	for (int i=2;i<=n;i++)
	{
        L[i]=1;
        P[i]=1;
        for (int j=1;j<=i-l;j++) {
                if (a[i]>=a[j]) {
                    if (a[i]-a[j]<=U) {
                        L[i]=max (P[j]+1,L[i]);
                        truocL [i] = j;
                    }
                }
               else{
                    if (a[j]-a[i]<=U) {
                        P[i]=max (L[j]+1,P[i]);
                        truocP [i] = j;
                    }
               }
        }

	}
	int MAX=0,ip=1,il=1;

	for (int i=1;i<=n;i++)
	{
        MAX=max(L[i],P[i]);
	}
    cout<<MAX<<endl;
	for (int i=2;i<=n;i++)
	{
        if ( L[i]>L[il] ) { il=i; }
        if ( P[i]>P[ip] ) { ip=i; }

	}

	if ( L[il]>P[ip] )
	{
        truyvet(il,truocL);
	}

	else
	{
        truyvet(ip,truocP);
	}







	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
