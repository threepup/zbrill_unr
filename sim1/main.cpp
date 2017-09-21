#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

#include "configList.h"
#include "metaQueue.h"

using namespace std;

int main(int argc, char* argv[])
{
	configList userFile;
	metaQueue taskList;
	string lineRead;
	string token;
	int tempNum;
	string metaFile;
	string tempStr;
	bool logToBoth = false;
	string logFile;
	char tempChar;
	
	//check for CLA
	if(argc != 2)
		cout << "Invalid arguments" << endl;
	
	//open file
	ifstream fin;
	fin.open(argv[1]);

	if(fin)
	{
		getline(fin, lineRead);
		token = lineRead.substr(0, lineRead.find(' '));
		if(token != "Start"){
			cout << "invalid file" << endl;
			return 0;
		}
		
		//discard version number
		getline(fin, lineRead);

		//get meta file
		getline(fin, lineRead);
		if(lineRead.find(':') == string::npos){
			cout << "invalid file" << endl;
			return 0;
		}
		token = lineRead.substr(lineRead.find(':')+2, 'f');
		metaFile = token;
		
		//read the configuration		
		for(int i = 0; i < 8; i++){
			getline(fin, lineRead);
			tempStr = lineRead.substr(0, lineRead.find(' '));
			token = lineRead.substr(lineRead.find(':')+2, '\n');
			tempNum = std::stoi(token);
			userFile.addNode(tempStr, tempNum, NULL); 	
			
		}

		//check for logs
		getline(fin, lineRead);
		token = lineRead.substr(lineRead.find(':')+2, 'h');
		if(token == "Log to Both"){
			logToBoth = true;
			getline(fin, lineRead);
			logFile = lineRead.substr(lineRead.find(':')+2, 't');
		}

		fin.close();
	}
	else
		cout << "Fail to open file" << endl;

	cout << "moving to metafile" << endl;
	fin.open(metaFile);

	if(!fin){
		cout << "invalid metafile" << endl;
		return 0;
	}

	//read metafile

	//discard start line
	getline(fin, lineRead);

	while(true){

		getline (fin, lineRead);
		if(lineRead.find('.') == string::npos){
			token = lineRead.substr(0, lineRead.find(';'));
			tempStr = lineRead.substr(lineRead.find(';')+2);
			for(int i = 0; i < count(lineRead.begin(), lineRead.end(), ';'); i++){
				//get the key
				tempChar = token.at(0);
				//get the value
				tempNum = stoi(token.substr(token.find(')')+1));
				//get the process
				token = token.substr(token.find('(')+1, token.find(')')-2);
				taskList.enqueue(tempChar, token, tempNum);
				//move down the line
				token = tempStr.substr(0, tempStr.find(';'));
				if(count(tempStr.begin(), tempStr.end(), ';') > 1){
					tempStr = tempStr.substr(tempStr.find(';')+2);
				}
			}
				
		}

		else{
			token = lineRead.substr(0, lineRead.find(';'));
			tempStr = lineRead.substr(lineRead.find(';')+2);
			for(int i = 0; i < count(lineRead.begin(), lineRead.end(), ';'); i++){
				//get the key
				tempChar = token.at(0);
				//get the value
				tempNum = stoi(token.substr(token.find(')')+1));
				//get the process
				token = token.substr(token.find('(')+1, token.find(')')-2);
				taskList.enqueue(tempChar, token, tempNum);
				//move down the line
				token = tempStr.substr(0, tempStr.find(';'));
				if(count(tempStr.begin(), tempStr.end(), ';') > 1){
					tempStr = tempStr.substr(tempStr.find(';')+2);
				}	
			
			}
			//grab the last segment
			tempChar = token.at(0);
			tempNum = stoi(token.substr(token.find(')') +1));
			token = token.substr(token.find('(')+1, token.find(')')-2);
			taskList.enqueue(tempChar, token, tempNum);
			break;
		}
	}	

	//simulation time
	//INCOMPLETE
	while(!taskList.isEmpty()){
		
	}	
	
	return 0;
}
