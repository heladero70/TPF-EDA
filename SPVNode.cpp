#include "SPVNode.h"

bool SPVNode::createBlockchainFromFile(std::string&)
{
    return false;
}

void SPVNode::deleteBlockchain()
{
}

Block* SPVNode::getBlock(std::string id)
{
    return nullptr;
}

bool SPVNode::getBlocksID(std::vector<std::string>& buffer, int numOfBlocks, int offset)
{
    return false;
}

int SPVNode::getBlockQuant(void)
{
    return 0;
}