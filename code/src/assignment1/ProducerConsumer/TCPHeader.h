#ifndef TCPHEADER_H
#define TCPHEADER_H
#include <systemc.h>
#define PACKET_SIZE 512
#define DATA_SIZE (PACKET_SIZE-20)
typedef struct constr
{
constr() : SourcePort(0), DestinationPort(0), SequenceNumber(0), Acknowledge(1)
        , StatusBits(10), WindowSize(10), Checksum(10), UrgentPointer(10), Data("This is a test")
    {
        DestinationPort = rand() % 2 + 1;
    }
sc_uint<16> SourcePort;
sc_uint<16> DestinationPort;
sc_uint<32> SequenceNumber;
sc_uint<32> Acknowledge;
sc_uint<16> StatusBits;
sc_uint<16> WindowSize;
sc_uint<16> Checksum;
sc_uint<16> UrgentPointer;
char Data[DATA_SIZE];
} TCPHeader;

#endif