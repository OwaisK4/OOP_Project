#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string line);

//int main(){
//	ifstream file("read.txt");
////	string lines[10];
//	string lines;
//	int i = 0;
////	while (getline(file, lines[i])){
////		cout << lines[i] << endl;
//	while (getline(file, lines)){
//		cout << lines << endl;
//		i++;
//	}
//	vector<string> words = split(lines);
//	for (i=0; i < words.size(); i++){
//		cout << words[i] << endl;
//	}
//	return 0;
//}

vector<string> split(string line){
	stringstream word_stream(line);
	string word;
	vector<string> split_words;
	while (getline(word_stream, word, '\t')){
		split_words.push_back(word);
	}
	return split_words;
}
//	char* word = strtok(lines, '\t');
//	while (word != NULL){
//		cout << word << ", ";
//		word = strtok(lines, NULL);
//	}

//	stringstream word_stream(lines);
//	string word;
//	while (getline(word_stream, word, '\t')){
//		cout << word << ", ";
//	}
