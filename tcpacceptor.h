#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "tcpstream.h"

using namespace std;

class TCPAcceptor {
    int     m_lsd;
    string  m_address;
    int     m_port;
    bool    m_listening;

public:
    TCPAcceptor(int port, const char *address="");
    ~TCPAcceptor();

    int start();
    TCPStream* accept();

private:
    TCPAcceptor();
};