#pragma once

#include <EngineDefines.h>

#include <iostream>
#include <fstream>
#include <sstream>

#include <array>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "imgui.h"
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <glad.h>

#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Log.h>

#if defined DERANOS_PLATFORM_WINDOWS
	#include <Windows.h>
#endif

