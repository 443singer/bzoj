#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 50003;
const int M = 100003;
int first[N],to[M*2],next_[M*2],eg;
long long d[M*2];
inline void addedge(int x,int y,long long dd) {
	next_[++eg] = first[x];
	first[x] = eg;
	to[eg] = y;
	d[eg] = dd;
}
inline void add(int x,int y,long long dd) {
	addedge(x,y,dd);
	addedge(y,x,dd);
}
int m,n,t;
long long xor_[N];
bool vis[N];
long long a[(N+M)*2],ans;//a presents jituan
void dfs(int u) {
	vis[u] = 1;
	for(int i = first[u] ; i ; i = next_[i]) {
		if(vis[to[i]]) {
			long long tmp = xor_[u]^xor_[to[i]]^d[i];
			if(tmp) a[++t] = tmp;
		}
		else {
			xor_[to[i]] = xor_[u]^d[i];
			dfs(to[i]);
		}
	}
}
long long b[100];
void solve() {
	for(int i = 1 ; i <= t ; ++i) {
		for(int j = 62 ; j >= 0 ; --j) {
			if(!(a[i]>>j)) continue;
			if(!b[j]) {
				b[j] = a[i];
				break;
			} else a[i] ^= b[j];
		}
	}
	for(int i = 62 ; i >= 0 ; --i) {
		if((ans^b[i]) > ans) ans = ans^b[i];
	}
	cout << ans << endl;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; ++i) {
		int x,y;
		long long dd;
		scanf("%d%d",&x,&y);
		cin >> dd;
		add(x,y,dd);
	}
	dfs(1);
	ans = xor_[n];
	solve();
}
