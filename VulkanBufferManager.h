//
// Created by nakajimakotaro on 17/11/08.
//

#ifndef VULKANCPPTEST_VULKANBUFFERMANAGER_H
#define VULKANCPPTEST_VULKANBUFFERMANAGER_H


#include <vulkan/vulkan.h>

class VulkanBufferManager {
    void allocateBuffer(const VkDevice& device, const VkCommandPool& cmdPool, VkCommandBuffer* commandBuffer, const VkCommandBufferAllocateInfo* commandBufferAllocateInfo);
    void beginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* commandBufferBeginInfo);
    void endCommandBuffer(VkCommandBuffer commandBuffer);
    void submitCommandBuffer(const VkQueue& queue, const VkCommandBuffer commandBuffer, const VkSubmitInfo* submitInfo, const VkFence& fence);
};


#endif //VULKANCPPTEST_VULKANBUFFERMANAGER_H
