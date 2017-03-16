#pragma once

#include <string>
#include <memory>

struct tnt_stream;
class Row;
namespace tnt {
	class Iterator;
	class TupleBuilder;
}

class TntConnection {
public:
	TntConnection();
	~TntConnection();

	void connect(const std::string &host_port);
	bool connected();

	std::shared_ptr<tnt::Iterator> select(const std::string &space);
	bool insert(const std::string &space, const tnt::TupleBuilder &builder);
	bool del(const std::string &space, const tnt::TupleBuilder &builder);
	bool update(const std::string &space, const tnt::TupleBuilder &builder);

	int resolveSpace(const std::string &space);
private:
	struct tnt_stream * tnt;
	std::string host;
	int port;

	void shutdownConnection();
};

