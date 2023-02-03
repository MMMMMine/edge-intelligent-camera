#ifndef Rule_H
#define Rule_H

#pragma once

#include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include "json/json.h"
#include <fstream>
#include <map>
#include <vector>

using namespace std;
using namespace Json;

class Rule {

public:
	 Rule();
	~Rule();
	Value Read(string file);

};
#endif 