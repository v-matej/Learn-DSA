#include <stdio.h>
#include <stdlib.h>

typedef struct _Element {
	int prioritet;
	void* data;
} Element;

typedef struct {
	int n;
	Element* queue_arr;
} Queue;


Queue create_queue(int n)
{
	Queue q;
	q.n = 0;
	q.queue_arr = (Element*)malloc(n * sizeof(Element));
	int i=0;
	for (i=0; i < n ;i++)
	{
		q.queue_arr[i].prioritet = 100;
	}
	return q;
}

void delete_queue(Queue* q)
{
	q->n = 0;
	free(q->queue_arr);
}

void sort_queue_top(Queue* q,int c)
{
	if (c == 0)
		return;

	int  r;
	Element temp;
	r = (c - 1) / 2;

	if (q->queue_arr[c].prioritet > q->queue_arr[r].prioritet)
	{
		temp.data = q->queue_arr[r].data;
		temp.prioritet = q->queue_arr[r].prioritet;
		q->queue_arr[r].data = q->queue_arr[c].data;
		q->queue_arr[r].prioritet = q->queue_arr[c].prioritet;
		q->queue_arr[c].data = temp.data;
		q->queue_arr[c].prioritet = temp.prioritet;
		sort_queue_top(q, r);
	}
}

void queue_add(Queue* q,Element n)
{
	q->n++;
	q->queue_arr[q->n - 1].data = n.data;
	q->queue_arr[q->n - 1].prioritet = n.prioritet;
	sort_queue_top(q, q->n - 1);
}

void sort_queue_bottom(Queue* q,int r)
{
	
	int c_l = 2 * r + 1;
	int c_r = 2 * r + 2;
	Element temp;
	if (c_l>q->n-1)
		return;
	if (c_r > q->n - 1)
	{
		if (q->queue_arr[r].prioritet < q->queue_arr[c_l].prioritet)
		{
			temp = q->queue_arr[r];
			q->queue_arr[r] = q->queue_arr[c_l];
			q->queue_arr[c_l] = temp;
			sort_queue_bottom(q, c_l);
			return;
		}
	}

	if (q->queue_arr[r].prioritet < q->queue_arr[c_l].prioritet || q->queue_arr[r].prioritet < q->queue_arr[c_r].prioritet)
	{
		if (q->queue_arr[c_l].prioritet > q->queue_arr[c_r].prioritet)
		{
			temp = q->queue_arr[r];
			q->queue_arr[r] = q->queue_arr[c_l];
			q->queue_arr[c_l] = temp;
			sort_queue_bottom(q, c_l);
		}
		if (q->queue_arr[c_l].prioritet < q->queue_arr[c_r].prioritet)
		{
			temp = q->queue_arr[r];
			q->queue_arr[r] = q->queue_arr[c_r];
			q->queue_arr[c_r] = temp;
			sort_queue_bottom(q, c_r);
		}

	}
	/*
	else if (q->queue_arr[r].prioritet < q->queue_arr[c_l].prioritet && q->queue_arr[r].prioritet > q->queue_arr[c_r].prioritet)
	{
		temp = q->queue_arr[r];
		q->queue_arr[r] = q->queue_arr[c_l];
		q->queue_arr[c_l] = temp;
		sort_queue_bottom(q, c_l);
	}
	else if (q->queue_arr[r].prioritet > q->queue_arr[c_l].prioritet && q->queue_arr[r].prioritet < q->queue_arr[c_r].prioritet)
	{
		temp = q->queue_arr[r];
		q->queue_arr[r] = q->queue_arr[c_r];
		q->queue_arr[c_r] = temp;
		sort_queue_bottom(q, c_r);
	}
	*/
}


void remove_from_top(Queue* q)
{
	q->queue_arr[0] = q->queue_arr[q->n - 1];
	q->n--;
	sort_queue_bottom(q, 0);
}

int main()
{
	Queue q;
	q=create_queue(10);
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		Element temp;
		temp.prioritet = i;
		queue_add(&q, temp);
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", q.queue_arr[i].prioritet);
	}

	remove_from_top(&q);
	printf("\n");
	for (i = 0; i < 9; i++)
	{
		printf("%d\n", q.queue_arr[i].prioritet);
	}
	delete_queue(&q);
	return 0;
}