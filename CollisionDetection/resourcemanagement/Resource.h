#pragma once

#include <string>

class Resource
{
	protected:
		std::string _fileName;
		unsigned int _handle;
		unsigned long _refCount;

	public:
		Resource(const unsigned int handle, const std::string&fileName);
		~Resource();

		std::string getFileName();
		unsigned int getHandle();
		unsigned long getRefCount();
		void incRef();
		void decRef();
};

