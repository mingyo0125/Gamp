#include<iostream>
#include<fstream>
#include <string>
using namespace std;

int main()
{
	std::ofstream writeFile;
	writeFile.open("text.txt");


	//char arr[5] = "Ahan";

	//if (writeFile.is_open())
	//{
	//	writeFile.write(arr, 5); //���ڿ�, ����
	//	writeFile << "����" << endl;
	//	writeFile << "�ٺ�";
	//}

	string str;
	/*for (int i = 0; i < 5; i++)
	{
		cin >> str;
		writeFile << str << endl;
	}*/



	//���� �б�
	ifstream readFile("text.txt");

	//while (!readFile.eof())  //end of file
	//{
	//	cout << readFile.get() << endl;
	//}
	
	//while (getline(readFile, str)) //stringdml getline
	//{
	//	cout << str << endl;
	//}


	char buf[1024];
	while (!readFile.eof())
	{
		readFile.getline(buf, 20);
		cout << buf << endl;
	}
	


	writeFile.close();
}