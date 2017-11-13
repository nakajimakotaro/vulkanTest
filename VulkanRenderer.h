//
// Created by nakajimakotaro on 17/11/11.
//

#ifndef VULKANCPPTEST_VULKANRENDERER_H
#define VULKANCPPTEST_VULKANRENDERER_H


#include <memory>
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include "VulkanSwapChain.h"
#include "VulkanDevice.h"

class VulkanRenderer {
public:
    void initialize();
    void createWindow(int w, int h);

private:
    void createSwapChain();
    void createDepthImage();
    void createCommandPool();
    std::unique_ptr<VulkanSwapChain> swapChain;
    std::unique_ptr<VulkanDevice> device;
    std::unique_ptr<VkCommandBuffer> cmdDepthImage;
    std::unique_ptr<VkCommandPool> cmdPool;
    GLFWwindow* window;
};


#endif //VULKANCPPTEST_VULKANRENDERER_H
