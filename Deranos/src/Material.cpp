#include "pch.h"
#include "Material.h"
#include "Camera.h"

Material::Material()
{
	//Attach dummy texture & dummy shader at initialization
	m_shader = std::make_shared<Shader>("shaders/simple.vs", "shaders/simple.ps");
	m_dummy_texture = std::make_shared<Texture>("resources/models/backpack/diffuse.jpg", true);

}

void Material::Bind(std::shared_ptr<Camera>& camera, std::shared_ptr<Transform>& model_xform)
{
	m_dummy_texture->Bind(USERMAP_DIFFUSE);
	m_shader->Bind(camera, model_xform);
}

void Material::AttachShader(std::shared_ptr<Shader>& shader)
{
	m_shader = shader;
}

void Material::AttachTexture(std::shared_ptr<Texture>& texture)
{
	m_dummy_texture = texture;
}

std::vector<Texture> Material::LoadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
{
	
	std::vector<Texture> textures;
	/*
	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		Texture texture;
		texture.id = TextureFromFile(str.C_Str(), directory);
		texture.type = typeName;
		texture.path = str;
		textures.push_back(texture);
	}
	*/
	return textures;

}

void Material::RetrieveMaterial(aiMesh* mesh, const aiScene* scene)
{
	/*
	std::vector<Texture> textures;
	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
		std::vector<Texture> diffuseMaps = loadMaterialTextures(material,
			aiTextureType_DIFFUSE, "texture_diffuse");
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
		std::vector<Texture> specularMaps = loadMaterialTextures(material,
			aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	}
	*/
}
