#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include "string"
#define UP 72
#define DOWN 80
#define TEXTLEN 512
#pragma comment(lib, "winmm.lib")
using namespace std;

/* ���� �� ���� */
void textcolor(int color_number) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

/*�ѱ� �迭*/
char texts[][TEXTLEN] = { "�ȳ��ϼ���", "������Ʈ ��", "��ûȭ����" };
const int size = sizeof(texts) / sizeof(texts[0]); 

int gettext(char *str)
{
	gets(str); //Ű���� �Է��� ����
	int len = (int)strlen(str); //�Է¹��� ���ڼ��� Ȯ��
	int onebyte = 0;
	int twobyte = 0;

	for (int i = 0; i<len; i++) //for���� ����Ͽ� ī��Ʈ�� ��
	{
		if (str[i] < 0) twobyte++;  // 2����Ʈ �ѱ�
		else onebyte++;           // 1����Ʈ ����
	}

	return onebyte + (twobyte / 2);
}

void run() {
	char user[TEXTLEN];
	int sum = 0; //���ϱ�
	double sum2 = 0; // ǥ������
	int diff; //ǥ������ ���ϱ�
	int avg;
	int arr[size] = { 0 }; //ǥ�� ������ ���� ��� Ÿ�� ����

	//������ ������ texts�� �迭�� for���� �̿�
	for (int i = 0; i < size; i++) {
		int taja_count = 0; //�Է��� Ÿ�ڼ��� ����

		printf("%s\n", texts[i]); //texts �迭�� ����� ���� ���

		unsigned int time = timeGetTime(); //���� �ð��� time�� ����
		taja_count = gettext(user); //����� �Է� �� count�� ������
		time = timeGetTime() - time; //������ �ð����� ���� �ð��� ��

		if (taja_count == 0) break; //count�� 0�̸� ����

		float n = (float)60 / (time / 1000); //���۽ð��� �̿� 1�� ������ ���
		arr[i] = (int)n * taja_count; //�ð����� �Է��� Ÿ�ڼ��� ����
		sum += arr[i];

		printf("Ÿ�� �ӵ��� ��� %dŸ\n", arr[i]);
	}

	avg = sum / size; //����� ����

	for (int i = 0; i < size; i++) {
		diff = arr[i] - avg;
		sum2 += diff * diff;
	}

	//���� ���
	printf("����: ��� Ÿ���� %dŸ, ǥ�� ���� %d\n", avg, (int)sqrt(sum2 / (size - 1)));
}
int han(){
	run(); //���α׷��� ����
	getchar();
	return 0;
}
int main(){
	string Menu[3] = { "Game Start", "How to play", "Exit" };
	int pointer = 0;
	while (true){
	system("mode con cols=115 lines=30");
	cout << endl; cout << endl; cout << endl; cout << endl;
	textcolor(15);
	cout << "	�ѱ۷� �ϴ�" << endl;	
	textcolor(12);
	cout << "	��      ��   ����   ��       ��       ����    �����   ����   ��       ��       ����" << endl;
	textcolor(4);
	cout << "	��      ��   ��  ��   ��       ��         ��      ��         ��  ��   ��       ��         �� " << endl;
	
	textcolor(14);
	cout << "	������   ����   ��       ��         ��      ��  ���   ����   ��       ��         ��" << endl;
	textcolor(10);
	cout << "	��      ��   ��  ��   ��       ��         ��      ��    ��   ��  ��   ��       ��         ��" << endl;
	
	textcolor(2);
	cout << "	��      ��   ��  ��   ����   ����   ����    �����   ��  ��   ����   ����   ����" << endl;
	cout << endl; cout << endl;	cout << endl; cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	  cout << "						--     Menu     --" << endl;
		cout << endl;
		for (int i = 0; i < 3; ++i){
			if (i == pointer){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << "						" << Menu[i] << endl;
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "						" << Menu[i] << endl;

			}
		}
		while (true){
			if (GetAsyncKeyState(VK_UP) != 0){
				pointer -= 1;
				if (pointer == -1){
					pointer = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0){
				pointer += 1;
				if (pointer == 3){
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0){
				switch (pointer)
				{
				case 0:
				{
						  system("cls");
						  han();
						 
				} 	break;
				case 1:
				{
						  cout << "how";
						
				} break;
				case 2:
				{
						  return 0;
				}
					break;
				}
			}
		}
		Sleep(150);

	}
	return 0;
}