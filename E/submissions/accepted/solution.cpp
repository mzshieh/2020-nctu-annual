#include<bits/stdc++.h>

using namespace std;

#define ll long long

void dump(vector<vector<ll> >const& A){
	for(int i=0;i<A.size();++i){
		for(int j=0;j<A[i].size();++j)
			cout << A[i][j]<<" ";
		cout <<"\n";
	}
	cout <<"\n";
}

ll pow(ll a, int b, ll mod){
	if(b==0) return 1LL;
	if(b&1) return pow(a,b-1,mod)*a%mod;
	return pow(a*a%mod,b/2,mod);
}

inline ll inv(ll a, ll p){return pow(a,p-2,p);}

inline void rowOp(vector<vector<ll> >& A, int i, int j, ll c, ll p){
	int n = A.size();
	for(int k=0;k<n;++k)
		A[i][k] = (A[i][k]+A[j][k]*c%p)%p;
}

inline void rowScale(vector<vector<ll> >& A, int i, ll c, ll p){
	int n = A.size();
	for(int j=0;j<n;++j) A[i][j] = A[i][j]*c%p;
}

inline void rowSwap(vector<vector<ll> >& A, int i, int j){
	if(i==j) return;
	int n = A.size();
	for(int k=0;k<n;++k) swap(A[i][k],A[j][k]);
}

inline void pivot(vector<vector<ll> >& A, vector<vector<ll> > &B, int j, ll p){
	int n = A.size();
	for(int i=j;i<n;++i)
		if(A[i][j]%p!=0){
			rowSwap(B,i,j);
			rowSwap(A,i,j);
			break;
		}
}

inline vector<vector<ll> > inv(vector<vector<ll> > A, ll p){
	int n = A.size();
	vector<vector<ll> > B(n, vector<ll>(n,0));
	for(int i=0;i<n;++i) B[i][i] = 1;
	for(int j=0;j<n;++j){
		pivot(A,B,j,p); ll c = inv(A[j][j],p);
		rowScale(B,j,c,p); rowScale(A,j,c,p);
		for(int i=j+1;i<n;++i){
			c = p-A[i][j];
			rowOp(B,i,j,c,p); rowOp(A,i,j,c,p);
		}
	}
	for(int j=n-1;j>=0;--j){
		for(int i=j-1;i>=0;--i){
			ll c = p-A[i][j];
			A[i][j] = (A[i][j]+c)%p;
			rowOp(B,i,j,c,p);
		}
	}
	return B;
}

vector<ll> mul(vector<vector<ll> >const& A, vector<ll>const& x, ll p){
	int n = A.size();
	vector<ll> y(n,0LL);
	for(int i=0;i<n;++i)
	for(int j=0;j<n;++j)
		y[i] = (y[i]+A[i][j]*x[j]%p)%p;
	return y;
}

void lift(vector<vector<ll> >& invA, vector<vector<ll> >& A,
		vector<ll>& xp, vector<ll>const& b, ll pk, ll p){
	int n = A.size();
	ll ppk = p*pk;
	vector<ll>&& z = mul(A,xp,ppk);
	for(int i=0;i<n;++i){
		z[i] = (b[i]%ppk+ppk-z[i])%ppk/pk;
	}

	vector<ll>&& t = mul(invA,z,p);
	for(int i=0;i<n;++i) xp[i] = (xp[i]+t[i]*pk)%ppk;
}

int main(){
	ll p,n,k; cin>>p>>n>>k;
	vector<ll> b(n);
	for(int i=0;i<n;++i) scanf("%lld",&b[i]);
	vector<vector<ll> > A(n, vector<ll>(n));
	for(int i=0;i<n;++i)
	for(int j=0;j<n;++j)
		scanf("%lld",&A[i][j]);
	vector<vector<ll> >&& invA = inv(A,p);

	vector<ll>&& x = mul(invA,b,p);
	for(ll pk=p;--k;pk*=p) lift(invA,A,x,b,pk,p);

	for(int i=0;i<n;++i){
		if(i) cout<<" ";
		cout<<x[i];
	}cout<<"\n";
	return 0;
}
