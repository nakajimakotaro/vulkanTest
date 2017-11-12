//
// Created by nakajimakotaro on 17/11/06.
//
#include <iostream>
#include <vulkan/vulkan.h>
#include <vector>

#include "VulkanLayerAndExtension.h"

VkResult VulkanLayerAndExtension::getInstanceLayerProperties(){
    uint32_t instanceLayerCount;

    std::vector<VkLayerProperties> layerProperties;
    VkResult result;

    do{
        result = vkEnumerateInstanceLayerProperties(&instanceLayerCount, NULL);
        if(result){
            return result;
        }
        if(instanceLayerCount == 0){
            return VK_INCOMPLETE;
        }
        layerProperties.resize(instanceLayerCount);
        result = vkEnumerateInstanceLayerProperties(&instanceLayerCount, layerProperties.data());
    } while(result == VK_INCOMPLETE);

    std::cout << "\nInstanced Layers" << std::endl;
    std::cout <<  "=================" << std::endl;
    for(auto globalLayerProp: layerProperties){
        std::cout << "\n" << globalLayerProp.description
                  << "\n\t|\n\t|--[Layer Name]--> "
                  << globalLayerProp.layerName << "\n";
        LayerProperties layerProps;
        layerProps.properties = globalLayerProp;

        //result = getExtensionProperties(layerProps);
        //if(result){
        //    continue;
        //}
        //for(auto j: layerProps.extensions){
        //    std::cout << "\t\t|\n\t\t|-- [Layer Extension]--> " << j.extensionName << std::endl;
        //}
    }

}
