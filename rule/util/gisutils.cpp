#include "gisUtils.h"


static bool isPolygonIntersect(vector<Location> locationList, vector<Location> locationList2) {

}
static double locationIou(Location rect1, Location rect2) {
    //x����������ֵ
    double xMax = max(rect1.getX(), rect2.getX());
    //x���������Сֵ
    double xMin = min(rect1.getMaxX(), rect2.getMaxX());
    // y����������ֵ
    double yMax = max(rect1.getY(), rect2.getY());
    // y����������Сֵ
    double yMin = min(rect1.getMaxY(), rect2.getMaxY());

    // �����ཻ
    if (xMax >= xMin || yMin <= yMax) {
        return 0.0;
    }

    double s1 = rect1.getWidth() * rect1.getHeight();
    double s2 = rect2.getWidth() * rect2.getHeight();
    double sCross = (xMin - xMax) * (yMin - yMax);
    return sCross / (s1 + s2 - sCross);
}
static double targetOverlapRate(Location targetLac, Location outerLac) {
    //x����������ֵ
    double xMax = max(targetLac.getX(), outerLac.getX());
    //x���������Сֵ
    double xMin = min(targetLac.getMaxX(), outerLac.getMaxX());
    // y����������ֵ
    double yMax = max(targetLac.getY(), outerLac.getY());
    // y����������Сֵ
    double yMin = min(targetLac.getMaxY(), outerLac.getMaxY());

    // �����ཻ
    if (xMax >= xMin || yMin <= yMax) {
        return 0;
    }

    double targetArea = targetLac.getWidth() * targetLac.getHeight();
    double sCross = (xMin - xMax) * (yMin - yMax);
    return sCross / targetArea;
}
//�ж�һ�����Ƿ���һ��������ڲ���߽�
static bool IsPointInPolygon(const Point& pt, const Polygon& poly)
{
    if (isPointOnPolygonEdge(pt, poly))
    {
        return true;
    }
    int i, j;
    bool c = false;
    for (i = 0, j = poly.size() - 1; i < poly.size(); j = i++)
    {
        if ((((poly[i].y <= pt.y) && (pt.y < poly[j].y)) ||
            ((poly[j].y <= pt.y) && (pt.y < poly[i].y)))
            && (pt.x < (poly[j].x - poly[i].x) * (pt.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x))
        {
            c = !c;
        }
    }
    return c;
}
// �ж�һ�����Ƿ��ڶ���α߽���
static bool isPointOnPolygonEdge(const Point & pt, const Polygon & poly)
{
    for (int i = 0; i < poly.size(); ++i)
    {
        if (IsPointOnSegment(pt, poly[i], poly[(i + 1) % poly.size()]))
        {
            return true;
        }
    }
    return false;
}
// �жϵ��Ƿ������߶��ڣ����������߶εĶ˵���Ҳ����true
static bool IsPointOnSegment(const Point& p, const Point& p1, const Point& p2)
{
    if ((p1.x - p.x) * (p2.y - p.y) - (p2.x - p.x) * (p1.y - p.y) != 0)
    {
        return false; 

��1`   }
    if (((p.x > p1.x) && (p.x > p2.x)) || ((p.x < p1.x) && (p.x < p2.x)))
    {
        return false;
    }
    if (((p.y > p1.y) && (p.y > p2.y)) || ((p.y < p1.y) && (p.y < p2.y)))
    {
        return false;
    }
    return true;
};