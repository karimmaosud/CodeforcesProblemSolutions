//
//  main.cpp
//  130_Div2_D
//
//  Created by Karim Masoud on 5/14/17.
//  Copyright © 2017 Karim Masoud. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> ps(n);
    for(int i =0; i<n; i++){
        scanf("%d", &ps[i]);
    }
    vector<ii> points;
    for(int i=0; i<5; i++){
        int p;
        scanf("%d", &p);
        points.push_back({p, i});
    }
    
    sort(points.begin(), points.end());
    reverse(points.begin(), points.end());
    
    vector<long long> res(5, 0);
    long long rem_points = 0;
    for(int i=0; i<n; i++){
        rem_points += ps[i];
        for(int j=0; j<5; j++){
            long long taken = rem_points/points[j].first;
            res[points[j].second] += taken;
            rem_points -= (taken*points[j].first);
        }
    }
    printf("%I64d", res[0]);
    for(int i=1; i<5; i++)
        printf(" %I64d", res[i]);
    printf("\n%I64d\n", rem_points);
    return 0;
}
