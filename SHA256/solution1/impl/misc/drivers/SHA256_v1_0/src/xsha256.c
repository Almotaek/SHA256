// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xsha256.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XSha256_CfgInitialize(XSha256 *InstancePtr, XSha256_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Crtls_BaseAddress = ConfigPtr->Crtls_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XSha256_Start(XSha256 *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSha256_ReadReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_AP_CTRL) & 0x80;
    XSha256_WriteReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_AP_CTRL, Data | 0x01);
}

u32 XSha256_IsDone(XSha256 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSha256_ReadReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XSha256_IsIdle(XSha256 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSha256_ReadReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XSha256_IsReady(XSha256 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSha256_ReadReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XSha256_EnableAutoRestart(XSha256 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSha256_WriteReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_AP_CTRL, 0x80);
}

void XSha256_DisableAutoRestart(XSha256 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSha256_WriteReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_AP_CTRL, 0);
}

u64 XSha256_Get_return(XSha256 *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSha256_ReadReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_AP_RETURN);
    Data += (u64)XSha256_ReadReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_AP_RETURN + 4) << 32;
    return Data;
}
void XSha256_Set_input_r(XSha256 *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSha256_WriteReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_INPUT_R_DATA, Data);
}

u32 XSha256_Get_input_r(XSha256 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSha256_ReadReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_INPUT_R_DATA);
    return Data;
}

u32 XSha256_Get_hash(XSha256 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSha256_ReadReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_HASH_DATA);
    return Data;
}

u32 XSha256_Get_hash_vld(XSha256 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSha256_ReadReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_HASH_CTRL);
    return Data & 0x1;
}

void XSha256_InterruptGlobalEnable(XSha256 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSha256_WriteReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_GIE, 1);
}

void XSha256_InterruptGlobalDisable(XSha256 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSha256_WriteReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_GIE, 0);
}

void XSha256_InterruptEnable(XSha256 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSha256_ReadReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_IER);
    XSha256_WriteReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_IER, Register | Mask);
}

void XSha256_InterruptDisable(XSha256 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSha256_ReadReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_IER);
    XSha256_WriteReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_IER, Register & (~Mask));
}

void XSha256_InterruptClear(XSha256 *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSha256_WriteReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_ISR, Mask);
}

u32 XSha256_InterruptGetEnabled(XSha256 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSha256_ReadReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_IER);
}

u32 XSha256_InterruptGetStatus(XSha256 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSha256_ReadReg(InstancePtr->Crtls_BaseAddress, XSHA256_CRTLS_ADDR_ISR);
}

