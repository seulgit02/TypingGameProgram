#include "taja.h"

////////////////////////////한컴 타자연습 필수 기능 구현 파트///////////////////////////////////////////


void make_file() {
    //낱말 파일 생성
    fstream file_1("words.txt", ios::out);
    file_1 << "Greenapple\n" << "Banana\n" << "Watermelon\n" << "Peach\n" << "Orange\n"
        << "Strawberry\n" << "Mango\n";
    file_1.close();

    //짧은글 파일 생성
    fstream file_2("short.txt", ios::out);
    file_2 << "세살 버릇 여든까지 간다.\n"
        << "지혜는 듣는 데서 오고 후회는 말하는 데서 온다.\n"
        << "하루에 3시간을 걸으면 7년 후에 지구를 한바퀴 돌 수 있다.\n"
        << "삶이 있는 한 희망은 있다.\n";
    file_2.close();

    //긴글 파일 생성
    fstream file_3("long.txt", ios::out);
    file_3 << "동해 물과 백두산이 마르고 닳도록 하느님이 보우하사 우리나라 만세.\n무궁화 삼천리 화려 강산 대한 사람, 대한으로 길이 보전하세.\n남산 위에 저 소나무, 철갑을 두른 듯 바람 서리 불변함은 우리 기상일세.\n무궁화 삼천리 화려 강산 대한 사람, 대한으로 길이 보전하세.\n";
    file_3.close();
}

#pragma once
void printStartOption() {
    cout << "     즐거운 타자 연습 프로그램~*^^*" << endl;
    cout << "----------------------------------------" << endl;
    cout << "|          <<옵션을 선택하세요>>        |" << endl;
    cout << "|       1. 게임 시작(낱말/짧은글/긴글)  |" << endl;
    cout << "|       2. 데이터 추가/수정/삭제        |" << endl;
    cout << "|        3. 프로그램 종료(ㅠ_ㅠ)        |" << endl;
    cout << "|                                       |" << endl;
    cout << "----------------------------------------" << endl;
}

void printGameOption() {
    cout << "     즐거운 타자 연습 프로그램~*^^*" << endl << endl;
    cout << "----------------------------------------" << endl;
    cout << "|      <<옵션을 선택하세요>>            |" << endl;
    cout << "|       1. 낱말 게임 시작               |" << endl;
    cout << "|       2. 짧은글 게임 시작             |" << endl;
    cout << "|       3. 긴 글 게임 시작              |" << endl;
    cout << "----------------------------------------" << endl;
}

void dataOption() {
    cout << "     즐거운 타자 연습 프로그램~*^^*" << endl << endl;
    cout << "----------------------------------------" << endl;
    cout << "|      <<옵션을 선택하세요>>            |" << endl;
    cout << "|       1. 데이터 추가                  |" << endl;
    cout << "|       2. 데이터 수정                  |" << endl;
    cout << "|       3. 데이터 삭제                  |" << endl;
    cout << "----------------------------------------" << endl;
}

void addOption() {
    cout << "     즐거운 타자 연습 프로그램~*^^*" << endl << endl;
    cout << "----------------------------------------" << endl;
    cout << "|      <<옵션을 선택하세요>>            |" << endl;
    cout << "|       1. 낱말 데이터 추가             |" << endl;
    cout << "|       2. 짧은글 데이터 추가           |" << endl;
    cout << "|       3. 긴 글 데이터 추가            |" << endl;
    cout << "----------------------------------------" << endl;
}

void eraseOption() {
    cout << "     즐거운 타자 연습 프로그램~*^^*" << endl << endl;
    cout << "----------------------------------------" << endl;
    cout << "|      <<옵션을 선택하세요>>            |" << endl;
    cout << "|       1. 낱말 데이터 삭제             |" << endl;
    cout << "|       2. 짧은글 데이터 삭제           |" << endl;
    cout << "|       3. 긴 글 데이터 삭제            |" << endl;
    cout << "----------------------------------------" << endl;
}

void changeOption() {
    cout << "     즐거운 타자 연습 프로그램~*^^*" << endl << endl;
    cout << "----------------------------------------" << endl;
    cout << "|      <<옵션을 선택하세요>>            |" << endl;
    cout << "|       1. 낱말 데이터 수정             |" << endl;
    cout << "|       2. 짧은글 데이터 수정           |" << endl;
    cout << "|       3. 긴 글 데이터 수정            |" << endl;
    cout << "----------------------------------------" << endl;
}

void logOut() {
    cout << "     즐거운 타자 연습 프로그램~*^^*" << endl << endl;
    cout << "----------------------------------------" << endl;
    cout << "|     프로그램을 종료합니다.           |" << endl;
    cout << "|       See                            |" << endl;
    cout << "|       you                            |" << endl;
    cout << "|       Later~!                        |" << endl;
    cout << "----------------------------------------" << endl;
}

//사용자 옵션 입력
int option_input() {
    cout << "옵션 입력) ";
    int option;
    cin >> option;
    return option;
}

//파일에 적힌 전체 문자수 카운트해서 반환->진행도 구할 때 사용(오류 해결 안됨. 한글의 글자 수가 하나에 +2씩 됨.)
int count_char(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Unable to open file" << endl;
        exit(1);
    }

    int count = 0;

    string sentence;
    while (getline(file, sentence)) {
        count += sentence.length();
    }
    return count;
}


// 사용자로부터 문자열 입력을 받는 함수
string getUserInput() {
    string input;
    getline(cin, input);
    return input;
}

//data 추가 함수
void add_data(const string& filename) {//단어 추가
    ofstream f(filename, ios::app);//ios::app 파일에 덧붙이기
    if (!f) {
        cout << "Unable to open file" << endl;
        exit(1);
    }
    string word[100];
    int count;
    cout << "추가할 data 개수는? >>";
    cin >> count;
    cin.ignore();//이전 입력된 개행문자 무시
    for (int i = 0; i < count; i++) {
        cout << i + 1 << "번째 추가 data: ";
        getline(cin, word[i]);
        f << word[i] << endl;//파일에 사용자 입력 쓰기
    }
    cout << "사용자 입력 추가 완료" << endl;
    f.close();
    Sleep(1000);
    system("cls");
}

vector<string>userinput;//사용자 입력 문장 저장하는 vector
vector<string>sentences;//원본 문장 저장하는 vector

//파일 데이터 삭제 함수(파일 데이터 -> 벡터로 복사 -> (수정 작업) -> 파일로복사)
void erase_data(const string& filename) {
    sentences.clear();//vector 비우기
    string line;
    ifstream file(filename);

    //해당 파일의 데이터 전체를 벡터에 복사
    if (!file) {
        cout << "Unable to open file" << endl;
        exit(1);
    }
    while (getline(file, line)) {
        sentences.push_back(line);

    }

    file.close();

    int op;
    cout << "삭제할 데이터 번호를 입력하세요>> ";
    cin >> op;
    if (op >= 1 && op <= sentences.size()) {
        sentences.erase(sentences.begin() + (op - 1));
        cout << "\n해당 번호 데이터 삭제가 완료되었습니다.\n\n";


        //파일에 삭제된 값 다시 쓰기
        ofstream file_2(filename);//ofstream 파일 쓰기 모드
        for (const string& sentence : sentences) {//vector에 있는 문장들 모두 파일로 복사
            file_2 << sentence << endl;
        }

        //파일 닫기
        file_2.close();

    }
    else cout << "인덱스 번호가 유효하지 않습니다. 삭제 불가합니다.\n";//유효하지 않은 인덱스 범위
    Sleep(1000);
    system("cls");
}


//파일 데이터 수정함수
void change_data(const string& filename) {
    sentences.clear();//vector 비우기
    string line;
    ifstream file(filename);
    if (!file) {
        cout << "파일을 열 수 없습니다." << endl;
        exit(1);
    }
    //파일에 있는 데이터 벡터로 모조리 복사
    while (getline(file, line)) {
        sentences.push_back(line);
    }
    file.close();

    //사용자에게 수정할 데이터 번호 입력받기
    int op;
    string change;
    cout << "수정할 데이터 번호를 입력하세요>> ";
    cin >> op;
    cin.ignore(); // 입력 버퍼에 남아 있는 개행 문자 무시
    cout << "수정할 내용을 입력하세요>> ";
    getline(cin, change);


    if (op >= 1 && op <= sentences.size()) {
        sentences[op - 1] = change;
        cout << "\n해당 번호 데이터 변경이 완료되었습니다.\n\n";

        //파일에 수정된 벡터 내용 복사
        ofstream file_2(filename);
        for (const string& sentence : sentences) {
            file_2 << sentence << endl;
        }
        file_2.close();
        Sleep(1500);
    }
    else {
        cout << "유효하지 않은 인덱스 번호입니다. 수정할 수 없습니다.\n";
    }
    Sleep(1000);
    system("cls");
}

//파일 내용 출력 함수(데이터 수정, 삭제할때 필요)
void printFile(const string& filename) {
    string line;
    ifstream file(filename);
    int i = 0;
    cout << "===========words.txt=================" << endl;
    while (getline(file, line)) {
        cout << i + 1 << "번째 data: " << line << endl;
        i++;
    }
    cout << "======================================" << endl << endl;
}

//파일에서의 data(단어 혹은 문장) 개수 세는 함수
int getLineNum(const string& filename) {
    ifstream file(filename);
    string line;
    int cnt = 0;
    while (getline(file, line)) {
        cnt++;
    }
    return cnt;
}

void gameStart(const string& filename) {

    cout << "\n\nEnter키를 누르면, 타자 연습 프로그램을 시작합니다." << endl;
    cin.get();

    cout << "\n------------------------------------------------------------\n" << endl;
    cout << "문장을 따라 입력하세요" << endl;

    auto start = chrono::steady_clock::now();//시작 시간

    string sentence; string line;
    ifstream file(filename);//파일 읽기 모드


    double going;
    int cnt = 0;//입력받은 data수(진행도 측정할 때 사용)
    //int wrong = 0;

    while (getline(file, line)) {
        cout << line << endl;//파일 문장 출력
        string input = getUserInput();//사용자 입력 받기

        if (input == "덧셈왕")//"덧셈왕" 키워드 입력받으면 덧셈왕 게임 실행
        {
            cout << "'덧셈왕' 키워드를 입력하셨군요. 곧 덧셈왕 게임이 시작됩니다!" << endl;
            Sleep(2000);
            addGame(); break;
        }



        userinput.push_back(input);//사용자 입력 저장하는 vector<string>

        sentences.push_back(line);//원본 문장 저장하는 vector<string>

        //int usergoing = input.length();
        cnt++;
        cout.precision(4);
        going = (double)cnt / getLineNum(filename);//진행도 계산 함수(현재까지 입력받은 data 수/전체 data 수)
        cout << "                                                                      >>  게임 진행도: " << going * 100 << "% " << endl;
    }
    auto end = chrono::steady_clock::now();//사용자 입력 종료 시간
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);


    double incorrectchars = 0;
    double correctchars = 0;

    int numSentences = min(userinput.size(), sentences.size());

    for (int i = 0; i < numSentences; i++) {
        const string& input = userinput[i];
        const string& original = sentences[i];
        int minLength = min(input.length(), original.length());
        int inputByteIndex = 0;
        int originalByteIndex = 0;

        while (inputByteIndex < input.length() && originalByteIndex < original.length()) {
            if (input[inputByteIndex] == original[originalByteIndex]) {
                correctchars++;

                // 영어 문자의 경우 1바이트로 처리되므로 다음 바이트로 이동
                if (static_cast<unsigned char>(input[inputByteIndex]) < 0x80) {
                    inputByteIndex++;
                    originalByteIndex++;
                }
                // 한글 문자의 경우 3바이트로 처리되므로 다음 2바이트를 건너뛰어야 함
                else {
                    inputByteIndex += 3;
                    originalByteIndex += 3;
                }
            }
            else {
                incorrectchars++;

                // 다음 바이트로 이동
                if (static_cast<unsigned char>(input[inputByteIndex]) < 0x80) {
                    inputByteIndex++;
                }
                else {
                    inputByteIndex += 3;
                }
            }
        }
    }


    double totalChars = correctchars + incorrectchars;
    double accuracy = 0.0;

    if (totalChars > 0) {
        accuracy = static_cast<double>(correctchars) / totalChars * 100;
    }

#
    double typingspeed = static_cast<double>((correctchars) / duration.count()) * 60 * 1000;

    cout << "\n------------------------------------------------------------\n" << endl;
    //cout << "타이핑 속도: " << typingspeed << " 타/분" << endl;
    cout << "정확도: " << accuracy << "%" << endl;
    cout << "오타 수: " << incorrectchars << endl;
    cout << "경과 시간: " << (double)duration.count() * 0.001 << "sec" << endl;//count함수 호출->해당 시간의 정수값 얻음.(단위 millisecond)->sec로 변환 위해 0.001 곱해줌.
    cout << "\n------------------------------------------------------------\n" << endl;
    Sleep(3000);
    //system("cls");

}


//////////////////////////////////////////산성비 게임 코드///////////////////////////////////////////////////////////////////////
//min~max 범위의 함수 호출
int random(int min, int max) {
    return rand() % (max - min + 1) + min;
}


void StartaddGame() {
    system("cls");
    cout << " ***머리가 좋아지는 덧셈왕 Game***" << endl;
    cout << "----------------------------------------" << endl;
    cout << "|      <<덧셈왕 게임 방식>>             |" << endl;
    cout << "|      곧 숫자비가 하늘에서 내려옵니다. |" << endl;
    cout << "|           내려오는 숫자들의           |" << endl;
    cout << "|           총 합을 암산하여            |" << endl;
    cout << "|      올바른 정답을 입력하세요!!       |" << endl;
    cout << "----------------------------------------" << endl;
}

void DyingMessage() {

    cout << endl << " ***머리가 좋아지는 덧셈왕 Game***" << endl;
    cout << "----------------------------------------" << endl;
    cout << "|                                      |" << endl;
    cout << "|                You                   |" << endl;
    cout << "|                Die                   |" << endl;
    cout << "|               .....                  |" << endl;
    cout << "|                                      |" << endl;
    cout << "----------------------------------------" << endl;
}


void addGame() {

    int level = 1;
    int answer = 0;
    int userInput;
    int randomNum;
    int life = 3;
    int arr[100];

    StartaddGame();
    Sleep(4000);
    system("cls");
    cout << "[ Level " << level << " game start!! ]" << endl;

    //레벨이 증가함에 따라 점진적으로 숫자 범위가 커지도록 설정
    for (int i = 0; i < 50; i++)
    {
        if (i < 5)
            randomNum = random(0, 5);
        else if (i < 10)
            randomNum = random(5, 10);
        else if (i < 15)
            randomNum = random(5, 20);
        else if (i < 20)
            randomNum = random(10, 20);
        else if (i < 25)
            randomNum = random(10, 30);
        else if (i < 30)
            randomNum = random(20, 30);
        else if (i < 35)
            randomNum = random(30, 40);
        else if (i < 40)
            randomNum = random(35, 50);
        else if (i < 45)
            randomNum = random(50, 70);
        else
            randomNum = random(70, 200);



        arr[i] = randomNum;
        answer += arr[i];

        // 숫자 비처럼 내려오는 출력 형식
        for (int j = 0; j < arr[i]; j++)
        {
            cout << " ";
        }
        //std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
        Sleep(1300);
        cout << arr[i] << endl;


        if ((i + 1) % 5 == 0) {
            //cout << "!!!제한시간 5초!!!" << endl;

            //thread notificationThread(showNotificationAfterDelay);
            cout << "정답 입력)) ";
            cin >> userInput;

            //스레드 종료시키고 합류하도록하는 함수
            //notificationThread.join();

            //5초 이내에 입력되었다면
            if (answer == userInput) {
                cout << "정답입니다!" << endl;
                Sleep(500);
                answer = 0;//answer값 초기화
                cout << endl << "***************************************************" << endl;
                cout << endl << "[ Level " << ++level << " game start!! ]" << endl;

            }
            else if (answer != userInput) {
                --life;
                cout << "틀렸습니다!";
                answer = 0;//answer값 초기화
                cout << "(남은 목숨 " << life << "개)" << endl;
                Sleep(800);

                if (life == 0) {
                    system("cls");
                    DyingMessage();
                    Sleep(1300);
                    break;
                }
                cout << endl << "***************************************************" << endl;
                cout << endl << "[ Level " << ++level << " game start!! ]" << endl;
            }

        }
    }
}