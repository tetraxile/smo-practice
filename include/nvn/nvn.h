#pragma once

#include <nvn/nvn_api.h>
#include <nvn/nvn_types.h>

NVNdummyProc nvnBootstrapLoader(const char* name);
void nvnLoadCProcs(const NVNdevice* device, nvnDeviceGetProcAddressFunction deviceGetProcAddress);
