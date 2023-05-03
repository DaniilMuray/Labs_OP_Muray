//
// Created by Legion on 4/16/2023.
//

#ifndef LAB_1_MYCLASS_H
#define LAB_1_MYCLASS_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>


using namespace std;



char getLetter();

void add_text_to_file(const string& filename);
void create_file(const string& filename);
void fileName(string &filename);
void changeFile(const string& filename, const string& filename2);
void PrintFile(const string& filename);


void add_text_to_file(const char* filename);
void create_file(const char* filename);
void fileName(char* filename);
void changeFile(const char* filename, const char* filename2);
void PrintFile(const char* filename);





bool isMode(const char *modeValue, int argc, char *argv[]);

#endif //LAB_1_MYCLASS_H
