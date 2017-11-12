//
// Created by nakajimakotaro on 17/11/07.
//

#ifndef VULKANCPPTEST_VULKANDEVICE_H
#define VULKANCPPTEST_VULKANDEVICE_H

#include <vulkan/vulkan.h>
#include <vector>
#include <memory>

class VulkanDevice {
public:
    VulkanDevice();
    ~VulkanDevice();
    VkDevice device;
    VkPhysicalDevice gpu;
    VkPhysicalDeviceProperties gpuProps;
    VkPhysicalDeviceMemoryProperties memoryProperties;

    VkQueue queue;
    std::vector<VkQueueFamilyProperties> queueFamilyProps;

    uint32_t grahicsQueueFamilyIndex;
    uint32_t queueFamilyCount;

    void createDevice();
    void memoryTypeFromProperties();
    void destoryDevice();
    void getGrahicsQueueHandle();
    void initializeDeviceQueue();
    void getPhysicalDeviceQueuesAndProperties();
};


#endif //VULKANCPPTEST_VULKANDEVICE_H
