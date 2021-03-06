#pragma once

#include "BaseNode.h"


class NodeFactory
{
public:

	NodeFactory(boost::asio::io_context& ioContext_);
	~NodeFactory();

	std::vector <BaseNode*>& getNodes(void);

	bool createFullNode(std::string port, std::string path2blockchain);
	bool createFullNode(std::string port);

	bool createSPVNode(std::string port, std::string path2blockchain);
	bool createSPVNode(std::string port);

	bool createMinerNode(std::string port, std::string path2blockchain);
	bool createMinerNode(std::string port);

	bool deleteNode(unsigned int nodeIndex);

	bool alreadyExist(std::string portNum);

	bool pollAllNodes();

private:
	boost::asio::io_context& ioContext;
	std::vector <BaseNode*> nodes;
};

