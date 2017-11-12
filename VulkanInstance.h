//
// Created by nakajimakotaro on 17/11/06.
//

#ifndef VULKANCPPTEST_VULKANINSTANCE_H
#define VULKANCPPTEST_VULKANINSTANCE_H

#include <vulkan/vulkan.h>
#include <vector>

class VulkanInstance{
public:
    VkResult createInstance(const std::vector<const char*>& layer, const std::vector<const char*>& extensions, char const* applicationName);
    VkInstance  instance;
    void destoryInstance();
};


#endif //VULKANCPPTEST_VULKANINSTANCE_H
