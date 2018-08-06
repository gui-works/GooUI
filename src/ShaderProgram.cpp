/*
 * Shader.cpp
 *
 *  Created on: 4 sie 2018
 *      Author: Hesitant
 */

#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char* vs_path, const char* fs_path) {
	// build and compile our shader program
	// ------------------------------------

	// vertex shader
	TextFile vertexShaderTextFile(vs_path);
	const char *vertexShaderSource = vertexShaderTextFile.c_str();

	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// fragment shader
	TextFile fragmentShaderTextFile(fs_path);
	const char *fragmentShaderSource = fragmentShaderTextFile.c_str();

	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// link shader's
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	delete vertexShaderSource;
	delete fragmentShaderSource;
}

ShaderProgram::~ShaderProgram() {
	// TODO Auto-generated destructor stub

}


void ShaderProgram::use() {
    glUseProgram(shaderProgram);
}

void ShaderProgram::setBool(const char* name, bool value) const {
	glUniform1i(glGetUniformLocation(shaderProgram, name), (int)value);
}

void ShaderProgram::setInt(const char* name, int value) const {
	glUniform1i(glGetUniformLocation(shaderProgram, name), value);
}

void ShaderProgram::setFloat(const char* name, float value) const {
	glUniform1f(glGetUniformLocation(shaderProgram, name), value);
}

void ShaderProgram::setFloat(const char* name, float v0, float v1) const {
	glUniform2f(glGetUniformLocation(shaderProgram, name), v0, v1);
}

void ShaderProgram::setFloat(const char* name, float v0, float v1,
	float v2) const {
	glUniform3f(glGetUniformLocation(shaderProgram, name), v0, v1, v2);
}

void ShaderProgram::setFloat(const char* name, float v0, float v1, float v2,
	float v3) const {
	glUniform4f(glGetUniformLocation(shaderProgram, name), v0, v1, v2, v3);
}
