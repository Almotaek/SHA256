// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xsha256.h"

extern XSha256_Config XSha256_ConfigTable[];

XSha256_Config *XSha256_LookupConfig(u16 DeviceId) {
	XSha256_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XSHA256_NUM_INSTANCES; Index++) {
		if (XSha256_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XSha256_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XSha256_Initialize(XSha256 *InstancePtr, u16 DeviceId) {
	XSha256_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XSha256_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XSha256_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

