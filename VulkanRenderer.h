//
// Created by nakajimakotaro on 17/11/11.
//

#ifndef VULKANCPPTEST_VULKANRENDERER_H
#define VULKANCPPTEST_VULKANRENDERER_H


#include <vulkan/vulkan.h>

class VulkanRenderer {
public:
    void initialize();
    void createWindow(int w, int h);

private:
    void createCommandPool();
    void createSwapChain();
    void createDepthImage();
    VkCommandBuffer cmdDepthImage;
    VkCommandPool cmdPool;
    Vulkan
};


#endif //VULKANCPPTEST_VULKANRENDERER_H
