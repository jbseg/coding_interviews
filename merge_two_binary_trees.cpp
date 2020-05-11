/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:

Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
*/
// tree1 - m nodes 
// tree2 - n nodes
// O(m + n)

TreeNode * f(TreeNode *root1, TreeNode* root2) {
	// base case
	if (!root1 && !root2) return nullptr;

	TreeNode * root = new TreeNode;

	int leftv; rightv;

	if (!root1) { leftv = 0; } else {leftv = root1->val; }
	if (!root2) { rightv = 0; } else {rightv = root2->val; }

	root->val = leftv + rightv;

	if (!root1) {
		// root->left = f(nullptr, root2->left);
		// root->right = f(nullptr, root2->right);
		return root2;
	} 
	else if (!root2 ){
		// root->left = f(root1->left, nullptr);
		// root->right = f(root1->right, nullptr);
		return root1;
	} 
	else {
		root->left = f(root1->left, root2->left);

		root->right = f(root1->right, root2->right);
	}

	return root;
}