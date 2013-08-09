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

		void (*createResource)(T **resource, const unsigned int, const std::string &);

	public:
		ResourceManager(void (*createResourceFunction) (T **resource, const unsigned int handle, const std::string& fileName) = NULL)
		{
			_list = new std::vector<T*>;
			createResource = createResourceFunction;
		}
		
		~ResourceManager(void)
		{
			emptyList();
			delete _list;
		}

		unsigned int add(const std::string& fileName)
		{
			if (_list == NULL || fileName.empty())
				return -1;

			T *element = getElement(fileName);
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
				createResource(&resource, handle, fileName);
			else
				resource = new T(handle, fileName);

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

		T* getElement(const std::string& fileName)
		{
			if (fileName.empty() || _list == NULL || _list->empty())
				return NULL;

			for (std::vector<T*>::iterator i = _list->begin(); i != _list->end(); i++) {
				if ((*i)->getFileName() == fileName)
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