#pragma once
/***************************************************************************//**
@file     +Gui.h+
@brief    +Header clase Gui+
@author   +Grupo 9+
******************************************************************************/

/******************************************************************************
* INCLUDE HEADER FILES
******************************************************************************/
#include <string>
#include <iostream>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>      
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <map>
#include <vector>
#include "../Node/FullNode.h"
#include "../Node/SPVNode.h"
#include "../Hashing.h"
#include "../MerkleTree.h"
#include "../Node/NodeFactory.h"

/*******************************************************************************
* ENUMERATIONS AND STRUCTURES AND TYPEDEFS
******************************************************************************/
enum STATES {CLOSEPROGRAM, RUNNING};

/******************************************************************************
* CLASS GUI
******************************************************************************/
class Gui
{
public:
	/*=====================================================
	* Name: Constructor
	* Entra: -
	* Resulta: Inicializa las librearias de allegro e ImGui
	*=====================================================*/
	Gui();

	/*=====================================================
	* Name: destructor
	* Entra: -
	* Resulta: Limpia residuos de memoria
	*=====================================================*/
	~Gui();

	/*=====================================================
	* Name: update
	* Entra: Objeto nodo de la red que se esta representando
	* Resulta: Genera un refresto en base al estado interno del display
	*=====================================================*/
	void update(NodeFactory& nodes);
	
	/*=====================================================
	* Name: getState
	* Entra: -
	* Resulta: Devuelve es estado de la GUI. Leer enum en este archivo
	*=====================================================*/
	int getState();

private:

	int state;					//Estado de la GUI
	int currentNodeActive;		//Indice del nodo actual
	int blockPage;				//Indice de pagina cuando se muestran los bloques
	int comboBoxNodesIndex;
	int comboBoxActionNodesIndex;
	int comboBoxVerifiedTxsIndex;
	float amountWritten;			//Entero donde se guarda la cantidad ingresada
	int blockQuantityWritten;	//Entero donde se guarda la cantidad de bloques ingresada
	int positionWritten;		//Entero donde se guarda la posicion ingresada
	std::string nodePort;		//Puerto ingresado por la GUI
	std::string nodeIp;			//IP ingresada por la GUI
	std::string connPort1;		//Puerto del nodo a conectar con el actual
	std::string filename;		//String que mantiene el path al archivo con la blockchain
	std::string actionGetBlockIDWritten;	//String donde se escriben los blockID para los mensajes
	std::string actionGetBlockPublicKeyWritten;	//String donde se escibe la public Key
	ALLEGRO_DISPLAY* display;	//Display y cola de eventos de allegro
	ALLEGRO_EVENT_QUEUE* queue; 
	std::map<std::string, MerkleTree<hash32>*> merkleTrees;	//Diccionario para almacenar los Merkle Trees de los bloques al momento en que se solicitan

	bool fileFound;		//Estado del texto que muestra cuando no encuentra un archivo
	bool linkedSuccess;
	bool falseActionActive;
	bool verifiedTrxSendActive;

	/*=====================================================
	* Name: deleteMerkleDic
	* Entra: -
	* Resulta: Limpia el diccionario de arboles
	*=====================================================*/
	void deleteMerkleDic();

	/*=====================================================
	* Name: showBlocksTab
	* Entra: Nodo en el que se esta trabajando
	* Resulta: Muestra la tabla con los bloques a mostrar
	*=====================================================*/
	void showBlocksTab(BaseNode& node);

	void showNodesTab(NodeFactory& nodes);

	void showCreateBox(NodeFactory& nodes);
	void showConnectBox(NodeFactory& nodes);
	void showActionsBox(NodeFactory& nodes);
	void showNodesTable(NodeFactory& nodes);
	void HelpMarker(const char* desc);

	/*=====================================================
	* Name: openSubTreeNode
	* Entra: Nodo de arbol desde el cual comenzar a dibujar y una id que se ira incrementando para generar las label de los nodos
	* Resulta: -
	*=====================================================*/
	void openSubTreeNode(MerkleNode* node, int& id);

	void nSpacing(int n);
};

