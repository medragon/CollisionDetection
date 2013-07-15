/* 
ResourceManagement.hpp

A template based simple and fast resource manager using STL and a base resource class to be used with the manager.

Copyright (c) 2008 by Ashic Mahtab and Zinat Wali. 
Permission is granted to use, distribute, or modify this source, provided that this copyright notice remains intact. 

The code is provided "as is" with no guarantees. 
It has been tested in Microsoft Visual Studio 2008 running under Windows Vista Ultimate x64. 

Feel free to contact us at:
aheartattack@gmail.com (Ashic)
zinat.wali@gmail.com (Zinat)

Happy coding :)
*/

#pragma once

#include <string>

class Resource
{
	protected:
		std::string _fileName;
		unsigned int _handle;
		std::string _name;
		std::string _path;
		unsigned long _refCount;

	public:
		Resource(const unsigned int handle, const std::string& name, const std::string& path);
		~Resource();

		std::string getFileName();
		unsigned int getHandle();
		std::string getName();
		std::string getPath();
		unsigned long getRefCount();
		void incRef();
		void decRef();
};

