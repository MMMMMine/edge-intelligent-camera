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

	//��ȡ����ͷ���
	string GetCameraIndexCode(Value root);

	//��ȡ��������
	string GetAreaName(Value root);

	//��ȡ����Χ����Ϣ-points(�൱�ڷ����������飩
	vector <Fence> GetFences(Value root);
};

#endif; 