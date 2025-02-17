#include<bits/stdc++.h>

using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define fo(a,n) for(int i=a;i<n;i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int mpow(int base, int exp) {
	base %= mod;
	int result = 1;
	while (exp > 0) {
		if (exp & 1) result = ((int)result * base) % mod;
		base = ((int)base * base) % mod;
		exp >>= 1;
	}
	return result;
}

void c_p_c()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int a[10000];
int fen[10000] = {0};

void update(int val, int i, int n) {
	while (i <= n) {
		fen[i] += val;
		i = i + (i & (-1 * i));
	}
}

void build(int n) {
	fo(1, n + 1) {
		update(a[i], i, n);
	}
}

int query(int i) {
	int ans = 0;
	while (i > 0) {
		ans += fen[i];
		i = i - (i & (-1 * i));
	}
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	c_p_c();
	int n;
	cin >> n;
	fo(1, n + 1) cin >> a[i];
	build(n);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(r) - query(l - 1) << endl;
	}
	// fo(1, n + 1) cout << fen[i] << ", ";
	return 0;
}
