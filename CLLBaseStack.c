#include <stdio.h>
#include "CLinkedList.h"
#include "CLLbaseStack.h"
#include <stdlib.h>

void stackinit(stack*pstack)
{
	pstack->plist = (List*)malloc(sizeof(List));
	ListInit(pstack->plist);
}

int SisEmpty(stack*pstack)
{
	if (LCount(pstack->plist) == 0)
		return TRUE;
	else
		return FALSE;
}
void spush(stack*pstack, Data data)
{
	LInsertFront(pstack->plist, data);
}
Data spop(stack*pstack)
{
	Data data;
	LFirst(pstack->plist, &data);
	LRemove(pstack->plist);
	return data;
}
Data speek(stack*pstack)
{
	Data data;
	LFirst(pstack->plist, &data);
	return data;
}