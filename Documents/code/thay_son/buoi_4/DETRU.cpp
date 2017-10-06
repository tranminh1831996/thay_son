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

vector <pair<int,int>> adj1[MAXN],adj2[MAXN],adj3[MAXN];
long n,m,k,t;
long a[MAXN],b[MAXN],
    way1[MAXN],way2[MAXN],way3[MAXN];


void dijkstra_1(){
    priority_queue <ii, vector<ii>, greater<ii> >pq;
    for (int i=1;i<=n;i++) way1[i]=oo;
    way1[k]=0;
    pq.push(make_pair(0,k));
    while (!pq.empty()){
        int u= pq.top().second;
        int val = pq.top().first;
        pq.pop();
        if (val>way1[u]) continue;
        for (int j=0;j<adj1[u].size();j++){
            ii v = adj1[u][j];
            if ( way1[u] + v.second < way1[v.first] ){
                way1[v.first] = way1[u] + v.second ;
                pq.push(ii (way1[v.first],v.first));
            }
        }
    }

}
void dijkstra_2(){
    priority_queue <ii, vector<ii>, greater<ii> >pq;
    for (int i=1;i<=n;i++) way2[i]=oo;
    way2[1]=0;
    pq.push(make_pair(0,1));
    while (!pq.empty()){

        int u= pq.top().second;
        int val = pq.top().first;
        pq.pop();
        if (val>way2[u]) continue;
        for (int j=0;j<adj2[u].size();j++){
            ii v = adj2[u][j];
            if ( way2[u] + v.second < way2[v.first] ){
                way2[v.first] = way2[u] + v.second ;
                pq.push(ii (way2[v.first],v.first));
            }
        }
    }

}

void dijkstra_3(){
    priority_queue <ii, vector<ii>, greater<ii> >pq;
    for (int i=1;i<=n;i++) way3[i]=oo;
    way3[n]=0;
    pq.push(make_pair(0,n));
    while (!pq.empty()){

        int u= pq.top().second;
        int val = pq.top().first;
        pq.pop();
        if (val>way3[u]) continue;
        for (int j=0;j<adj3[u].size();j++){
            ii v = adj3[u][j];
            if ( way3[u] + v.second < way3[v.first] ){
                way3[v.first] = way3[u] + v.second ;
                pq.push(ii (way3[v.first],v.first));
            }
        }
    }

}



int main()
{
    //freopen("t.txt","r",stdin);
	cin>>n>>m>>k>>t;

    while (m--){
        int u,v,a,b;
        cin>>u>>v>>a>>b;
        adj1[v].push_back(make_pair(u,a)); //  di bo tu 1 vi tri bat ky den k
        adj2[u].push_back(make_pair(v,b)); //   di xe tu 1 den 1 vi tri bat ky
        adj3[v].push_back(make_pair(u,b));//     di xe tu 1 vi tri bat ky den n

    }
    dijkstra_1();
    dijkstra_2();
    dijkstra_3();
    long res=oo;
    for (int j=1;j<=n;j++){
        if ( way1[j]+way2[j]<=t ){
            res= min(res,way2[j]+way3[j]);
        }
    }
    cout<<res;


 	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
