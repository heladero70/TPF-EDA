#pragma once
/***************************************************************************//**
@file     +OutTx.h+
@brief    +Header+
@author   +Grupo 9+
******************************************************************************/

/******************************************************************************
* INCLUDE HEADER FILES
******************************************************************************/
#include <iostream>

/******************************************************************************
* CLASS OutTx
******************************************************************************/
class OutTx
{
public:

	/*=====================================================
	* Name: constructor
	* Entra: Recibe los datos con los que va a llenar el bloque
	* Resulta: -
	*=====================================================*/
	OutTx(std::string publicId_, float amount_);

	std::string getPublicId(void);
	float getAmount(void);

private:
	std::string publicId;
	float amount;
};

