// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XSHA256_H
#define XSHA256_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xsha256_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Crtls_BaseAddress;
} XSha256_Config;
#endif

typedef struct {
    u64 Crtls_BaseAddress;
    u32 IsReady;
} XSha256;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XSha256_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XSha256_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XSha256_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XSha256_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XSha256_Initialize(XSha256 *InstancePtr, u16 DeviceId);
XSha256_Config* XSha256_LookupConfig(u16 DeviceId);
int XSha256_CfgInitialize(XSha256 *InstancePtr, XSha256_Config *ConfigPtr);
#else
int XSha256_Initialize(XSha256 *InstancePtr, const char* InstanceName);
int XSha256_Release(XSha256 *InstancePtr);
#endif

void XSha256_Start(XSha256 *InstancePtr);
u32 XSha256_IsDone(XSha256 *InstancePtr);
u32 XSha256_IsIdle(XSha256 *InstancePtr);
u32 XSha256_IsReady(XSha256 *InstancePtr);
void XSha256_EnableAutoRestart(XSha256 *InstancePtr);
void XSha256_DisableAutoRestart(XSha256 *InstancePtr);
u64 XSha256_Get_return(XSha256 *InstancePtr);

void XSha256_Set_input_r(XSha256 *InstancePtr, u32 Data);
u32 XSha256_Get_input_r(XSha256 *InstancePtr);
u32 XSha256_Get_hash(XSha256 *InstancePtr);
u32 XSha256_Get_hash_vld(XSha256 *InstancePtr);

void XSha256_InterruptGlobalEnable(XSha256 *InstancePtr);
void XSha256_InterruptGlobalDisable(XSha256 *InstancePtr);
void XSha256_InterruptEnable(XSha256 *InstancePtr, u32 Mask);
void XSha256_InterruptDisable(XSha256 *InstancePtr, u32 Mask);
void XSha256_InterruptClear(XSha256 *InstancePtr, u32 Mask);
u32 XSha256_InterruptGetEnabled(XSha256 *InstancePtr);
u32 XSha256_InterruptGetStatus(XSha256 *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
