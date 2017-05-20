//
//  main.cpp
//  256_Div2_D
//
//  Created by Karim Masoud on 5/10/17.
//  Copyright © 2017 Karim Masoud. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

long long count (long long start, int m, long long key){
    return min((long long )ceil((double)key/start) - 1, (long long) m);
}

long long get_num_smaller_nums(int n, int m, long long num){
    long long cnt = 0;
    for(int i=1; i <= n; i++){
        long long cur = count(i, m, num);
        if (cur) {
            cnt += cur;
        }else{
            break;
        }
    }
    return cnt;
}

long long find_kth_number(int n, int m, long long k){
    long long low = 1;
    long long high = (long long)n * m;
    while(low <= high){
        long long mid = (low + high) / 2;
        long long count = get_num_smaller_nums(n, m, mid);
        if (count < k) {
            low = mid+1;
        }else if(count >= k){
            high = mid-1;
        }
    }
    if(get_num_smaller_nums(n, m, low) >= k){
        return high;
    }
    return low;
}

int main() {
    
    int n, m;
    long long k;
    scanf("%d %d %lld", &n, &m, &k);
    printf("%lld\n", find_kth_number(n, m, k));
    return 0;
}



