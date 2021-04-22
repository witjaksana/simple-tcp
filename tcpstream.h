#include <sys/types.h>
#include <sys/socket.h>

#include <unistd.h>
#include <string>

using namespace std;

class TCPStream {
    int     m_sd;
    string  m_peerIP;
    int     m_peerPort;

public:

    friend class TCPAcceptor;
    friend class TCPConnector;

    ~TCPStream();

    ssize_t send(const char * buf, size_t len);
    ssize_t receive(char * buf, size_t len);

    string getPeerIP();
    int getPeerPort();

private:
    TCPStream(int sd, struct sockaddr_in* address);
    TCPStream();
    TCPStream(const TCPStream& stream);

};