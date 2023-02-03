#ifndef ReadCameraUtil_H
#define ReadCameraUtil_H

#pragma once
#include <iostream>
#include <string>
#include <json/json.h>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;
using namespace Json;



struct Point
{
public:

	double x, y;

};

struct Fence
{
public:

	std::string label;
	vector <Point> point;
};


class ReadCameraUtil
{
public:
	ReadCameraUtil();
	~ReadCameraUtil();

	Value Read(string file);

	//获取摄像头编号
	string GetCameraIndexCode(Value root);

	//获取工作区域
	string GetAreaName(Value root);

	//获取电子围栏信息-points(相当于返回整形数组）
	vector <Fence> GetFences(Value root);
};

#endif; 