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
	//	writeFile.write(arr, 5); //문자열, 길이
	//	writeFile << "형주" << endl;
	//	writeFile << "바보";
	//}

	string str;
	/*for (int i = 0; i < 5; i++)
	{
		cin >> str;
		writeFile << str << endl;
	}*/



	//파일 읽기
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