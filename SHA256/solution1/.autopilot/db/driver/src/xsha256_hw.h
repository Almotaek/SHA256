// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// CRTLS
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - enable ap_done interrupt (Read/Write)
//        bit 1  - enable ap_ready interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - ap_done (COR/TOW)
//        bit 1  - ap_ready (COR/TOW)
//        others - reserved
// 0x10 : Data signal of ap_return
//        bit 31~0 - ap_return[31:0] (Read)
// 0x14 : Data signal of ap_return
//        bit 31~0 - ap_return[63:32] (Read)
// 0x1c : Data signal of input_r
//        bit 7~0 - input_r[7:0] (Read/Write)
//        others  - reserved
// 0x20 : reserved
// 0x24 : Data signal of hash
//        bit 7~0 - hash[7:0] (Read)
//        others  - reserved
// 0x28 : Control signal of hash
//        bit 0  - hash_ap_vld (Read/COR)
//        others - reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XSHA256_CRTLS_ADDR_AP_CTRL      0x00
#define XSHA256_CRTLS_ADDR_GIE          0x04
#define XSHA256_CRTLS_ADDR_IER          0x08
#define XSHA256_CRTLS_ADDR_ISR          0x0c
#define XSHA256_CRTLS_ADDR_AP_RETURN    0x10
#define XSHA256_CRTLS_BITS_AP_RETURN    64
#define XSHA256_CRTLS_ADDR_INPUT_R_DATA 0x1c
#define XSHA256_CRTLS_BITS_INPUT_R_DATA 8
#define XSHA256_CRTLS_ADDR_HASH_DATA    0x24
#define XSHA256_CRTLS_BITS_HASH_DATA    8
#define XSHA256_CRTLS_ADDR_HASH_CTRL    0x28

