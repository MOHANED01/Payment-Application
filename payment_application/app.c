/*
 * app.c
 *
 *  Created on: Oct 11, 2022
 *      Author: mohaned
 */
#include<stdio.h>
#include<stdlib.h>
#include"app.h"
void appStart(void)
{

    uint32_t state=0;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	ST_cardData_t g_carddata;
	ST_terminalData_t g_terminaldata;
	ST_transaction_t g_transactiondata;


   /*********card data******/

	state=getCardHolderName(&g_carddata);
	if(state==WRONG_NAME)
	{
		printf("wrong name\n");
	}
	state=getCardExpiryDate(&g_carddata);
	if(state==WRONG_EXP_DATE)
	{
		printf("wrong date\n");
	}
	state=getCardPAN(&g_carddata);
	if(state==WRONG_PAN)
	{
		printf("wrong pan\n");
	}
	/*****terminal data********/
	state=getTransactionDate(&g_terminaldata);
	if(state==WRONG_DATE)
	{
		printf("wrong date\n");
	}
	state=isCardExpired(g_carddata,g_terminaldata);
	if(state==EXPIRED_CARD)
	{
		printf("expired card\n");
		exit(0); /*if card expired terminate the program*/
	}
	state=getTransactionAmount(&g_terminaldata);
	if(state==INVALID_AMOUNT)
	{
		printf("invalid amount\n");
	}
	state=setMaxAmount(&g_terminaldata);
	if(state==INVALID_MAX_AMOUNT)
	{
		printf("invalid max amount\n");
	}
	state=isBelowMaxAmount(&g_terminaldata);
	if(state==EXCEED_MAX_AMOUNT)
	{
		printf("declined amount exceeding limit\n");
		exit(0); /*if costumer exceeds limits of machine*/
	}
	/*******enter to server data*********/
	else
	{
		g_transactiondata.cardHolderData=g_carddata;
		g_transactiondata.terminalData=g_terminaldata;

		state=recieveTransactionData(&g_transactiondata);
		if(state==FRAUD_CARD)
				{
					printf("declined invalid account\n");
					exit(0);
				}
		else if(state==DECLINED_INSUFFECIENT_FUND)
			{
					printf("declined insuffecient fund\n ");
					exit(0);
				}



	}

}
