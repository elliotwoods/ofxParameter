# Introduction

Test of the ofParameter concept discussed at http://forum.openframeworks.cc/index.php?topic=7795.0

* ofxParameter
 * Problem
     * Trivial saving / loading of parameters
     * Creating user controls for parameters
     * Extension agnostic (gui's, timelines, etc)
     * Grouping parameters
 * Features
     * Instantiate and access have same syntax
     * Save / Load / Autosave
     * Global parameter register
     * Folders / Subregisters / Tags
     * Remote network access
     * Enumerate parameters
 * Tags
     * By default every param has 'user' tag
     * "user,timeline1" refers to
       * During instantiation
           * create parameter with both tags
       * During access
           * Parameters containing both tags
 * Alternative names
     * Control
     * Argument
     * Tweak
     * InteractiveVariable
     * Fiddle
     * Variable
 * Syntax
     * Instantiation / access
       * ofParam<T>[string parameter, string tag="user"]
           * E.g.
             * ofParam<float>["myValue"]
           * Equivalent allocation
             * ofParam<ofVec3f>["v"]
             * ofParam<float*>["v", 3]
       * ofParam<T*>[string parameter, int allocationSize=3, string tag="user"]
     * File
       * ofParamSave() / ofParamLoad()
           * ofParametersSave(string filename="parameters.XML")
       * ofParamSetAutoSave(bool b=true, string filename="parameters.xml")
       * ofParamSetSaveable(string parameter, bool saveable)
     * Tags
       * ofParamAddTag(string paramName, string tag)
       * ofParamRemoveTag(string paramName, string tag)
     * Listing
       * vector<ofParameter> ofParameterGetList(string tag="user")
           * if tag="*" then we return all parameters
     * Debug
       * ofParameterSetAccessCountEnabled(bool b)
           * Turns on access counting.
When enabled, we count how many accesses we make to each variable per frame
       * ofParameterGetAccessCount(string param, bool cached=true)
           * Returns how many times a parameter has been accessed in a frame
