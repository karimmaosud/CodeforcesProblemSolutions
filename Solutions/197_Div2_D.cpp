//
//  main.cpp
//  197_Div2_D
//
//  Created by Karim Masoud on 5/10/17.
//  Copyright © 2017 Karim Masoud. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
};
class Tree{
public:
    TreeNode* root;
    Tree(TreeNode* root){
        this->root = root;
    }
};
void buid_tree(queue<TreeNode*>& q, int n){
    bool is_or = true;
    while(n != 1){
        for(int i =0; i<n/2; i++){
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            TreeNode* new_node= NULL;
            if(is_or)
                new_node = new TreeNode(left->val | right->val);
            else
                new_node = new TreeNode(left->val ^ right->val);
            q.push(new_node);
            new_node->left = left;
            new_node->right = right;
        }
        is_or = !is_or;
        n/=2;
    }
}

void update(TreeNode* node, int idx, int n, int level, int new_val){
    
    if(n == 1){
        node->val = new_val;
        return;
    }
    
    if(idx <= n/2){
        update(node->left, idx, n/2, level-1, new_val);
    }else{
        update(node->right, idx-n/2, n/2, level-1, new_val);
    }
    if(level&1){
        node->val = node->left->val | node->right->val;
    }else{
        node->val = node->left->val ^ node->right->val;
    }
}
int main() {
    
    int n,m;
    scanf("%d %d", &n, &m);
    
    queue<TreeNode*> q;
    for(int i=0; i<(1<<n); i++){
        int num;
        scanf("%d", &num);
        TreeNode* node = new TreeNode(num);
        q.push(node);
    }
    buid_tree(q, 1<<n);
    Tree* tree = new Tree(q.front());
    for(int q=0; q<m; q++){
        int idx, val;
        scanf("%d %d", &idx, &val);
        update(tree->root, idx, 1<<n, n, val);
        printf("%d\n", tree->root->val);
    }
    return 0;
    
    
}
