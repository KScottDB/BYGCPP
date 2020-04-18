#include "YoutubeDL.hh"
#include <iostream>

namespace bp = boost::process;

namespace YoutubeDL {
    void YoutubeInterface::dbgOutput(std::string output) {
        std::cout << "DEBUG - " << output << std::endl;
    }

    void YoutubeInterface::zmqInit() {
        dbgOutput("zmqInit() called");

        dbgOutput("zmqInit(): Init context");
        zmqContext = zmq::context_t(1);
        dbgOutput("zmqInit(): Init socket");
        zmqSocket  = zmq::socket_t(zmqContext, ZMQ_REQ);

        dbgOutput("zmqInit() finished");
    }

    void YoutubeInterface::connectPy() {
        dbgOutput("connectPy() called");

        if (connectedToPython) {
            dbgOutput("connectPy(): Already connected to python. Skipping");
            return;
        }

        dbgOutput("connectPy(): Starting python3");
        pyInstance = bp::child( bp::search_path("python3"), "PyAPIServer/main.py" );
        
        dbgOutput("connectPy(): Connecting to python API server. (STUB)");
        // TODO: connect

        dbgOutput("connectPy() finished");
    }
}