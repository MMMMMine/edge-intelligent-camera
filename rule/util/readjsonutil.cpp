#include "readjsonutil.h"

using namespace std;
using namespace Json;

ReadJsonUtil::ReadJsonUtil() {
	cout << "����ReadJsonUtil����" << endl;
}
ReadJsonUtil::~ReadJsonUtil()
{
	cout << "����ReadJsonUtil����" << endl;
};

//��ȡ�ļ�
 Json::Value ReadJsonUtil::Read(std::string file)
{
	// ����json��Json::Reader
	Json::Reader reader;
	// Json::Value��һ�ֺ���Ҫ�����ͣ����Դ����������͡���int, string, object, array...
	Json::Value root;

	ifstream srcFile(file, ios::binary);/*����һ��ifstream���������ļ�demo.json���й���*/

	if (!srcFile.is_open())
	{
		cout << "δ�ҵ�json�ļ����˳���" << endl;
		exit(0); //ֱ���˳�
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
//��ȡgroovycode
 string ReadJsonUtil::GetRuleLayoutCode(Json::Value root)
{
	string groovycode;

	/*��ȡ���ڵ���Ϣ*/
	string ruleLayoutCode = root["ruleLayoutCode"].asString();

	groovycode = ruleLayoutCode;

	return groovycode;

}


//��ȡ����
 vector<Params> ReadJsonUtil::GetParams(Json::Value root)
{
	vector <Params> arrayparam;

	/*��ȡ�ӽڵ���Ϣ*/
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


//����ɸѡ������ȡ���ϵ�����
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














