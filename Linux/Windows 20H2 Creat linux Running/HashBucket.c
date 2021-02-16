#include"HashBucket.h"
//初始化
void HTBInit(HTB* htb, size_t len)
{
	assert(htb);
	//根据素数表获取哈希表的长度
	int HTB_len = GetPrime(len);
	//为哈希表开辟空间(注意二级指针的使用)
	HashNode** table = (HashNode**)malloc(sizeof(HashNode*) * (HTB_len));
	if (table == NULL)
	{
		perror("use malloc of create");
		exit(EXIT_FAILURE);
	}
	htb->_table = table;
	htb->_size = 0;
	htb->_len = HTB_len;
	//将哈希表中的所有指针初始化为空，否则会对野指针操作
	memset(htb->_table, 0, sizeof(HashNode*) * (htb->_len));
}
////销毁哈希表
//void HTBDestory(HTB* htb)
//{
//	assert(htb);
//	int i = 0;
//	//1.释放哈希表上每一条链上的结点
//	for (; i < htb->_len; i++)
//	{
//		HashNode* cur = htb->_table[i];
//		while (cur)
//		{
//			HashNode* next = cur->_next;
//			free(cur);
//			cur = next;
//		}
//		htb->_table[i] = NULL;
//	}
//	//2.释放哈希表(动态开辟的数组)
//	free(htb->_table);
//	htb->_table = NULL;
//	htb->_size = 0;
//	htb->_len = 0;
//}
//哈希函数,计算哈希地址(字符串，模留余数法)
static int HTBFunc(char* key, int len)
{
	int count = 0;
	int i = 0;
	int seed = 31;//31,131(种子)
	while (*(key + i) != '\0')
	{
		count += count * seed + *(key + i);
		++i;
	}
	return count % len;
}
//哈希函数,计算哈希地址(整数)
//static int HTBFunc(HTBKeyType key, int len)
//{
//	return key%len;
//}


//创建哈希结点
//HashNode* BuyHashNode(HTBKeyType key, Movement* steps, MiniAction** value)
HashNode* BuyHashNode(char* key, Movement* value)
{
	/*实现方法三*/
	////Movement*** movement = (Movement***)malloc(sizeof(Movement**) * steps->NumberOfCommands);//申请了Value中的一段内存，用于存储各阶段动作
	HashNode* node = (HashNode*)malloc(sizeof(HashNode)); //申请了一个节点
	////memset(movement, 0, sizeof(Movement**) * steps->NumberOfCommands);


	//if (node != NULL)
	//{
	//	int counter = 0;
	//	MiniAction ActionPool1, ActionPool2, ActionPool3, ActionPool4,
	//		* Action_pointer1, * Action_pointer2, * Action_pointer3, * Action_pointer4,
	//		** MiniAction1, ** MiniAction2, ** MiniAction3, ** MiniAction4;
	//	Movement* CommandPool;
	//	Action_pointer1 = &ActionPool1, Action_pointer2 = &ActionPool2,
	//		Action_pointer3 = &ActionPool3, Action_pointer4 = &ActionPool4;
	//	MiniAction1 = &Action_pointer1, MiniAction2 = &Action_pointer2, MiniAction3 = &Action_pointer3, MiniAction4 = &Action_pointer4;
	//	CommandPool = (Movement*)malloc(sizeof(Movement) * 1); //申请一个指针
	//	//printf("%p %p\n", &CommandPool, &Action_pointer1);
	//	CommandPool->CrawlTarget = &Action_pointer1;
	//	CommandPool->GoToTestCenter = &Action_pointer2;
	//	CommandPool->PutOnFailPlate_And_BackToNextOne = &Action_pointer3;
	//	CommandPool->PutOnPassPlate_And_BackToNextOne = &Action_pointer4;
	//	CommandPool->NumberOfCommands = value->NumberOfCommands;

	//	for (counter = 0; counter < value->CrawlTarget[0]->EffectiveNumber; counter++)
	//	{

	//		CommandPool->CrawlTarget[0]->Sendpool[counter] = value->CrawlTarget[0]->Sendpool[counter];
	//	}
	//	CommandPool->CrawlTarget[0]->EffectiveNumber = value->CrawlTarget[0]->EffectiveNumber;

	//	for (counter = 0; counter < value->GoToTestCenter[0]->EffectiveNumber; counter++)
	//	{
	//		CommandPool->GoToTestCenter[0]->Sendpool[counter] = value->GoToTestCenter[0]->Sendpool[counter];
	//	}
	//	CommandPool->GoToTestCenter[0]->EffectiveNumber = value->GoToTestCenter[0]->EffectiveNumber;

	//	for (counter = 0; counter < value->PutOnFailPlate_And_BackToNextOne[0]->EffectiveNumber; counter++)
	//	{
	//		CommandPool->PutOnFailPlate_And_BackToNextOne[0]->Sendpool[counter] = value->PutOnFailPlate_And_BackToNextOne[0]->Sendpool[counter];
	//	}
	//	CommandPool->PutOnFailPlate_And_BackToNextOne[0]->EffectiveNumber = value->PutOnFailPlate_And_BackToNextOne[0]->EffectiveNumber;

	//	for (counter = 0; counter < value->PutOnPassPlate_And_BackToNextOne[0]->EffectiveNumber; counter++)
	//	{
	//		CommandPool->PutOnPassPlate_And_BackToNextOne[0]->Sendpool[counter] = value->PutOnPassPlate_And_BackToNextOne[0]->Sendpool[counter];
	//	}
	//	CommandPool->PutOnPassPlate_And_BackToNextOne[0]->EffectiveNumber = value->PutOnPassPlate_And_BackToNextOne[0]->EffectiveNumber;
	//	
	//	node->_key = key;
	//	node->_next = NULL;
	//	node->_vaule = &CommandPool;

	//}
	//return node;





	/*实现方法二*/
	////Movement*** movement = (Movement***)malloc(sizeof(Movement**) * steps->NumberOfCommands);//申请了Value中的一段内存，用于存储各阶段动作
	//HashNode* node = (HashNode*)malloc(sizeof(HashNode)); //申请了一个节点
	////memset(movement, 0, sizeof(Movement**) * steps->NumberOfCommands);
	//
	//
	//if (node != NULL)
	//{
	//int counter = 0;
	//MiniAction ActionPool, ActionPool1, ActionPool2, ActionPool3, ActionPool4,
	//	* Action_pointer1, * Action_pointer2, * Action_pointer3, * Action_pointer4,
	//		** MiniAction1, ** MiniAction2, ** MiniAction3, ** MiniAction4;
	//Movement* CommandPool;
	//Action_pointer1 = &ActionPool1, Action_pointer2 = &ActionPool2,
	//	Action_pointer3 = &ActionPool3, Action_pointer4 = &ActionPool4;
	//MiniAction1 = &Action_pointer1, MiniAction2 = &Action_pointer2, MiniAction3 = &Action_pointer3, MiniAction4 = &Action_pointer4;
	//CommandPool = (Movement*)malloc(sizeof(Movement) * 1); //申请一个指针
	//printf("%p %p\n", &CommandPool, &Action_pointer1);
	//CommandPool->CrawlTarget = &Action_pointer1;
	//CommandPool->GoToTestCenter = &Action_pointer2;
	//CommandPool->PutOnFailPlate_And_BackToNextOne = &Action_pointer3;
	//CommandPool->PutOnPassPlate_And_BackToNextOne = &Action_pointer4;

	//CommandPool->NumberOfCommands = 4;

	//	for (counter = 0; counter < value->CrawlTarget[0]->EffectiveNumber; counter++)
	//	{
	//		
	//		CommandPool->CrawlTarget[0]->Sendpool[counter] = value->CrawlTarget[0]->Sendpool[counter];
	//	}
	//	CommandPool->CrawlTarget[0]->EffectiveNumber = value->CrawlTarget[0]->EffectiveNumber;
	//	for (counter = 0; counter < value->GoToTestCenter[0]->EffectiveNumber; counter++)
	//	{
	//		CommandPool->GoToTestCenter[0]->Sendpool[counter] = value->GoToTestCenter[0]->Sendpool[counter];
	//	}
	//	CommandPool->GoToTestCenter[0]->EffectiveNumber = value->GoToTestCenter[0]->EffectiveNumber;
	//	for (counter = 0; counter < value->PutOnFailPlate_And_BackToNextOne[0]->EffectiveNumber; counter++)
	//	{
	//		CommandPool->PutOnFailPlate_And_BackToNextOne[0]->Sendpool[counter] = value->PutOnFailPlate_And_BackToNextOne[0]->Sendpool[counter];
	//	}
	//	CommandPool->PutOnFailPlate_And_BackToNextOne[0]->EffectiveNumber = value->PutOnFailPlate_And_BackToNextOne[0]->EffectiveNumber;
	//	for (counter = 0; counter < value->PutOnPassPlate_And_BackToNextOne[0]->EffectiveNumber; counter++)
	//	{
	//		CommandPool->PutOnPassPlate_And_BackToNextOne[0]->Sendpool[counter] = value->PutOnPassPlate_And_BackToNextOne[0]->Sendpool[counter];
	//	}
	//	CommandPool->PutOnPassPlate_And_BackToNextOne[0]->EffectiveNumber = value->PutOnPassPlate_And_BackToNextOne[0]->EffectiveNumber;
	//	node->_key = key;
	//	node->_next = NULL;
	//	node->_vaule = &CommandPool;
	//	
	//}
	//return node;


	/*实现方法一*/
	Movement*** movement = (Movement***)malloc(sizeof(Movement**) * value->NumberOfCommands);//申请了Value中的一段内存，用于存储各阶段动作
	if (node != NULL)
	{
		int counter = 0;
		movement[0] = (Movement**)malloc((sizeof(Movement*) * (value->NumberOfCommands)));	//对movement二级变量申请地址，写入三级指针第一个位置
		while (movement[0] == NULL);
		movement[0][0] = (Movement*)malloc(sizeof(Movement) * (value->NumberOfCommands));//访问movement二级指针变量地址里边的值：改为一级指针组的首地址
		while (movement[0][0] == NULL);

		movement[0][0]->CrawlTarget = (MiniAction**)malloc(sizeof(MiniAction*) * 1);	//对movement[0][0]二级指针里边的成员(CrawlTarget_pointer)赋地址：二级指针的地址
		while (movement[0][0]->CrawlTarget == NULL);
		movement[0][0]->CrawlTarget[0] = (MiniAction*)malloc(sizeof(MiniAction) * 1);	//对movement[0][0]二级指针里边的成员(CrawlTarget_pointer)赋值：一级指针的地址
		while (movement[0][0]->CrawlTarget[0] == NULL);
		for (counter = 0; counter < value->CrawlTarget[0]->EffectiveNumber; counter++)
		{
			movement[0][0]->CrawlTarget[0]->Sendpool[counter] = value->CrawlTarget[0]->Sendpool[counter];
		}
		movement[0][0]->CrawlTarget[0]->EffectiveNumber = value->CrawlTarget[0]->EffectiveNumber;

		movement[0][0]->GoToTestCenter = (MiniAction**)malloc(sizeof(MiniAction*) * 1);
		while (movement[0][0]->GoToTestCenter == NULL);
		movement[0][0]->GoToTestCenter[0] = (MiniAction*)malloc(sizeof(MiniAction) * 1);
		while (movement[0][0]->GoToTestCenter[0] == NULL);
		for (counter = 0; counter < value->GoToTestCenter[0]->EffectiveNumber; counter++)
		{
			movement[0][0]->GoToTestCenter[0]->Sendpool[counter] = value->GoToTestCenter[0]->Sendpool[counter];
		}
		movement[0][0]->GoToTestCenter[0]->EffectiveNumber = value->GoToTestCenter[0]->EffectiveNumber;

		movement[0][0]->PutOnFailPlate_And_BackToNextOne = (MiniAction**)malloc(sizeof(MiniAction*) * 1);
		while (movement[0][0]->PutOnFailPlate_And_BackToNextOne == NULL);
		movement[0][0]->PutOnFailPlate_And_BackToNextOne[0] = (MiniAction*)malloc(sizeof(MiniAction) * 1);
		while (movement[0][0]->PutOnFailPlate_And_BackToNextOne[0] == NULL);
		for (counter = 0; counter < value->PutOnFailPlate_And_BackToNextOne[0]->EffectiveNumber; counter++)
		{
			movement[0][0]->PutOnFailPlate_And_BackToNextOne[0]->Sendpool[counter] = value->PutOnFailPlate_And_BackToNextOne[0]->Sendpool[counter];
		}
		movement[0][0]->PutOnFailPlate_And_BackToNextOne[0]->EffectiveNumber = value->PutOnFailPlate_And_BackToNextOne[0]->EffectiveNumber;


		movement[0][0]->PutOnPassPlate_And_BackToNextOne = (MiniAction**)malloc(sizeof(MiniAction*) * 1);
		while (movement[0][0]->PutOnPassPlate_And_BackToNextOne == NULL);
		movement[0][0]->PutOnPassPlate_And_BackToNextOne[0] = (MiniAction*)malloc(sizeof(MiniAction) * 1);
		while (movement[0][0]->PutOnPassPlate_And_BackToNextOne[0] == NULL);
		for (counter = 0; counter < value->PutOnPassPlate_And_BackToNextOne[0]->EffectiveNumber; counter++)
		{
			movement[0][0]->PutOnPassPlate_And_BackToNextOne[0]->Sendpool[counter] = value->PutOnPassPlate_And_BackToNextOne[0]->Sendpool[counter];
		}
		movement[0][0]->PutOnPassPlate_And_BackToNextOne[0]->EffectiveNumber = value->PutOnPassPlate_And_BackToNextOne[0]->EffectiveNumber;
		
		movement[0][0]->NumberOfCommands = value->NumberOfCommands;
		node->_key = key;
		node->_vaule = movement;
		node->_next = NULL;
	}
	return node;
	/*******************************************************************/
	//Movement*** movement = (Movement***)malloc(sizeof(Movement**) * steps->NumberOfCommands);//申请了Value中的一段内存，用于存储各阶段动作
	//if (node != NULL)
	//{
	//	movement[0] = (Movement**)malloc((sizeof(Movement*) * (steps->NumberOfCommands)));	//对movement二级变量申请地址，写入三级指针第一个位置
	//	while (movement[0] == NULL);
	//	movement[0][0] = (Movement*)malloc(sizeof(Movement) * (value[0]->NumberofMiniAction));//访问movement二级指针变量地址里边的值：改为一级指针组的首地址
	//	while (movement[0][0] == NULL);

	//	movement[0][0]->CrawlTarget_pointer = (MiniAction**)malloc(sizeof(MiniAction*) * 1);	//对movement[0][0]二级指针里边的成员(CrawlTarget_pointer)赋地址：二级指针的地址
	//	while (movement[0][0]->CrawlTarget_pointer == NULL);
	//	movement[0][0]->CrawlTarget_pointer[0] = (MiniAction*)malloc(sizeof(MiniAction) * 1);	//对movement[0][0]二级指针里边的成员(CrawlTarget_pointer)赋值：一级指针的地址
	//	while (movement[0][0]->CrawlTarget_pointer[0] == NULL);
	//	movement[0][0]->CrawlTarget_pointer[0]->MiniAction1_Pointer = value[0]->MiniAction1_Pointer;//对movement[0][0]->MiniAction1_Pointer该指针赋值，指向变量的地址
	//	movement[0][0]->CrawlTarget_pointer[0]->MiniAction2_Pointer = value[0]->MiniAction2_Pointer;
	//	movement[0][0]->CrawlTarget_pointer[0]->MiniAction3_Pointer = value[0]->MiniAction3_Pointer;
	//	movement[0][0]->CrawlTarget_pointer[0]->MiniAction4_Pointer = value[0]->MiniAction4_Pointer;
	//	movement[0][0]->CrawlTarget_pointer[0]->MiniAction5_Pointer = value[0]->MiniAction5_Pointer;
	//	movement[0][0]->CrawlTarget_pointer[0]->MiniAction6_Pointer = value[0]->MiniAction6_Pointer;
	//	movement[0][0]->CrawlTarget_pointer[0]->NumberofMiniAction = value[0]->NumberofMiniAction;

	//	movement[0][0]->GoToTestCenter_pointer = (MiniAction**)malloc(sizeof(MiniAction*) * 1);
	//	while (movement[0][0]->GoToTestCenter_pointer == NULL);
	//	movement[0][0]->GoToTestCenter_pointer[0] = (MiniAction*)malloc(sizeof(MiniAction) * 1);
	//	while (movement[0][0]->GoToTestCenter_pointer[0] == NULL);
	//	movement[0][0]->GoToTestCenter_pointer[0]->MiniAction1_Pointer = value[0]->MiniAction1_Pointer;
	//	movement[0][0]->GoToTestCenter_pointer[0]->MiniAction2_Pointer = value[0]->MiniAction2_Pointer;
	//	movement[0][0]->GoToTestCenter_pointer[0]->MiniAction3_Pointer = value[0]->MiniAction3_Pointer;
	//	movement[0][0]->GoToTestCenter_pointer[0]->MiniAction4_Pointer = value[0]->MiniAction4_Pointer;
	//	movement[0][0]->GoToTestCenter_pointer[0]->MiniAction5_Pointer = value[0]->MiniAction5_Pointer;
	//	movement[0][0]->GoToTestCenter_pointer[0]->MiniAction6_Pointer = value[0]->MiniAction6_Pointer;
	//	movement[0][0]->GoToTestCenter_pointer[0]->NumberofMiniAction = value[0]->NumberofMiniAction;

	//	movement[0][0]->PutOnFailPlate_And_BackToNextOne_pointer = (MiniAction**)malloc(sizeof(MiniAction*) * 1);
	//	while (movement[0][0]->PutOnFailPlate_And_BackToNextOne_pointer == NULL);
	//	movement[0][0]->PutOnFailPlate_And_BackToNextOne_pointer[0] = (MiniAction*)malloc(sizeof(MiniAction) * 1);
	//	while (movement[0][0]->PutOnFailPlate_And_BackToNextOne_pointer[0] == NULL);
	//	movement[0][0]->PutOnFailPlate_And_BackToNextOne_pointer[0]->MiniAction1_Pointer = value[0]->MiniAction1_Pointer;
	//	movement[0][0]->PutOnFailPlate_And_BackToNextOne_pointer[0]->MiniAction2_Pointer = value[0]->MiniAction2_Pointer;
	//	movement[0][0]->PutOnFailPlate_And_BackToNextOne_pointer[0]->MiniAction3_Pointer = value[0]->MiniAction3_Pointer;
	//	movement[0][0]->PutOnFailPlate_And_BackToNextOne_pointer[0]->MiniAction4_Pointer = value[0]->MiniAction4_Pointer;
	//	movement[0][0]->PutOnFailPlate_And_BackToNextOne_pointer[0]->MiniAction5_Pointer = value[0]->MiniAction5_Pointer;
	//	movement[0][0]->PutOnFailPlate_And_BackToNextOne_pointer[0]->MiniAction6_Pointer = value[0]->MiniAction6_Pointer;
	//	movement[0][0]->PutOnFailPlate_And_BackToNextOne_pointer[0]->NumberofMiniAction = value[0]->NumberofMiniAction;

	//	movement[0][0]->PutOnPassPlate_And_BackToNextOne_pointer = (MiniAction**)malloc(sizeof(MiniAction*) * 1);
	//	while (movement[0][0]->PutOnPassPlate_And_BackToNextOne_pointer == NULL);
	//	movement[0][0]->PutOnPassPlate_And_BackToNextOne_pointer[0] = (MiniAction*)malloc(sizeof(MiniAction) * 1);
	//	while (movement[0][0]->PutOnPassPlate_And_BackToNextOne_pointer[0] == NULL);
	//	movement[0][0]->PutOnPassPlate_And_BackToNextOne_pointer[0]->MiniAction1_Pointer = value[0]->MiniAction1_Pointer;
	//	movement[0][0]->PutOnPassPlate_And_BackToNextOne_pointer[0]->MiniAction2_Pointer = value[0]->MiniAction2_Pointer;
	//	movement[0][0]->PutOnPassPlate_And_BackToNextOne_pointer[0]->MiniAction3_Pointer = value[0]->MiniAction3_Pointer;
	//	movement[0][0]->PutOnPassPlate_And_BackToNextOne_pointer[0]->MiniAction4_Pointer = value[0]->MiniAction4_Pointer;
	//	movement[0][0]->PutOnPassPlate_And_BackToNextOne_pointer[0]->MiniAction5_Pointer = value[0]->MiniAction5_Pointer;
	//	movement[0][0]->PutOnPassPlate_And_BackToNextOne_pointer[0]->MiniAction6_Pointer = value[0]->MiniAction6_Pointer;
	//	movement[0][0]->PutOnPassPlate_And_BackToNextOne_pointer[0]->NumberofMiniAction = value[0]->NumberofMiniAction;

	//	node->_next = NULL;



	//}

}

////检查负载因子是否达到1，如果达到1，则需要扩容，否则查找效率会变慢
void CheckHTBCapacity(HTB* htb)
{
	assert(htb);
	HTB newhtb;
	//根据旧的哈希表长计算新的哈希表长
	int newlen = GetPrime(htb->_len);
	HTBInit(&newhtb, newlen);
	//负载因子达到1，需要扩容
	if (htb->_size == htb->_len)
	{
		for (int i = 0; i < htb->_len; i++)
		{
			HashNode* cur = htb->_table[i];
			while (cur)
			{
				//记录下一个结点的位置
				HashNode* next = cur->_next;
				int index = HTBFunc(cur->_key, newlen);
				//头插到新的哈希表中
				cur->_next = newhtb._table[index];
				newhtb._table[index] = cur;
				cur = next;
			}
			htb->_table[i] = NULL;
		}
		//释放旧表
		free(htb->_table);
		htb->_table = newhtb._table;
		htb->_size = newhtb._size;
		htb->_len = newhtb._len;
	}
}

//向哈希表中插入一个元素
int HTBInsert(HTB* htb, char* key, Movement* value)
{
	assert(htb);
	int index = HTBFunc(key, htb->_len);
	CheckHTBCapacity(htb);
	HashNode* cur = htb->_table[index];
	HashNode* newnode = BuyHashNode(key, value);
	//printf("%d\n", newnode->_vaule[0]->CrawlTarget[0]->Sendpool[0][0]);
	//头插
	newnode->_next = cur;
	htb->_table[index] = newnode;
	htb->_size++;
	return 1;
}

////删除哈希表中的一个元素
int HTBRemove(HTB* htb, HTBKeyType key)
{
	assert(htb);
	int index = HTBFunc(key, htb->_len);
	HashNode* cur = htb->_table[index];
	HashNode* prev = NULL;//记录要删除结点的前一个结点
	while (cur)
	{
		//要删除的结点是第一个结点，特殊处理
		if (prev == NULL)
		{
			htb->_table[index] = cur->_next;
			free(cur);
			cur = NULL;
			htb->_size--;
			return 1;
		}
		if (cur->_key == key)
		{
			prev->_next = cur->_next;
		}
		prev = cur;
		cur = cur->_next;
	}
	return 0;
}
//在哈希表中查找一个元素
HashNode* HTBFind(HTB* htb, char* key)
{
	assert(htb);
	int index = HTBFunc(key, htb->_len);
	//int index = 1;
	HashNode* cur = htb->_table[index];
	//遍历哈希表，查找
	while (cur)
	{
		if (cur->_key == key)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
//打印哈希表(方便测试)
void PrintHTB(HTB* htb)
{
	assert(htb);
	for (int i = 0; i < htb->_len; i++)
	{
		int count = 0;
		//printf("桶[%d]->\n", i);
		HashNode* cur = htb->_table[i];
		while (cur)
		{
			printf("Find effective content:([key:%s]:[value:%p])\n", cur->_key, *(cur->_vaule));
			count++;
			cur = cur->_next;
		}
		//printf("(count=%d)->over\n", count);
	}
}
//哈希表的大小
int HTBSize(HTB* htb)
{
	assert(htb);
	return htb->_size == 0 ? 0 : 1;
}
//哈希表是否为空
int HTBEmpty(HTB* htb)
{
	assert(htb);
	return htb->_size == htb->_len ? 0 : 1;
}