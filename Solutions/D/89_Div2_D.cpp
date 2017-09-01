//
//  main.cpp
//  89_Div2_D
//
//  Created by Karim Masoud on 5/10/17.
//  Copyright © 2017 Karim Masoud. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <string.h>
#define mod 100000000
using namespace std;
int K1, K2;
long long dp[101][101][11][11];
long long solve(int n1, int n2, int k1, int k2){
    
    if(k1 < 0 || k2 < 0)
        return 0;
    if(n1 == 0 && n2 == 0)
        return 1;
    long long &mem = dp[n1][n2][k1][k2];
    if(mem != -1)
        return mem;
    long long ans = 0;
    if(n1)
        ans = (ans%mod + solve(n1-1, n2, k1-1, K2)%mod)%mod;
    if(n2)
        ans = (ans%mod + solve(n1, n2-1, K1, k2-1)%mod)%mod;
    return mem = ans;
}
int main() {
    int n1, n2;
    scanf("%d %d %d %d", &n1, &n2, &K1, &K2);
    memset(dp, -1, sizeof(dp));
    printf("%I64d\n", solve(n1, n2, K1, K2));
    return 0;
}



