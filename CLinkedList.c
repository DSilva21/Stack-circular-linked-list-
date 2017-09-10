#include <stdio.h>
#include "CLinkedList.h"
#include <stdlib.h>

void ListInit(List *plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsert(List *plist, Data data)  //��带 ������ �߰�
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) //ù��° �����.
	{
		plist->tail = newNode;  // tail�� �� ��带 ����Ű�� �Ѵ�.
		newNode->next = newNode; //�� ��� �ڽ��� ����Ű�� �Ѵ�.
	}
	else
	{

		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	(plist->numOfData)++;
}

void LInsertFront(List *plist, Data data)  //��带 �Ӹ��� �߰�
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) //ù��° �����.
	{
		plist->tail = newNode;  // tail�� �� ��带 ����Ű�� �Ѵ�.
		newNode->next = newNode; //�� ��� �ڽ��� ����Ű�� �Ѵ�.
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;

	}

	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
	if (plist->tail == NULL) //����� ��尡 ���ٸ�
		return FALSE;
	
	plist->before = plist->tail; //before�� ������ ����Ű�� �Ѵ�.
	plist->cur = plist->tail->next; //cur�� �Ӹ��� ����Ű�� �Ѵ�.
	*pdata = plist->cur->data; //cur�� ����Ű�� ����� ������ ��ȯ
	return TRUE;
}

int LNext(List *plist, Data *pdata)
{
	if (plist->tail == NULL)//����� ��尡 ���ٸ�
		return FALSE;

	plist->before = plist->cur; //before�� ���� ��带 ����Ű�� �Ѵ�.
	plist->cur = plist->cur->next; //cur�� ���� ��带 ����Ű�� �Ѵ�.
	*pdata = plist->cur->data; //cur�� ����Ű�� ����� ������ ��ȯ
	return TRUE;
}

Data LRemove(List *plist)
{
	Node *rpos = plist->cur;
	Data rdata = rpos->data;
	
	if (rpos == plist->tail) //���� ����� tail�� ����Ų�ٸ�
	{
		if (plist->tail == plist->tail->next) //�׸��� ������ ���� �����
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List*plist)
{
	return plist->numOfData;
}
