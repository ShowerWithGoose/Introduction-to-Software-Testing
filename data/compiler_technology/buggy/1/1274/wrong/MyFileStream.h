#pragma once
//
// Created by  on 2024/10/9.
//

#ifndef BIANYI_MYFILESTREAM_H
#define BIANYI_MYFILESTREAM_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
class Error {
public:
	int lineNum;
	int characterNum;
	std::string errortype;
	Error(int lineNum, int characterNum, std::string errortype) : lineNum(lineNum), characterNum(characterNum), errortype(errortype) {};
};
extern std::vector<Error> errorList;
extern std::ofstream fileout;
extern std::ofstream errorout;
extern std::ifstream inputFile;
inline void RecordError(int lineNum, int characterNum, std::string errorType) {
	errorList.push_back(Error(lineNum, characterNum, errorType));
}
inline bool CompareErrors(const Error& a, const Error& b) {
	if (a.lineNum != b.lineNum) {
		return a.lineNum < b.lineNum;
	}
	else if(a.characterNum != b.characterNum){
		return a.characterNum < b.characterNum;
	}
	else {
		return a.errortype < b.errortype;
	}
}
inline void SortErrors() {
	std::sort(errorList.begin(), errorList.end(), CompareErrors);
}
#endif 
