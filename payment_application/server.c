/*
 * server.c
 *
 *  Created on: Oct 11, 2022
 *      Author: mohaned
 */

#include"server.h"
#include<stdio.h>
#include<string.h>
#include"std_types.h"
#include"stdio.h"



static ST_accountsDB_t database_accounts[255]={{20000,"111111111111111110",RUNNING},{30000,"111111111111111111",RUNNING},\
		{40000,"111111111111111112",RUNNING},{50000,"111111111111111113",RUNNING}\
		,{60000,"111111111111111114",BLOCKED}};
/* fill first 5 elements in array with PAN consists of 18 digits
 PAN differs from each others by last digit only 0 or 1 or 2 or 3 or 4 */
static ST_transaction_t database_transactions[255]={0};




EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
	ST_accountsDB_t account;
	if(isValidAccount(&transData->cardHolderData,&account)==ACCOUNT_NOT_FOUND)
	{
		return FRAUD_CARD;
	}
	if(isAmountAvailable(&transData->terminalData,&account)==LOW_BALANCE)
	{
		return DECLINED_INSUFFECIENT_FUND;
	}
	if(isBlockedAccount(&account)==BLOCKED_ACCOUNT)
	{
		return DECLINED_STOLEN_CARD;
	}
	if(saveTransaction(transData)==SAVING_FAILED)
	{
		return INTERNAL_SERVER_ERROR;
	}
	else
	{
		return APPROVED;
		account.balance=((account.balance)-(transData->terminalData.transAmount));
	}



}


EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence)
{
	uint8_t i,state=ACCOUNT_NOT_FOUND;

	for(i=0;i<5;i++)
	{

		if(strcmp((const char*)cardData->primaryAccountNumber,(const char*)database_accounts[i].primaryAccountNumber)==0)
		{
			*accountRefrence=database_accounts[i];
			state=SERVER_OK;
		}
	}
	return state;
}
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence)
{
	if(accountRefrence->state==BLOCKED)
	{
		return BLOCKED_ACCOUNT;
	}
	else
	{
		return SERVER_OK;
	}
}



EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence)
{
	if((accountRefrence->balance)<(termData->transAmount))
	{
		return  LOW_BALANCE;
	}
	else
	{
		return SERVER_OK;
	}
}
EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
	static uint8_t iteration=0;
	EN_serverError_t state;
	if(database_transactions[iteration].transactionSequenceNumber<255)
	{
	database_transactions[iteration].cardHolderData=transData->cardHolderData;
	database_transactions[iteration].terminalData=transData->terminalData;
	database_transactions[iteration].transState=transData->transState;
	database_transactions[iteration].transactionSequenceNumber++;
	iteration++;
    state =SERVER_OK;
	}
	else
	{
		state=SAVING_FAILED;
	}
	listSavedTransactions();
	return state;
}

void listSavedTransactions(void)
{

printf("#########################\n");
printf("Transaction Sequence Number: ");
printf("%u",database_transactions->transactionSequenceNumber);
printf("\n Transaction Date: ");
printf("%s",database_transactions->terminalData.transactionDate);
printf("\n Transaction Amount: ");
printf("%f",database_transactions->terminalData.transAmount);
printf("\n Transaction State: ");
if(database_transactions->transState==RUNNING)
{
printf("RUNNING");
}
else
{
	printf("BLOCKED");
}
printf("\n Terminal Max Amount: ");
printf("%f",database_transactions->terminalData.maxTransAmount);
printf("\n Cardholder Name: ");
printf("%s",database_transactions->cardHolderData.cardHolderName);
printf("\n PAN: ");
printf("%s",database_transactions->cardHolderData.primaryAccountNumber);
printf("\n Card Expiration Date: ");
printf("%s",database_transactions->cardHolderData.cardExpirationDate);
printf("\n #########################\n");

}













