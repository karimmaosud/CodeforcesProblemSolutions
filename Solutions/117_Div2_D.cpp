//
//  main.cpp
//  117_Div2_D
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
#include <set>
#include <unordered_set>
#define mod 1000000009
using namespace std;
long long const_base = 31;
int find_smallest_period(string& s){
    int n = (int) s.length();
    vector<int> pi(n, 0);
    
    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    int min_period = n - pi[n-1];
    if(n % min_period == 0){
        return min_period;
    }
    return 0;
}

int main() {
    
    char str[100010];
    string s1, s2;
    scanf("%s", str);
    s1 = str;
    scanf("%s", str);
    s2 = str;
    if(s1.length() > s2.length())
        swap(s1, s2);
    int p1 = find_smallest_period(s1);
    int p2 = find_smallest_period(s2);
    
    long long base = const_base;
    long long hash = 0;
    unordered_set<long long> divisors;
    
    for(int i=0; i<s1.length(); i++){
        hash = (hash%mod + ((s1[i]-96)%mod * base%mod)%mod)%mod;
        base = (base%mod * const_base%mod)%mod;
        int len = i+1;
        if(p1 && len % p1 == 0 && (s1.length() % len == 0)){
            divisors.insert(hash);
        }
    }
    divisors.insert(hash);
    hash = 0;
    base = 31;
    int res = 0;
    for(int i=0; i<s2.length(); i++){
        hash = (hash%mod + ((s2[i]-96)%mod * base%mod)%mod)%mod;
        base = (base%mod * const_base%mod)%mod;
        int len = i+1;
        if(p2 && len % p2 == 0 && (s2.length() % len == 0) && divisors.count(hash)){
            res ++;
        }
    }
    printf("%d\n", res);
    return 0;
}



