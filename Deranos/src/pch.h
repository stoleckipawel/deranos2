#pragma once

#include <EngineDefines.h>

#include <iostream>
#include <fstream>
#include <sstream>

#include <map>
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

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>


#include <assimp/Importer.hpp>// c++ importer interface
#include <assimp/scene.h>//data structure
#include <assimp/postprocess.h>//postprocessing flags

#include <Timer.h>
#include <Log.h>
#include "TextureTypes.h"

#if defined DERANOS_PLATFORM_WINDOWS
	#include <Windows.h>
#endif

