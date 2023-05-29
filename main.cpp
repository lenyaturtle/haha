

#include "TXLib.h"
struct Forma
{
    string text_question;
    int r_a;
    HDC pic_answer1;
    string text_answer1;
    HDC pic_answer2;
    string text_answer2;
    HDC pic_answer3;
    string text_answer3;
};
void drawAnswer(int x, HDC pic_answer, string text_answer)
{
    txSelectFont("Times New Roman", 40);
    txSetColor (TX_WHITE, 7);
    txRectangle (x, 320, x+200, 470);
    txBitBlt(txDC(), x, 320, 200, 150, pic_answer);
    txDrawText  (x, 535, x+200, 580, text_answer.c_str());
};

bool clickAnswer(int x)
{
    return(txMouseButtons()==1 && txMouseX()>x && txMouseX()<x+200 && txMouseY()>320 && txMouseY()<470);
};

int main()
{
txCreateWindow (800, 600);

    Forma quest_buf;
    Forma quest[20];
    int n_question = 1;
    int kol_right_answer = 0;
    char stroka[50];

    quest[0] = {"Откуда упал(а) главный(ая)герой(иня)\n"
    "в начале игры?", 1,
                    txLoadImage("Kartinka/гора.bmp"), "гора",
                    txLoadImage("Kartinka/дорога.bmp"), "дорога",
                    txLoadImage("Kartinka/ядро.bmp"), "ядро"};

    quest[1] = {"Кто главный герой?", 1,
                    txLoadImage("Kartinka/фриск.bmp"), "фриск",
                    txLoadImage("Kartinka/чара.bmp"), "чара",
                    txLoadImage("Kartinka/санс.bmp"), "санс"};

    quest[2] = {"Первый босс?", 3,
                    txLoadImage("Kartinka/андайн.bmp"), "андуха",
                    txLoadImage("Kartinka/метта.bmp"), "метта",
                    txLoadImage("Kartinka/ториэль.bmp"), "торька"};

    int kol_question = 3;

    while(n_question <= kol_question)
    {
        txSetColor (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txClear();
        txBegin();

        quest_buf = quest[n_question - 1];

        txSetColor (TX_WHITE);
        txSetFillColor (TX_TRANSPARENT);
        txRectangle (10, 10, 790, 590);

        char str[50];
        sprintf(str, "Вопрос %d/%d", n_question, kol_question);
        txDrawText(0, 20, 800, 50, str);

        txSelectFont("Times New Roman", 40);
        txDrawText(0, 100, 800, 200, quest_buf.text_question.c_str());

        txRectangle(35,535,235,578);
        txRectangle(270,535,470,578);
        txRectangle(510,535,710,578);

        drawAnswer( 35, quest_buf.pic_answer1, quest_buf.text_answer1);
        drawAnswer(265, quest_buf.pic_answer2, quest_buf.text_answer2);
        drawAnswer(510, quest_buf.pic_answer3, quest_buf.text_answer3);

        if( txMouseButtons() == 1 &&
            txMouseX() > 35 && txMouseX() < 235 &&
            txMouseY() > 535 && txMouseY() < 578)
        {
            if(quest_buf.r_a == 1) kol_right_answer++;
            txSleep(200);
            n_question++;
        }

        if( txMouseButtons() == 1 &&
            txMouseX() > 270 && txMouseX() < 470 &&
            txMouseY() > 535 && txMouseY() < 578)
        {
            if(quest_buf.r_a == 2) kol_right_answer++;
            txSleep(200);
            n_question++;
        }

        if( txMouseButtons() == 1 &&
            txMouseX() > 510 && txMouseX() < 710 &&
            txMouseY() > 535 && txMouseY() < 578)
        {
            if(quest_buf.r_a == 3) kol_right_answer++;
            txSleep(200);
            n_question++;
        }
        txEnd();
        txSleep(20);
    }

    txSetColor (TX_WHITE);
    txSetFillColor (TX_BLACK);
    txClear();
    txDrawText(0, 0, 800, 600, "Результаты");

    sprintf(stroka, "Количество правильных ответов - %d", kol_right_answer);
    txDrawText(0, 20, 800, 50, stroka);






    txTextCursor (false);
    return 0;
    }

