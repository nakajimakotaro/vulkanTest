cmake_minimum_required(VERSION 3.8)
project(vulkanCppTest)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp VulkanLayerAndExtension.cpp VulkanInstance.cpp VulkanApplication.cpp VulkanDevice.cpp VulkanDevice.h VulkanApplication.h VulkanInstance.h VulkanBufferManager.cpp VulkanBufferManager.h VulkanRenderer.cpp VulkanRenderer.h)
add_executable(vulkanCppTest ${SOURCE_FILES})
target_link_libraries(vulkanCppTest glfw vulkan)