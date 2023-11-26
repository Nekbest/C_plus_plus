#pragma once
#include <iostream>

struct TreeNode
{
	int element;
	TreeNode* left;
	TreeNode* right;

};

void Init(TreeNode*& root);
void Init(TreeNode*& root, int element);
void Init(TreeNode*& root, int element, TreeNode* left_subtree, TreeNode* right_subtree);
bool IsEmpty(TreeNode* root);
bool AttachLeftSubTree(TreeNode* root, TreeNode* subtree);
bool AttachRightSubTree(TreeNode* root, TreeNode* subtree);
void Copy(TreeNode* root, TreeNode* new_root);
void DetacheLeftSubtree(TreeNode* root, TreeNode*& subtree);
void DetacheRightSubtree(TreeNode* root, TreeNode*& subtree);
void PrefOrder(TreeNode* root);
void InOrder(TreeNode* root);
void PostOrder(TreeNode* root);
