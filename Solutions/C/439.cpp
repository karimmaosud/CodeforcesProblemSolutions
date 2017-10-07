#include <set>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#define maxn 1000000
#define mod 998244353
using namespace std;

long long c[5010][5010];

void init(){
    c[0][0] = 1;
    for(int i=0; i<5010; i++){
        for(int j =0; j<5010; j++){
            if(i > 0){
                c[i][j] = (c[i][j]%mod + c[i-1][j]%mod)%mod;
                if(j > 0){
                    c[i][j] = (c[i][j]%mod + c[i-1][j-1]%mod)%mod;
                }
            }
        }
    }
}

long long calc_ways(int a, int b){
    int m = min(a,b);
    int n = max(a,b);
    
    long long res = 0;
    long long runner = n;
    for(int i=1; i<=m; i++){
        res = (res%mod + (c[m][i] * runner)%mod)%mod;
        runner = (runner%mod * (n-i))%mod;
    }
    return (res+1)%mod;
}

int main(){
    memset(c, 0, sizeof(c));
    init();
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    long long ab = calc_ways(a, b);
    long long ac = calc_ways(a, c);
    long long bc = calc_ways(b, c);
    long long res = ((ab * ac)%mod * bc)%mod;
    printf("%lld\n", res);
    return 0;
}
