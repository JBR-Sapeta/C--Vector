#pragma once

#include "node.h"
#include "vector_file.h"

#include <iostream>
enum MENU
{
	INTERFACE_PUSH_ELEMENT,
	INTERFACE_POP_ELEMENT,
	INTERFACE_CLEAR_VECTOR,
	INTERFACE_MODIFY_ELEMENT,
	INTERFACE_INSERT_ELEMENT,
	INTERFACE_FIND_ELEMENT,
	INTERFACE_SAVE_VECTOR_BINARY,
	INTERFACE_LOAD_VECTOR_BINARY,
	INTERFACE_DISPLAY_VECTOR,
	INTERFACE_END_PROGRAM,
	INTERFACE_TOT,
};



class Interface
{
	static const char* interfaceArray[];
	VectorFile <Node> vector;
	Node object ;
	Node* ptr;
public:
	bool runing;
	Interface(char* filenamebin);
	Interface(char* filenamebin, size_t size);
	void menu();
	void pushElement();
	void popElement();
	void clearVector();
	void modifyElement();
	void insertElement();
	void findElement();
	void saveVectoBin();
	void loadVectorBin();
	void displeyVector();
	void closeProgram();
	void defaultCase();
};