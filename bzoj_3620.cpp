#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 15015;
char a[N];
int k,lena,fail[N],g[N],ans = 0;
int main() {
	scanf("%s",a);
	scanf("%d",&k);
	lena = strlen(a);
	for(int i = 0 ; i < lena-2*k ; ++i) {
		fail[i] = i-1;
		int t = i-1;
		for(int j = i + 1 ; j < lena ; ++j) {
			while(t!=i-1 && a[t+1]!=a[j]) t = fail[t];
			if(a[t+1]==a[j]) t++;
			fail[j] = t;
			g[j] = t;
			if(g[j]>=0 && g[g[j]]-i+1>=k) g[j] = g[g[j]];
			int len = g[j]-i+1;
			if(len>=k&&g[j]+len+1<=j) ans++;
		}
	}
	cout << ans << endl;
}
