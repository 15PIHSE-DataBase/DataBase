<<<<<<< HEAD
#include "stdafx.h"
//Âûâîä íà ýêðàí âñåõ çíà÷åíèé óçëà ñ èõ ñïåöèôèêàòîðàìè è òèïîâ ýòèõ çíà÷åíèé.
//Ôóíêöèÿ âîçâðàçàåò êîëè÷åñòâî çíà÷åíèé òðåáóåìîãî òèïà â óêàçàííîì óçëå
//VALUE * head - óêàçàòåëü íà óçåë
//TYPE Type - òèï çíà÷åíèé, êîòîðûå íóîáõîäèìî âûâåñòè (ALL, INT, FLOAT, DOUBLE, CHAR)
int PrintValues(NODE *head, TYPE Type) //Âûâîä íà ýêðàí âñåõ çíà÷åíèé óçëà è èõ òèïîâ
{
	if (head->Values == NULL) {
=======
ï»¿#include "stdafx.h"
//Ð’Ñ‹Ð²Ð¾Ð´ Ð½Ð° ÑÐºÑ€Ð°Ð½ Ð²ÑÐµÑ… Ð·Ð½Ð°Ñ‡ÐµÐ½Ð¸Ð¹ ÑƒÐ·Ð»Ð° Ñ Ð¸Ñ… ÑÐ¿ÐµÑ†Ð¸Ñ„Ð¸ÐºÐ°Ñ‚Ð¾Ñ€Ð°Ð¼Ð¸ Ð¸ Ñ‚Ð¸Ð¿Ð¾Ð² ÑÑ‚Ð¸Ñ… Ð·Ð½Ð°Ñ‡ÐµÐ½Ð¸Ð¹.
//Ð¤ÑƒÐ½ÐºÑ†Ð¸Ñ Ð²Ð¾Ð·Ð²Ñ€Ð°Ð·Ð°ÐµÑ‚ ÐºÐ¾Ð»Ð¸Ñ‡ÐµÑÑ‚Ð²Ð¾ Ð·Ð½Ð°Ñ‡ÐµÐ½Ð¸Ð¹ Ñ‚Ñ€ÐµÐ±ÑƒÐµÐ¼Ð¾Ð³Ð¾ Ñ‚Ð¸Ð¿Ð° Ð² ÑƒÐºÐ°Ð·Ð°Ð½Ð½Ð¾Ð¼ ÑƒÐ·Ð»Ðµ
//VALUE *head - ÑƒÐºÐ°Ð·Ð°Ñ‚ÐµÐ»ÑŒ Ð½Ð° Ð¿ÐµÑ€Ð²Ð¾Ðµ Ð¿Ñ€Ð¸ÐºÑ€ÐµÐ¿Ð»Ñ‘Ð½Ð½Ð¾Ðµ Ðº ÑƒÐ·Ð»Ñƒ Ð·Ð½Ð°Ñ‡ÐµÐ½Ð¸Ðµ
//TYPE Type - Ñ‚Ð¸Ð¿ Ð·Ð½Ð°Ñ‡ÐµÐ½Ð¸Ð¹, ÐºÐ¾Ñ‚Ð¾Ñ€Ñ‹Ðµ Ð½ÑƒÐ¾Ð±Ñ…Ð¾Ð´Ð¸Ð¼Ð¾ Ð²Ñ‹Ð²ÐµÑÑ‚Ð¸ (ALL, INT, FLOAT, DOUBLE, CHAR)
int PrintValues(VALUE *head, TYPE Type) 
{
	if (head == NULL) { //Ð’ ÑƒÐ·Ð»Ðµ Ð½ÐµÑ‚ Ð·Ð½Ð°Ñ‡ÐµÐ½Ð¸Ð¹
>>>>>>> refs/remotes/origin/master
		printf("Empty\n");
		return 0;
	}
	VALUE *temp = head->Values;
	int Count = 0;
	while (temp != NULL){		
		if ((temp->type == Type)||(Type==ALL)){
			printf("%s: %s ", temp->Qualifier, temp->Value);
			switch (temp->type){
			case INT:printf("(int)  "); break;
			case FLOAT:printf("(float)  "); break;
			case DOUBLE:printf("(double)  "); break;
			case CHAR:printf("(char)  "); break;
			}
			Count++;
		}
		temp = temp->NextValue;
	}
	if (Count) printf("\n");
	else printf("No required type values\n");
	return Count;
}