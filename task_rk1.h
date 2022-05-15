//
// Created by 4739361 on 15.05.2022.
//

#ifndef RK__TASK_RK1_H
#define RK__TASK_RK1_H
#include <fstream>
#include <iterator>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <tuple>

using namespace std;

//task 2
void convertDecToBin(int number);
void WriteToFile (const char &FileName, const char* strNum);

//task 3
void convertBinToHex(const char* bin);
void WriteToFile3 (const char &FileName, const char* strNum);

//task6
struct Node
{
    Node* next;
    Node* prev;
    int nameNode;
    Node(){};
};
class LinkedList {
private:
    Node *Head;
    Node *Tail;
    int countNodes=0;
public:

    LinkedList() {
        Head = nullptr;
        Tail = nullptr;
    }

    ~LinkedList() {
        while (Head != nullptr) {
            Tail = Head->next;
            delete Head;
            Head = Tail;
        }
    }
    void push_back(int nameNode);
    void writeToFileFromHead();
    void WriteFileFromTail();
    //task7
    void insert(int nameNode, int position);
};
//task8
class StudentInfo {
private:
    tuple<string, string, char *> info;
    map<string, pair<list < int>, float >> subjMark;
public:
    StudentInfo();

    ~StudentInfo();

    int addMark(const string &subjName, int mark);
    int addSubj(const string &subjName);
    float getAverMark(const string &subjName);
    void printInfoStudent();
    void writeAllInfoToFile();
};
#endif //RK__TASK_RK1_H
