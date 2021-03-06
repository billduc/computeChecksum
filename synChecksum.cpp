/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "checksum.h"

void ComputeTcpChecksum(struct tcphdr *tcp_header, struct iphdr *ip_header)
{

    int packet_size = sizeof(struct tcphdr);
    unsigned char *packet = malloc(sizeof(struct pseudo_header_t) + packet_size);  
    
    struct pseudo_header_t *pseudo_header = (struct pseudo_header_t *) packet;
    struct tcphdr * tcp = (struct tcphdr *) (packet + sizeof(struct pseudo_header_t));
    memset(packet, 0, sizeof(struct pseudo_header_t) +packet_size);

    memcpy(&pseudo_header->source_address, &ip_header->saddr, 4);
    memcpy(&pseudo_header->dest_address, &ip_header->daddr, 4);
    pseudo_header->placeholder = 0;
    pseudo_header->protocol      = 6; /* tcp */
    pseudo_header->length        = htons(sizeof (struct tcphdr) );

    tcp->source = tcp_header->source;
    tcp->dest = tcp_header->dest;
    tcp->seq = tcp_header->seq;
    tcp->ack_seq = tcp_header->ack_seq;
    tcp->doff = tcp_header->doff;
    tcp->window = tcp_header->window;
    tcp->fin =  tcp_header->fin;
    tcp->syn = tcp_header->syn; // SYN = 1, since its the first part of tcp Handshake
    tcp->rst = tcp_header->rst;
    tcp->psh = tcp_header->psh;
    tcp->ack = tcp_header->ack; // ACK = 0, since its the first packet
    tcp->urg = tcp_header->urg;
    tcp->urg_ptr = tcp_header->urg_ptr;
    

    tcp_header->check = ( cksum((u_short*) packet, sizeof(struct pseudo_header_t) +
              packet_size) );

    free(packet);
    return ;

}