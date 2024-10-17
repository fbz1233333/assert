#pragma once

#include "fxcc/graph/interface.h"

namespace fxcc
{
	namespace graph
	{
		
		enum DataType
		{
			_dataType_none_=0,
			_dataType_float_,
			_dataType_Unsigned_byte_,
			_dataType_Unsigned_short_,
			_dataType_Unsigned_int_,
			_dataType_byte_,
			_dataType_short_,
			_dataType_int_,
		};

		struct DataTypeDesc
		{
			std::string m_Name;
			int m_Value;
		};
		enum RenderTargetDescType
		{
			_none_ = 0,
			_desc1_,
			_desc2_,
		};
		struct RenderTargetDescTypeDesc
		{
			std::string m_Name;
		};

		enum TextureMatType
		{
			_Texture_Mat_NONE = 0,
			_Texture_Mat_DIFFUSE,
			_Texture_Mat_SPECULAR,
			_Texture_Mat_AMBIENT,
			_Texture_Mat_EMISSIVE,
			_Texture_Mat_HEIGHT,
			_Texture_Mat_NORMALS,
			_Texture_Mat_SHININESS,
			_Texture_Mat_OPACITY,
			_Texture_Mat_DISPLACEMENT,
			_Texture_Mat_LIGHTMAP,
			_Texture_Mat_REFLECTION,
			_Texture_Mat_BASE_COLOR,
			_Texture_Mat_NORMAL_CAMERA,
			_Texture_Mat_EMISSION_COLOR,
			_Texture_Mat_METALNESS,
			_Texture_Mat_DIFFUSE_ROUGHNESS,
			_Texture_Mat_AMBIENT_OCCLUSION,
			_Texture_Mat_UNKNOWN,
			_Texture_Mat_End,
		};
		struct TextureMatTypeDesc
		{
			std::string m_Name;
		};
		enum AnimationDescType
		{
			_None_=0,
			_Animation_Model_File_,
		};
		struct AnimationDescTypeDesc
		{
			std::string m_Name;

		};
		enum ShaderDescType
		{
			_shader_desc_none_=0,
			_shader_desc_text_,
			_shader_desc_file_,
			_shader_desc_end_,
		};
		struct ShaderDescTypeDesc
		{
			std::string m_Name;

		};
		enum Texture2DDescType
		{
			_texture_2d_desc_none_=0,
			// Form origin data
			_texture_2d_desc_origin_data_,
			// From image
			_texture_2d_desc_imaga_desc_,
			// From origin file
			_texture_2d_desc_origin_file_,

			_texture_2d_desc_end_

		};
		struct Texture2DDescTypeDesc
		{
			std::string m_Name;
		};

		enum MeshDescType
		{
			_mesh_desc_none = 0,
			_mesh_origin_data_,
			_mesh_mesh_data_,
			_mesh_origin_file_,
			_mesh_mesh_data_file_,
			_mesh_model_file_,
			_mesh_desc_end,
		};
		struct MeshDescTypeDesc
		{
			std::string m_Name;

		};

		enum LightSourceType
		{
			_light_none = 0x0,
			_light_directioon= 0x1,
			_light_point = 0x2,
			_light_spot= 0x3,
			_light_ambient = 0x4,
			_light_area = 0x5,
			_light_end_
		};
		struct LightSourceTypeDesc
		{
			std::string m_Name;
		};


		enum TextureMaterialType
		{
			_material_none_ = 0,
			_material_diffuse_,
			_material_specular_,
			_material_ambient_,
			_material_end_,
		};



		enum SamplerType
		{
			_sampler_none_ = 0 ,
			_sampler_2d_default_,
			_sampler_cube_default_,
			_sampler_2d_array_default,
			_sampler_end_
		};

		// struct TextureMaterialTypeDesc
		// {
		// 	std::string m_Name;
		// };
		// struct SamplerTypeDesc
		// {
		// 	std::string m_Name;
		// 	fxcc::graph::SamplerDesc m_SampDesc;
		// };
		// struct VertexTypeDesc
		// {
		// 	std::string m_Name;
		// 	int m_VertexStride;
		// 	InputLayout m_InputLayout;
		// };
		// struct ModeTypeDesc
		// {
		// 	std::string m_Name;
		// 	int m_Target;
		// };
		// struct TextureTypeDesc
		// {
		// 	std::string m_Name;
		// 	int m_Target;
		// };
		// struct IndexTypeDesc
		// {
		// 	std::string m_Name;
		// 	int m_Target;
		// 	int m_IndexStride;
		// };

		enum TextureType
		{
			_texture_none_ = 0,
			_texture_2d_,
			_texture_cube_,
			_texture_2d_array_,
			_texture_end_

		};

		enum VertexType
		{
			_vertex_none_ = 0,
			_vertex_fixed_,
			_vertex_skinned_,
			_vertex_font_,
			_vertex_end_
		};


		enum IndexType
		{
			_index_none_ = 0,
			_index_unsigned_byte_,
			_index_unsigned_short_,
			_index_unsigned_int_,
			_index_end_
		};

		enum ModeType
		{
			_mode_none_=0,
			_mode_Triangles_,
			_mode_Triangle_fan_,
			_mode_Triangle_stripe_,
			_mode_Lines_,
			_mode_Line_Stripe,
			_mode_Line_Look,
			_mode_end_
		};


	};
};