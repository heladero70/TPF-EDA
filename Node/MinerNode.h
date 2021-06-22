#pragma once

#include "BaseNode.h"
#include "FullNode.h"

class MinerNode : public FullNode {

public:

	MinerNode(boost::asio::io_context& ioContext, std::string port, std::string path2blockchain);
	MinerNode(boost::asio::io_context& ioContext, std::string port);

	virtual std::string getNodeType() override;

	virtual bool poll() override;

	void newUTXO(int amount, std::string blockId, std::string txId, std::string publicId, int outputIndex);

private:
    
	void prepareBlock2mine();
	bool mine();
	bool mining;
    std::vector<Tx> tx2add;
    Block block2mine;
	unsigned int blockReward;

};

