//
// Created by nakajimakotaro on 17/11/06.
//

#ifndef VULKANCPPTEST_VULKANLAYERANDEXTENSION_H
#define VULKANCPPTEST_VULKANLAYERANDEXTENSION_H

#include <vector>

struct LayerProperties {
    VkLayerProperties properties;
    std::vector<VkExtensionProperties> extensions;
};

class VulkanLayerAndExtension{
    std::vector<LayerProperties> layergetInstanceLayerProperties();

public:
    VkResult getExtensionProperties(LayerProperties &layerProps, VkPhysicalDevice* gpu = NULL);
    VkResult getDeviceExtensionProperties(VkPhysicalDevice* gpu);
    static VkResult getInstanceLayerProperties();

};

#endif //VULKANCPPTEST_VULKANLAYERANDEXTENSION_H
