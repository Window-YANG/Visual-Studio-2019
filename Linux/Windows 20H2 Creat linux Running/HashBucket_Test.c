#include "HashBucket.h"

typedef struct
{
	int ex;
}aaa;
typedef struct
{
	uint8_t x;
	uint8_t y;
	uint8_t z;
	aaa* yyy;
}example;

void TestHashTable()
{
	HTB ht;
	MiniAction miniaction1, miniaction2, miniaction3, miniaction4,
		* miniaction_pointer1, * miniaction_pointer2, * miniaction_pointer3, * miniaction_pointer4;
	Movement Testcommands;
	//example d,*p=&d,**pp=&p,***ppp=&pp;
	//d.x = 10;
	//aaa fuck;
	//d.yyy = &fuck;
	//d.yyy->ex = 10;
	//printf("%d\n",d.x);
	//aaa* pointer = (aaa*)malloc(sizeof(aaa) * 10);
	//ppp = (example***)malloc(sizeof(example**) * 10);
	//ppp[0] = (example**)malloc(sizeof(example*) * 10);
	//ppp[0][0] = (example*)malloc(sizeof(example) * 10); 
	//ppp[0][0]->yyy = pointer;
	//ppp[0][0][0].yyy = 10;

	//ppp[0][0][0].x = 1000;
	//printf("%d %d\n", d.yyy->ex,ppp[0][0][0].yyy);
	//d.x = 100;


	//printf("%p\n",&Testcommands);
	uint8_t move1[] = { 100,1,12,13,14,83 };
	uint8_t move2[] = { 101,1,12,13,14,83 };
	uint8_t move3[] = { 101,1,12,13,14,83 };
	uint8_t move4[] = { 103,1,12,13,14,83 };
	uint8_t move5[] = { 77,1,12,13,14,83 };
	uint8_t move6[] = { 99,1,12,13,14,83 };


	miniaction_pointer1 = &miniaction1, miniaction_pointer2 = &miniaction2, miniaction_pointer3 = &miniaction3, miniaction_pointer4 = &miniaction4;
	miniaction1.Sendpool[0] = move1;
	miniaction1.Sendpool[1] = move2;
	miniaction1.Sendpool[2] = move3;
	miniaction1.Sendpool[3] = move4;
	miniaction1.Sendpool[4] = move5;
	miniaction1.Sendpool[5] = move6;

	miniaction2.Sendpool[0] = move1;
	miniaction2.Sendpool[1] = move2;
	miniaction2.Sendpool[2] = move3;
	miniaction2.Sendpool[3] = move4;
	miniaction2.Sendpool[4] = move5;
	miniaction3.Sendpool[5] = move6;

	miniaction3.Sendpool[0] = move1;
	miniaction3.Sendpool[1] = move2;
	miniaction3.Sendpool[2] = move3;
	miniaction3.Sendpool[3] = move4;
	miniaction3.Sendpool[4] = move5;
	miniaction3.Sendpool[5] = move6;

	miniaction4.Sendpool[0] = move1;
	miniaction4.Sendpool[1] = move2;
	miniaction4.Sendpool[2] = move3;
	miniaction4.Sendpool[3] = move4;
	miniaction4.Sendpool[4] = move5;
	miniaction4.Sendpool[5] = move6;
	//miniaction3.EffectiveNumber = sizeof(miniaction)/(sizeof(&miniaction))-1;
	//Testcommands.CrawlTargetPool = miniaction_pointer1;
	//Testcommands.CrawlTarget = &Testcommands.CrawlTargetPool;
	//Testcommands.CrawlTarget[0]->EffectiveNumber = 4;

	//Testcommands.GoToTestCenterPool = miniaction_pointer2;
	//Testcommands.GoToTestCenter = &Testcommands.GoToTestCenterPool;
	//Testcommands.GoToTestCenter[0]->EffectiveNumber = 5;

	////Testcommands.NumberOfCommands = sizeof(miniaction) / (sizeof(&miniaction)) - 1;
	//Testcommands.PutOnFailPlate_And_BackToNextOnePool = miniaction_pointer3;
	//Testcommands.PutOnFailPlate_And_BackToNextOne = &Testcommands.PutOnFailPlate_And_BackToNextOnePool;
	//Testcommands.PutOnFailPlate_And_BackToNextOne[0]->EffectiveNumber = 3;

	//Testcommands.PutOnPassPlate_And_BackToNextOnePool = miniaction_pointer4;
	//Testcommands.PutOnPassPlate_And_BackToNextOne = &Testcommands.PutOnPassPlate_And_BackToNextOnePool;
	//Testcommands.PutOnPassPlate_And_BackToNextOne[0]->EffectiveNumber = 6;
	//Testcommands.NumberOfCommands = 4;

	Testcommands.CrawlTarget = &miniaction_pointer1;
	Testcommands.CrawlTarget[0]->EffectiveNumber = 4;

	Testcommands.GoToTestCenter = &miniaction_pointer2;
	Testcommands.GoToTestCenter[0]->EffectiveNumber = 5;

	////Testcommands.NumberOfCommands = sizeof(miniaction) / (sizeof(&miniaction)) - 1;

	Testcommands.PutOnFailPlate_And_BackToNextOne = &miniaction_pointer3;
	Testcommands.PutOnFailPlate_And_BackToNextOne[0]->EffectiveNumber = 3;

	Testcommands.PutOnPassPlate_And_BackToNextOne = &miniaction_pointer4;
	Testcommands.PutOnPassPlate_And_BackToNextOne[0]->EffectiveNumber = 6;
	Testcommands.NumberOfCommands = 4;

	HashNode* current, * current1;
	HTBInit(&ht, 8);
	HTBInsert(&ht, "One", &Testcommands);
	HTBInsert(&ht, "Two", &Testcommands);
	PrintHTB(&ht);
	current = HTBFind(&ht,"One");
	//current1 = HTBFind(&ht, "Two");
	//current1 = HTBFind(&ht, "Three");
	//printf("%d %d\n",current->_vaule[0][0]->CrawlTarget[0]->Sendpool[1][0], current1->_vaule[0][0]->PutOnFailPlate_And_BackToNextOne[0]->Sendpool[2][3]);

}
int main()
{
	TestHashTable();
	return 0;
}
