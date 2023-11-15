#pragma once
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	//��¼��Ч����
	int capacity;
	//�ռ�����--������ݾ���������������һ��ѡ����ԭ���Ķ���
}SL;

void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPushBack(SL* ps, SLDataType x);//˳����β��
void SLPushFront(SL* ps, SLDataType x);//˳����ͷ��
void SLPopBack(SL* ps);//˳����βɾ
void SLPopFront(SL* ps);//˳����ͷɾ

void SLPrint(SL* ps);