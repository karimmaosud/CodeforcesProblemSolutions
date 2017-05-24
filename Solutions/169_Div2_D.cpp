//
//  main.cpp
//  169_Div2_D
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

using namespace std;

bool can_one(long long num, int bit_index, long long max){
    if((num|(1LL << bit_index)) <= max){
        return true;
    }
    return false;
}

bool can_zero(long long num, int bit_index, long long min){
    if(num >= min || (num| ((1LL<<bit_index)-1)) >= min){
        return true;
    }
    return false;
}

int main() {
    long long l, r;
    cin >> l >> r;
    long long a =0 , b = 0;
    
    for(int bit = 62; bit>=0; bit--){
        // 1 0
        if(can_one(a, bit, r) && can_zero(b, bit, l)){
            a|= (1LL<<bit);
        }
        // 0 1
        else if(can_zero(a, bit, l) && can_one(b, bit, r)){
            b|= (1LL<<bit);
        }
        // 0 0
        else if(can_zero(a, bit, l) && can_zero(b, bit, l)){
            // do nothing
        }
        // 1 1
        else{
            b|= (1LL<<bit);
            a|= (1LL<<bit);
        }
    }
    cout << (a^b) << endl;
    return 0;
}



