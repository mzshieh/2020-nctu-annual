
#include <bits/stdc++.h>

using namespace std;

#define NMAX 3001

bool compare(const pair<int, int> &a, const pair<int, int> &b){
	return a.second < b.second;
}

struct CC {
	
	int par[NMAX];
	pair<int, int> edge[NMAX];
	int ptr;
	
	CC(){
		for(int i=0; i<NMAX; ++i){
			par[i] = i;
		}
		ptr = 0;
	}

	bool insert(pair<int, int> e){

		int ru = find(e.first);
		int rv = find(e.second);

		if(ru == rv){
			return false;
		}else{
			par[ru] = rv;
			edge[ptr++] = e;
			return true;
		}
	}

	int find(int u){
		if(par[u] == u){
			return u;
		}
		return par[u] = find(par[u]);
	}

	bool reach(int u, int v, int y){
		
		if(u <= y && v <= y){

			for(int i=1; i<=y; ++i){
				par[i] = i;
			}

			for(int i=0; i<ptr; ++i){
				if(edge[i].second <= y){
					if(find(edge[i].first) != find(edge[i].second)){
						par[par[edge[i].first]] = par[edge[i].second];
					}
				}else{
					break;
				}
			}
			return find(u) == find(v);
		}
		return false;
	}
};

int main(){
	
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	
	vector< pair<int, int> > s;

	for(int i=0; i<m; ++i){
		int u, v; scanf("%d%d", &u, &v);
		if(u > v){
			int swap = u; u = v; v = swap;
		}
		s.push_back(make_pair(u, v));
	}

	sort(s.begin(), s.end(), compare);

	CC *r = new CC [n+1];

	for(int i=2; i<=n; ++i){
		r[0].insert(make_pair(1, i));
	}

	for(int i=0; i<m; ++i){
		int x = 0, y = n;
		while(x < y-1){
			int z = (x+y)/2;
			if(r[z].find(s[i].first) == r[z].find(s[i].second)){
				x = z;
			}else{
				y = z;
			}
		}
		for(int j=y; j<=s[i].first; ++j){
			r[j].insert(s[i]);
		}
	}

	for(int q=0; q<k; ++q){
		int u, v; scanf("%d%d", &u, &v);
		int x = 1, y = 1;
		int opt = n-1;

		if(u == v){
			printf("0\n");
			continue;
		}

		while(y <= n){
			if(r[x].reach(u, v, y)){
				opt = min(opt, y-x);
				++ x;
			}else{
				++ y;
			}
		}
		printf("%d\n", opt);
	}

	return 0;
}
