//
// Created by nakajimakotaro on 17/11/06.
//

#include <iostream>
#include "VulkanInstance.h"

VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT, uint64_t object,
                                             size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage, void* pUserData){
    std::cout << pMessage << std::endl;
}
VkResult VulkanInstance::createInstance(const std::vector<const char *> &layer,
                                        const std::vector<const char *> &extensions, char const *applicationName) {
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pNext = nullptr;
    appInfo.pApplicationName = applicationName;
    appInfo.apiVersion = 1;
    appInfo.pEngineName = applicationName;
    appInfo.engineVersion = 1;
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo instInfo = {};
    instInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instInfo.pNext = nullptr;
    instInfo.flags = 0;
    instInfo.pApplicationInfo = &appInfo;
    instInfo.enabledLayerCount = (uint32_t)layer.size();
    instInfo.ppEnabledLayerNames = layer.data();
    instInfo.enabledExtensionCount = (uint32_t)extensions.size();
    instInfo.ppEnabledExtensionNames = extensions.data();

    VkResult res = vkCreateInstance(&instInfo, nullptr, &instance);

    VkDebugReportCallbackCreateInfoEXT callbackInfo;
    callbackInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
    callbackInfo.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT | VK_DEBUG_REPORT_INFORMATION_BIT_EXT | VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT;
    callbackInfo.pfnCallback = &debugCallback;
    auto _vkCreateDebugReportCallbackEXT = reinterpret_cast<PFN_vkCreateDebugReportCallbackEXT>(vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT"));
    VkDebugReportCallbackEXT callback;
    _vkCreateDebugReportCallbackEXT(instance, &callbackInfo, nullptr, &callback);

    return res;
}

void VulkanInstance::destoryInstance() {
    vkDestroyInstance(instance, nullptr);
}