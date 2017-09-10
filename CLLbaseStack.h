#pragma once
#ifndef __CLL_STACK_H__
#define __CLL_STACK_H__

#include "CLinkedList.h"

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _listStack
{
	List *plist;
}ListStack;

typedef ListStack stack;

void stackinit(stack*pstack);
int SisEmpty(stack*pstack);
void spush(stack*pstack, Data data);
Data spop(stack*pstack);
Data speek(stack*pstack);

#endif
