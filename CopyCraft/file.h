#ifndef FILE_H
#define FILE_H
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class File {
public:
	static const std::string readFromFile(const std::string pathToFile);
private:
	File();
};
#endif