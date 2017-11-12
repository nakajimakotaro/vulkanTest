//
// Created by nakajimakotaro on 17/11/08.
//

#include "VulkanBufferManager.h"

void VulkanBufferManager::allocateBuffer(const VkDevice& device, const VkCommandPool& cmdPool, VkCommandBuffer* commandBuffer, const VkCommandBufferAllocateInfo* commandBufferAllocateInfo) {
    if (commandBufferAllocateInfo) {
        vkAllocateCommandBuffers(device, commandBufferAllocateInfo, commandBuffer);
        return;
    }
    VkCommandBufferAllocateInfo commandInfo = {};
    commandInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    commandInfo.commandPool = cmdPool;
    commandInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    commandInfo.commandBufferCount = 1;
    vkAllocateCommandBuffers(device, &commandInfo, commandBuffer);
}

void VulkanBufferManager::beginCommandBuffer(VkCommandBuffer commandBuffer,
                                             const VkCommandBufferBeginInfo* commandBufferBeginInfo) {
    if(commandBufferBeginInfo){
        vkBeginCommandBuffer(commandBuffer, commandBufferBeginInfo);
        return;
    }
    VkCommandBufferInheritanceInfo commandBufferInheritanceInfo = {};
    commandBufferInheritanceInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
    commandBufferInheritanceInfo.renderPass = VK_NULL_HANDLE;
    commandBufferInheritanceInfo.subpass = 0;
    commandBufferInheritanceInfo.framebuffer = VK_NULL_HANDLE;
    commandBufferInheritanceInfo.occlusionQueryEnable = VK_FALSE;
    commandBufferInheritanceInfo.queryFlags = 0;
    commandBufferInheritanceInfo.pipelineStatistics = 0;

    VkCommandBufferBeginInfo commandBufferBeginInfoDefault;
    commandBufferBeginInfoDefault.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    commandBufferBeginInfoDefault.pInheritanceInfo = &commandBufferInheritanceInfo;
    vkBeginCommandBuffer(commandBuffer, &commandBufferBeginInfoDefault);
}

void VulkanBufferManager::endCommandBuffer(VkCommandBuffer commandBuffer) {
    vkEndCommandBuffer(commandBuffer);
}

void submitCommandBuffer(const VkQueue& queue, const VkCommandBuffer commandBuffer, const VkSubmitInfo* submitInfo, const VkFence& fence){
    if(submitInfo){
        vkQueueSubmit(queue, 1, submitInfo, fence);
    }
    VkSubmitInfo submitInfoDefault;
    submitInfoDefault.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submitInfoDefault.waitSemaphoreCount = 0;
    submitInfoDefault.pWaitSemaphores = nullptr;
    submitInfoDefault.pWaitDstStageMask = nullptr;
    submitInfoDefault.commandBufferCount = sizeof(commandBuffer) / sizeof(VkCommandBuffer);
    submitInfoDefault.pCommandBuffers = &commandBuffer;
    submitInfoDefault.signalSemaphoreCount = 0;
    submitInfoDefault.pSignalSemaphores = nullptr;

    vkQueueSubmit(queue, 1, &submitInfoDefault, fence);
    vkQueueWaitIdle(queue);
}
