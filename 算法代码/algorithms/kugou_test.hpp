/*
 * 题目：
 * 两个已按非降序排序的列表，
 * 使用一个函数，递归实现，
 * 将两个列表组合成一个非降序排列的列表，并输出
 */

struct node
{
	int date;
	node* next;
};

node* montageList_1(note* la, node* lb)
{
	if(!la && lb)
	{
		return lb;
	}
	else if(la && !lb)
	{
		return la;
	}
	else if(!la && !lb)
	{
		return NULL;
	}

	node* tmp_a, tmp_b;
	if(la->date <= lb->date)
	{
		tmp_a = la;
		tmp_b = lb;
	}
	else
	{
		tmp_a = lb;
		tmp_b = la;
	}

	for(; tmp_a->next; tmp_a = tmp_a->next)
	{
		if(tmp_a->next->date > tmp_b->date)
		{
			node* next_lb = tmp_a->next;
			tmp_a->next = tmp_b;
			if(! next_lb)
			{
				return tmp_a;
			}
			else
			{
				return montageList(tmp_a, next_lb);
			}
		}
	}
}

node* montageList_2(note* la, note* lb)
{
	node* res = NULL;
	node* tmp_a, tmp_b;
	if(la->date <= lb->date)
	{
		tmp_a = la;
		tmp_b = lb;
	}
	else
	{
		tmp_a = lb;
		tmp_b = la;
	}

	res = tmp_a;
	do
	{
		tmp_a = tmp_a->next;
		if(tmp_a->date > lb->date)
		{
			break;
		}
	}while(tmp_a->next);
	
	if(tmp_a->next)
	{
		tmp_a->next = montageList_2(tmp_a, lb);
	}
	else
	{
		tmp_a->next = lb;
	}

	return res;
}
