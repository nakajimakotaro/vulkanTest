//
// Created by nakajimakotaro on 17/11/07.
//

#include "VulkanDevice.h"
#include "VulkanApplication.h"


void VulkanDevice::createDevice() {
    VulkanApplication* app = VulkanApplication::GetInstance();
    std::vector<VkPhysicalDevice> gpus;
    uint32_t physicalDeviceCount = 0;
    //物理デバイスの取得
    vkEnumeratePhysicalDevices(app->instanceObj.instance, &physicalDeviceCount, nullptr);
    gpus.resize(physicalDeviceCount);
    vkEnumeratePhysicalDevices(app->instanceObj.instance, &physicalDeviceCount, gpus.data());
    this->gpu = gpus[0];

    //物理デバイスのキューファミリの取得
    uint32_t queueFamilyCount;
    vkGetPhysicalDeviceQueueFamilyProperties(gpu, &queueFamilyCount, nullptr);
    std::vector<VkQueueFamilyProperties> queueFamilyProperties(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(gpu, &queueFamilyCount, queueFamilyProperties.data());
    int queueIndex = 0;
    for(auto queueProps: queueFamilyProperties){
        if(queueProps.queueFlags & VK_QUEUE_GRAPHICS_BIT){
            break;
        }
        queueIndex++;
    }


    //キューの作成
    VkDeviceQueueCreateInfo deviceQueueCreateInfo = {};
    deviceQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    deviceQueueCreateInfo.flags = 0;
    deviceQueueCreateInfo.pNext = nullptr;
    deviceQueueCreateInfo.queueCount = 1;
    float queuePriorities[1] = {0.0};
    deviceQueueCreateInfo.pQueuePriorities = queuePriorities;
    deviceQueueCreateInfo.queueFamilyIndex = queueIndex;

    VkDeviceCreateInfo deviceCreateInfo = {};
    deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    deviceCreateInfo.pNext = nullptr;
    deviceCreateInfo.queueCreateInfoCount = 1;
    deviceCreateInfo.pQueueCreateInfos = &deviceQueueCreateInfo;

    vkCreateDevice(this->gpu, &deviceCreateInfo, nullptr, &this->device);
}

VulkanDevice::VulkanDevice() {

}
VulkanDevice::~VulkanDevice() {

}
