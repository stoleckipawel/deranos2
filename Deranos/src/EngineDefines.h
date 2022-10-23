#pragma once
#include <memory>

//Unique pointer life span based on scope, cant be copied
//std::unique_ptr<Entity> = std::make_unique<Entity>();
template<typename T>
using Scope = std::unique_ptr<T>;

//Shared pointer, life span based on reference counted
//std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
template<typename T>
using Ref = std::shared_ptr<T>;