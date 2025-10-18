/*
 * terminal.c
 *
 *  Created on: Oct 11, 2022
 *      Author: mohaned
 */

#include"terminal.h"
#include<stdio.h>
#include<stdlib.h>

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
	uint8_t i=0,size_of_date;
		printf("please enter date of the day \n");

		fgets(termData->transactionDate,20,stdin); //20 to read all data entered by user in case of invalid input

		while(termData->transactionDate[i]!='\0')
		{

			size_of_date=i;
			i++;
		}
		if(size_of_date!=10)
		{
			return WRONG_DATE;
		}
		else
		{
			return TERMINAL_OK;
		}
}
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	//let expiration date is 05/25 and transaction date is 25/06/2022
	 if(cardData.cardExpirationDate[3]<termData.transactionDate[8])//compare 05/(2)5 with 25/06/20(2)2
	 {
		 return EXPIRED_CARD;
	 }
	 else  if(cardData.cardExpirationDate[4]<termData.transactionDate[9]) // compare 05/2(5) with 25/06/202(2)
 {
	 return EXPIRED_CARD;
 }
if(cardData.cardExpirationDate[3]==termData.transactionDate[8]&&cardData.cardExpirationDate[4]==termData.transactionDate[9])
	/*in case of card expire in the same year of transaction day*/
{
 if(cardData.cardExpirationDate[1]<termData.transactionDate[4])// compare 0(5)/25 with 25/0(6)/2022
  {
	 return EXPIRED_CARD;
  }

 else if(cardData.cardExpirationDate[1]<termData.transactionDate[4])//compare (0)5/25 with 25/(0)6/2022
  {
	 return EXPIRED_CARD;
  }
}
 else
 {
	 return TERMINAL_OK;
 }

}
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
	printf("please enter the transaction amount\n");
	scanf("%f",&termData->transAmount);
	if((termData->transAmount)<=0)
	{
		return INVALID_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
	if((termData->transAmount)>(termData->maxTransAmount))
	{
		return EXCEED_MAX_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}
}
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
	printf("please enter your terminal max amount\n");
	scanf("%f",&termData->maxTransAmount);
	if((termData->maxTransAmount)<=0)
	{
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}

}

