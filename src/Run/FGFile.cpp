/* MIT License
 *
 * Copyright (c) 2021 laferenorg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN C
 */
/* Include header C++ */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ios>
#include <filesystem>

/* Include header from include directory in this project */
#include "Run/FGFile.hpp"

/* Handle function Exist File */
bool FGFile::ExistFile(std::string path,
	FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Setup variable return */
	bool FileExist = false;

	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run Check File because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGFile::ExistFile";
	} else {
		/* If no have error */

		/* Setup variable ifstream */
		std::ifstream TempCheckFile;

		/* Open file */
		TempCheckFile.open(path, std::ios::binary);

		/* Check the file open */
		if(TempCheckFile.is_open()) {
			/* If file open */
			/* Set variable file exist into true */
			FileExist = true;
		}

		/* Close file */
		TempCheckFile.close();
	}

	/* Return result */
	return FileExist;
}

/* Handle function for Count File */
unsigned int FGFile::CountFile(std::string path,
	FGData_System& system, std::string& message_error, bool& errorEvent) {
	unsigned int CountFileVariable = 0;

	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run Count File because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGFile::CountFile";
	} else {
		/* Setup count file */
		std::filesystem::path TempPath(path.c_str());

		/* Check folder */
		if(std::filesystem::exists(TempPath) && 
			std::filesystem::is_directory(TempPath)) {
			/* If all good */
			for (auto& count : std::filesystem::directory_iterator(path)) {
				CountFileVariable += 1;
			}
		} else {
			/* If that's not folder or not exist */
			/* Change error event into true */
			errorEvent = true;

			/* Write message error */
			message_error = "Can't know directory: ";
			message_error += path;
			message_error += " | in function FGFile::CountFile";
		}
	}

	/* Return variable of result count */
	return CountFileVariable;
}

/* Handle function for Check Folder */
bool FGFile::ExistFolder(std::string path,
	FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Setup variable exist */
	bool ExistFolder = false;

	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run Exist Folder because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGFile::ExistFolder";
	} else {
		/* If all good */
		/* Setup count file */
		std::filesystem::path TempPath(path.c_str());

		/* Check folder */
		if(std::filesystem::exists(TempPath) && 
			std::filesystem::is_directory(TempPath)) {
			/* If exist folder */
			ExistFolder = true;
		}
	}

	/* Return result */
	return ExistFolder;
}

/* Handle function for get all list file on Folder */
std::vector<std::string> FGFile::List(std::string path,
	FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Setup vector */
	std::vector<std::string> ListOfFile;

	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run Get List because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGFile::List";
	} else {
		/* Setup count file */
		std::filesystem::path TempPath(path.c_str());

		/* Check folder */
		if(std::filesystem::exists(TempPath) && 
			std::filesystem::is_directory(TempPath)) {
			/* If all good */
			for (auto& count : std::filesystem::directory_iterator(path)) {
				std::string nameFile = count.path();
				ListOfFile.push_back(nameFile);
			}
		} else {
			/* If that's not folder or not exist */
			/* Change error event into true */
			errorEvent = true;

			/* Write message error */
			message_error = "Can't know directory: ";
			message_error += path;
			message_error += " | in function FGFile::List";
		}
	}

	/* Return result */
	return ListOfFile;
}