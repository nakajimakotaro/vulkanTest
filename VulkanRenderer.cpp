//
// Created by nakajimakotaro on 17/11/11.
//

#include "VulkanRenderer.h"

void VulkanRenderer::initialize(){
    //window作成
    glfwInit();
    this->window = glfwCreateWindow(600, 800, "vulkan", nullptr, nullptr);
    this->device = std::make_unique(new VulkanDevice());
    this->device->createDevice();
}
void VulkanRenderer::createCommandPool(){

}
void VulkanRenderer::createDepthImage(){

}
void VulkanRenderer::createSwapChain(){

}

