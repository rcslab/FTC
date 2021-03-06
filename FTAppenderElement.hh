#pragma once

#include "FTTypes.hh"
#include <click/config.h>
#include <click/element.hh>
#include <clicknet/tcp.h>
#include <boost/archive/archive_exception.hpp>

#define FROM_DUMP 0
#define FROM_TO_DEVICE 1
#define TO_FT_STATE 0
#define FT_APPENDER_CLASS_NAME "FTAppenderElement"

#define IP_PACKET_OFFSET 14
#define IP_PACKET_AFTER_VLAN_OFFSET 18

CLICK_DECLS

class FTAppenderElement : public Element {
private:
    FTPiggyBackMessage _temp;
    VLANId _first_vlan;

public:
    FTAppenderElement();

    ~FTAppenderElement();

    const char *class_name() const { return "FTAppenderElement"; }

    const char *port_count() const { return PORTS_1_1; }

    const char *processing() const { return AGNOSTIC; }

    int configure(Vector<String> &conf, ErrorHandler *errh);

    void push(int source, Packet *p);

    void append(FTPiggyBackMessage state);

    static void serializePiggyBacked(FTPiggyBackMessage &pbStates, stringstream &ss);

    static void deserializePiggyBacked(stringstream &ss, FTPiggyBackMessage &piggyBackedStates);

    static void deserializePiggyBacked(string& states, FTPiggyBackMessage &piggyBackedStates);

    static void serialize(FTPiggyBackState &state, stringstream &ss);

    static void serialize(FTTimestampState &state, stringstream &ss);

    static void deserialize(stringstream &ss, FTPiggyBackState &state);

    static void deserialize(stringstream &ss, FTTimestampState &state);

    static int  payloadOffset(Packet *p);

    /// Encode the states from the packet
    /// \param p The packet
    /// \param piggyBackedState The state that is being piggybacked
    /// \return an encoded packet
    static WritablePacket *encodeStates(Packet *p, FTPiggyBackMessage& msg);

    /// Decode the states from the packet
    /// \param p The packet
    /// \param piggyBackedState The state that is being piggybacked
    /// \return the location of the payload
    static int decodeStates(Packet *p, FTPiggyBackMessage &piggyBackedState);

    /// Decode the states from the packet and return a packet without the state
    /// \param p The packet
    /// \param piggyBackedState The state that is being piggybacked
    /// \return The packet without the state
    static WritablePacket* decodeStatesRetPacket(Packet *p, FTPiggyBackMessage &piggyBackedState);

    /// Compress @arg data and write the compression result into @param buffer
    /// \param data To be compressed
    /// \param buffer Compressed
    static void compress(const std::string &data, std::string &buffer);

    /// Decompress @arg data and write the decompression result into @param buffer
    /// \param data To be decompressed
    /// \param buffer Decompressed
    static void decompress(const std::string &data, std::string &buffer);

    /// Serialize and compress state
    /// \param state The state to be encoded
    /// \param buffer The encoded byte stream
    static void encode(FTTimestampState& state, string& buffer);

    /// Deserialize and decompress state
    /// \param data The compressed serialized state
    /// \param state The state
    static void decode(const string& data, FTTimestampState& state);

    static void decode(const char* data, int size, FTTimestampState& state);

    /// Get a unique identifier for a packet
    /// \param p The packet
    /// \return The unique identifier
    static FTPacketId getPacketId(Packet *p, int ip_offset = IP_PACKET_OFFSET);

    // TODO: remove this function
    static void printState(FTState &state);
    static void printState(FTTimestampState &state);
    static void printState(FTPiggyBackState &state);
    static void printState(FTPiggyBackMessage &state);
};

CLICK_ENDDECLS