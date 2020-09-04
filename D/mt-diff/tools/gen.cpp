
#include <bits/stdc++.h>

using namespace std;

#define NMAX 3001

struct CC{

	int par[NMAX];
	int n;
	int count;

	CC(int _n) : n(_n) { 
		count = 0;
		for(int i=1; i<=n; ++i){
			par[i] = i;
		}
	}

	int find(int u){
		if(u == par[u]){
			return u;
		}
		return par[u] = find(par[u]);
	}

	int insert(int u, int v){
		int ru = find(u);
		int rv = find(v);
		if(ru != rv){
			par[ru] = rv;
			++ count;
		}
		return 0;
	}

	int pass(){
		return count == n-1;
	}
};

int main(int argc, char **argv){

	assert(argc == 5);

	int t, n, m, p;

	sscanf(argv[1], "%d", &t);
	sscanf(argv[2], "%d", &n);
	sscanf(argv[3], "%d", &m);
	sscanf(argv[4], "%d", &p);
	
	srand(60000+t*199);
	
	int k = 20;
	int bisect[NMAX];

	for(int i=1; i<=n; ++i){
		bisect[i] = 0;
	}

	for(int i=0; i<n/2; ++i){
		int k = rand()%n+1;
		if(!bisect[k]){
			bisect[k] = 1;
		}else{
			--i;
		}
	}

	CC check(n);
	
	static bitset<NMAX> s[NMAX];

	for(int i=1; i<=n; ++i){
		s[i].reset();
	}

	int count = 0;

	assert(p <= n/2 && p <= m);
	assert(m <= n/2*(n/2-1)+p);

	printf("%d %d %d\n", n, m, k);

	for(int i=0; i<p; ++i){
		int u = rand()%n+1;
		int v = rand()%n+1;
		if(u != v && bisect[u] != bisect[v] && !s[u][v]){
			s[u][v] = s[v][u] = true;
			printf("%d %d ", u, v);
			check.insert(u, v);
			++ count;
		}else{
			-- i;
		}
	}

	while(count < m){
		int u = rand()%n+1;
		int v = rand()%n+1;
		if(u != v && bisect[u] == bisect[v] && !s[u][v]){
			s[u][v] = s[v][u] = true;
			printf("%d %d ", u, v);
			check.insert(u, v);
			++ count;
		}
	}
	printf("\n");

	for(int i=0; i<k; ++i){
		int u = rand()%n+1;
		int v = rand()%n+1;
		printf("%d %d\n", u, v);
	}

	assert(check.pass());

	return 0;
}
