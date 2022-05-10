//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//This is the header file where we declare Base casses for our Buffers. There are Two
//types of buffers, Vertex Buffer that stores the Vertex Data (position, normal, UV, etc)
//And Index Buffer that stores the Indices, or in other words, In what order we want
//to Connect the Vertices

#pragma once

#include "Copper/Core/Core.h"

namespace Copper {

	//Enum of the possible types that each attribute can be
	enum class DataType {

		None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool

	};

	//Function to get the size of a Data Type in bytes
	static uint32_t DataTypeSize(DataType type) {

		switch (type) {

		case DataType::Float:	return 4;
		case DataType::Float2:	return 4 * 2;
		case DataType::Float3:  return 4 * 3;
		case DataType::Float4:  return 4 * 4;
		case DataType::Mat3:	return 4 * 3 * 3;
		case DataType::Mat4:	return 4 * 4 * 4;
		case DataType::Int:		return 4;
		case DataType::Int2:	return 4 * 2;
		case DataType::Int3:	return 4 * 3;
		case DataType::Int4:	return 4 * 4;
		case DataType::Bool:	return 1;

		}

		EngineLogError("Unkown Data Type!");
		return 0;

	}

	//Attribute Struct that stores the needed stuff for setting a BufferLayout
	struct Attribute {

		//Default and a constructor that takes in needed variables
		Attribute() = default;
		Attribute(const char* name, DataType dataType) : name(name), type(dataType), size(DataTypeSize(type)), offset(0) {}

		//Variables
		const char* name;
		DataType type;
		uint32_t size;
		size_t offset;

		//Function to get the dimensions/how many numbers are in this Attribute
		uint32_t GetDimensions() const {

			switch (type) {

			case DataType::Float:	return 1;
			case DataType::Float2:	return 2;
			case DataType::Float3:  return 3;
			case DataType::Float4:  return 4;
			case DataType::Mat3:	return 9;
			case DataType::Mat4:	return 16;
			case DataType::Int:		return 1;
			case DataType::Int2:	return 2;
			case DataType::Int3:	return 3;
			case DataType::Int4:	return 4;
			case DataType::Bool:	return 1;


			}

			EngineLogError("Unkown Data Type!");
			return 0;

		}

	};

	//BufferLayout class. Buffer Layout helps us have one buffer that stores all of the
	//Vertex data and layout how the data is stored. We might know that a Vertex has a
	//position, Normal maybe a UV coord etc, but the GPU doesn't know that. This class
	//helps us to just say "hey the first thing in the Buffer is the position, then
	//the color and then the normals" and the BufferLayout will calculate the Stride and
	//Offset (see OpenGLVertexArray.cpp for explanation of what's a strid and offset)
	class BufferLayout {

	public:
		BufferLayout() = default;
		//Constructor that takes in a Initializer List so that we can create a new Layout
		//Like this:
		//
		//Buffer Layout({"position", DataType::Float3},
		//				{"Uv_Coord", DataType::Float2})
		BufferLayout(std::initializer_list<Attribute> attributes) : attributes(attributes) {

			//Calculate The offset and Stride of The Buffer Layout and its attributes
			CalculateOffsetAndStride();

		}

		//Function to Get the Stride
		inline uint32_t GetStride() { return stride; }

		//Vector Iterator functions so that we can loop through the attributes easily
		std::vector<Attribute>::iterator begin()				{ return attributes.begin(); }
		std::vector<Attribute>::iterator end()					{ return attributes.end(); }
		std::vector<Attribute>::const_iterator begin() const	{ return attributes.begin(); }
		std::vector<Attribute>::const_iterator end() const		{ return attributes.end(); }

	private:
		//vector of the attributes and stride of this whole layout
		std::vector<Attribute> attributes;
		uint32_t stride = 0;

		//Function to Calculate The offset and Stride of The Buffer Layout and its attributes
		void CalculateOffsetAndStride() {

			uint32_t offset = 0;
			stride = 0;

			//Loop through the attributes
			for (Attribute& attribute : attributes) {

				//sets the attributes offset and then increases the offset and the stride
				//by the size of the attribute so that the next attribute will have the right
				//offset and the BufferLayout will have the right stride
				attribute.offset = offset;
				offset += attribute.size;
				stride += attribute.size;

			}

		}

	};

	//VertexBuffer Class, as mentioned previously Vertex Buffer stores the Vertex data
	class VertexBuffer {

	public:
		//A Create function and a default Destructor
		static Shared<VertexBuffer> Create(std::vector<float> vertices);
		virtual ~VertexBuffer() = default;

		//Functions used to Bind the Vertex Buffer. Before we can use the VBO we need
		//to Bind it and after we are done using it we can Unbind it.
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		//Functions to set and Get the Buffer Layout
		virtual void SetLayout(const BufferLayout layout) = 0;
		virtual BufferLayout GetLayout() = 0;

	};

	class IndexBuffer {

	public:
		//Again, a Static Create function and a Default Destructor
		static Shared<IndexBuffer> Create(std::vector<uint32_t> indices);
		virtual ~IndexBuffer() = default;

		//Same case as IndexBuffer. Before we can use it we need to Bind the IBO(or EBO)
		//And Unbind it when we are done using it
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		//Returns the Indices Count
		virtual uint32_t Count() = 0;

	};

}