#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include "Graphic_Nazari.h"
#include <time.h>
#include <math.h>
using namespace std;

#define colorbox 0xffffff
#define ctbox 0x0

	int login(char an[], char ap[]);
	int pos(int a);
	void box(char text[], int x, int y);
	int tach(char t[], int x, int y);
	void keybord(char *a);
	int listfirst();
	int Login_to_account();
	int Guest_Login();
	void reverse(char ary[]);
	void error(char file_name[]);
	void cbox(char text[], int x, int y, int color);
	int buy_tickets(int *mabdae, int *maghsad, int *vasile);
	int page(char *a);
	void sabt();
	void schange();
	int tashkhis(char ac_id[], char ac_pas[]);
	int Define_travel(char origin[], char destination[], char vehicle[], char time[], char date[]);
	int chang_trips(int number_trips,char time[], char date[]);
	int character_to_integer(char str[]);
	void integr_to_character(int num, char str[]);
	int palindor(int num);
	void sabt2();
	int getmm(char origin_str[], char destination_str[], char vehicle[]);
	int show_trips(char f_name_t[], int number_trips, int origin, int destination, char time[], char date[], char vehicle[], int price);
	int buy_ticket(char f_name_t[], int number_trips, int origin, int destination, char time[], char date[], char vehicle[], int price);
	int finality(int price);

void clrscr()
{
	system("cls");
}
void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		pos.X = x;
		pos.Y = y;

		SetConsoleCursorPosition(hConsole, pos);
	}
}
int pos(int a)
{
	if (a >= 0)
		return a;
	return -a;

}
void reverse(char ary[])
{
	int l = strlen(ary);
	char hold;
	for (int i = 0; i < l / 2; i++)
	{
		hold = ary[i];
		ary[i] = ary[l - i - 1];
		ary[l - i - 1] = hold;
	}
}
int palindor(int num)
{
	int sum = 0;
	for (; num > 0; num /= 10)
	{
		sum += num % 10;
		sum *= 10;
	}
	sum /= 10;
	return sum;
}
int character_to_integer(char str[])
{
	int l=strlen(str) , pow=1;
	int sum;
	for (int i = 0; i < l; i++)
	{
		sum = str[i] * pow;
		pow *= 10;
	}
	return sum;
}
void integr_to_character(int num, char str[])
{
	int num1 = palindor(num);
	for (int i = 0; i < 10 && num1>0 ; i++ , num1/=10)
	{
		str[i] = (num1 % 10) + '0';
	}

}
int convert_stoi(char str[])
{
	int num=0;
	int legth = strlen(str);
	for (int i = 0; str[i] != 0; i++)
		num += (str[i] - '0')*pow(10.0, --legth);
	return num;

}



void cbox(char text[], int x, int y,int color)
{
	int l = strlen(text);
	for (int i = 0; i < 10; i++)
	{
		DrawLine(color, x - 3.5*l - 10, x + 3.5* l + 10, y - i, y - i,0,0);
		DrawLine(color, x - 3.5*l - 10, x + 3.5* l + 10, y + i, y + i,0,0);
	}
	DrawText1(x - 3.5*l, y + 9, ctbox, text);
}
void box(char text[], int x, int y)
{
	int l = strlen(text);
	if (l != 0){
		for (int i = 0; i < 10; i++)
		{
			DrawLine(colorbox, x - 3.5*l - 10, x + 3.5* l + 10, y - i, y - i,0,0);
			DrawLine(colorbox, x - 3.5*l - 10, x + 3.5* l + 10, y + i, y + i,0,0);
		}
		DrawText1(x - 3.5*l, y + 9, ctbox, text);
		_sleep(10);
	}
}
int tach(char t[], int x, int y)
{
	int a, b, c;
	ReadXYpos(&a, &b, &c);
	int l = strlen(t);
	if (c == 1)
	{
		//printf("\n%d\t%d\n", a, b);
		if (pos(x - a) <= (3.5*l + 10))
			if (pos(y - b) <= 10)
			{
				while (c == 1){
					ReadXYpos(&a, &b, &c); _sleep(80);
				}
				return 1;
			}
	}
	return 0;

}
void keybord(char *a)
{
	char t[15] = { 0, 0 };
	int x[41],y[41];
	int cont = 0; int k = 10; int l = 0;
	char temp[41] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ':', '/' };
	for (; cont < 39;cont++)
	{
		if (cont == 10)
			l = -35;
		if (cont == 20)
			l = -70;
		if (cont == 29)
			l = -105;
		y[cont] = l;
	}
	cont = 0;l = 24;
	for (; cont < 39; cont++){
		if (cont == 10)
			l = 24;
		if (cont == 20)
			l = 38;
		if (cont == 29)
			l = 54;
		x[cont] = -290 + l;
		l += 54;
	}
		ResetCanvas();
		t[1] = 0;
		for (int i = 0; i < 39; i++){
			t[0] = temp[i];
			box(t, x[i], y[i]);
			_sleep(4);
			DrawCanvas();
			_sleep(4);
		}
		DrawCanvas();
		strcpy(t, "            ");
		t[12] = 0;
		box(t, 0, 100);
		box("enter", 100, 100);
		int i = 19;
		DrawCanvas();
		int g = tach("enter", 100, 100);
		int w, h, c;
		while (g != 1)
		{
			ReadXYpos(&w, &h, &c);
			if (c == 1)
				for (int j = 0; j < 38; j++){
					if (pos(x[j] - w) <= 10 && pos(y[j] - h) <= 10)
					{
							a[19 - i] = temp[j];
							a[19 - i + 1] = 0;
							i--;
							DrawText1(-41, 107, 0x0, a);
							DrawCanvas();
							ReadXYpos(&w, &h, &c);
						}
						while (c == 1){
							ReadXYpos(&w, &h, &c);
							_sleep(5);
						}
				}
			_sleep(20);
			g = tach("enter", 100, 100);
		}
}
int page(char *a)
{
	int m, v, c;
	ReadXYpos(&m, &v, &c);
	while (c == 1)
	{
		ReadXYpos(&m, &v, &c);
		_sleep(40);
	}
	char stv[300], *b;
	strcpy(stv, a);
	b = stv;
	char temp[50];
	int n = 1, x, y, i = 1;
	int *arr = (int *)malloc(3 * (sizeof(int)));
	ResetCanvas();
	while (i)
	{
		x = 0; y = 0; i = 0;
		for (i = 0; b[i] != '\t'; i++);
		x += (b[i - 7] - '0') * 100;
		x += (b[i - 6] - '0') * 10;
		x += (b[i - 5] - '0');
		if (b[i - 8] == '-')
			x = -x;
		y += (b[i - 3] - '0') * 100;
		y += (b[i - 2] - '0') * 10;
		y += (b[i - 1] - '0');
		if (b[i - 4] == '-')
			y = -y;
		b[i - 8] = 0;
		for (i = 0; b[i] != '\t'; i++);
		box(b, x, y);
		arr[(n - 1) * 3] = i;
		arr[(n - 1) * 3 + 1] = x;
		arr[(n - 1) * 3 + 2] = y;
		b = &b[i + 1];
		
		if (i != 0)
		{
			n++;
			arr = (int *)realloc(arr, 3 * n*sizeof(int));
		}

	}
	
	DrawCanvas();
	int d = 1;
	while (1)
	{
		ReadXYpos(&m, &v, &c);
		if (c == 1)
		{
			for (d = (n - 1); d >= 0; d--)
			{
				if (pos(arr[3 * d + 1] - m) < (3.5*arr[3 * d] + 10))
					if (pos(arr[3 * d + 2] - v) < 10)
						return d;
			}
		}
		_sleep(40);
	}
}

int listfirst()
{
	ResetCanvas();
	box("Login to account", -210, 100);
	box("Guest Login", 210, 100);
	box("Account build", 0, 100);
	DrawCanvas();
	while (1)
	{

		if (tach("Login to account", -210, 100))
		{
			return 1;
		}
		if (tach("Guest Login", 210, 100))
		{
			return 2;
		}
		if (tach("Account build", 0, 100))
		{
			return 3;
		}
		_sleep(80);
	}
}
int Login_to_account()
{
	ResetCanvas();
	box("Exit", -275, 190);
	box("Login Administrator", -50, 90);
	box("Login Drivers", -50, -90);
	box("Login User", -50, 0);
	DrawCanvas();

	while (true)
	{
		if (tach("Exit", -250, 190)) //Exit
			return 0;
		if (tach("Login Administrator", -50, 90)) //Login Administrator
		{
			return 1;
		}
		if (tach("Login Drivers", -50, -90)) //Login Drivers
		{
			return 2;
		}
		if (tach("Login User", -50, 0)) //Login User
		{
			return 3;
		}
		_sleep(80);
	}
}
int show_trips(char f_name_t[], int number_trips, int origin, int destination, char time[], char date[], char vehicle[], int price)
{
	char destination_t[10] = { 0 }, origin_t[10] = { 0 }, number_trips_t[10] = { 0 };
	integr_to_character(origin, origin_t);
	integr_to_character(destination, destination_t);
	integr_to_character(number_trips, number_trips_t);

	ResetCanvas();
	box("Back", -275, 190);
	box("origin", -200, 150);		box(origin_t, 100, 150);
	box("destination", -200, 120);		box(destination_t, 100, 120);
	box("vehicle", -200, 90);		box(vehicle, 100, 90);
	box("Time", -200, 60);		box(time, 100, 60);
	box("date", -200, 30);		box(date, 100, 30);
	box("Number Trips", -200, 0);		box(number_trips_t, 100, 0);
	box("Driver Name", -200, -30);		box(f_name_t, 100, -30);
	box("Enter", -40, -120);
	DrawCanvas();

	while (true)
	{
		if (tach("Back", -275, 190))
			return 0;
		if (tach("Next", 40, -120))
			return 10;
	}//End while

}
int buy_ticket(char f_name_t[], int number_trips, int origin, int destination, char time[], char date[], char vehicle[], int price)
{

	char destination_t[10] = { 0 }, origin_t[10] = { 0 }, number_trips_t[10] = { 0 };
	integr_to_character(origin, origin_t);
	integr_to_character(destination, destination_t);
	integr_to_character(number_trips, number_trips_t);
	
	ResetCanvas();
	box("Back", -275, 190);
	box("origin", -200, 150);		box(origin_t, 100, 150);
	box("destination", -200, 120);		box(destination_t, 100, 120);
	box("vehicle", -200, 90);		box(vehicle, 100, 90);
	box("Time", -200, 60);		box(time, 100, 60);
	box("date", -200, 30);		box(date, 100, 30);
	box("Number Trips", -200, 0);		box(number_trips_t, 100, 0);
	box("Driver Name", -200, -30);		box(f_name_t, 100, -30);
	box("Buy", -40, -120);
	box("Next", 40, -120);
	DrawCanvas();

	while (true)
	{
		if (tach("Back", -275, 190))
			return 0;
		if (tach("Buy", -40, -120))
			return 2;
		if (tach("Next", 40, -120))
			return 3;
	}//End while
}
int finality(int price)
{
	char price_str[10] = { 0 };
	integr_to_character(price, price_str);
	ResetCanvas();	
	box("Exit", -275, 190);
	box("ticket price is:", -60, 100);		box(price_str, 60, 100);
	box("Are you sure of your purchase ?", 0, 0);
	box("YES", -40, -120);
	box("No", 40, -120);
	DrawCanvas();


	while (true)
	{
		if (tach("Exit", -275, 190))
			return 0;
		if (tach("YES", -40, -120))
			return 1;
		if (tach("No", 40, -120))
			return 2;
	}//End while

}
int get_hesab(char a[])
{
	for (int i = 0; i < 20; i++)
	{
		a[i] = 0;
	}
	ResetCanvas();
	box("Please enter your bank account number", 0, 100);
	box("bank account number", 0, 50);
	box(a, 0, 0);
	box("Enter", 0, -120);
	DrawCanvas();

	while (true)
	{

		if (tach("Enter", 0, -120))
			{
				if (a[0] == 0)
				{
					while (!tach("OK", -40, -120))
					{
						ResetCanvas();
						box("Please complete the information", 0, 30);
						cbox("OK", -40, -120, 0xc6033e);
						DrawCanvas();
						_sleep(20);
					}

					ResetCanvas();
					box("Please enter your bank account number", 0, 100);
					box("bank account number", 0, 50);
					box(a, 0, 0);
					box("Enter", 0, -120);
					DrawCanvas();

				} 
				else return 1;
		}
		if (tach("bank account number", 0, 50))
		{
			keybord(a);
			ResetCanvas();
			box("Please enter your bank account number", 0, 100);
			box("bank account number", 0, 50);
			box(a, 0, 0);
			box("Enter", 0, -120);
			DrawCanvas();
		}
	}
}

int login(char an[],char ap[])
{
	for (int i = 0; i < 20; i++)
	{
		an[i] = 0;
		ap[i] = 0;
	}

	ResetCanvas();
	box("Exit", -275, 190);
	box("enter account id", -60, 100);
	box("enter account password", -60, 0);
	box(an, 50, 100);
	box(ap, 50, 0);
	box("Enter", -60, -100);
	DrawCanvas();

	while (true)
	{

		if (tach("Enter", -60, -100))
		{
			if (!((an[0] == 0) || (ap[0] == 0)))
				return 1;  //مقدار دهی کامل

			else
			{
				while (!tach("OK", -40, -120)) //صفحه اعلام خطا
				{
					ResetCanvas();
					box("Please complete the information", 0, 30);
					cbox("OK", -40, -120, 0xea2a33);
					DrawCanvas();
					_sleep(40);
				}

				ResetCanvas();
				box("Exit", -275, 190);
				box("enter account id", -60, 100);
				box("enter account password", -60, 0);
				box(an, 50, 100);
				box(ap, 50, 0);
				box("Enter", -60, -100);
				DrawCanvas();
			}
		}


		if (tach("Exit", -275, 190)) //Exit
			return 0;

		if (tach("enter account id", -60, 100)) //Enter account
		{
			keybord(an);
			ResetCanvas();
			box("Exit", -275, 190);
			box("enter account id", -60, 100);
			box(an, 100, 100);
			box(ap, 100, 0);
			box("enter account password", -60, 0);
			box("Enter", -60, -100);
			DrawCanvas();
		}

		if (tach("enter account password", -60, 0)) //Enter pasword
		{
			keybord(ap);
			ResetCanvas();
			box("Exit", -275, 190);
			box("enter account id", -60, 100);
			box(an, 100, 100);
			box(ap, 100, 0);
			box("enter account password", -60, 0);
			box("Enter", -60, -100);
			DrawCanvas();
		}
		
		_sleep(20);
	}//end while
}
int signup(char ac_id[], char ac_pas[], char hesab_num[], char hesab_pas[], char Phone[], char f_name[], char l_name[], char moarref_id[])
{
	for (int i = 0; i < 20; i++)
	{
		ac_pas[i] = 0;
		hesab_num[i] = 0;
		hesab_pas[i] = 0;
		Phone[i] = 0;
		ac_id[i] = 0;
		f_name[i] = 0;
		l_name[i] = 0;
		moarref_id[i] = 0;
	}

	ResetCanvas();
	box("Exit", -275, 190);
	box("Registration Form", -50, 190);
	box("Account name", -200, 150);		box(ac_id, 100, 150);
	box("Account password", -200, 120);		box(ac_pas, 100, 120);
	box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
	box("Hesab bnaki password", -200, 60);
	box("First name", -200, 30);		box(f_name, 100, 30);
	box("Last name", -200, 0);		box(l_name, 100, 0);
	box("Phone number", -200, -30);	box(Phone, 100, -30);
	box("Moarref ID", -200, -60);		box(moarref_id, 100, -60);
	box("Enter", -40, -120);
	DrawCanvas();

	while (true)
	{
		if (tach("Exit", -275, 190))
			return 0;

		if (tach("Enter", -40, -120))
		{
			if (!((ac_id[0] == 0) || (ac_pas[0] == 0) || (hesab_num[0] == 0) || (hesab_pas[0] == 0) || (f_name[0] == 0) || (l_name[0] == 0) || (Phone[0] == 0)))
				return 1;  //مقدار دهی کامل
			else
			{
				while (!tach("OK", -40, -120)) //صفحه اعلام خطا
				{
					ResetCanvas();
					box("Please complete the information", 0, 30);
					cbox("OK", -40, -120, 0xc6033e);
					DrawCanvas();
					_sleep(40);
				}

				ResetCanvas();
				box("Exit", -275, 190);
				box("Registration Form", -50, 190);
				box("Account name", -200, 150);		box(ac_id, 100, 150);
				box("Account password", -200, 120);		box(ac_pas, 100, 120);
				box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
				box("Hesab bnaki password", -200, 60);
				box("First name", -200, 30);		box(f_name, 100, 30);
				box("Last name", -200, 0);		box(l_name, 100, 0);
				box("Phone number", -200, -30);	box(Phone, 100, -30);
				box("Moarref ID", -200, -60);		box(moarref_id, 100, -60);
				box("Enter", -40, -120);
				DrawCanvas();
			}
		}
		
		if (tach("Account name", -200, 150)) //write account name (1)
		{
			keybord(ac_id);
			ResetCanvas();
			box("Exit", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Moarref ID", -200, -60);		box(moarref_id, 100, -60);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		if (tach("Account password", -200, 120)) //write account password (2)
		{
			keybord(ac_pas);
			ResetCanvas();
			box("Exit", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Moarref ID", -200, -60);		box(moarref_id, 100, -60);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		if (tach("Hesab bnaki number", -200, 90)) //write Hesab bnaki number (3)
		{
			keybord(hesab_num);
			ResetCanvas();
			box("Exit", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Moarref ID", -200, -60);		box(moarref_id, 100, -60);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		if (tach("Hesab bnaki password", -200, 60)) //write Hesab bnaki password (4)
		{
			keybord(hesab_pas);
			ResetCanvas();
			box("Exit", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Moarref ID", -200, -60);		box(moarref_id, 100, -60);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		if (tach("First name", -200, 30)) //write First name (5)
		{
			keybord(f_name);
			ResetCanvas();
			box("Exit", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Moarref ID", -200, -60);		box(moarref_id, 100, -60);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		if (tach("Last name", -200, 0)) //write Last name (6)
		{
			keybord(l_name);
			ResetCanvas();
			box("Exit", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Moarref ID", -200, -60);		box(moarref_id, 100, -60);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		if (tach("Phone number", -200, -30)) //write Phone number (7)
		{
			keybord(Phone);
			ResetCanvas();
			box("Exit", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Moarref ID", -200, -60);		box(moarref_id, 100, -60);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		if (tach("Moarref ID", -200, -60)) //write Moarref ID (8)
		{
			keybord(moarref_id);
			ResetCanvas();
			box("Exit", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Moarref ID", -200, -60);		box(moarref_id, 100, -60);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		_sleep(20);
	}//end while

}
int add_driver(char ac_pas[], char hesab_num[], char Phone[], char ac_id[], char f_name[], char l_name[])
{
	for (int i = 0; i < 20; i++)
	{
		ac_pas[i] = 0;
		hesab_num[i] = 0;
		Phone[i] = 0;
		ac_id[i] = 0;
		f_name[i] = 0;
		l_name[i] = 0;
	}

	ResetCanvas();
	box("Back", -275, 190);
	box("Add Form", -50, 190);
	box("Account name", -200, 150);		box(ac_id, 100, 150);
	box("Account password", -200, 120);		box(ac_pas, 100, 120);
	box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
	box("First name", -200, 60);		box(f_name, 100, 60);
	box("Last name", -200, 30);		box(l_name, 100, 30);
	box("Phone number", -200, 0);	box(Phone, 100, 0);
	box("Enter", -40, -120);
	DrawCanvas();

	while (true)
	{
			if (tach("Back", -275, 190))
			return 3; //Back
			if (tach("Enter", -40, -120))
			{
				if (!( (ac_id[0] == 0) || (ac_pas[0] == 0) || (hesab_num[0] == 0) || (f_name[0] == 0) || (l_name[0] == 0) || (Phone[0] == 0) ))
					return 1;  //مقدار دهی کامل
				else
				{
					while (!tach("OK", -40, -120)) //صفحه اعلام خطا
					{
						ResetCanvas();
						box("Please complete the information", 0, 30);
						cbox("OK", -40, -120, 0xc6033e);
						DrawCanvas();
						_sleep(40);
					}

					ResetCanvas();
					box("Back", -275, 190);
					box("Add Form", -50, 190);
					box("Account name", -200, 150);		box(ac_id, 100, 150);
					box("Account password", -200, 120);		box(ac_pas, 100, 120);
					box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
					box("First name", -200, 60);		box(f_name, 100, 60);
					box("Last name", -200, 30);		box(l_name, 100, 30);
					box("Phone number", -200, 0);	box(Phone, 100, 0);
					box("Enter", -40, -120);
					DrawCanvas();
				}
			}


		if (tach("Account name", -200, 150))
		{
			keybord(ac_id);
			ResetCanvas();
			box("Back", -275, 190);
			box("Add Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("First name", -200, 60);		box(f_name, 100, 60);
			box("Last name", -200, 30);		box(l_name, 100, 30);
			box("Phone number", -200, 0);	box(Phone, 100, 0);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		if (tach("Account password", -200, 120))
		{
			keybord(ac_pas);
			ResetCanvas();
			box("Back", -275, 190);
			box("Add Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("First name", -200, 60);		box(f_name, 100, 60);
			box("Last name", -200, 30);		box(l_name, 100, 30);
			box("Phone number", -200, 0);	box(Phone, 100, 0);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		if (tach("Hesab bnaki number", -200, 90))
		{
			keybord(hesab_num);
			ResetCanvas();
			box("Back", -275, 190);
			box("Add Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("First name", -200, 60);		box(f_name, 100, 60);
			box("Last name", -200, 30);		box(l_name, 100, 30);
			box("Phone number", -200, 0);	box(Phone, 100, 0);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		if (tach("First name", -200, 60))
		{
			keybord(f_name);
			ResetCanvas();
			box("Back", -275, 190);
			box("Add Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("First name", -200, 60);		box(f_name, 100, 60);
			box("Last name", -200, 30);		box(l_name, 100, 30);
			box("Phone number", -200, 0);	box(Phone, 100, 0);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		if (tach("Last name", -200, 30))
		{
			keybord(l_name);
			ResetCanvas();
			box("Back", -275, 190);
			box("Add Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("First name", -200, 60);		box(f_name, 100, 60);
			box("Last name", -200, 30);		box(l_name, 100, 30);
			box("Phone number", -200, 0);	box(Phone, 100, 0);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		if (tach("Phone number", -200, 0))
		{
			keybord(Phone);
			ResetCanvas();
			box("Back", -275, 190);
			box("Add Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("First name", -200, 60);		box(f_name, 100, 60);
			box("Last name", -200, 30);		box(l_name, 100, 30);
			box("Phone number", -200, 0);	box(Phone, 100, 0);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		_sleep(80);
	}//End while
}
int Change_information(char ac_id[], char ac_pas[], char hesab_num[], char hesab_pas[], char Phone[], char f_name[], char l_name[])
{
	for (int i = 0; i < 20; i++)
	{
		ac_pas[i] = 0;
		hesab_num[i] = 0;
		hesab_pas[i] = 0;
		Phone[i] = 0;
		ac_id[i] = 0;
		f_name[i] = 0;
		l_name[i] = 0;
	}

	ResetCanvas();
	box("Back", -275, 190);
	box("Registration Form", -50, 190);
	box("Account name", -200, 150);		box(ac_id, 100, 150);
	box("Account password", -200, 120);		box(ac_pas, 100, 120);
	box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
	box("Hesab bnaki password", -200, 60);
	box("First name", -200, 30);		box(f_name, 100, 30);
	box("Last name", -200, 0);		box(l_name, 100, 0);
	box("Phone number", -200, -30);	box(Phone, 100, -30);
	box("Enter", -40, -120);
	DrawCanvas();

	while (1)
	{
		if (tach("Back", -275, 190))
			return 0;
		if (tach("Enter", -40, -120))
		{
			if (ac_id[0] == 0 || hesab_pas[0] == 0 || ac_pas[0] == 0 || hesab_num[0] == 0 || f_name[0] == 0 || l_name[0] == 0 || Phone[0] == 0)
			{
				while (!tach("OK", -40, -120))
				{
					ResetCanvas();
					box("Please complete the information", 0, 30);
					cbox("OK", -40, -120, 0xc6033e);
					DrawCanvas();
					_sleep(40);
				}

				ResetCanvas();
				box("Back", -275, 190);
				box("Registration Form", -50, 190);
				box("Account name", -200, 150);		box(ac_id, 100, 150);
				box("Account password", -200, 120);		box(ac_pas, 100, 120);
				box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
				box("Hesab bnaki password", -200, 60);
				box("First name", -200, 30);		box(f_name, 100, 30);
				box("Last name", -200, 0);		box(l_name, 100, 0);
				box("Phone number", -200, -30);	box(Phone, 100, -30);
				box("Enter", -40, -120);
				DrawCanvas();
			}
			else return 1;
		}

		if (tach("Account name", -200, 150)) //write account name (1)
		{
			keybord(ac_id);
			ResetCanvas();
			box("Back", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		if (tach("Account password", -200, 120)) //write account password (2)
		{
			keybord(ac_pas);
			ResetCanvas();
			box("Back", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		if (tach("Hesab bnaki number", -200, 90)) //write Hesab bnaki number (3)
		{
			keybord(hesab_num);
			ResetCanvas();
			box("Back", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		if (tach("Hesab bnaki password", -200, 60)) //write Hesab bnaki password (4)
		{
			keybord(hesab_pas);
			ResetCanvas();
			box("Back", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		if (tach("First name", -200, 30)) //write First name (5)
		{
			keybord(f_name);
			ResetCanvas();
			box("Back", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		if (tach("Last name", -200, 0)) //write Last name (6)
		{
			keybord(l_name);
			ResetCanvas();
			box("Back", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Enter", -40, -120);
			DrawCanvas();
		}

		if (tach("Phone number", -200, -30)) //write Phone number (7)
		{
			keybord(Phone);
			ResetCanvas();
			box("Back", -275, 190);
			box("Registration Form", -50, 190);
			box("Account name", -200, 150);		box(ac_id, 100, 150);
			box("Account password", -200, 120);		box(ac_pas, 100, 120);
			box("Hesab bnaki number", -200, 90);	box(hesab_num, 100, 90);
			box("Hesab bnaki password", -200, 60);
			box("First name", -200, 30);		box(f_name, 100, 30);
			box("Last name", -200, 0);		box(l_name, 100, 0);
			box("Phone number", -200, -30);	box(Phone, 100, -30);
			box("Enter", -40, -120);
			DrawCanvas();
		}
	}//end while
}
int initialize_vehicles(char s[], char cap[], char cost[])
{
	for (int i = 0; i < 5; i++)
	{
		s[i] = 0;
		cap[i] = 0;
		cost[i] = 0;
	}

	ResetCanvas();
	box("Back", -275, 190);
	box("Speed", -200, 150);		box(s, 100, 150);
	box("capacity", -200, 120);		box(cap, 100, 120);
	box("Cost", -200, 90);		box(cost, 100, 90);
	box("Enter", -40, -120);
	DrawCanvas();

	while (true)
	{
		if (tach("Back", -275, 190))
			return 0;

		if (tach("Enter", -40, -120))
		{
			if (s[0] == 0 || cap[0] == 0 || cost[0] == 0)
			{
				while (!tach("OK", -40, -120))
				{
					ResetCanvas();
					box("Please complete the information", 0, 30);
					cbox("OK", -40, -120, 0xc6033e);
					DrawCanvas();
					_sleep(20);
				}

				ResetCanvas();
				box("Back", -275, 190);
				box("Speed", -200, 150);		box(s, 100, 150);
				box("capacity", -200, 120);		box(cap, 100, 120);
				box("Cost", -200, 90);		box(cost, 100, 90);
				box("Enter", -40, -120);
				DrawCanvas();
			}
			else return 1;
		}
		if (tach("Speed", -200, 150))
		{
			keybord(s);
			ResetCanvas();
			box("Back", -275, 190);
			box("Speed", -200, 150);		box(s, 100, 150);
			box("capacity", -200, 120);		box(cap, 100, 120);
			box("Cost", -200, 90);		box(cost, 100, 90);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		if (tach("capacity", -200, 120))
		{
			keybord(cap);
			ResetCanvas();
			box("Back", -275, 190);
			box("Speed", -200, 150);	box(s, 100, 150);
			box("capacity", -200, 120);		box(cap, 100, 120);
			box("Cost", -200, 90);		box(cost, 100, 90);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		if (tach("Cost", -200, 90))
		{
			keybord(cost);
			ResetCanvas();
			box("Back", -275, 190);
			box("Speed", -200, 150);		box(s, 100, 150);
			box("capacity", -200, 120);		box(cap, 100, 120);
			box("Cost", -200, 90);		box(cost, 100, 90);
			box("Enter", -40, -120);
			DrawCanvas();
		}
	}//End while
}
int Define_travel(char origin[], char destination[], char vehicle[], char time[], char date[])
{

	for (int i = 0; i < 10; i++)
	{
		origin[i] = 0;
		destination[i] = 0;
		vehicle[i] = 0;
		time[i] = 0;
		date[i] = 0;
	}

	ResetCanvas();
	box("Back", -275, 190);
	box("origin", -200, 150);		box(origin, 100, 150);
	box("destination", -200, 120);		box(destination, 100, 120);
	box("vehicle", -200, 90);		box(vehicle, 100, 90);
	box("Time", -200, 60);		box(time, 100, 60);
	box("date", -200, 30);		box(date, 100, 30);
	box("Enter", -40, -120);
	DrawCanvas();

	while (true)
	{
		if (tach("Back", -275, 190))
			return 0;

		if (tach("Enter", -40, -120))
		{
			if (origin[0] == 0 || destination[0] == 0 || vehicle[0] == 0 || time[0] == 0 || date[0] == 0)
			{
				while (!tach("OK", -40, -120))
				{
					ResetCanvas();
					box("Please complete the information", 0, 30);
					cbox("OK", -40, -120, 0xc6033e);
					DrawCanvas();
					_sleep(20);
				}

				ResetCanvas();
				box("Back", -275, 190);
				box("origin", -200, 150);		box(origin, 100, 150);
				box("destination", -200, 120);		box(destination, 100, 120);
				box("vehicle", -200, 90);		box(vehicle, 100, 90);
				box("Time", -200, 60);		box(time, 100, 60);
				box("date", -200, 30);		box(date, 100, 30);
				box("Enter", -40, -120);
				DrawCanvas();
			}
			else return 1;
		}
		if (tach("origin", -200, 150))
		{
			keybord(origin);
			ResetCanvas();
			box("Back", -275, 190);
			box("origin", -200, 150);		box(origin, 100, 150);
			box("destination", -200, 120);		box(destination, 100, 120);
			box("vehicle", -200, 90);		box(vehicle, 100, 90);
			box("Time", -200, 60);		box(time, 100, 60);
			box("date", -200, 30);		box(date, 100, 30);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		if (tach("destination", -200, 120))
		{
			keybord(destination);
			ResetCanvas();
			box("Back", -275, 190);
			box("origin", -200, 150);		box(origin, 100, 150);
			box("destination", -200, 120);		box(destination, 100, 120);
			box("vehicle", -200, 90);		box(vehicle, 100, 90);
			box("Time", -200, 60);		box(time, 100, 60);
			box("date", -200, 30);		box(date, 100, 30);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		if (tach("vehicle", -200, 90))
		{
			char v[] = "Exit-275+190\tBus0000+150\tTrain+000+100\tAirplane0000+050\t\t";
			int device = page(v);
			if (device == 0) { continue; }
			if (device == 1) strcpy(vehicle, "Bus");
			if (device == 2) strcpy(vehicle, "Train");
			if (device == 3) strcpy(vehicle, "Airplan");
			ResetCanvas();
			box("Back", -275, 190);
			box("origin", -200, 150);		box(origin, 100, 150);
			box("destination", -200, 120);		box(destination, 100, 120);
			box("vehicle", -200, 90);		box(vehicle, 100, 90);
			box("Time", -200, 60);		box(time, 100, 60);
			box("date", -200, 30);		box(date, 100, 30);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		if (tach("Time", -200, 60))
		{
			keybord(time);
			ResetCanvas();
			box("Back", -275, 190);
			box("origin", -200, 150);		box(origin, 100, 150);
			box("destination", -200, 120);		box(destination, 100, 120);
			box("vehicle", -200, 90);		box(vehicle, 100, 90);
			box("Time", -200, 60);		box(time, 100, 60);
			box("date", -200, 30);		box(date, 100, 30);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		if (tach("date", -200, 30))
		{
			keybord(date);
			ResetCanvas();
			box("Back", -275, 190);
			box("origin", -200, 150);		box(origin, 100, 150);
			box("destination", -200, 120);		box(destination, 100, 120);
			box("vehicle", -200, 90);		box(vehicle, 100, 90);
			box("Time", -200, 60);		box(time, 100, 60);
			box("date", -200, 30);		box(date, 100, 30);
			box("Enter", -40, -120);
			DrawCanvas();
		}
	}//End while
}
int chang_trips(int number_trips,char time[], char date[])
{
	char num_t[10] = { 0 };
	integr_to_character(number_trips, num_t);

	ResetCanvas();
	box("Back", -275, 190);
	box("Number Trips", -200, 90);	box(num_t, 100, 90);
	box("Time", -200, 60);		box(time, 100, 60);
	box("date", -200, 30);		box(date, 100, 30);
	box("Enter", -40, -120);
	box("Next", 40, -120);
	DrawCanvas();

	while (true)
	{
		if (tach("Back", -275, 190))
			return 0;
		if (tach("Next", 40, -120))
			return 10;

		if (tach("Enter", -40, -120))
		{
			if (time[0] == 0 || date[0] == 0)
			{
				while (!tach("OK", -40, -120))
				{
					ResetCanvas();
					box("Please complete the information", 0, 30);
					cbox("OK", -40, -120, 0xc6033e);
					DrawCanvas();
					_sleep(20);
				}

				ResetCanvas();
				box("Back", -275, 190);
				box("Number Trips", -200, 90);	box(num_t, -200, 90);
				box("Time", -200, 60);		box(time, 100, 60);
				box("date", -200, 30);		box(date, 100, 30);
				box("Enter", -40, -120);
				box("Next", 40, -120);
				DrawCanvas();
			}
			else return 1;
		}
		if (("Time", -200, 60))
		{
			keybord(time);
			ResetCanvas();
			box("Back", -275, 190);
			box("Number Trips", -200, 90);	box(num_t, -200, 90);
			box("Time", -200, 60);		box(time, 100, 60);
			box("date", -200, 30);		box(date, 100, 30);
			box("Enter", -40, -120);
			box("Next", 40, -120);
			DrawCanvas();
		}
		if (("date", -200, 60))
		{
			keybord(date);
			ResetCanvas();
			box("Back", -275, 190);
			box("Number Trips", -200, 90);	box(num_t, -200, 90);
			box("Time", -200, 60);		box(time, 100, 60);
			box("date", -200, 30);		box(date, 100, 30);
			box("Enter", -40, -120);
			box("Next", 40, -120);
			DrawCanvas();
		}

	}//End while
}
int getmm(char origin_str[], char destination_str[], char vehicle[])
{
	for (int i = 0; i < 10; i++)
	{
		vehicle[i] = 0;
		origin_str[i] = 0;
		destination_str[i] = 0;
	}

	ResetCanvas();
	box("Back", -275, 190);
	box("Origin", -200, 90);	box(origin_str, 100, 90);
	box("destination", -200, 60);		box(destination_str, 100, 60);
	box("vehicle", -200, 30);		box(vehicle, 100, 30);
	box("Enter", -40, -120);
	DrawCanvas();

	while (true)
	{
		if (tach("Back", -275, 190))
			return 0;

		if (tach("Enter", -40, -120))
		{
			if (origin_str[0] == 0 || destination_str[0] == 0 || vehicle[0]==0)
			{
				while (!tach("OK", -40, -120))
				{
					ResetCanvas();
					box("Please complete the information", 0, 30);
					cbox("OK", -40, -120, 0xc6033e);
					DrawCanvas();
					_sleep(20);
				}

				ResetCanvas();
				box("Back", -275, 190);
				box("Origin", -200, 90);	box(origin_str, 100, 90);
				box("destination", -200, 60);		box(destination_str, 100, 60);
				box("vehicle", -200, 30);		box(vehicle, 100, 30);
				box("Enter", -40, -120);
				DrawCanvas();

			}
			else return 1;
		}
		if (tach("Origin", -200, 90))
		{
			keybord(origin_str);
			ResetCanvas();
			box("Back", -275, 190);
			box("Origin", -200, 90);	box(origin_str, 100, 90);
			box("destination", -200, 60);		box(destination_str, 100, 60);
			box("vehicle", -200, 30);		box(vehicle, 100, 30);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		if (tach("destination", -200, 60))
		{
			keybord(destination_str);
			ResetCanvas();
			box("Back", -275, 190);
			box("Origin", -200, 90);	box(origin_str, 100, 90);
			box("destination", -200, 60);		box(destination_str, 100, 60);
			box("vehicle", -200, 30);		box(vehicle, 100, 30);
			box("Enter", -40, -120);
			DrawCanvas();
		}
		if (tach("vehicle", -200, 30))
		{
			int device;
			char v[] = "Exit-275+190\tBus0000+150\tTrain+000+100\tAirplane0000+050\t\t";
			device = page(v);
			if (device == 0) { continue; }
			if (device == 1) strcpy(vehicle, "Bus");
			if (device == 2) strcpy(vehicle, "Train");
			if (device == 3) strcpy(vehicle, "Airplan");
			ResetCanvas();
			box("Back", -275, 190);
			box("Origin", -200, 90);	box(origin_str, 100, 90);
			box("destination", -200, 60);		box(destination_str, 100, 60);
			box("vehicle", -200, 30);		box(vehicle, 100, 30);
			box("Enter", -40, -120);
			DrawCanvas();
		}
	}//End while
}

void error(char file_name[]){
	InitCanvas(600,400);
	SetBkColor(255, 0, 0);
	ResetCanvas();
	char str[30] = "Erroe! can't open : ";
	strcat_s(str, file_name);
	box(str, -20, 30);
	DrawCanvas();
}
int khoshmad()
{
	ResetCanvas();
	box("Exit", -275, 190);
	box("Your registration has been successfully completed", -20, 115);
	box("Welcome to your account in IUT Azhans!", -20, 100);
	box("Pleas press Enter to log in", -20, 85);
	box("or press Exit to Quit", -20, 70);
	box("Enter", -40, -120);
	DrawCanvas();
	while(true)
	{
	if (tach("Enter", -40, -120))
		return 10;
	if (tach("Exit", -275, 190))
		return 0;
	_sleep(20);
	}
}
int khoshmad2()
{
	ResetCanvas();
	box("Exit", -275, 190);
	box("Welcome to your account in IUT Azhans!", -20, 100);
	box("Pleas press Enter to log in", -20, 85);
	box("or press Exit to Quit", -20, 70);
	box("Enter", -40, -120);
	DrawCanvas();

	while (!tach("Enter", -40, -120))
	{
		if (tach("Exit", -275, 190))
			return 0;
	}
}
void khata()
{
	ResetCanvas();
	box("Your input information was incorrect!", -20, 100);
	box("Please re-enter information", -20, 85);
	box("OK", -40, -120);
	DrawCanvas();
	while (!tach("OK", -40, -120))
	{
	}
}
void sabt()
{
	ResetCanvas();
	box("Registration information completed successfully", -20, 100);
	box("Pleas press Enter to Return to admin panel", -20, 85);
	box("Enter", -40, -120);
	DrawCanvas();
	while (!tach("Enter", -40, -120))
	{
	}
}
void schange()
{
	ResetCanvas();
	box("Changing information was successful", -20, 100);
	box("Pleas press Enter to return", -20, 85);
	box("Enter", -40, -120);
	DrawCanvas();
	while (!tach("Enter", -40, -120))
	{
	_sleep(40);
	}
		
}
void errore2()
{
	char b[] = "ok", a[] = "An error occurred";
	ResetCanvas();
	box(a, -30, +100);
	box(b, -20, -100);
	DrawCanvas();
	while (!tach(b, -20, -100));
}
void sabt2()
{
	ResetCanvas();
	box("The trip was successfully recorded", -20, 100);
	box("Pleas press Enter to Return to admin panel", -20, 85);
	box("Enter", -40, -120);
	DrawCanvas();
	while (!tach("Enter", -40, -120))
	{
	}
}
void yaftnashod()
{
	ResetCanvas();
	box("No trips are availebel", -20, 100);
	box("Pleas press OK", -20, 85);
	box("Ok", -40, -120);
	DrawCanvas();
	while (!tach("OK", -40, -120))
	{
	}
}
void sbuy()
{
	ResetCanvas();
	box("Buy is successfully", -20, 100);
	box("Pleas press Ok to Return to panel", -20, 85);
	box("Ok", -40, -120);
	DrawCanvas();
	while (!tach("Ok", -40, -120))
	{
	}


}
void sbuy2()
{
	ResetCanvas();
	box("Buy is successfully", -20, 100);
	box("Pleas press Ok to Return to main page", -20, 85);
	box("Ok", -40, -120);
	DrawCanvas();
	while (!tach("Ok", -40, -120))
	{
	}

}

/*int tashkhis(char ac_id[], char ac_pas[])
{
	for (int i = 0; i < 20; i++)
	{
		ac_id[i] = 0;
		ac_pas[i] = 0;
	}
	ResetCanvas();
	box("Back", -275, 190);
	box("Please enter your new username and password", -10, 190);
	box("Then press the Enter", -10, 175);
	box("new Account name", -200, 150);		box(ac_id, 100, 150);
	box("new Account password", -200, 120);		box(ac_pas, 100, 120);
	cbox("Enter", -10, -120, 0x78f453);
	DrawCanvas();

	while (1)
	{

		if (tach("Back", -275, 190))
			return 0;

		if (tach("Enter", -40, -120))
		{
			if (ac_id[0] != 0 && ac_pas[0] != 0)
				return 1;
			else
			while (!tach("OK", -40, -120))
			{
				ResetCanvas();
				box("Please complete the information", 0, 30);
				cbox("OK", -40, -120, 0xc6033e);
				DrawCanvas();
				_sleep(40);
			}
			ResetCanvas();
			box("Back", -275, 190);
			box("Please enter your new username and password", -10, 190);
			box("Then press the Enter", -10, 175);
			box("new Account name", -200, 150);		box(ac_id, 100, 150);
			box("new Account password", -200, 120);		box(ac_pas, 100, 120);
			cbox("Enter", -10, -120, 0x78f453);
			DrawCanvas();
		}

		if (tach("Account name", -200, 150)) //write account name (1)
		{
			keybord(ac_id);
			ResetCanvas();
			box("Back", -275, 190);
			box("Please enter your new username and password", -10, 190);
			box("Then press the Enter", -10, 175);
			box("new Account name", -200, 150);		box(ac_id, 100, 150);
			box("new Account password", -200, 120);		box(ac_pas, 100, 120);
			cbox("Enter", -10, -120, 0x78f453);
			DrawCanvas();
		}

		if (tach("Account password", -200, 120)) //write account password (2)
		{
			keybord(ac_pas);
			ResetCanvas();
			box("Back", -275, 190);
			box("Please enter your new username and password", -10, 190);
			box("Then press the Enter", -10, 175);
			box("new Account name", -200, 150);		box(ac_id, 100, 150);
			box("new Account password", -200, 120);		box(ac_pas, 100, 120);
			cbox("Enter", -10, -120, 0x78f453);
			DrawCanvas();
		}
	}//End while
}*/
