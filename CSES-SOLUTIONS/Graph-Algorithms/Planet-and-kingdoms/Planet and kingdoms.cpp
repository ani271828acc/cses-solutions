
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define endl "\n"
#define all(v) v.begin(), v.end()

const ll i1 = 1e5 + 5;

ll n, m;

vll adj[i1];
vll adj1[i1];
bool vis[i1];
ll vis1[i1];
map<ll, ll> mp;
vll topo;

void dfs(ll i)
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            dfs(it);
        }
    }
    topo.pb(i);
}

void dfs1(ll i, ll k)
{
    if (vis1[i] != 0)
        return;
    vis1[i] = k;
    for (auto it : adj1[i])
    {
        dfs1(it, k);
    }
}

void solve(ll test_case)
{

    cin >> n >> m;

    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj1[b].pb(a);
    }

    ll cnt = 1;

    for (int i = 1; i < n + 1; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    reverse(all(topo));
    for (auto it : topo)
    {
        if (vis1[it] == 0)
        {
            dfs1(it, cnt);
            cnt++;
        }
    }

    cout << cnt - 1 << endl;
    for (int i = 1; i < n + 1; i++)
    {
        cout << vis1[i] << " ";
    }
}

int main()
{

    ll ttcc = 1;
    ll test_case = 1;
    while (ttcc--)
    {
        solve(test_case);
        test_case++;
    }
}
