#include "EvalScript.hpp"
#include <string>
#include <logger.h>
#include <MinHook.h>
#include <SDK.hpp>
#include <chrono>
#include <thread>

namespace js {

std::uintptr_t NewStringAddress{0};
NewString_t NewString_Origin{nullptr};

void* hkEvalScript(void* Isolate, const char* data, int type, int length) {
    LOG_INFO("JSDATA: %s", data);
    
    // Example
    /*
    std::string scriptData(data);
    if (scriptData.find("__esModule") != std::string::npos) {
        // Modify the script data here
        size_t pos = scriptData.find("this.Entity.CheckGetComponent(116).IsInState(2)");
        if (pos != std::string::npos) {
            scriptData.replace(pos, std::string("this.Entity.CheckGetComponent(116).IsInState(2)").length(), 
                             "this.Entity.CheckGetComponent(116).IsInState(1)");
            LOG_INFO("Changed entity state!");
        }
        return NewString_Origin(this_, Isolate, scriptData.c_str(), type, length);
    }
    */
    
    return NewString_Origin(Isolate, data, type, length);
}

bool EvalScript_Initialize() {
    LOG_INFO("Trying to create NewString hook");

    while (NewStringAddress == 0) {
        if (SDK::InSDKUtils::GetImageBase() == 0)
            continue;

        if (NewStringAddress == 0)
            NewStringAddress = SDK::InSDKUtils::GetImageBase() + NewStringOffset;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    LOG_INFO("NewString Address: %p", (void*)NewStringAddress);

    if (MH_CreateHook(reinterpret_cast<LPVOID>(NewStringAddress), 
                      &hkEvalScript, 
                      reinterpret_cast<LPVOID*>(&NewString_Origin)) == MH_OK) {
        MH_STATUS stat = MH_EnableHook(reinterpret_cast<LPVOID>(NewStringAddress));
        LOG_INFO("MH_EnableHook status: %d", stat);
        
        if (stat == MH_OK) {
            LOG_SUCCESS("NewString Hook enabled");
            return true;
        } else {
            LOG_ERROR("Failed to enable NewString hook");
            return false;
        }
    } else {
        LOG_ERROR("Failed to create NewString hook");
        return false;
    }

    return false;
}

bool EvalScript_Shutdown() {
    try {
        if (NewStringAddress != 0) {
            if (MH_DisableHook(reinterpret_cast<LPVOID>(NewStringAddress)) == MH_OK) {
                if (MH_RemoveHook(reinterpret_cast<LPVOID>(NewStringAddress)) == MH_OK) {
                    NewStringAddress = 0;
                    NewString_Origin = nullptr;
                    LOG_INFO("NewString hook successfully removed");
                    return true;
                }
            }
        }
        LOG_ERROR("Failed to remove NewString hook");
        return false;
    }
    catch (const std::exception& e) {
        LOG_ERROR("Exception in EvalScript_Shutdown: %s", e.what());
        return false;
    }
}

} // namespace js