#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 20003;
int first[N],next_[N*2],to[N*2],v[N*2],eg;
inline void addedge(int x,int y,int d) {
	next_[++eg] = first[x];
	first[x] = eg;
	to[eg] = y;
	v[eg] = d;
}
inline void add(int x,int y,int d) {
	addedge(x,y,d);
	addedge(y,x,d);
}
int n,nown,root,f[N],size[N];
bool vis[N];
void getroot(int u,int fa) {
	size[u] = 1;
	f[u] = 0;
	for(int i = first[u] ; i ; i = next_[i]) {
		if(vis[to[i]] || to[i]==fa) continue;
		getroot(to[i],u);
		size[u] += size[to[i]];
		f[u] = max(f[u],size[to[i]]);
	}
	f[u] = max(f[u],nown-size[u]);
	if(f[u]<f[root]) root = u;
}
long long ans;
int len1[4],len2[4];
void dfs(int u,int fa,int tmp) {
	len2[tmp%3]++;
	for(int i = first[u] ; i ; i = next_[i]) {
		if(vis[to[i]] || to[i]==fa) continue;
		dfs(to[i],u,tmp+v[i]);
	}
}
long long cal(int u) {
	len1[0] = len1[1] = len1[2] = 0;
	long long tmpans = 0;
	for(int i = first[u] ; i ; i = next_[i]) {
		if(vis[to[i]]) continue;
		len2[0] = len2[1] = len2[2] = 0;
		dfs(to[i],u,v[i]);
		tmpans += len2[0];
		tmpans += len1[1]*len2[2];
		tmpans += len1[2]*len2[1];
		tmpans += len1[0]*len2[0];
		for(int j = 0 ; j < 3 ; ++j) len1[j] += len2[j];
	}	
	return tmpans;
}
void solve(int u) {
	vis[u] = 1;
	ans += cal(u);
	for(int i = first[u] ; i ; i = next_[i]) {
		if(vis[to[i]]) continue;
		root = 0;nown = size[to[i]];
		getroot(to[i],u);
		solve(root);
	}
}
long long gcd_(long long a,long long b) {return b==0?a:gcd_(b,a%b);}
int main() {
	scanf("%d",&n);
	for(int i = 1 ; i < n ; ++i) {
		int x,y,d;
		scanf("%d%d%d",&x,&y,&d);
		d%=3;
		add(x,y,d);
	}
	f[0] = n ; root = 0;
	nown = n;
	getroot(1,0);
	solve(root);
	ans *= 2;
	ans += n;
	long long tmp = 1ll*n*n;
	long long g = gcd_(tmp,ans);
	cout << ans/g << "/" << tmp/g << endl;
}
