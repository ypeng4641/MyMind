#include <stdio.h>
#include <queue>

struct Node
{
	int uid;
	Status s;
	int d;
	Node* parent;
	
	Node* nxt;
};

struct Graph
{
	Node* head;
	Graph* nxt;
};

enum Status
{
	NIL = 0,
	WHITE = 1,
	GRAY = 2,
	BLACK = 3,
};


TreeGraph BFS(const Graph* g)
{
std::queue<Node*> searchQue;

Graph* ng = g;
for(; ng != NULL; ng = ng->nxt)
	{
	Node* nn = g->head;
	searchQue.push(nn);
	}

for(; !searchQue.empty(); )
	{
	
	}
}

