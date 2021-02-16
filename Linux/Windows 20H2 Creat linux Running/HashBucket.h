#ifndef __HASHTABLEBUCKET_H__
#define __HASHTABLEBUCKET_H__

#include "HashBucket_Commet.h"

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<assert.h>

typedef char* HTBKeyType;
typedef char* HTBValueType;

typedef struct
{

	int EffectiveNumber;
	uint8_t* Sendpool[6];

}MiniAction;

typedef struct Movement
{
	MiniAction** CrawlTarget;//ץȡĿ��
	MiniAction** GoToTestCenter;//ǰ����������
	MiniAction** PutOnPassPlate_And_BackToNextOne;//�ŵ�ͨ����Ȼ��ص���һ��оƬ��
	MiniAction** PutOnFailPlate_And_BackToNextOne;//�ŵ�ʧ����Ȼ��ص���һ��оƬ��
	int NumberOfCommands;
}Movement;

//typedef struct
//{
//	MiniAction* CrawlTargetPool;
//	MiniAction* GoToTestCenterPool;
//	MiniAction* PutOnPassPlate_And_BackToNextOnePool;
//	MiniAction* PutOnFailPlate_And_BackToNextOnePool;
//	MiniAction** CrawlTarget;//ץȡĿ��
//	MiniAction** GoToTestCenter;//ǰ����������
//	MiniAction** PutOnPassPlate_And_BackToNextOne;//�ŵ�ͨ����Ȼ��ص���һ��оƬ��
//	MiniAction** PutOnFailPlate_And_BackToNextOne;//�ŵ�ʧ����Ȼ��ص���һ��оƬ��
//	size_t NumberOfCommands;
//}Movement;

typedef struct PerformActions
{
	Movement CrawlTarget;
	Movement GoToTestCenter;
	Movement PutOnPassPlate_And_BackToNextOne;
	Movement PutOnFailPlate_And_BackToNextOne;
}PerformActions;





//��ϣ���н�������(������)
//typedef struct HashNode
//{
//	struct HashNode* _next;
//	HTBKeyType _key;
//	HTBValueType _vaule;//key-valueģ��
//}HashNode;

typedef struct HashNode
{
	struct HashNode* _next;
	char* _key;
	Movement*** _vaule;//key-valueģ��
}HashNode;

//typedef struct
//{
//	struct HashNode* _next;
//	char* _key;
//	Movement** _vaule;//key-valueģ��
//}HashNode;

//��ϣ�������
typedef struct HashTableBucket
{
	HashNode** _table;//��̬���飬��ߴ�ŵ���ָ�����ָ��
	int _len;//��ϣ����
	int _size;//��ЧԪ�صĸ���
}HTB;

//��ʼ��
void HTBInit(HTB* htb, size_t len);
//���ٹ�ϣ��
void HTBDestory(HTB* htb);
//���ϣ���в���һ��Ԫ��
int HTBInsert(HTB* htb, char* key, Movement* value);
//ɾ����ϣ���е�һ��Ԫ��
int HTBRemove(HTB* htb, char* key);
//�ڹ�ϣ���в���һ��Ԫ��
HashNode* HTBFind(HTB* htb, char* key);
//��ϣ��Ĵ�С
int HTBSize(HTB* htb);
//��ϣ���Ƿ�Ϊ��
int HTBEmpty(HTB* htb);
void PrintHTB(HTB* htb);
//HashNode* BuyHashNode(HTBKeyType key, Movement* steps, MiniAction** value);
HashNode* BuyHashNode(char* key, Movement* value);
//__HASHTABLEBUCKET_H__
#endif
