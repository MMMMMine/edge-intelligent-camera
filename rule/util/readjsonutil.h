#ifndef ReadJsonUtil_H
#define ReadJsonUtil_H

#pragma once

#include <iostream>
#include <string>
#include "json/json.h"
#include <fstream>
#include <map>
#include <vector>

using namespace std;
using namespace Json;

struct Params
{
	double socre;
	double rate;
	int location[4];
	string label;
};

class ReadJsonUtil {

public:
	ReadJsonUtil();

	~ReadJsonUtil();

	 Value Read(string file);
	 void testRead(string s);

	 string GetRuleLayoutCode(Value root);

	 vector <Params> GetParams(Value root);

	 vector <Params> GetLabelInfo(Value root, string label, double socre);

};

#endif 



