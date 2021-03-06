/***************************************************************************//**
@file     +Main.cpp+
@brief    +Archivo donde esta la funcion main +
@author   +Grupo 9+
******************************************************************************/

/******************************************************************************
* INCLUDE HEADER FILES
******************************************************************************/
#include "Node/FullNode.h"		// Todo: sacar estos dos de aca
#include "Node/SPVNode.h"
#include "ImGui/Gui.h"
#include "MerkleTree.h"
#include "Hashing.h"
#include "Node/NodeFactory.h"

#include <cryptopp/hex.h>
#include <cryptopp/sha.h>

using namespace std;

/******************************************************************************
* Funcion Main
******************************************************************************/
int main(int argc, char** argv) {

	Gui menu;
	boost::asio::io_context contexto;
	NodeFactory nodes(contexto);

	////NODOS PARA DEBUGGING
	//nodes.createFullNode(std::to_string(25676));
	//nodes.createSPVNode(std::to_string(25678));
	//nodes.createFullNode(std::to_string(25672) ,std::string("blockchain_sample_0.json"));
	
	//nodes.getNodes()[2]->addNeighbour("127.0.0.1:25676", std::string("Full"));
	//nodes.getNodes()[1]->addNeighbour("127.0.0.1:25672", std::string("Full"));
	// 
	
	nodes.createMinerNode(std::to_string(25670));
	nodes.createFullNode(std::to_string(25672));
	nodes.getNodes()[0]->addNeighbour("127.0.0.1:25672", std::string("Full"));

	////*****************************************************

	while (menu.getState() == RUNNING) {

		nodes.pollAllNodes();
		menu.update(nodes);
	}
	

	return 0;
}