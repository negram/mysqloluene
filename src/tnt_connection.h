#pragma once

#include <string>
#include <memory>

struct tnt_stream;
class TntRow;

class TntConnection {
public:
	TntConnection();
	~TntConnection();

	void connect(const std::string &host_port);
	bool connected();

	std::shared_ptr<TntRow> select(const std::string &space);

private:
	struct tnt_stream * tnt;
	std::string host;
	int port;

	void shutdownConnection();
};
