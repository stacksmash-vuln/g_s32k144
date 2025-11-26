/* ###################################################################
**     Copyright 2019-2020 NXP 
**     Copyright (c) 2001-2003 Swedish Institute of Computer Science.
**     All rights reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
*
**     1. Redistributions of source code must retain the above copyright notice,
**        this list of conditions and the following disclaimer.
**     2. Redistributions in binary form must reproduce the above copyright notice,
**        this list of conditions and the following disclaimer in the documentation
**        and/or other materials provided with the distribution.
**     3. The name of the author may not be used to endorse or promote products
**        derived from this software without specific prior written permission.
*
**     This software is owned or controlled by NXP and may only be
**     used strictly in accordance with the applicable license terms. By expressly
**     accepting such terms or by downloading, installing, activating and/or otherwise
**     using the software, you are agreeing that you have read, and that you agree to
**     comply with and are bound by, such license terms. If you do not agree to be
**     bound by the applicable license terms, then you may not retain, install,
**     activate or otherwise use the software. The production use license in
**     Section 2.3 is expressly granted for this software.
*
**     This file is part of the lwIP TCP/IP stack.
*
**     Author: Adam Dunkels <adam@sics.se>
*
** ###################################################################*/

#ifndef LWIP_NETIFCFG_H_
#define LWIP_NETIFCFG_H_

#include "lwip/netif.h"

/* Structure containing network interfaces configuration. */
typedef struct {
    u8_t num;                               /* Interface number */
    uint8_t hwaddr[NETIF_MAX_HWADDR_LEN];   /* MAC address */
    bool has_dhcp;                          /* Variable containing information whether dhcp is enabled or not */
    bool has_auto_ip;                       /* Variable containing information whether auto ip is enabled or not */
    bool has_IPv6;                          /* Variable containing information whether ipv6 is enabled or not */
    u8_t ip_addr[4];                        /* Board's ip address. Needs to be set if dhcp is turned off. */
    u8_t netmask[4];                        /* Board's netmask. Needs to be set if dhcp is turned off. */
    u8_t gw[4];                             /* Board's network gateway. Needs to be set if dhcp is turned off. */
    const char *hostname;                   /* Board's hostname used for dns. */
    char name[2];                           /* Interface name */
} netif_custom_t;

#include "enetif.h"

/* Number of active network interfaces. */
#define ENETIF_NUMBER 1

/* Number of Ethernet Interfaces for the stack */
#define ETHIF_NUMBER ENETIF_NUMBER

/* Network interfaces configuration. */
extern netif_custom_t *netif_cfg[ENETIF_NUMBER];

/* Ethernet MII mode - speed. */
#define ENET_MIIMODE                  ENET_RMII_MODE
#define ENET_MIISPEED                 ENET_MII_SPEED_100M

#ifndef FEATURE_ENET_RX_CONFIG_PAYLOAD_LEN_CHECK
#define FEATURE_ENET_RX_CONFIG_PAYLOAD_LEN_CHECK    1U
#endif /* FEATURE_ENET_RX_CONFIG_PAYLOAD_LEN_CHECK */

#ifndef FEATURE_ENET_RX_CONFIG_STRIP_CRC_FIELD
#define FEATURE_ENET_RX_CONFIG_STRIP_CRC_FIELD      1U
#endif /* FEATURE_ENET_RX_CONFIG_STRIP_CRC_FIELD */

#ifndef FEATURE_ENET_RX_CONFIG_REMOVE_PADDING
#define FEATURE_ENET_RX_CONFIG_REMOVE_PADDING    1U
#endif /* FEATURE_ENET_RX_CONFIG_REMOVE_PADDING */

#ifndef FEATURE_ENET_HAS_TX_CONFIG
#define FEATURE_ENET_HAS_TX_CONFIG      1U
#endif /* FEATURE_ENET_HAS_TX_CONFIG */

#ifndef FEATURE_ENET_HAS_ACCELERATOR
#define FEATURE_ENET_HAS_ACCELERATOR      1U
#endif /* FEATURE_ENET_HAS_ACCELERATOR */

#endif /* LWIP_NETIFCFG_H_ */

