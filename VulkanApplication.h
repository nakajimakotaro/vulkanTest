//
// Created by nakajimakotaro on 17/11/06.
//

#ifndef VULKANCPPTEST_VULKANAPPLICATION_H
#define VULKANCPPTEST_VULKANAPPLICATION_H

#include <vector>
#include <memory>
#include <vulkan/vulkan.h>
#include "VulkanInstance.h"
#include "VulkanDevice.h"
class VulkanApplication{

public:
    ~VulkanApplication();

    VulkanApplication();

private:
    static std::unique_ptr<VulkanApplication> instance;
    VkResult createVulkanInstance(const std::vector<const char*>& layer, const std::vector<const char*>& extensions, char const* applicationName);
    VkResult createVulkanDevice();

public:
    VulkanInstance instanceObj;
    VulkanDevice deviceObj;

    static VulkanApplication* GetInstance();
    void initialize();
    void prepare();
    void update();
    void render();
    void deInitialize();

};


#endif //VULKANCPPTEST_VULKANAPPLICATION_H
