#include "Register.h"

namespace ofxParameter {

	bool Register::contains(const ofxParameter::Header &header) {
		return list.count(header) != 0;
	}
}