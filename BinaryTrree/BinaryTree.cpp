#include "BinaryTree.h"
#include "string"
#include<windows.h>

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

void DetacheLeftSubtree(TreeNode* root)
{
	if (!IsEmpty(root))
		root->left = nullptr;
}

void DetacheRightSubtree(TreeNode* root)
{
	if (IsEmpty(root))
		root->right = nullptr;
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

int MaxElement(TreeNode* root, int max_element)
{
	int value_1 = 0;
	int value_2 = 0;
	if (!IsEmpty(root))
	{
		if (root->element > max_element)
			max_element = root->element;
		value_1 = MaxElement(root->left, max_element);
		value_2 = MaxElement(root->right, max_element);
	}
	else
		return max_element;
	if (value_1 >= value_2)
		return value_1;
	else
		return value_2;
}

int CounterMaxElement(TreeNode* root, int max_element, int counter_max_element, int access)
{
	if (!IsEmpty(root))
	{
		if (access == 1)
			max_element = MaxElement(root);
		counter_max_element += CounterMaxElement(root->left, max_element, 0, 0);
		counter_max_element += CounterMaxElement(root->right, max_element, 0, 0);
	}
	if (!IsEmpty(root) && max_element == root->element)
		return counter_max_element + 1;
	else
		return counter_max_element;

}

void Print(TreeNode* root, int level, size_t len)
{
	if (!IsEmpty(root))
	{
		if (level == 0)
			len =  std::to_string(MaxElement(root)).length();
		Print(root->left, level + 1, len * 2);
		for (int i = 0; i < level; i++)
			std::cout << "    ";
		if (level != 0)
		{
			for (int i = 0; i < len; i++)
				std::cout << " ";
			std::cout << root->element << "\n";
		}
		else
		{
			HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_BLUE);
			std::cout << root->element << "\n";
			SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		Print(root->right, level + 1, len * 2);
	}
}
