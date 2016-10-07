#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include <stdio.h>
#include <queue>
#include <map>

#include "GraphDef.h"

struct BreadthVetex
{
	Vetex v;
	int distance;
};

static std::map<int, VetexWithList*> vMap;

int InitVetex(int amount, int vPtr[])
{
	for(int i = 0; i < amount; ++i)
	{
		BreadthVetex* v = new BreadthVetex;
		v->v.id = vPtr[i];
		v->v.s = S_WHITE;
		v->distance = -1;

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
	//转换成广度结点链表
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

	//将新的广度结点链表加入图
	ListNode* newArr = new ListNode[g->listAmn +1];
	if(g->listAmn > 0)
		memcpy(newArr, g->listArr, g->listAmn * sizeof(ListNode));

	delete[] g->listArr; g->listArr = newArr;
	g->listArr[g->listAmn] = lHead;
	++g->listAmn;

	return 0;
}

int BFSVisit(ListNode* n)
{
	std::queue<VetexWithList*> vQue;
	VetexWithList* vsl = n->node;
	BreadthVetex* bv = reinterpret_cast<BreadthVetex*>(vsl->vetex);
	bv->v.s = S_GRAY;
	vQue.push(vsl);

	do
	{
		VetexWithList* curVSL = vQue.front();
		BreadthVetex* curBV = reinterpret_cast<BreadthVetex*>(curVSL->vetex);
		vQue.pop();
		printf("id(%d), distance(%d)\n", curBV->v.id, curBV->distance);

		for(ListNode* it = curVSL->adjNxt; it != NULL; it = it->nxt)
		{
			VetexWithList* itVWL = it->node;
			BreadthVetex* itBV = reinterpret_cast<BreadthVetex*>(itVWL->vetex);
			if(S_WHITE == itBV->v.s)
			{
				itVWL->parent = curVSL;
				itBV->distance = curBV->distance +1;

				itBV->v.s = S_GRAY;
				vQue.push(itVWL);
			}
		}

		curBV->v.s = S_BLACK;
	}
	while(! vQue.empty());

	return 0;
}

int BFS(GraphInList* g)
{
	int ret = 0;
	for(int i = 0; i < g->listAmn; ++i)
	{
		VetexWithList* vsl = g->listArr[i].node;
		BreadthVetex* bv = reinterpret_cast<BreadthVetex*>(vsl->vetex);
		if(S_WHITE == bv->v.s)
		{
			vsl->parent = NULL;
			bv->distance = 0;
			ret = BFSVisit(&(g->listArr[i]));
		}
	}

	return ret;
}


#endif