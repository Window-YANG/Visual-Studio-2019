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
	MiniAction** CrawlTarget;//抓取目标
	MiniAction** GoToTestCenter;//前往测试中心
	MiniAction** PutOnPassPlate_And_BackToNextOne;//放到通过盘然后回到下一颗芯片上
	MiniAction** PutOnFailPlate_And_BackToNextOne;//放到失败盘然后回到下一颗芯片上
	int NumberOfCommands;
}Movement;

//typedef struct
//{
//	MiniAction* CrawlTargetPool;
//	MiniAction* GoToTestCenterPool;
//	MiniAction* PutOnPassPlate_And_BackToNextOnePool;
//	MiniAction* PutOnFailPlate_And_BackToNextOnePool;
//	MiniAction** CrawlTarget;//抓取目标
//	MiniAction** GoToTestCenter;//前往测试中心
//	MiniAction** PutOnPassPlate_And_BackToNextOne;//放到通过盘然后回到下一颗芯片上
//	MiniAction** PutOnFailPlate_And_BackToNextOne;//放到失败盘然后回到下一颗芯片上
//	size_t NumberOfCommands;
//}Movement;

typedef struct PerformActions
{
	Movement CrawlTarget;
	Movement GoToTestCenter;
	Movement PutOnPassPlate_And_BackToNextOne;
	Movement PutOnFailPlate_And_BackToNextOne;
}PerformActions;





//哈希表中结点的类型(拉链法)
//typedef struct HashNode
//{
//	struct HashNode* _next;
//	HTBKeyType _key;
//	HTBValueType _vaule;//key-value模型
//}HashNode;

typedef struct HashNode
{
	struct HashNode* _next;
	char* _key;
	Movement*** _vaule;//key-value模型
}HashNode;

//typedef struct
//{
//	struct HashNode* _next;
//	char* _key;
//	Movement** _vaule;//key-value模型
//}HashNode;

//哈希表的类型
typedef struct HashTableBucket
{
	HashNode** _table;//动态数组，里边存放的是指向结点的指针
	int _len;//哈希表长度
	int _size;//有效元素的个数
}HTB;

//初始化
void HTBInit(HTB* htb, size_t len);
//销毁哈希表
void HTBDestory(HTB* htb);
//向哈希表中插入一个元素
int HTBInsert(HTB* htb, char* key, Movement* value);
//删除哈希表中的一个元素
int HTBRemove(HTB* htb, char* key);
//在哈希表中查找一个元素
HashNode* HTBFind(HTB* htb, char* key);
//哈希表的大小
int HTBSize(HTB* htb);
//哈希表是否为空
int HTBEmpty(HTB* htb);
void PrintHTB(HTB* htb);
//HashNode* BuyHashNode(HTBKeyType key, Movement* steps, MiniAction** value);
HashNode* BuyHashNode(char* key, Movement* value);
//__HASHTABLEBUCKET_H__
#endif
