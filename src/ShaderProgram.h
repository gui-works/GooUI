/*
 * Shader.h
 *
 *  Created on: 4 sie 2018
 *      Author: Hesitant
 */

#ifndef SHADERPROGRAM_H_
#define SHADERPROGRAM_H_

#include <glad/glad.h>
#include <iostream>

#include "TextFile.h"

class ShaderProgram {
public:
	ShaderProgram(const char* vs_path, const char* fs_path);
	virtual ~ShaderProgram();

	int shaderProgram;
	void use();

	void setBool(const char* name, bool value) const;
	void setInt(const char* name, int value) const;
	void setFloat(const char* name, float value) const;
	void setFloat(const char* name, float v0, float v1) const;
	void setFloat(const char* name, float v0, float v1, float v2) const;
	void setFloat(const char* name, float v0, float v1, float v2, float v3) const;
};

#endif /* SHADERPROGRAM_H_ */
