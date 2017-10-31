#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1003;
int n;
struct hp {
	long long a;
	int b;
}stone[N];
inline bool cmp(hp x,hp y) {return x.b>y.b;}
long long c[100];
void solve() {
	int ans = 0;
	for(int i = 1 ; i <= n ; ++i) {
		for(int j = 62 ; j >= 0 ; --j) {
			if(!(stone[i].a>>j)) continue;
			if(!c[j]) {
				c[j] = stone[i].a;
				break;
			} else stone[i].a ^= c[j];
		}
		if(stone[i].a) ans += stone[i].b;
	}
	cout << ans << endl;
}
int main() {
	freopen("test2.in","r",stdin);
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++i) cin >> stone[i].a >> stone[i].b;
	sort(stone+1,stone+1+n,cmp);
	solve();
}	
