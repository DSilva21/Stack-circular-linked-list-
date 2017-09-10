#include <stdio.h>
#include "CLinkedList.h"
#include <stdlib.h>
#include "CLLbaseStack.h"



int main(void)
{
	stack stack;
	stackinit(&stack);

	spush(&stack, 1);
	spush(&stack, 2);
	spush(&stack, 3);
	spush(&stack, 4);
	spush(&stack, 5);

	while (!SisEmpty(&stack))
		printf("%d ", spop(&stack));
	getch();
	return 0;
}

