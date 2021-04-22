#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "tcpconnector.h"

int main(int argc, char** argv) {

    if (argc != 3) {
        printf("usage: %s <port> [<ip>]\n", argv[0]);
        exit(1);
    }

    int len;
    string message;
    char line[256];

    TCPConnector * connector = new TCPConnector();
    TCPStream * stream = connector->connect(atoi(argv[1]), argv[2]);

    if (stream) {
        message = "Is there life in Mars?";
        stream->send(message.c_str(), message.size());
        printf("sent - %s\n", message.c_str());
        len = stream->receive(line, sizeof(line));
        line[len] = NULL;
        printf("received - %s\n", line);
        delete stream;
    }

    stream = connector->connect(atoi(argv[1]), argv[2]);

    if (stream) {
        message = "Why is there air?";
        stream->send(message.c_str(), message.size());
        printf("sent - %s\n", message.c_str());
        len = stream->receive(line, sizeof(line));
        line[len] = NULL;
        printf("received - %s\n", line);
        delete stream;
    }
}