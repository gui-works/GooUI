/*
 * TextFile.h
 *
 *  Created on: 4 sie 2018
 *      Author: Hesitant
 */

#ifndef TEXTFILE_H_
#define TEXTFILE_H_

#include <string>
#include <fstream>
#include <streambuf>

class TextFile {
	std::string str;
public:
	TextFile(const char* path);
	virtual ~TextFile();

	const char* c_str();
};

#endif /* TEXTFILE_H_ */
