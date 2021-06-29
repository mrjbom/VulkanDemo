#pragma once
#include <vector>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class ValidationLayers
{
public:
#ifdef _DEBUG
	static const bool enabled = true;
#else
	static const bool enabled = false;
#endif
	//See initialization in .cpp file
	static const std::vector<const char*> validationLayers;


	static bool checkSupport();
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);
};
