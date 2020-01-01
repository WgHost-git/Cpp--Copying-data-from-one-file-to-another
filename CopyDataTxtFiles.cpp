#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class FileCopy {
public:

	void copyData(string fileNameRead, string fileNameWrite);
	void logFile(string message);
	bool FileRead(string fileNameRead);
	void FileWrite(string fileNameWrite);

private:

	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);

	string fileLog = "d:\\log.txt";
	string tempString;
};

int main() {
	setlocale(LC_ALL, "ru");

	string file1, file2, fileLog;
	file1 = "d:\\test1.txt";
	file2 = "d:\\test2.txt";

	FileCopy valera;

	valera.copyData(file1, file2);

	cout << endl << endl;
	system("pause>null");
}

void FileCopy::copyData(string fileNameRead, string fileNameWrite)
{
	if (FileRead(fileNameRead))
	{
		FileWrite(fileNameWrite);
		logFile("Copy is complete");
	}
}

bool FileCopy::FileRead(string fileNameRead) 
{
	ifstream fileRead;
	string buffer;

	fileRead.open(fileNameRead);

	if (fileRead.is_open()) 
	{
		logFile("FileRead is open");

		while (!fileRead.eof()) {
			getline(fileRead, buffer);
			tempString += buffer + "\n";
		}
	}
	else 
	{
		logFile("FileRead is not open!"); // FileRead is not open
		return false;
	}

	fileRead.close();

	logFile("FileRead closed");

	return true;
}

void FileCopy::FileWrite(string fileNameWrite)
{
	ofstream fileWrite;

	fileWrite.open(fileNameWrite);

	if (fileWrite.is_open()) 
	{
		logFile("FileWrite is open");
		fileWrite << tempString;
	}
	else 
	{
		logFile("FileWrite is not open!"); // FileWrite is not open
	}

	fileWrite.close();

	logFile("FileWrite closed");
}

void FileCopy::logFile(string addMessage) 
{
	ofstream fileWrite;

	fileWrite.open(fileLog, ios_base::app);

	if (fileWrite.is_open())
	{
		fileWrite << asctime(timeinfo) << " " << addMessage << endl;
		cout << "В лог-файле создана запись!" << endl;
	}
	else 
	{
		cout << "Error! Log file is not open" << endl;
		cout << addMessage;
	}
}