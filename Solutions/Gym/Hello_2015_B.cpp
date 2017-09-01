/*http://codeforces.com/gym/100571/problem/B*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <string.h>
#include <set>
#include <unordered_set>
#define mod 1000000007
#define maxn 100050
using namespace std;

long long f[maxn];
long long x[maxn];
long long p[maxn];

void init(int f0, int f1, int a, int b){
    memset(p, 0, maxn);
    f[0] = (long long)f0;
    f[1] = (long long)f1;
    for(int i = 2; i < maxn; i++){
        f[i] = ((a * f[i-2])%mod + (b * f[i-1])%mod)%mod;
    }
}

void update_p(int l, int r, int n, int a, int b){
    p[l] = (p[l] + f[0])%mod;
    if(l < r){
        p[l+1] = (p[l+1] + f[1] - (b * f[0])%mod + mod)%mod;
        p[r+1] = (p[r+1] - f[r - l + 1] + mod)%mod;
        p[r+2] = (p[r+2] - (a * f[r - l])%mod + mod)%mod;
    }else{
        p[r+1] = (p[r+1] - (b * f[0])%mod + mod)%mod;
        p[r+2] = (p[r+2] - (a * f[0])%mod + mod)%mod;
    }
}

void adjust_p(int n, int a, int b){
    p[1] = (p[1] + (b * p[0])%mod) %mod;
    for(int i = 2; i < n; i++){
        p[i] = ((p[i] + a * p[i-1])%mod + b * p[i-2])%mod;
    }
}
int main(){
    int f0, f1, a, b, n, q;
    scanf("%d %d %d %d %d %d", &n, &q, &f0, &f1, &a, &b);
    
    init(f0, f1, a, b);
    
    for(int i = 0; i < n; i++){
        scanf("%I64d", &x[i]);
    }
    
    for(int i = 0; i < q; i++){
        int l, r;
         scanf("%d %d", &l, &r);
        l--, r--;
    
        update_p(l, r, n, a, b);
        
    }
    for(int i = 0; i < n; i++){
        if(i > 1){
            p[i] = (p[i] + (a * p[i-2])%mod)%mod;
        }
        if(i){
            p[i] = (p[i] + (b * p[i-1])%mod)%mod;
        }
        x[i] = (x[i] + p[i])%mod;
        printf("%I64d ", x[i]);
    }
    printf("\n");
    return 0;
}

