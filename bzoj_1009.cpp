#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m,fail[23],k,b[23];
char a[233];
void get_fail() {
	int j = 0 ;
	for(int i = 0 ; i <= m ; ++i) {
		while(j!=0 && a[j+1]!=a[i]) j = fail[j];
		if(a[j+1]==a[i]) j++;
		fail[i] = j;
	}
}
struct hp {
	int w[23][23];
}ans,start;
void prepare() {
	for(int i = 0 ; i < m ; ++i) ans[i][i] = 1;

int main() {
	scanf("%d%d%d",&n,&m,&k);
	scanf(" %s",a+1);
	for(int i = 1 ; i <= m ; ++i) b[i] = a[i]-'0';
	get_fail();
	prepare();
