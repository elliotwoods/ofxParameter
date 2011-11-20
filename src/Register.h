#pragma once

#include <map>

#include "Parameters.h"

using namespace std;

namespace ofxParameter {	
	typedef map<Header, ParameterBase*> RegisterMap;
	typedef pair<Header, ParameterBase*> RegisterPair;
	
	class Register {
	public:
		template <typename T>
		T& at(string name, string tagString="user") {
			return *(this->operator()<T>(name, 1, tagString));
		}
		
		template <typename T>
		T* operator ()(string name, size_t size, string tagString="user") {
			Header h(name, tagString);
			if (this->contains(h)) {
				//parameter already exists
				return (T*)list[h]->getPointer();
			} else {
				//create parameter
				list.insert(RegisterPair(h, createParameter( T() ) ));
				cout << (contains(h) ? "true" : "false") << endl;
				return (T*)list[h]->getPointer();
			}
		}
		
		bool contains(const Header &header);
		
	protected:
		RegisterMap	list;
	};
}