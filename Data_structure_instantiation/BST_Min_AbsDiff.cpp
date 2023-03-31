//
// Created by KAI on 2023/3/21.
//
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
class Solution {
public:
    vector<int> vec;
    void to_vector(TreeNode* root){
        if(root == NULL){
            return;
        }
        to_vector(root->left);
        vec.push_back(root->val);
        to_vector(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        vec.clear();
        to_vector(root);
        if(vec.size() < 2){
            return 0;
        }
        int res = INT_MAX;
        for(int i = 1; i < vec.size(); i++){
            res = min(res, vec[i] - vec[i-1]);
        }
        return res;
    }
};

int main(){
    TreeNode *A = new TreeNode(1);
    TreeNode *B = new TreeNode(2);
    TreeNode *C = new TreeNode(3);
    TreeNode *D = new TreeNode(4);
    TreeNode *E = new TreeNode(6);
//    TreeNode* tmp = A;
//    A = B;
//    cout << tmp->val;
    D->left = B;
    B->left = A;
    B->right = C;
    D->right = E;
    Solution s;
    int res = s.getMinimumDifference(D);
    cout << res << endl;
}
