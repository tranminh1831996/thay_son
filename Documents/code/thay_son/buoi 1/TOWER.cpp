#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int>  vi;
typedef long double ld;
typedef long long ll;
const char *fi ="TOWER.INP";
const char *fo ="";
const int  MAXN = 10000;
const ld EPS = 1e-9;
fstream f;

struct tower{
    int x,y,z,v,id;
};
tower a[MAXN];
int l[MAXN],l1[MAXN];
int truoc[MAXN];
int n;

void qhd(){

        l[1]=1;
        l1[1]= a[1].z;
        int i,j;
        for ( i=2;i<=n;i++){

            l[i]=1;
            l1[i]= a[i].z;

            for ( j=1;j<i;j++){

                if (a[j].x<=a[i].x && a[j].y<=a[i].y) {

                        if (l1[i]<l1[j]+a[i].z){

                            l1[i]= l1[j]+a[i].z;

                            l[i] = l[j] +1;

                            truoc[i]=j;
                        }

                }
            }
        }
}



void truyvet(int i){
    if (truoc[i]==0) {cout<<a[i].id<<" "<<a[i].x<<" "<<a[i].y<<" "<<a[i].z;}
    else{
        cout<<a[i].id<<" "<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
        truyvet(truoc[i]);


    }
}
bool compare(tower o, tower b){
    return (o.v<b.v);
}
int main()
{
	//freopen("t.txt","r",stdin);
    f.open(fi,ios::in);
	f>>n;

	for (int i=1;i<=n;i++){
        f>>a[i].x>>a[i].y>>a[i].z;
        if (a[i].x <= a[i].y && a[i].x <= a[i].z) { swap (a[i].x,a[i].z); }
        if (a[i].y <= a[i].x && a[i].y <= a[i].z) { swap (a[i].y,a[i].z); }
        if (a[i].x >  a[i].y) { swap(a[i].x,a[i].y);}

        a[i].v= a[i].x*a[i].y;
        a[i].id=i;
	}

    sort(a+1,a+n+1,compare);

    qhd();


    int MAX=0,id1=0;
        for (int i=1;i<=n;i++) { if (l[i]>MAX) { MAX= l[i]; id1= i; } }
        cout<<MAX<<endl;
        truyvet(id1);


	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
