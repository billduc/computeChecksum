/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   checksum.h
 * Author: hydra
 *
 * Created on November 28, 2017, 7:02 PM
 */

#ifndef CHECKSUM_H
#define CHECKSUM_H

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>

#include <linux/if_packet.h>
#include <arpa/inet.h>


#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include <netinet/udp.h>

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <string>

struct pseudo_header_t
{
        u_int32_t source_address;
        u_int32_t dest_address;
        u_int8_t placeholder;
        u_int8_t protocol;
        u_int16_t length;
};



#endif /* CHECKSUM_H */

