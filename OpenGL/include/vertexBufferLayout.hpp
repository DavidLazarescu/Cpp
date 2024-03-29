#pragma once

#include <GL/glew.h>

#include <vector>

#include "renderer.hpp"	
#include <iostream>


struct VertexBufferElement {
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int getSizeOfType(unsigned int type) {
		switch (type) {
		case GL_FLOAT:
			return 4;
			break;
		case GL_UNSIGNED_INT:
			return 4;
			break;
		case GL_UNSIGNED_BYTE:
			return 1;
			break;
		}

		ASSERT(false);
		return 0;
	}
};


class VertexBufferLayout
{
public:
	VertexBufferLayout() : m_Stride(0) {};


	template <typename T>
	void push(unsigned int count) {
		ASSERT(false);
	}
	
	template <>
	void push<float>(unsigned int count) {

		m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
		m_Stride += VertexBufferElement::getSizeOfType(GL_FLOAT) * count;
	}

	template <>
	void push<unsigned int>(unsigned int count) {

		m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		m_Stride += VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT) * count;
	}

	template <>
	void push<unsigned char>(unsigned int count) {

		m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		m_Stride += VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE) * count;
	}

	inline const std::vector<VertexBufferElement>& getElements() const { return m_Elements; };
	inline unsigned int getStride() const { return m_Stride; };

private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
};