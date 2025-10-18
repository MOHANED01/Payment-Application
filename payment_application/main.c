/*
 * main.c
 *
 *  Created on: Oct 11, 2022
 *      Author: mohaned
 */

#include"app.h"
#include<stdio.h>
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
		setvbuf(stderr, NULL, _IONBF, 0);
	appStart();

	return 0;
}
