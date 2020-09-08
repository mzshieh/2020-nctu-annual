#include<bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    set<pair<pii,int>> s;
    map<pii,int> m;
    long long ans=0;
    for(int i = 0;i<n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int gcd=__gcd(__gcd(a,b),c);
        a/=gcd;
        b/=gcd;
        c/=gcd;
        if(a<0){
            a*=-1;
            b*=-1;
            c*=-1;
        }
        if(s.find(mp(mp(a,b),c))!=s.end()){
            printf("TOO MANY\n");
            return 0;
        }
        s.insert(mp(mp(a,b),c));
        gcd=__gcd(a,b);
        a/=gcd;
        b/=gcd;
        if(a<0){
            a*=-1;
            b*=-1;
        }
        m[mp(a,b)]++;
    }
    for(auto it:m){
        ans+=it.y*1ll*(n-it.y);
    }
    assert(ans%2==0);
    if(ans/2>1000000)printf("TOO MANY\n");
    else
    printf("%lld\n",ans/2);
}
