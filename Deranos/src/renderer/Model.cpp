
#include "pch.h"
#include "Model.h"

Model::Model()
{
	//Dummy Model Implementation
	mesh.push_back(std::make_shared<Mesh>());
	model_xform = std::make_shared<Transform>();
	material = std::make_shared<Material>();
}

Model::Model(const char* path)
{
	Model::LoadModel(path);
	model_xform = std::make_shared<Transform>();
	material = std::make_shared<Material>();
}

void Model::LoadModel(std::string path)
{
	Assimp::Importer* importer = new Assimp::Importer();

	const aiScene* scene = importer->ReadFile(path, aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace | aiProcess_ValidateDataStructure | aiProcess_FindInvalidData);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		DERANOS_CORE_ERROR(std::strcat("ASSIMP::IMPORT ", importer->GetErrorString()));
		return;
	}

	ProcessNode(scene->mRootNode, scene);

	delete importer;
}

void Model::ProcessNode(aiNode* node, const aiScene* scene)
{
	// process all the node's meshes (if any)
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		ProcessMesh(mesh, scene);
	}
	// then do the same for each of its children
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		ProcessNode(node->mChildren[i], scene);
	}
}

void Model::ProcessMesh(aiMesh* mesh, const aiScene* scene)
{
	std::shared_ptr<Mesh> submesh = std::make_shared<Mesh>(mesh);
	this->mesh.push_back(submesh);
}

void Model::Draw(Camera& camera)
{
	//Set proper camera consts in  the material, model, view, projection xform in the material
	material->Bind(camera, *model_xform);

	//Draw each sub mesh of the mesh
	for each (auto submesh in mesh)
	{
		submesh->Draw();
	}
}
