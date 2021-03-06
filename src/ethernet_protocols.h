#ifndef ETHERNET_PROTOCOLS_H__
#define ETHERNET_PROTOCOLS_H__

#include <inttypes.h>

/* ETH */
#define ETH_HEADER_LEN    14
#define ETHTYPE_ARP_H_V 0x08
#define ETHTYPE_ARP_L_V 0x06
#define ETHTYPE_IP_H_V  0x08
#define ETHTYPE_IP_L_V  0x00
#define ETH_TYPE_H_P 12
#define ETH_TYPE_L_P 13
#define ETH_DST_MAC 0
#define ETH_SRC_MAC 6

/* ARP */
#define ETH_ARP_OPCODE_REPLY_H_V 0x0
#define ETH_ARP_OPCODE_REPLY_L_V 0x02
#define ETH_ARP_OPCODE_REQ_H_V 0x0
#define ETH_ARP_OPCODE_REQ_L_V 0x01
#define ETH_ARP_P 0xe
#define ETHTYPE_ARP_L_V 0x06
#define ETH_ARP_DST_IP_P 0x26
#define ETH_ARP_OPCODE_H_P 0x14
#define ETH_ARP_OPCODE_L_P 0x15
#define ETH_ARP_SRC_MAC_P 0x16
#define ETH_ARP_SRC_IP_P 0x1c
#define ETH_ARP_DST_MAC_P 0x20
#define ETH_ARP_DST_IP_P 0x26

/* IP */
#define IP_HEADER_LEN    20
#define IP_SRC_P 0x1a
#define IP_DST_P 0x1e
#define IP_HEADER_LEN_VER_P 0xe
#define IP_CHECKSUM_P 0x18
#define IP_TTL_P 0x16
#define IP_FLAGS_P 0x14
#define IP_ID_P 0x12
#define IP_P 0xe
#define IP_TOTLEN_H_P 0x10
#define IP_TOTLEN_L_P 0x11
#define IP_PROTO_P 0x17
#define IP_PROTO_ICMP_V 1
#define IP_PROTO_TCP_V 6
#define IP_PROTO_UDP_V 17

/* UDP */
#define UDP_HEADER_LEN    8
#define UDP_SRC_PORT_H_P 0x22
#define UDP_SRC_PORT_L_P 0x23
#define UDP_DST_PORT_H_P 0x24
#define UDP_DST_PORT_L_P 0x25
#define UDP_LEN_H_P 0x26
#define UDP_LEN_L_P 0x27
#define UDP_CHECKSUM_H_P 0x28
#define UDP_CHECKSUM_L_P 0x29
#define UDP_DATA_P 0x2a

extern const uint8_t mac[];

uint8_t eth_type_is_arp_and_my_ip(const uint16_t len);
void make_arp_answer_from_request(void);

uint8_t eth_type_is_ip_and_my_ip(const uint16_t len);

int16_t check_checksum(const uint8_t dest, const uint8_t off, uint16_t len, const uint8_t type);

void makeUdpReply(uint16_t datalen, const uint16_t port);

#endif
