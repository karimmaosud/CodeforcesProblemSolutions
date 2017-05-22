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
#include <set>

using namespace std;

int main() {
    map<int, vector<int>> color_nodes;
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> adjList(n+1);
    vector<int> node_color(n+1);
    for(int i=1; i<=n; i++){
        int c;
        scanf("%d", &c);
        color_nodes[c].push_back(i);
        node_color[i] = c;
    }
    for(int i=0; i<m; i++){
        int u,v;
        scanf("%d %d", &u, &v);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int res_color = -1;
    int max_cardinality = -10000;
    for(map<int, vector<int>>::iterator itr=color_nodes.begin(); itr!=color_nodes.end(); itr++){
        int c = itr->first;
        vector<int> nodes = itr->second;
        set<int> adjColors;
        for(int i=0; i<nodes.size(); i++){
            int u = nodes[i];
            for(int j=0; j<adjList[u].size(); j++){
                int v = adjList[u][j];
                if(node_color[v] != c)
                    adjColors.insert(node_color[v]);
            }
        }
        if(max_cardinality < (int)adjColors.size()){
            max_cardinality = (int) adjColors.size();
            res_color = c;
        }
    }
    printf("%d\n", res_color);
    return 0;
}



