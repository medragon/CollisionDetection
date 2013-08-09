#include "Resource.h"


Resource::Resource(const unsigned int handle, const std::string& fileName)
{
	if (!fileName.empty())
		_fileName = fileName;

	_handle = handle;

	_refCount = 1;
}


Resource::~Resource(void)
{
}

std::string Resource::getFileName()
{
	return _fileName;
}

unsigned int Resource::getHandle()
{
	return _handle;
}

unsigned long Resource::getRefCount()
{
	return _refCount;
}

void Resource::incRef()
{
	_refCount++;
}

void Resource::decRef()
{
	_refCount--;
}
