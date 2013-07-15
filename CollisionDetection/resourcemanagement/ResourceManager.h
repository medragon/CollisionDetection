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

#include <stack>
#include <vector>
#include <string>

#define SAFE_DELETE(p) { if ( p ) { delete ( p ); ( p ) = NULL; } }

template<class T>
class ResourceManager
{
	private:
		std::stack<unsigned int> _handles;
		std::vector<T*> *_list;

		void (*createResource)(T **resource, const unsigned int, const std::string &, const std::string &);

	public:
		ResourceManager(void (*createResourceFunction) (T **resource, const unsigned int handle, const std::string& name, const std::string& path) = NULL)
		{
			_list = new std::vector<T*>;
			createResource = createResourceFunction;
		}
		
		~ResourceManager(void)
		{
			emptyList();
			delete _list;
		}

		unsigned int add(const std::string& name, const std::string& path)
		{
			if (_list == NULL || name.empty() || path.empty())
				return -1;

			T *element = getElement(name, path);
			if ( element != NULL) {
				element->incRef();
				return element->getHandle();
			}

			bool handleAvailable = !_handles.empty();
			unsigned int handle;
			if (handleAvailable) {
				handle = _handles.top();
				_handles.pop();
			} else {
				handle = _list->size();
			}

			T* resource = NULL;
			if (createResource != NULL)
				createResource(&resource, handle, name, path);
			else
				resource = new T(handle, name, path);

			if (handleAvailable)
				(*_list)[handle] = resource;
			else
				_list->push_back(resource);

			return handle;
		}

		void emptyList()
		{
			for (std::vector<T*>::iterator i = _list->begin(); i != _list->end(); i++) {
				SAFE_DELETE(*i);
			}

			while(!_handles.empty())
				_handles.pop();

			_list->clear();
			_list->swap(*_list);
		}

		T* getElement(const int handle)
		{
			if (handle < _list->size() && handle >= 0)
				return (*_list)[handle];

			return NULL;
		}

		T* getElement(const std::string& name, const std::string& path)
		{
			if (name.empty() || path.empty() || _list == NULL || _list->empty())
				return NULL;

			for (std::vector<T*>::iterator i = _list->begin(); i != _list->end(); i++) {
				if ((*i)->getName() == name)
					if ((*i)->getPath() == path)
						return (*i);
			}

			return NULL;
		}

		std::vector<T*> getList()
		{
			return _list;
		}

		T* operator[](unsigned int handle)
		{
			if (handle < _list->size() && handle >= 0)
				return (*_list)[handle];

			return NULL:
		}

		void remove(const unsigned int handle)
		{
			if (handle < 0 || _list == NULL || handle >= _list->size() || (*_list)[handle] == NULL)
				return;

			T * resource = (*_list)[handle]

			resource->decRef();

			if(resource->getRefCount() == 0)
			{
				_handles.push(handle);
				delete resource;
				(*_list)[handle] = NULL;
			}
		}
};