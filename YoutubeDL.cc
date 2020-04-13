#include "YoutubeDL.hh"

namespace YoutubeDL {
    void YoutubeInterface::zmqInit() {
        zmqContext = zmq::context_t(1);
        zmqSocket  = zmq::socket_t(zmqContext, ZMQ_REQ);
    }

    void YoutubeInterface::connectPy() {
        // TODO: Start Python instance
    }
}