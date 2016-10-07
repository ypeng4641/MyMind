#include <stdio.h>
#include <string>
#include <queue>

//#define DFS_ALG
#ifdef DFS_ALG
#include "DepthFirstSearch.h"
#else
#include "BreadthFirstSearch.h"
#endif

std::string PrintfVetex(VetexWithList* v)
{
	std::string ret;

	std::queue<VetexWithList*> vQue;
	vQue.push(v);
	do
	{
		ret += "\n";
		VetexWithList* curVWL = vQue.front();
		vQue.pop();

		for(ListNode* it = curVWL->adjNxt; it != NULL; it = it->nxt)
		{
			VetexWithList* itVWL = it->node;
#ifdef DFS_ALG
			DepthVetex* vetex = reinterpret_cast<DepthVetex*>(itVWL->vetex);
#else
			BreadthVetex* vetex = reinterpret_cast<BreadthVetex*>(itVWL->vetex);
#endif
			if(vetex->v.s != S_NIL && itVWL->parent == curVWL)
			{
				char buf[16];
				sprintf(buf, "%d\t", vetex->v.id);
				ret += buf;
				vetex->v.s = S_NIL;
			}
		}
	}
	while(! vQue.empty());

	return ret;
}

std::string PrintGraph(GraphInList* g)
{
	std::string ret;

	for(int i = 0; i < g->listAmn; ++i)
	{
		VetexWithList* vwl = g->listArr[i].node;
#ifdef DFS_ALG
		DepthVetex* vetex = reinterpret_cast<DepthVetex*>(vwl->vetex);
#else
		BreadthVetex* vetex = reinterpret_cast<BreadthVetex*>(vwl->vetex);
#endif

		if(S_NIL != vetex->v.s)
		{
			ret += PrintfVetex(vwl);
		}
	}

	puts(ret.c_str());
	return ret;
}

int main(int argc, char* argv[])
{
	int ret = 0;

	int vArr[] = {1, 2, 3, 4, 5};
	int eList1[] = {1, 2, 5};
	int eList2[] = {2, 1, 5, 3, 4};
	int eList3[] = {3, 2, 4};
	int eList4[] = {4, 2, 5, 3};
	int eList5[] = {5, 4, 1, 2};
	
	ret = InitVetex(sizeof(vArr)/sizeof(int), vArr);

	GraphInList* g = new GraphInList;
	g->listAmn = 0;
	g->listArr = NULL;
	ret = InsertAdj(g, sizeof(eList1)/sizeof(int), eList1);
	ret = InsertAdj(g, sizeof(eList2)/sizeof(int), eList2);
	ret = InsertAdj(g, sizeof(eList3)/sizeof(int), eList3);
	ret = InsertAdj(g, sizeof(eList4)/sizeof(int), eList4);
	ret = InsertAdj(g, sizeof(eList5)/sizeof(int), eList5);

#ifdef DFS_ALG
	ret = DFS(g);
#else
	ret = BFS(g);
#endif

	getchar();
	return ret;
}