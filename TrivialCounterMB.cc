#include "FTStateElement.hh"
#include "FTAppenderElement.hh"
#include <click/config.h>
#include <click/router.hh>
#include <clicknet/tcp.h>
#include <click/args.hh>
#include "TrivialCounterMB.hh"

CLICK_DECLS

TrivialCounterMB::TrivialCounterMB() : _counter(INIT_COUNTER) {};

TrivialCounterMB::~TrivialCounterMB() { };

void TrivialCounterMB::_print_ip_port_list() {
#ifndef DEBUG
    return;
#else
    for (size_t i = 0; i < _ips.size(); ++i) {
        DEBUG("%s:%u", _ips[i].c_str(), _ports[i]);
    }//for
#endif
}

void TrivialCounterMB::_split(string& str, char dlm, vector<string>& tokens) {
    int last_index = 0;
    int i = 0;
    for (; i < str.size(); ++i) {
        if (str[i] == dlm && i - last_index > 0) {
            string token(str, last_index, i - last_index);
            tokens.push_back(token);
            last_index = i + 1;
        }//if
    }//for

    if (i - last_index > 0) {
        string token(str, last_index, i - last_index);
        tokens.push_back(token);
        last_index = i + 1;
    }//if
}

int TrivialCounterMB::configure(Vector<String> &conf, ErrorHandler *errh) {
    Args(conf, this, errh).read_or_set("ID", _id, rand() % MB_ID_MAX);

    BoundedIntArg b_int(0, 0xFFFF);
    for (int i = 1; i < conf.size(); ++i) {
        string line(conf[i].c_str());
        vector<string> strs;
        _split(line, ':', strs);
        string ip = strs[0];
        uint16_t port;
        b_int.parse(String(strs[1].c_str()), port);

        _ips.push_back(ip);
        _ports.push_back(port);
    }//for
    _client.set_ip_ports(_ips, _ports);
    _print_ip_port_list();

    LOG("Trivial Counter MB id is %d!\n", _id);

    return 0;
}


Packet *TrivialCounterMB::simple_action(Packet *p) {
    LOG("--------------------");
    LOG("Begin TrivialCounterMB %d:", _id);
    Router *r = this->router();

    _counter++;

    FTState state;
    state[COUNTER] = _counter;
    _client.send(state);

    LOG("Packet id is: %llu", FTAppenderElement::getPacketId(p));
    LOG("Packet counter read is %d, and written %d", _counter - 1, _counter);

    LOG("End TrivialCounterMB %d:", _id);
    LOG("--------------------");

    return p;
}

CLICK_ENDDECLS
EXPORT_ELEMENT(TrivialCounterMB)