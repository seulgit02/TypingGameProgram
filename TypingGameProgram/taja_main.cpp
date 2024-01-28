#include "taja.h"

int main(void)
{
    srand(time(NULL));
    //파일 생성
    make_file();


    while (true) {
        //system("cls");
        printStartOption();

        switch (option_input())
        {

        case 1:
            system("cls"); printGameOption();

            switch (option_input()) {
            case 1: system("cls"); gameStart("words.txt"); break;
            case 2:system("cls"); gameStart("short.txt"); break;
            case 3:system("cls"); gameStart("long.txt"); break;
            default:"올바른 옵션을 입력하세요.\n"; break;
            }
            break;


        case 2:
            system("cls"); dataOption();//추가, 수정, 삭제
            switch (option_input())
            {
            case 1://데이터 추가
                system("cls"); addOption();//단어, 짧은 글, 긴 글
                switch (option_input())
                {
                case 1: system("cls"); add_data("words.txt"); break;
                case 2: system("cls"); add_data("short.txt"); break;
                case 3: system("cls"); add_data("long.txt"); break;
                }
                break;

            case 2://데이터 수정 
                system("cls"); changeOption();//단어, 짧은 글, 긴 글
                switch (option_input())
                {
                case 1: system("cls"); printFile("words.txt"); change_data("words.txt"); break;
                case 2:system("cls"); printFile("short.txt"); change_data("short.txt"); break;
                case 3:system("cls"); printFile("long.txt"); change_data("short.txt"); break;
                default: cout << "잘못된 옵션을 입력하셨습니다.\n"; break;
                }
                break;

            case 3://데이터 삭제 
                system("cls"); eraseOption();//단어, 짧은 글, 긴 글
                switch (option_input()) {
                case 1: system("cls"); printFile("words.txt"); erase_data("words.txt"); break;
                case 2: system("cls"); printFile("short.txt"); erase_data("short.txt"); break;
                case 3: system("cls"); printFile("long.txt"); erase_data("long.txt"); break;
                default: cout << "잘못된 옵션을 입력하셨습니다.\n"; break;
                }
                break;
            }
            break;

        case 3:
            system("cls");
            logOut();
            exit(1);




        }
    }//while문 괄호


    return 0;
}