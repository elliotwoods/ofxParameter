#pragma once
#include "ParameterBase.h"
#include "ofMain.h"

namespace ofxParameter {
	class ParameterFloat : public ParameterTemplate<float> {
	public:
		string getString(int index);
	};
	
	class ParameterInt : public ParameterTemplate<int> {
	public:
		string getString(int index);
	};
	
	ParameterBase* createParameter(float f);
	ParameterBase* createParameter(int i);
	
}