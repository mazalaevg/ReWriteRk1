#include "task_rk1.h"



//task_2
char binNumb[128];
void convertDecToBin(int number)
{
    memset(binNumb, 0x00, 32 * sizeof(int));
    for (int i = 0; i < 32; i++) {
        binNumb[32 - i - 1] = ((number & (1 << i))) ? 0x31 : 0x30;
    }
    cout<< binNumb;

}
void WriteToFile (const char &FileName, const char* strNum)
{
    FILE *f1;
    f1 = fopen(&FileName, "w");

    for (int i = 127; i >= 0; i--) {

        fprintf(f1, "%c", strNum[i]);
    }
    fclose(f1);
}

//tas3
void convertBinToHex(const char* bin) {
    const char* inp = bin;
    int length = strlen(inp);
    int temp = 0;
    for (int i = 0; i < length; i++)
    {
        if (bin[i] == 0x31)
            temp++;
        if (i != length - 1)
            temp = temp << 1;
    }
    cout<< temp;
}
void WriteToFile3 (const char &FileName, const char* strNum)
{
    FILE *f1;
    f1 = fopen(&FileName, "w");

    for (int i = 31; i >= 0; i--) {

        fprintf(f1, "%c", strNum[i]);
    }
    fclose(f1);
}
//task6
void LinkedList::push_back(int nameNode)  {
    Node *node = new Node;
    node->nameNode = nameNode;
    node->next = nullptr;
    if (Head == nullptr) {
        node->prev = nullptr;
        Head = node;
        Tail = node;
    } else {
        node->prev = Tail;
        Tail->next = node;
        Tail = node;
    }
}

void LinkedList::writeToFileFromHead(){
    Node *p = Head;
    FILE *f;
    if (Head == NULL) {
        cout << "Список пуст!" << endl;
    } else {
        fopen_s(&f, "task6.txt", "wb");
        if (f != NULL) {
            while (p != NULL) {
                fwrite(p, sizeof(Node), 1, f);
                p = p->next;
            }
            cout << "Данные сохранены " << endl;
            fclose(f);
        } else
            cout << "\n" << "\tНе удалось создать файл " << endl;
    }
}
void LinkedList::WriteFileFromTail() {
    Node *p = Tail;
    FILE *f;
    if (Tail == NULL) {
        cout << "Список пуст!" << endl;
    } else {
        fopen_s(&f, "task6.txt", "wb");
        if (f != NULL) {
            while (p != NULL) {
                fwrite(p, sizeof(Node), 1, f);
                p = p->prev;
            }
            cout << "Данные сохранены " << endl;
            fclose(f);
        } else
            cout << "\n" << "\tНе удалось создать файл " << endl;
    }
}
//task7
void LinkedList::insert(int nameNode, int position) {
    if(position>LinkedList::countNodes+1 || position<1){
        return;
    }
    else {
        if(position==1){
            Node *temp = new Node;
            Node *tempHead = Head;
            tempHead->prev=temp;
            temp->next=tempHead;
            temp->prev= nullptr;
            Head=temp;
        }
        else {
            if(position==LinkedList::countNodes+1){
                Node *temp = new Node;
                Node *tempTail = Tail;
                tempTail->next=temp;
                temp->next= nullptr;
                temp->prev=tempTail;
                Tail=temp;
            }
            else {
                Node *temp = new Node;
                Node *tempHead = Head;
                for (int i = 1; i < position - 1; i++) {
                    tempHead = tempHead->next;
                }
                temp->next = tempHead->next;
                tempHead->next->prev = temp;
                tempHead->next = temp;
                temp->prev = tempHead;
                position++;
            }
        }
    }
}




//task8

int StudentInfo::addMark(const string &subjName, int mark) {
    int temp = 0;
    map<string, pair<list<int>, float>>::iterator it = subjMark.begin();
    while (it != subjMark.end()) {
        it++;
        if (it->first == subjName) {
            temp++;
            it->second.first.push_back(mark);
            float size = it->second.first.size();
            float sum = 0;
            for (int i = 0; i < size; i++) {
                sum += mark;
            }
            sum /= size;
            it->second.second = sum;
            cout << " Mark added " << endl;
        }
    }
    if (temp == 0) { return 1; }
}

int StudentInfo::addSubj(const string &subjName) {
    for (map<string, pair<list<int>, float>>::iterator it = subjMark.begin(); it != subjMark.end(); it++) {
        if (it->first == subjName) {
            return 1;
            break;
        }
    }
    pair<list<int>, float> MYPAIR;
    subjMark[subjName]=MYPAIR;
    return 0;
}

float StudentInfo::getAverMark(const string &subjName) {
    for (map<string, pair<list<int>, float>>::iterator iter = subjMark.begin(); iter != subjMark.end(); iter++) {
        if (iter->first == subjName) {
            return iter->second.second;
        }
    }
}

void StudentInfo::printInfoStudent() {
    string surname = get<0>(info);
    string name = get<1>(info);
    string number = get<2>(info);
    map<string, pair<list<int>, float>>::iterator it = subjMark.begin();
    while (it != subjMark.end()) {
        it++;
        string ss = it->first;
        for (int count: it->second.first) {
            cout << "\t" << count;
        }
        getAverMark(it->first);
        cout << "\t" << " average - " << it->second.second;
    }
}

void StudentInfo::writeAllInfoToFile() {
    ofstream fout;
    fout.open("resultTask8.txt");
    if (!fout.is_open()) {
        fout << "Error! " << endl;
    } else {

        fout << get<0>(info) << "\t" << get<1>(info) << " " << ":" << " " << get<2>(info) << endl;
        for (map<string, pair<list<int>, float>>::iterator it = subjMark.begin(); it != subjMark.end(); it++) {
            fout << it->first << " " << ":" << " ";
            for (int count: it->second.first) {
                fout << count << " , ";
            }
            fout << "=====" << it->second.second << endl;
        }
    }
    fout.close();
}
