#include "readjsonutil.h"

using namespace std;
using namespace Json;

ReadJsonUtil::ReadJsonUtil() {
	cout << "建立ReadJsonUtil对象" << endl;
}
ReadJsonUtil::~ReadJsonUtil()
{
	cout << "销毁ReadJsonUtil对象" << endl;
};

//读取文件
 Json::Value ReadJsonUtil::Read(std::string file)
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

 void ReadJsonUtil:: testRead(std::string s) {
	 cout << " s" << endl;

 };
//获取groovycode
 string ReadJsonUtil::GetRuleLayoutCode(Json::Value root)
{
	string groovycode;

	/*读取根节点信息*/
	string ruleLayoutCode = root["ruleLayoutCode"].asString();

	groovycode = ruleLayoutCode;

	return groovycode;

}


//获取参数
 vector<Params> ReadJsonUtil::GetParams(Json::Value root)
{
	vector <Params> arrayparam;

	/*读取子节点信息*/
	for (int i = 0; i < root["params"].size(); i++)
	{
		Params inparams;
		inparams.socre = root["params"][i]["socre"].asDouble();
		inparams.rate = root["params"][i]["rate"].asDouble();

		int a[4];
		for (int j = 0; j < 4; j++) {
			a[j] = root["params"][i]["location"][j].asInt();
		}
		memcpy(inparams.location, a, sizeof(inparams.location)); // <=> a2 = a1
		//cout <<  root["params"][i]["location"] << endl;

		inparams.label = root["params"][i]["label"].asString();

		arrayparam.push_back(inparams);
	}
	return arrayparam;

}


//根据筛选条件获取符合的数组
 vector <Params> ReadJsonUtil::GetLabelInfo(Json::Value root, std::string label, double socre)
{
	vector <Params> params;
	vector <Params> person;

	params = GetParams(root);

	for (auto it = begin(params); it != end(params); ++it)
		if (label.compare(it->label) == 0 && (it->socre) > socre)
		{
			person.push_back(*it);
		}
	return person;
};














