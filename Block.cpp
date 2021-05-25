#include "Block.h"

Block::Block(std::string blockid_, unsigned int height_, std::string merkleRoot_, unsigned int nTx_, int nonce_, std::string prevblockid_) :
	blockId(blockid_),
	height(height_),
	nonce(nonce_),
	previousBlockId(prevblockid_),
	merkleRoot(merkleRoot_)
{
}

bool Block::push_transaction(Tx newTx)
{
	txs.push_back(newTx);
	return true;
}

void Block::getMerklePath(void)
{


}

void Block::getMerkleRoot(void)
{
	
	std::vector<std::string> tempTree;	//Aca voy a ir metiendo los strings a medida que los calcule
	std::string tempString;

	bool esPar = false;


	for (std::vector<Tx>::iterator it = txs.begin(); it != txs.end(); it++) {

		if (esPar == false) {

			tempString = it->getId();


		}
	}

}

std::string Block::getBlockId(void)
{
	return blockId;
}
