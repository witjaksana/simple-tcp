#include <netinet/in.h>

#include "tcpstream.h"

class TCPConnector {
public:
    TCPStream * connect(int port, const char * server);

private:
    int resolveHostName(const char* hostname, struct in_addr* addr);
};