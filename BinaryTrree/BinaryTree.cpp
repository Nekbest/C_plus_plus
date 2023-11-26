#include "BinaryTree.h"

void Init(TreeNode*& root)
{
	root = nullptr;
}

void Init(TreeNode*& root, int value)
{ 
	root = new TreeNode;
	root->element = value;
	root->right = nullptr;
	root->left = nullptr;
}

void Init(TreeNode*& root, int value, TreeNode* left_subtree, TreeNode* right_subtree)
{
	Init(root, value);
	AttachLeftSubTree(root, left_subtree);
	AttachRightSubTree(root, right_subtree);
}

bool IsEmpty(TreeNode* root)
{
	return (root == nullptr);
}

bool AttachLeftSubTree(TreeNode* root, TreeNode* subtree)
{
	bool can_attach = false;
	if (!IsEmpty(root) && root->left == nullptr)
	{
		root->left = subtree;
		can_attach = true;
	}
	return can_attach;
}

bool AttachRightSubTree(TreeNode* root, TreeNode* subtree)
{
	bool can_attach = false;
	if (!IsEmpty(root) && root->right == nullptr)
	{
		root->right = subtree;
		can_attach = true;
	}
	return can_attach;
}

void Copy(TreeNode* root, TreeNode* new_root)
{
	if (!IsEmpty(root))
	{
		Init(new_root, root->element);
		Copy(root->left, new_root->left);
		Copy(root->right, new_root->right);
	}
	else
		new_root = nullptr;
}

void DetacheLeftSubtree(TreeNode* root, TreeNode*& subtree)
{
	if (root != nullptr)
	{
		subtree = root->left;
		root->left = nullptr;
	}
}

void DetacheRightSubtree(TreeNode* root, TreeNode*& subtree)
{
	if (root != nullptr)
	{
		subtree = root->right;
		root->right = nullptr;
	}
}

void PrefOrder(TreeNode* root)
{
	if (!IsEmpty(root))
	{
		std::cout << root->element << "\n";
		PrefOrder(root->left);
		PrefOrder(root->right);
	}
}

void InOrder(TreeNode* root)
{
	if (!IsEmpty(root))
	{
		InOrder(root->left);
		std::cout << root->element << "\n";
		InOrder(root->right);
	}
}

void PostOrder(TreeNode* root)
{
	if (!IsEmpty(root))
	{
		PostOrder(root->left);
		PostOrder(root->right);
		std::cout << root->element << "\n";
	}
}

