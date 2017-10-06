#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int>  vi;
typedef long double ld;
typedef long long ll;
const char *fi ="WAVIO.INP";
const char *fo ="";
const int  MAXN = 10000;
const ld EPS = 1e-9;
fstream f;

int n, a[MAXN], L[MAXN],P[MAXN], truocL[MAXN],truocP[MAXN];


void truyvetL( int i)
{
    if ( truocL[i]==0 ) {cout<<a[i];return;}
    {
        truyvetL(truocL[i]);
        cout<<endl<<a[i];
    }
}
void truyvetP (int i)
{
    if ( truocP[i]==0 ) {cout<<a[i];return;}
    else
    {
        cout<<a[i]<<endl;
        truyvetP(truocP[i]);

    }

}


int main()
{
	//freopen("t.txt","r",stdin);
	f.open( fi, ios::in );
    f>>n;
    for (int i=1;i<=n;i++) f>>a[i];
    L[1]=1;
    for (int i=2;i<=n;i++){
        L[i]=1;
        for (int j=1;j<i;j++){

            if (a[j]<a[i]){
                L[i]=max ( L[i],L[j]+1 );
                truocL[i]=j;
            }

        }
    }
    P[n]=1;
    for (int i=n-1;i>=1;i-- )
    {
        P[i]=1;
        for (int j=n;j>i;j--)
        {
            if (a[i]>a[j])
            {
                P[i]= max (P[i],P[j]+1);
                truocP[i]=j;
            }
        }
    }

    int MAX=0,id;
    for (int i=1;i<=n;i++){

        if (L[i]+P[i]>MAX) {
            MAX=L[i]+P[i];
            id = i;
        }
    }

    MAX-=1;
    cout<<endl;
    cout<<MAX<<endl;
    truyvetL(id);
    cout<<endl<<"="<<endl;
    truyvetP(id);


	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
