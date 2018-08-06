/*
 * TextFile.cpp
 *
 *  Created on: 4 sie 2018
 *      Author: Hesitant
 */

#include "TextFile.h"

TextFile::TextFile(const char* path) {
	// TODO Auto-generated constructor stub
	std::ifstream t(path);

	t.seekg(0, std::ios::end);
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)),
				std::istreambuf_iterator<char>());
	t.close();
}

TextFile::~TextFile() {
	// TODO Auto-generated destructor stub
	str.clear();
}

const char* TextFile::c_str() {
	return this->str.c_str();
}
