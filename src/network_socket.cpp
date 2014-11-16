#include <network_socket.hpp>

using namespace cosmodon;
using namespace cosmodon::network;

// Constructor.
socket::socket(void *context, int type)
{
    if (context == nullptr) {
        throw exception::fatal("Initialized Network Socket on Empty Context");
    }

    // Initialize socket.
    m_socket = zmq_socket(context, type);
    if (m_socket == nullptr) {
        throw exception::fatal(network::error());
    }
}

// Destructor. @@@ What do?
socket::~socket()
{

}

// Establish a socket connection.
void socket::connect(const char *endpoint)
{
    debug("network", "Connecting to: ", false);
    debug("network", endpoint);
    if (zmq_connect(m_socket, endpoint) != 0) {
        throw exception::fatal(network::error());
    }
    debug("network", "Connection Established.");
}

// Establish a socket binding.
void socket::bind(const char *endpoint)
{
    debug("network", "Binding to: ", false);
    debug("network", endpoint);
    if (zmq_bind(m_socket, endpoint) != 0) {
        throw exception::fatal(network::error());
    }
    debug("network", "Binded and Listening.");
}

// Send a message over this socket.
bool socket::send(network::message *msg)
{
    return false;
}

// Receive a message over this socket.
bool socket::receive(network::message *msg)
{
    return false;
}

// Set outgoing high water mark.
void socket::set_send_hwm(unsigned int value)
{
    zmq_setsockopt(m_socket, ZMQ_SNDHWM, &value, sizeof value);
}

// Set incoming high water mark.
void socket::set_receive_hwm(unsigned int value)
{
    zmq_setsockopt(m_socket, ZMQ_RCVHWM, &value, sizeof value);
}

// Set subscription filter.
void socket::set_filter(const void *value)
{
    zmq_setsockopt(m_socket, ZMQ_SUBSCRIBE, value, sizeof value);
}

// Unset subscription filter.
void socket::unset_filter(const void *value)
{
    zmq_setsockopt(m_socket, ZMQ_UNSUBSCRIBE, value, sizeof value);
}

// Set identity.
void socket::set_identity(const void *value)
{
    zmq_setsockopt(m_socket, ZMQ_IDENTITY, value, sizeof value);
}

// Get identity.
void socket::get_identity(const void *value)
{
    zmq_setsockopt(m_socket, ZMQ_IDENTITY, value, sizeof value);
}

// Set lingering period.
void socket::set_linger(unsigned int value)
{
    zmq_setsockopt(m_socket, ZMQ_LINGER, &value, sizeof value);
}