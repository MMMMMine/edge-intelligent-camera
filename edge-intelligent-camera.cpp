// edge-intelligent-camera.cpp: 定义应用程序的入口点
#include "edge-intelligent-camera.h"
#include "rule/rule.h"
#include "rule/util/readjsonutil.h"

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
using namespace Json;

//******-----------------------------------------数据结构定义 begin--------------------------------------------******//

// 特征提取结果数据结构.




//******-----------------------------------------数据结构定义 End --------------------------------------------******//


//******-----------------------------------------函数申明     Begin --------------------------------------------******//

// 抓取图片函数声明.
string imageGrabber();

// 特征提取算法函数申明.


// 规则判断函数声明.

// 告警函数声明.

//******-----------------------------------------函数申明     End   --------------------------------------------******//

/**
* 启动Main函数
* 
* 
*/


int main()
{
	// 监控程序启动.
	cout << "Edge intelligent camera starting ... " << endl;

	//ReadJson rj;
	// 摄像头配置打印.
	/*Json::Value root= rj.Read("demo.json");
	cout << root << endl;*/

	ReadJsonUtil rj ;

	Json::Value root=	rj.Read("demo.json");

	cout << root << endl;
	cout << "Edge intelligent camera start completed !" << endl;

	//  循环抓取摄像头图片进行模型推理及告警.
	while (true)
	{
		 cout << "主体工程执行完成 !" << endl;
		
		 break;
	}

	cout << "Edge intelligent camera stop running !" << endl;
	return 0;
}


string imageGrabber() {
	return "iamge address.";
}