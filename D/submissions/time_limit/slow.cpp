
#include <bits/stdc++.h>

using namespace std;

#define NMAX 3001

int par[NMAX];

int clear(int n){
	for(int i=1; i<=n; ++i){
		par[i] = i;
	}
	return 0;
}

int find(int x){
	if(x == par[x]){
		return x;
	}
	return par[x] = find(par[x]);
}

bool insert(int u, int v){
	
	if(find(u) == find(v)){
		return false;
	}

	par[find(u)] = find(v);
	
	return true;
}

int main(){
	
	int n, m, k; scanf("%d%d%d", &n, &m, &k);

	vector<int> s[NMAX];

	for(int i=0; i<m; ++i){
		int u, v; scanf("%d%d", &u, &v);
		if(u > v){
			int swap = u; u = v; v = swap;
		}
		s[u].push_back(v);
	}

	for(int i=1; i<=n; ++i){
		sort(s[i].begin(), s[i].end());
	}

	for(int i=0; i<k; ++i){
		int x, y; scanf("%d%d", &x, &y);
		int opt = n-1;
		for(int l=1; l<=n; ++l){
			for(int u=l; u<=min(n, l+opt-1); ++u){
				clear(n);
				int pass = 0;
				for(int j=l; j<u && !pass; ++j){
					for(auto &k : s[j]){
						if(k <= u){
							insert(j, k);
							if(find(x) == find(y)){
								pass = 1;
								break;
							}
						}else{
							break;
						}
					}
				}
				if(find(x) == find(y)){
					opt = min(opt, u-l);
				}
			}
		}

		printf("%d\n", opt);
	}
	return 0;
}
