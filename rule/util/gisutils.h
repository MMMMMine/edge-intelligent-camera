#pragma once

#include "rule/common/gis/location.h"
#include "rule/common/gis/point.h"

#include <math.h>
#include<vector>

using namespace std;
//多边形的数据结构（由点组成的vector）
typedef vector<Point> Polygon;

class GisUtils {
public:
	static double locationIou(Location rect1, Location rect2);

	static double targetOverlapRate(Location targetLac, Location outerLac);


	static bool IsPointInPolygon(const Point& pt, const Polygon& poly);

	// 判断一个点是否在多边形边界上
	static bool isPointOnPolygonEdge(const Point& pt, const Polygon& poly);

	static bool IsPointOnSegment(const Point& p, const Point& p1, const Point& p2);

};