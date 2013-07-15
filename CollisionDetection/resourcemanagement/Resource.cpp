#include "Resource.h"


Resource::Resource(const unsigned int handle, const std::string& name, const std::string& path)
{
	if (!name.empty())
		_name = name;

	if (!path.empty())
		_path = path;

	_handle = handle;

	if (!name.empty() && !path.empty())
		_fileName = path + name;

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

std::string Resource::getName()
{
	return _name;
}

std::string Resource::getPath()
{
	return _path;
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
