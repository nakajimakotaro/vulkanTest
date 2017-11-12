//
// Created by nakajimakotaro on 17/11/06.
//

#include "VulkanApplication.h"

VulkanApplication::VulkanApplication() {}
VulkanApplication::~VulkanApplication() {}
std::unique_ptr<VulkanApplication> VulkanApplication::instance;
extern std::vector<const char*> layerName;
extern std::vector<const char*> instanceExtensionNames;
VulkanApplication* VulkanApplication::GetInstance() {
    if(!instance){
        instance.reset(new VulkanApplication());
    }
    return instance.get();
}

VkResult VulkanApplication::createVulkanInstance(const std::vector<const char *> &layer,
                                                 const std::vector<const char *> &extensions,
                                                 char const *applicationName) {
    instanceObj.createInstance(layer, extensions, applicationName);
    return VK_SUCCESS;
}
VkResult VulkanApplication::createVulkanDevice() {
    deviceObj.createDevice();
    return VK_SUCCESS;
}
void VulkanApplication::initialize(){
    createVulkanInstance(layerName, instanceExtensionNames, "name");
    createVulkanDevice();
}
void VulkanApplication::prepare(){

}
void VulkanApplication::update(){

}
void VulkanApplication::render(){

}
void VulkanApplication::deInitialize(){

}
