#pragma once
/***************************************************************************//**
@file     +BaseNode.h+
@brief    +Header padre+
@author   +Grupo 9+
******************************************************************************/

/******************************************************************************
* INCLUDE HEADER FILES
******************************************************************************/
#include "Block.h"
#include <vector>
#include <iostream>


/******************************************************************************
* CLASS BASE NODE
******************************************************************************/
class BaseNode
{

public:
	
	/*=====================================================
	* Name: getActionList
	* Entra: 
	* Resulta: 
	*=====================================================*/
	virtual std::vector<std::string> getActionList() = 0;

	/*=====================================================
	* Name: createBlockchainFromFile
	* Entra: String con la direcciion del archivo .json
	* Resulta: true si se pudo leer el archivo y false en caso contrario
	*=====================================================*/
	virtual bool createBlockchainFromFile(std::string&) = 0;

	/*=====================================================
	* Name: deleteBlockchain
	* Entra: -
	* Resulta: limpia la blockchain que este cargada
	*=====================================================*/
	virtual void deleteBlockchain() = 0;

	/*=====================================================
	* Name: getBlock
	* Entra: string con ID del bloque que se desea
	* Resulta: puntero al blocke solicitado
	*=====================================================*/
	virtual Block * getBlock(std::string id) = 0;

	/*=====================================================
	* Name: getBlocksID
	* Entra: vector de strings donde se guardaran las IDs. numero de bloques que 
	* se desean y offset referenciado al primer bloque. Si nu se recibe numero de bloques se cargaran todos los disponibles
	* Resulta: true o false dependiendo si se pudieron leer todos los bloques o solo algunos.
	* Si la cantidad solicitada es mayor a la disponible se devuelven los que esten.
	*=====================================================*/
	virtual bool getBlocksID(std::vector<std::string>& buffer, int numOfBlocks = 0, int offset = 0) = 0;

	/*=====================================================
	* Name: getBlockQuant
	* Entra: -
	* Resulta: Numero de bloques cargados
	*=====================================================*/
	virtual int getBlockQuant(void) = 0;

protected:

	/*=====================================================
	* Name: commSend used for POST messages
	* Entra: -
	* Resulta: envia un mensaje al nodo conectado.
	*=====================================================*/
	virtual void commSend(std::string host, std::string path, std::string& msg);

	/*=====================================================
	* Name: commSend used for GET messages
	* Entra: -
	* Resulta: envia un mensaje al nodo conectado.
	*=====================================================*/
	virtual void commSend(std::string host, std::string path);

	/*=====================================================
	* Name: commReceive
	* Entra: -
	* Resulta: recive un mensaje del nodo conectado. A implementar
	*=====================================================*/
	virtual void commReceive(void);

	std::vector <Block> blockchain;		//blockchain con los datos
	int state;	//Estado del nodo (recibi� mensaje, manda mensaje, escucha, etc.)
	std::vector <std::string> IPsSentList;
};