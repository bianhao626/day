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
void SLInsert(SL* ps, int pos, SLDataType x);//�����±�λ�ò���
void SLErase(SL* ps, int pos);//�����±�λ��ɾ��
void SLFind(SL* ps, SLDataType x);//˳�����Ҳ������ҵ��˷����±꣬û�ҵ��ͷ���-1


void SLPrint(SL* ps);
void SLCheckCapacity(SL* ps);