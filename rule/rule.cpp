#include "rule.h"
using namespace std;
using namespace Json;



Rule :: Rule() {
    cout << "创建Rule对象" << endl;
}

Rule::~Rule() {
    cout << "销毁rule对象" << endl;
}

//读取文件
Json::Value Rule :: Read(std :: string file)
{
	// 解析json用Json::Reader
	Json::Reader reader;
	// Json::Value是一种很重要的类型，可以代表任意类型。如int, string, object, array...
	Json::Value root;

	ifstream srcFile(file, ios::binary);/*定义一个ifstream流对象，与文件demo.json进行关联*/

	if (!srcFile.is_open())
	{
		cout << "未找到json文件，退出！" << endl;
		exit(0); //直接退出
	}
	if (reader.parse(srcFile, root))
	{
		return root;
	}
	return root;
}