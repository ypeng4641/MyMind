#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H

#include <stdio.h>
#include <map>

#include "GraphDef.h"

struct DepthVetex
{
	Vetex v;
	int foundT;
	int finishT;
};

static std::map<int, VetexWithList*> vMap;

int InitVetex(int amount, int vPtr[])
{
	for(int i = 0; i < amount; ++i)
	{
		DepthVetex* v = new DepthVetex;
		v->v.id = vPtr[i];
		v->v.s = S_WHITE;
		v->finishT = -1;
		v->foundT = -1;

		VetexWithList* vl = new VetexWithList;
		vl->vetex = v;
		vl->adjNxt = NULL;
		vl->parent = NULL;

		auto r = vMap.insert(std::make_pair(vPtr[i], vl));
		if(! r.second)
			printf("vMap insert failed! v(%d)", vPtr[i]);
	}

	return 0;
}

int InsertAdj(GraphInList* g, int listSize, int list[])
{
	if(listSize <= 0 || !list)
		return -1502;

	auto vit = vMap.find(list[0]);
	if(vMap.end() == vit)
		return -1631;
	VetexWithList *head= vit->second;
	//转换成深度结点链表
	ListNode lHead = {head, NULL};
	ListNode *pre = &lHead;
	for(int i = 0; i < listSize; ++i)
	{
		vit = vMap.find(list[i]);
		if(vMap.end() == vit)
			return -1631;
		VetexWithList* dv = vit->second;
		ListNode* ln = new ListNode;
		ln->node = dv;
		ln->nxt = NULL;

		pre->nxt = ln;
		pre = ln;
	}
	//初始化结点的邻接链表
	head->adjNxt = lHead.nxt;

	//将新的深度结点链表加入图
	ListNode* newArr = new ListNode[g->listAmn +1];
	if(g->listAmn > 0)
		memcpy(newArr, g->listArr, g->listAmn * sizeof(ListNode));

	delete[] g->listArr; g->listArr = newArr;
	g->listArr[g->listAmn] = lHead;
	++g->listAmn;
	return 0;
}

int DFSVisit(ListNode* n, int& curT)
{
	int ret = 0;
	++curT;

	VetexWithList* vwl = (n->node);
	DepthVetex* dv = reinterpret_cast<DepthVetex*>(vwl->vetex);

	dv->foundT = curT;
	dv->v.s = S_GRAY;
	printf("id(%d), foundT(%d)\n", dv->v.id, curT);
	for(ListNode* it = vwl->adjNxt; it != NULL; it = it->nxt)
	{
		VetexWithList* itVWL = it->node;
		DepthVetex* itDV = reinterpret_cast<DepthVetex*>(it->node->vetex);
		if(S_WHITE == itDV->v.s)
		{
			itVWL->parent = vwl;
			ret = DFSVisit(it, curT);
		}
	}

	++curT;
	dv->finishT = curT;
	dv->v.s = S_BLACK;
	printf("id(%d), finishT(%d)\n", dv->v.id, curT);

	return ret;
}

int DFS(GraphInList* g)
{
	int ret = 0;
	for(int i = 0; i < g->listAmn; ++i)
	{
		VetexWithList *head = (g->listArr[i].node);
		DepthVetex* curV = reinterpret_cast<DepthVetex*>(head->vetex);
		if(S_WHITE == curV->v.s)
		{
			int ct = 0;
			ret = DFSVisit(&(g->listArr[i]), ct);
		}
	}

	return ret;
}


#endif