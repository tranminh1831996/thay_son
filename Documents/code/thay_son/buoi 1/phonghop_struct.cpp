#include<bits/stdc++.h>
#define ll long long
#define MAX_N 200005

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int>  vi;
const int MAXN = 10000;
const char * fi = "BOTRIPH.INP";
const char * fo = "BOTRIPH.OUT";
fstream f;

int n,l[MAXN],truoc[MAXN],k,MAX=0;

struct rooms {
    int s,f;
};

rooms a[MAXN];


bool compare (rooms x, rooms y)
{
    return (x.f<y.f);
}

void nhap()
{
    f.open(fi,ios::in);
	f>>n;
	for (int i=1;i<=n;i++)
	{
        f>> a[i].s>>a[i].f;
	}
}

void qhd()
{
    l[1]=1;
    for (int i=2;i<=n;i++)
    {
        l[i]=1;
        for (int j=1;j<i;j++)
        {
            if (a[j].f<=a[i].s)
            {
                if (l[i]<l[j]+1)
                {
                    l[i]=l[j]+1;
                    truoc[i]=j;
                }
            }
        }
    }
}

void truyvet(int i)
{
    if (truoc[i]==0) cout<< a[i].s<<" "<<a[i].f;
    else{
        truyvet(truoc[i]);
        cout<<endl<<a[i].s<<" "<<a[i].f;
    }
}

void xuat()
{

}

int main()
{
	//freopen("t.txt","r",stdin);
	nhap();
    sort (a+1,a+n+1,compare); // sap xep

    qhd();
    for (int i=1;i<=n;i++)
    {
        if (l[i]>MAX)
        {
            MAX= l[i];
            k=i;
        }
    }

    cout<<MAX<<endl;
    truyvet(k);


	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
