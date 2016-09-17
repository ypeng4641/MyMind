#include <stdio.h>

struct TreeNode
{
	int key;
	TreeNode* parent;
	TreeNode* leftKid;
	TreeNode* rightKid;
};

int InorderTreeWalk(TreeNode* n)
{
	InorderTreeWalk(n->lefKid);
	printf(n->key);
	InorderTreeWalk(n->rightKid);
	
	return 0;
}

int TreeSearch(TreeNode* n, int k, TreeNode** tar)
{
	if(n == NULL || n.key == k)
		*tar = n;
	else
	{
		if(k < n.key)
			TreeSearch(n.leftKid, k, tar);
		else
			TreeSearch(n.rightKid, k, tar);
	}

	return 0;
}

int IterativeTreeSearch(TreeNode* n, int k, TreeNode* tar)
{
	TreeNode* nxt = NULL;
	for(; n != NULL; n = nxt)
	{
		if(n->key == k)
			break;
		else
		{
			if(k < n->key)
				nxt = n->leftKid;
			else
				nxt = n->rightKid;
		}
	}
	*tar = n;

	return 0;
}

int TreeMinimum(TreeNode* n, TreeNode** min)
{
	if(n->leftKid != NULL)
		TreeMinimum(n->leftKid, min);
	else
		*min = n;

	return 0;
}

int TreeMaximum(TreeNode* n, TreeNode** max)
{
	if(n->rightKid != NULL)
		TreeMaximum(n->rightKid, max);
	else
		*max = n;

	return 0;
}

int TreeSuccessor(TreeNode* n, TreeNode** suc)
{
	if(n->rightKid != NULL)
		TreeMinmum(n->rightKid, suc);
	else
	{
		for(; n->parent != NULL && n != n->parent->leftKid; n = n->parent)
		{
		}
		*suc = n->parent;
	}

	return 0;
}

int TreePredecessor(TreeNode* n, TreeNode** pred)
{
	if(n->leftKid != NULL)
		TreeMaximum(n->leftKid, pred);
	else
	{
		for(; n->parent != NULL && n != n->prarent->rightKid; n = n->parent);
		{
		}
		*pred = n->parent;
	}

	return 0;
}

int TreeInsert(TreeNode* n, TreeNode* ins)
{
	TreeNode* tarPrn = NULL;
	TreeNode* nxt = NULL;
	for(; n != NULL; n = nxt)
	{
		tarPrn = n;
		if(ins->key < n->key)
			nxt = n->leftKid;
		else
			nxt = n->rightKid;
	}
	if(NULL != tarPrn)
	{
		if(ins->key < tarPrn->key)
			tarPrn->leftKid = ins;
		else
			tarPrn->rightKid = ins;
	}
	ins->parent = tarPrn;

	return 0;
}

int TreeDelete(TreeNode* n)
{
	if(NULL == n)
	{}
	else if(NULL == n->leftKid && NULL == n->rightKid)
	{
		if(NULL != n->parent)
		{
			if(n != n->parent->leftKid)
				n->parent->rightKid = NULL;
			else
				n->parent->leftKid = NULL;
		}
	}
	else if(NULL == n->leftKid && NULL != n->rightKid)
	{
		if(NULL != n->parent)
		{
			if(n != n->parent->leftKid)
				n->parent->rightKid = n->rightKid;
			else
				n->parent->leftKid = n->rightKid;
		}
		n->rightKid->parent = n->parent;
	}
	else if(NULL != n->leftKid && NULL == n->rightKid)
	{
		if(NULL != n->parent)
		{
			if(n != n->parent->leftKid)
				n->parent->rightKid = n->leftKid;
			else
				n->parent->leftKid = n->leftKid;
		}
		n->leftKid->parent = n->parent;
	}
	else
	{
		TreeNode* suc = NULL;
		TreeSuccessor(n, &suc);	
		if(suc != n->rightKid)
		{
			suc->parent->leftKid = suc->rightKid;
			if(NULL != suc->rightKid)
				suc->rightKid->parent = suc->parent;

			suc->rightKid = n->rightKid;
			suc->rightKid->parent = suc;
		}
		suc->leftKid = n->leftKid;
		suc->leftKid->parent = suc;

		if(NULL != n->parent)
		{
			if(n != n->parent->leftKid)
				n->parent->rightKid = suc;
			else
				n->parent->leftKid = suc;
		}
		suc->parent = n->parent;
	}
	delete n;

	return 0;
}

int TreeRandomizedBuild(TreeNode** n, TreeNode* elm)
{
	if(NULL == *n)
		*n = elm;
	else
		TreeInsert(*n, elm);

	return 0;
}
