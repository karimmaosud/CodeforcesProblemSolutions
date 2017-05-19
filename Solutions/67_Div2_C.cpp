//
//  main.cpp
//  67_Div2_C
//
//  Created by Karim Masoud on 5/10/17.
//  Copyright © 2017 Karim Masoud. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

void find_divisors(int num, vector<int>& divisors){
    for(int i =1; i*i<=num; i++){
        if(num % i == 0){
            divisors.push_back(i);
            if(i*i != num){
                divisors.push_back(num/i);
            }
        }
    }
}

int find_greatest_divisor(int key, vector<int>& divisors){
    int low = 0;
    int high = (int) divisors.size() - 1;
    while(low <= high){
        int mid = (low+high)/2;
        if(divisors[mid] <= key){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return high;
}
int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    int g = gcd(a, b);
    vector<int> divisors;
    find_divisors(g, divisors);
    sort(divisors.begin(), divisors.end());
    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++){
        int low, high;
        scanf("%d %d", &low, &high);
        int idx = find_greatest_divisor(high, divisors);
        if (idx == -1 || !(divisors[idx] >= low && divisors[idx] <= high)) {
            printf("%d\n", -1);
        }else{
            printf("%d\n", divisors[idx]);
        }
    }
    return 0;
}



