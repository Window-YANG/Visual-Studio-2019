#include"HashBucket.h"
//��ʼ��
void HTBInit(HTB* htb, size_t len)
{
	assert(htb);
	//�����������ȡ��ϣ��ĳ���
	int HTB_len = GetPrime(len);
	//Ϊ��ϣ���ٿռ�(ע�����ָ���ʹ��)
	HashNode** table = (HashNode**)malloc(sizeof(HashNode*) * (HTB_len));
	if (table == NULL)
	{
		perror("use malloc of create");
		exit(EXIT_FAILURE);
	}
	htb->_table = table;
	htb->_size = 0;
	htb->_len = HTB_len;
	//����ϣ���е�����ָ���ʼ��Ϊ�գ�������Ұָ�����
	memset(htb->_table, 0, sizeof(HashNode*) * (htb->_len));
}
////���ٹ�ϣ��
//void HTBDestory(HTB* htb)
//{
//	assert(htb);
//	int i = 0;
//	//1.�ͷŹ�ϣ����ÿһ�����ϵĽ��
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
//	//2.�ͷŹ�ϣ��(��̬���ٵ�����)
//	free(htb->_table);
//	htb->_table = NULL;
//	htb->_size = 0;
//	htb->_len = 0;
//}
//��ϣ����,�����ϣ��ַ(�ַ�����ģ��������)
static int HTBFunc(char* key, int len)
{
	int count = 0;
	int i = 0;
	int seed = 31;//31,131(����)
	while (*(key + i) != '\0')
	{
		count += count * seed + *(key + i);
		++i;
	}
	return count % len;
}
//��ϣ����,�����ϣ��ַ(����)
//static int HTBFunc(HTBKeyType key, int len)
//{
//	return key%len;
//}


//������ϣ���
//HashNode* BuyHashNode(HTBKeyType key, Movement* steps, MiniAction** value)
HashNode* BuyHashNode(char* key, Movement* value)
{
	/*ʵ�ַ�����*/
	////Movement*** movement = (Movement***)malloc(sizeof(Movement**) * steps->NumberOfCommands);//������Value�е�һ���ڴ棬���ڴ洢���׶ζ���
	HashNode* node = (HashNode*)malloc(sizeof(HashNode)); //������һ���ڵ�
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
	//	CommandPool = (Movement*)malloc(sizeof(Movement) * 1); //����һ��ָ��
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





	/*ʵ�ַ�����*/
	////Movement*** movement = (Movement***)malloc(sizeof(Movement**) * steps->NumberOfCommands);//������Value�е�һ���ڴ棬���ڴ洢���׶ζ���
	//HashNode* node = (HashNode*)malloc(sizeof(HashNode)); //������һ���ڵ�
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
	//CommandPool = (Movement*)malloc(sizeof(Movement) * 1); //����һ��ָ��
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


	/*ʵ�ַ���һ*/
	Movement*** movement = (Movement***)malloc(sizeof(Movement**) * value->NumberOfCommands);//������Value�е�һ���ڴ棬���ڴ洢���׶ζ���
	if (node != NULL)
	{
		int counter = 0;
		movement[0] = (Movement**)malloc((sizeof(Movement*) * (value->NumberOfCommands)));	//��movement�������������ַ��д������ָ���һ��λ��
		while (movement[0] == NULL);
		movement[0][0] = (Movement*)malloc(sizeof(Movement) * (value->NumberOfCommands));//����movement����ָ�������ַ��ߵ�ֵ����Ϊһ��ָ������׵�ַ
		while (movement[0][0] == NULL);

		movement[0][0]->CrawlTarget = (MiniAction**)malloc(sizeof(MiniAction*) * 1);	//��movement[0][0]����ָ����ߵĳ�Ա(CrawlTarget_pointer)����ַ������ָ��ĵ�ַ
		while (movement[0][0]->CrawlTarget == NULL);
		movement[0][0]->CrawlTarget[0] = (MiniAction*)malloc(sizeof(MiniAction) * 1);	//��movement[0][0]����ָ����ߵĳ�Ա(CrawlTarget_pointer)��ֵ��һ��ָ��ĵ�ַ
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
	//Movement*** movement = (Movement***)malloc(sizeof(Movement**) * steps->NumberOfCommands);//������Value�е�һ���ڴ棬���ڴ洢���׶ζ���
	//if (node != NULL)
	//{
	//	movement[0] = (Movement**)malloc((sizeof(Movement*) * (steps->NumberOfCommands)));	//��movement�������������ַ��д������ָ���һ��λ��
	//	while (movement[0] == NULL);
	//	movement[0][0] = (Movement*)malloc(sizeof(Movement) * (value[0]->NumberofMiniAction));//����movement����ָ�������ַ��ߵ�ֵ����Ϊһ��ָ������׵�ַ
	//	while (movement[0][0] == NULL);

	//	movement[0][0]->CrawlTarget_pointer = (MiniAction**)malloc(sizeof(MiniAction*) * 1);	//��movement[0][0]����ָ����ߵĳ�Ա(CrawlTarget_pointer)����ַ������ָ��ĵ�ַ
	//	while (movement[0][0]->CrawlTarget_pointer == NULL);
	//	movement[0][0]->CrawlTarget_pointer[0] = (MiniAction*)malloc(sizeof(MiniAction) * 1);	//��movement[0][0]����ָ����ߵĳ�Ա(CrawlTarget_pointer)��ֵ��һ��ָ��ĵ�ַ
	//	while (movement[0][0]->CrawlTarget_pointer[0] == NULL);
	//	movement[0][0]->CrawlTarget_pointer[0]->MiniAction1_Pointer = value[0]->MiniAction1_Pointer;//��movement[0][0]->MiniAction1_Pointer��ָ�븳ֵ��ָ������ĵ�ַ
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

////��鸺�������Ƿ�ﵽ1������ﵽ1������Ҫ���ݣ��������Ч�ʻ����
void CheckHTBCapacity(HTB* htb)
{
	assert(htb);
	HTB newhtb;
	//���ݾɵĹ�ϣ�������µĹ�ϣ��
	int newlen = GetPrime(htb->_len);
	HTBInit(&newhtb, newlen);
	//�������Ӵﵽ1����Ҫ����
	if (htb->_size == htb->_len)
	{
		for (int i = 0; i < htb->_len; i++)
		{
			HashNode* cur = htb->_table[i];
			while (cur)
			{
				//��¼��һ������λ��
				HashNode* next = cur->_next;
				int index = HTBFunc(cur->_key, newlen);
				//ͷ�嵽�µĹ�ϣ����
				cur->_next = newhtb._table[index];
				newhtb._table[index] = cur;
				cur = next;
			}
			htb->_table[i] = NULL;
		}
		//�ͷžɱ�
		free(htb->_table);
		htb->_table = newhtb._table;
		htb->_size = newhtb._size;
		htb->_len = newhtb._len;
	}
}

//���ϣ���в���һ��Ԫ��
int HTBInsert(HTB* htb, char* key, Movement* value)
{
	assert(htb);
	int index = HTBFunc(key, htb->_len);
	CheckHTBCapacity(htb);
	HashNode* cur = htb->_table[index];
	HashNode* newnode = BuyHashNode(key, value);
	//printf("%d\n", newnode->_vaule[0]->CrawlTarget[0]->Sendpool[0][0]);
	//ͷ��
	newnode->_next = cur;
	htb->_table[index] = newnode;
	htb->_size++;
	return 1;
}

////ɾ����ϣ���е�һ��Ԫ��
int HTBRemove(HTB* htb, HTBKeyType key)
{
	assert(htb);
	int index = HTBFunc(key, htb->_len);
	HashNode* cur = htb->_table[index];
	HashNode* prev = NULL;//��¼Ҫɾ������ǰһ�����
	while (cur)
	{
		//Ҫɾ���Ľ���ǵ�һ����㣬���⴦��
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
//�ڹ�ϣ���в���һ��Ԫ��
HashNode* HTBFind(HTB* htb, char* key)
{
	assert(htb);
	int index = HTBFunc(key, htb->_len);
	//int index = 1;
	HashNode* cur = htb->_table[index];
	//������ϣ������
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
//��ӡ��ϣ��(�������)
void PrintHTB(HTB* htb)
{
	assert(htb);
	for (int i = 0; i < htb->_len; i++)
	{
		int count = 0;
		//printf("Ͱ[%d]->\n", i);
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
//��ϣ��Ĵ�С
int HTBSize(HTB* htb)
{
	assert(htb);
	return htb->_size == 0 ? 0 : 1;
}
//��ϣ���Ƿ�Ϊ��
int HTBEmpty(HTB* htb)
{
	assert(htb);
	return htb->_size == htb->_len ? 0 : 1;
}