#pragma once

#include <string>
#include <set>
#include <sstream>

using namespace std;

namespace ofxParameter {
	
#pragma mark Header
	typedef set<string> TagSet;
	class Header {
	public:
		Header(string name, string tags);
		
		///Other header has same name, and contains all my tags
		bool within(const Header& other) const;
		bool operator==(const Header& other) const {
			return within(other);
		}
		string		name;
		TagSet		tags;
	};
	
#pragma mark ParameterBase
	class ParameterBase {
	public:
		void* getPointer() { return data;};
		virtual string getString(int index) = 0;
		
		template <typename T>
		void allocate(T value, size_t size=1)  {
			this->size = size;
			data = new T[size];
			for (size_t i=0; i<size; ++i)
				((T*)data)[i] = value;
		}
		virtual void allocate(size_t size=1) = 0;
		
	protected:
		void*	data;
		size_t	size;
	};

#pragma mark ParameterTemplate
	template <typename T>
	class ParameterTemplate : public ParameterBase {
	public:
		T getValue(int index) {
			return ( (T*) this->getPointer() ) [index];
		}
		void allocate(size_t size=1) {
			((ParameterBase*)this)->allocate(T(), size);
		}
	};
}
