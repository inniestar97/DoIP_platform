#include <stdio.h>
#include <iostream>

// #include "doiplib/diag_message.h"
#include "sockpp/tcp_acceptor.h"
#include "sockpp/error.h"


int main(int argc, char* argv[]) { 

    in_port_t port = 12345;

    sockpp::initialize();

    sockpp::error_code ec;
    sockpp::tcp_acceptor tcp_acc(port, 4, ec);

    if (ec) {
        std::cerr << "Error creating the accepter: " << ec.message() << std::endl;
        return 1;
    }

    std::cout << "Awaiting connections on port" << port << "..." << std::endl;

    sockpp::inet_address peer;

    if (auto res = tcp_acc.accept(&peer); !res) {
        std::cerr << "Error accepting incoming connection: " << res.error_message() << std::endl;
    } else {
        std::cout << "Receive a connection request from " << peer << std::endl;
        sockpp::tcp_socket sock = res.release();
    }
    



    return 0;

}
