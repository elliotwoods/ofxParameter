#include "Parameters.h"

namespace ofxParameter {

#pragma mark definitions
	string ParameterFloat::getString(int index) {
		return ofToString(this->getValue(index));
	}
	
	string ParameterInt::getString(int index) {
		return ofToString(this->getValue(index));
	}
	
#pragma mark creators
	ParameterBase* createParameter(float f) {
		return new ParameterFloat();
	}
	
	ParameterBase* createParameter(int i) {
		return new ParameterInt();
	}
}