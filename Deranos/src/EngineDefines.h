#pragma once

#define USERMAP_COLOR 0
#define USERMAP_DIFFUSE 1
#define USERMAP_NORMAL 2
#define USERMAP_SPECULAR 3
#define USERMAP_ROUGHNESS 4
#define USERMAP_METALIC 5
#define USERMAP_TANGENT 6

#define USERMAP_TMP_0 10
#define USERMAP_TMP_1 11
#define USERMAP_TMP_2 12
#define USERMAP_TMP_3 13
#define USERMAP_TMP_4 14
#define USERMAP_TMP_5 15
#define USERMAP_TMP_6 16



typedef unsigned int uint;


/*
#include <memory>

//Unique pointer life span based on scope, cant be copied
//std::unique_ptr<Entity> = std::make_unique<Entity>();
template<typename T>
using Scope = std::unique_ptr<T>;

//Shared pointer, life span based on reference counted
//std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
template<typename T>
using Ref = std::shared_ptr<T>;
*/



