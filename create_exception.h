#pragma once


#include <iostream>

namespace ERROR_ENUM
{
	enum  EXCEPTIONS
	{
		EXCEPT_MEMORY_ALOCATION_ERROR,
		EXCEPT_OPEN_FILE_ERROR,
		EXCEPT_WRITE_TO_FILE_ERROR,
		EXCEPT_READ_FROM_FILE_ERROR,
		EXCEPT_TO_LONG_NODE_NAME_WARNING,
		EXCEPT_VECTOR_OVERFLOW_WARNING,
		EXCEPT_EMPTY_VECTOR_WARNING,
		EXCEPT_WRONG_INDEX_WARNING,
		EXCEPT_UNKNOWN_COMAND_WARNING,
		EXCEPT_TOT
	};
};


class CreateException
{
private:

	ERROR_ENUM::EXCEPTIONS position;
	static const char* exceptionArray[];

public:
	CreateException(enum ERROR_ENUM::EXCEPTIONS newExceptions);
	void displayMessage();
};