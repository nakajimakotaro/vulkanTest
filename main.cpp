#define VK_USE_PLATFORM_XLIB_KHR
#include <vulkan/vulkan.h>
#include "VulkanApplication.h"
#include "VulkanLayerAndExtension.h"

std::vector<const char*> instanceExtensionNames = {
        VK_KHR_SURFACE_EXTENSION_NAME,
        VK_KHR_XLIB_SURFACE_EXTENSION_NAME,
        VK_EXT_DEBUG_REPORT_EXTENSION_NAME,
};

std::vector<const char*> layerName = {
    "VK_LAYER_LUNARG_standard_validation",
};
int main(){

    VulkanApplication* appObj = VulkanApplication::GetInstance();
    appObj->initialize();
    return 0;
};
