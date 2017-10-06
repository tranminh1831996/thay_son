#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
const int oo=1e9+7;
const int maxN=10005;

long N,M,K,bo[maxN],d[maxN],dd[maxN];
vector<ii> a[maxN],b[maxN],c[maxN];

bool kt[maxN],ktt[maxN];

void dijkstra()
{
    priority_queue < ii, vector<ii> , greater<ii> > pq;
    for (int i=1;i<=N;i++)
        bo[i]=oo;
    bo[K]=0;
    pq.push(ii(0,K));
    while (!pq.empty())
    {
        int u=pq.top().second;
        int bou=pq.top().first;
        pq.pop();
        if (bou!=bo[u])
            continue;
        for (int i=0;int v=a[u][i].second;i++)
        {
            int uv=a[u][i].first;
            if (bo[v] > bo[u] + uv)
            {
                bo[v]=bo[u]+uv;
                pq.push(ii(bo[v],v));
            }
        }
    }
}

void dijkstra2()
{
    priority_queue < ii, vector<ii> , greater<ii> > pq;
    for (int i=1;i<=N;i++)
        d[i]=oo;
    d[1]=0;
    pq.push(ii(0,1));
    while (!pq.empty())
    {
        int u=pq.top().second;
        int du=pq.top().first;
        pq.pop();
        if (du!=d[u])
            continue;
        for (int i=0;int v=b[u][i].second;i++)
        {
            int uv=b[u][i].first;
            if (d[v] > d[u] + uv)
            {
                d[v]=d[u]+uv;
                pq.push(ii(d[v],v));
            }
        }
    }
}

void dijkstra3()
{
    priority_queue < ii, vector<ii> , greater<ii> > pq;
    for (int i=1;i<=N;i++)
        dd[i]=oo;
    dd[N]=0;
    pq.push(ii(0,N));
    while (!pq.empty())
    {
        int u=pq.top().second;
        int ddu=pq.top().first;
        pq.pop();
        if (ddu!=dd[u])
            continue;
        for (int i=0;int v=c[u][i].second;i++)
        {
            int uv=c[u][i].first;
            if (dd[v] > dd[u] + uv)
            {
                dd[v]=dd[u]+uv;
                pq.push(ii(dd[v],v));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i=1;i<=M;i++)
    {
        int u,v,ai,bj;
        cin >> u >> v >> ai >> bj;
        a[v].push_back(ii(ai,u));
        b[u].push_back(ii(bj,v));
        c[v].push_back(ii(bj,u));
    }
    for (int i=1;i<=N;i++)
    {
        a[i].push_back(ii(0,0));
        b[i].push_back(ii(0,0));
        c[i].push_back(ii(0,0));
    }
    dijkstra();
    dijkstra2();
    dijkstra3();
    memset(kt,false,sizeof kt);
    memset(ktt,false,sizeof kt);
    long res=oo;
    for (int i=1;i<=N;i++)
        if (d[i] + bo[i] <= 59)
            res=min(res,d[i] + dd[i]);
    cout << res;
    return 0;
}
