#include "rule.h"
using namespace std;
using namespace Json;



Rule :: Rule() {
    cout << "����Rule����" << endl;
}

Rule::~Rule() {
    cout << "����rule����" << endl;
}

//��ȡ�ļ�
Json::Value Rule :: Read(std :: string file)
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