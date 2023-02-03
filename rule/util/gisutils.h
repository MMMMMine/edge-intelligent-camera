#pragma once

#include "rule/common/gis/location.h"
#include "rule/common/gis/point.h"

#include <math.h>
#include<vector>

using namespace std;
//����ε����ݽṹ���ɵ���ɵ�vector��
typedef vector<Point> Polygon;

class GisUtils {
public:
	static double locationIou(Location rect1, Location rect2);

	static double targetOverlapRate(Location targetLac, Location outerLac);


	static bool IsPointInPolygon(const Point& pt, const Polygon& poly);

	// �ж�һ�����Ƿ��ڶ���α߽���
	static bool isPointOnPolygonEdge(const Point& pt, const Polygon& poly);

	static bool IsPointOnSegment(const Point& p, const Point& p1, const Point& p2);

};