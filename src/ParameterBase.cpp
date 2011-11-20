#include "ParameterBase.h"

namespace ofxParameter {
	
#pragma mark helpers
	void splitTags(const string &tagString, TagSet &tagSet) {
		stringstream ss(tagString);
		string tag;
		while(getline(ss, tag, ',')) {
			tagSet.insert(tag);
		}
	}

	TagSet splitTags(const string &tagString) {
		TagSet set;
		splitTags(tagString, set);
		return set;
	}

#pragma mark Header
	Header::Header(string name, string tagString) {
		this->name = name;
		this->tags = splitTags(tagString);
	}

	bool Header::within(const Header &other) const {
		if (other.name != this->name)
			return false;
		TagSet::iterator it = this->tags.begin();
		for (;it != this->tags.end(); it++) {
			if (other.tags.find(*it) == other.tags.end())
				return false;
		}
		return true;
	}
}