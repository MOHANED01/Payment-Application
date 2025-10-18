/*
 * card.c
 *
 *  Created on: Oct 11, 2022
 *      Author: mohaned
 */

#include"card.h"
#include<stdio.h>
#include<stdlib.h>
EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
	uint8_t i=0,size_of_name=0;
printf("please enter your name (more than 20 and less than 24 character)\n");
fgets(cardData->cardHolderName,200,stdin); // 200 to read all data entered by user in case of invalid input
while(cardData->cardHolderName[i]!='\0')
{
	size_of_name=i;
	i++;
}
if(size_of_name==0||size_of_name<20||size_of_name>24)
{
	return WRONG_NAME;
}
else
{
	return CARD_OK;
}

}
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
	uint8_t i=0,size_of_date=0;
	printf("please enter the card expiry date\n");

	fgets(cardData->cardExpirationDate,20,stdin); //20 to read all data entered by user in case of invalid input

	while(cardData->cardExpirationDate[i]!='\0')
	{

		size_of_date=i;
		i++;
	}
	if(size_of_date!=5)
	{
		return WRONG_EXP_DATE;
	}
	else
	{
		return CARD_OK;
	}


}
EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
	uint8_t i=0,size_of_PAN=0;
	printf("please enter your card primary account number(more then 16 and less than 19 digit) \n");
	gets(cardData->primaryAccountNumber);
	while(cardData->primaryAccountNumber[i]!='\0')
	{

		size_of_PAN=i;
		i++;
	}
	if(size_of_PAN<16||size_of_PAN>19)
	{
		return WRONG_PAN;
	}
	else
	{
		return CARD_OK;
	}




}

