#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Functions.h"
#include "Graphic_Nazari.h"
using namespace std;


FILE *cities = fopen("E:/cities.txt", "r+");
FILE *accounts = fopen("E:/accounts.txt", "r+");
FILE *users = fopen("E:/users.txt", "r+");
FILE *trips = fopen("E:/trips.txt", "r+");
FILE *tickets = fopen("E:/tickets.txt", "r+");
FILE *vehicles = fopen("E:/vehicles.txt", "r+");


void admin_pannel();
void Driver_pannel(char f_name[]);
void user_pannel(char id[]);
double distance(int city1, int city2);
int cost(char v[]);

int main()
{
	if (cities == NULL)	{error("cities"); return -1;}
	if (accounts == NULL)	{error("accounts"); return -1;}
	if (users == NULL)	{error("users");  return -1;}
	srand(time(NULL));
	//_tzset();

	int control, type=0;
	char hesab_num[20] = { 0 }, hesab_pas[20] = { 0 }, hesab_inventory[20] = { 0 };
	char account_id[20] = { 0 }, account_password[20] = { 0 };
	char f_name[20] = { 0 }, l_name[20] = { 0 };
	char Phone[20] = { 0 }, moarref_id[20] = { 0 };

	clrscr();
	InitCanvas(600, 400);
	SetBkColor(150, 150, 255);


	while (true)
	{
		int e=0;
		control = listfirst(); //(1)Login to account (2)Guest Login (3)Account build

//(1)Login to account
		if (control == 1)
		{

			char account_id_temp[20], account_password_temp[20];
			char hesab_num_temp[20], hesab_pas_temp[20];
			char Phone_temp[20], f_name_temp[20], l_name_temp[20], moarref_id_temp[20];
			fseek(users, 0, SEEK_SET);
			control=Login_to_account(); //(0)Exit (1)Admin (2)Drivers (3)Users
			if (control == 0) { cout << "\a"; continue; } //Exit


			if (control == 1) //Login Administrator
				{
					control = login(account_id, account_password); //(0)Exit (otherwise)Countinue + Initialize
					if (control == 0) { cout << "\a"; continue; } //Exit
					
					for (int i = 0, havas = 0; i < 100000; i++)
					{
						fscanf(users, "%d\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s", &type, account_id_temp, account_password_temp, hesab_num_temp, Phone_temp, f_name_temp, l_name_temp);
						if (strcmp(account_id, account_id_temp)==0)
						{
							havas++;
							if ( strcmp(account_password, account_password_temp)==0 && type==0 ) //Confirmation information
							{
								admin_pannel();		
								control = 0;
								break;
							}
							else { khata(); control = 0; break;} //If the password was wrong!
						}

						if (i == 99999 && havas==0)//peyda nashodan
						{
							char a[] = "id not found-020+020\tOK-020-080\t\t";
							page(a);	control = 0;
						}

					} //End for
				if (control == 0){ continue;} //Exit
			}
			//End login Admin


			if (control == 2) //Login Drivers
				{
					control=login(account_id, account_password);//(0)Exit (otherwise)Countinue + Initialize
					if (control == 0){ cout << "\a"; continue; } //Exit

					for (int i = 0, havas = 0; i < 100000; i++)
					{
						fscanf(users, "%d\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s", &type, account_id_temp, account_password_temp, hesab_num_temp, Phone_temp, f_name_temp, l_name_temp);

						if (strcmp(account_id, account_id_temp) == 0)
						{
							havas++;
							if (strcmp(account_password, account_password_temp) == 0 && type == 2) //Confirmation information
							{
								Driver_pannel(f_name_temp);
								control = 0;
								break;
							}
							else { khata(); control = 0; break; } //If the password was wrong!
						}

						if (i == 99999 && havas==0)//peyda nashodan
						{
							char a[] = "id not found-020+020\tOK-020-080\t\t";
							page(a);	control = 0;
						}

					} //End for
					if (control == 0){ cout << "\a"; continue; } //Exit
				}
			//End Login Drivers



			if (control == 3) //Login User
				{
					control = login(account_id, account_password);//(0)Exit (otherwise)Countinue + Initialize
					if (control == 0){ cout << "\a"; continue; } //Exit

					for (int i = 0, havas = 0; i < 100000; i++)
					{
						fscanf(users, "%d\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s", &type, account_id_temp, account_password_temp, hesab_num_temp, Phone_temp, f_name_temp, l_name_temp);

						if (strcmp(account_id, account_id_temp) == 0)
						{
							havas++;
							if (strcmp(account_password, account_password_temp) == 0 && type == 1) //Confirmation information
							{
								user_pannel(account_id);
								control = 0;
								break;
							}
							else { khata(); control = 0; break; } //If the password was wrong!
						}

						if (i == 99999 && havas == 0)//peyda nashodan
						{
							char a[] = "id not found-020+020\tOK-020-080\t\t";
							page(a);	control = 0;
						}

					} //End for
					if (control == 0){ cout << "\a"; continue; } //Exit
				}	
			//End Login User

		}
//Login to account End

	

//(2)Guest Login
		if (control == 2)
		{
			int origin, destination;
			int number_trips, origin_t, destination_t, price, pool;
			char origin_str[20], destination_str[20], vehicle[20];
			char f_name_d[20], time[10], date[10], vehicle_t[10];
			char shomarehh[20], passhomarehh[20], passhomarehh_t[20], pool_str[20], pool_str_t[20], shomarehh_t[20];

			control = getmm(origin_str, destination_str, vehicle);
			if (control == 0) { continue; } //Back

			//Convert string to integer
			origin = convert_stoi(origin_str);
			destination = convert_stoi(destination_str);
		
			fseek(trips, 0, SEEK_SET);
			int havas2 = 0, havas=0;

			for (int i = 0; i < 10000; i++)
			{
				if (havas2 == 1) { break; }
				fscanf(trips, "%20s%10d%5d%5d%10s%10s%10s%10d", f_name_d, &number_trips, &origin_t, &destination_t, time, date, vehicle_t, &price);

				if ((origin == origin_t) && (destination_t == destination) && (strcmp(vehicle, vehicle_t) == 0))
				{
					control = buy_ticket(f_name_d, number_trips, origin, destination, time, date, vehicle, price); //(0)Back (2)Buy (3)Next
					if (control == 0) { havas = 1; break; } //If press Back
					if (control == 2) //Buy
					{
						havas2 = 1;

						//پیدا کردن حساب خریدار
						int hmaintori=get_hesab(shomarehh);

						fseek(accounts, 0, SEEK_SET);
						for (int j = 0; j < 10000; j++)
						{
							fscanf(accounts, "%s\t%s\t%s", shomarehh_t, passhomarehh, pool_str);
							if (strcmp(shomarehh, shomarehh_t) == 0) { break; }
						}


						//Convert string to integer(Beginning)
						pool = convert_stoi(pool_str);

						if (pool > price)
						{
							control = finality(price); //(0)Exit (1)Yes (2)No
							if (control == 0 || control == 2) { havas = 1; break; } //If press Exit

							if (control == 1)
							{
								int h_balence_integer = 0,h_balence_integer2 = 0;
								char ai[20], ap[20], hn[20], p[20], fn[20], ln[20];
								char ai2[20], ap2[20], hn2[20], p2[20], fn2[20], ln2[20];
								char h_name[20], h_pas[20], h_balence[20], h_balence_t[20];
								char h_name2[20], h_pas2[20], h_balence2[20], h_balence_t2[20], hesab_inventory_temp2[20];

								//پیدا کردن حساب مدیر
									fseek(users, 0, SEEK_SET);
									for (int i = 0; i < 10000; i++)
									{
										fscanf(users, "%d\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s", &type, ai, ap, hn, p, fn, ln);
										if (type == 0){ break; }
									}

									fseek(accounts, 0, SEEK_SET);
									for (int j = 0; j < 100000; j++)
									{
										fscanf(accounts, "%s\t%s\t%s\n", h_name, h_pas, h_balence);
										if (strcmp(h_name, hn) == 0) { break; }
									}

								//پیدا کردن حساب راننده
									fseek(users, 0, SEEK_SET);
									for (int i = 0; i < 10000; i++)
									{
										fscanf(users, "%d\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s", &type, ai2, ap2, hn2, p2, fn2, ln2);
										if (strcmp(fn2, f_name_d) == 0){ break; }
									}
									fseek(accounts, 0, SEEK_SET);
									for (int j = 0; j < 100000; j++)
									{
										fscanf(accounts, "%s\t%s\t%s", h_name2, h_pas2, h_balence2);
										if (strcmp(h_name2, hn2) == 0) { break; }
									}


								//کم کردن از حساب شخص
								pool -= price;
								integr_to_character(pool, pool_str);
								fseek(accounts, 0, SEEK_SET);
								for (int j = 0; j < 100000; j++)
								{
									fscanf(accounts, "%s\t%s\t%s", shomarehh_t, passhomarehh_t, pool_str_t);
									if (strcmp(shomarehh_t, shomarehh) == 0)
									{
										fseek(accounts, -18, SEEK_CUR);
										fprintf(accounts, "%s\t%s\t%s", shomarehh, passhomarehh_t, pool_str);
										fclose(accounts);
										accounts = fopen("E:/accounts.txt", "r+");
										break;
									}
								}


								//اضافه کردن به حساب راننده
								//Convert string to integer(Beginning)
								h_balence_integer2 = convert_stoi(h_balence2);
								
								h_balence_integer2 += 0.9*price;
								integr_to_character(h_balence_integer2, h_balence2);
								fseek(accounts, 0, SEEK_SET);
								for (int j = 0; j < 100000; j++)
								{
									fscanf(accounts, "%s\t%s\t%s", h_name2, h_pas2, h_balence_t2);
									if (strcmp(h_name2, hn2) == 0)
									{
										fseek(accounts, -18, SEEK_CUR);
										fprintf(accounts, "%s\t%s\t%s", h_name2, h_pas2, h_balence2);
										fclose(accounts);
										accounts = fopen("E:/accounts.txt", "r+");
										break;
									}
								}

								//اضافه کردن به حساب مدیر
								//Convert string to integer(Beginning)
								int legth2 = strlen(h_balence);
								for (int i = 0; h_balence[i] != 0; i++)
									h_balence_integer += (h_balence[i] - '0')*pow(10.0, --legth2);
								//Convert string to integer(Ending)
								h_balence_integer += 0.1*price;
								integr_to_character(h_balence_integer, h_balence);
								fseek(accounts, 0, SEEK_SET);
								for (int j = 0; j < 100000; j++)
								{
									fscanf(accounts, "%s\t%s\t%s", h_name, h_pas, h_balence_t);
									if (strcmp(h_name, hn2) == 0)
									{
										fseek(accounts, -18, SEEK_CUR);
										fprintf(accounts, "%s\t%s\t%s", h_name, h_pas, h_balence);
										fclose(accounts);
										accounts = fopen("E:/accounts.txt", "r+");
										break;
									}
								}
								sbuy2();
							}
						}
						else{ havas = 1; break; }
					}
				}
			}//End for
			if (havas == 1) { continue; }
			else if (havas2 == 0) { yaftnashod(); continue; }




		}
//End Guest Login



//(3)Account build
		if (control == 3)
		{

			char account_id_temp[20], account_password_temp[20], hesab_num_temp[20];
			char Phone_temp[20], f_name_temp[20], l_name_temp[20], hesab_inventory_temp[20], hesab_pas_temp[20];
			int calculator , havas=0; //condition

			while (true)
				{
					calculator = 0;
					control = signup(account_id, account_password, hesab_num, hesab_pas, Phone, f_name, l_name, moarref_id); //(0)Exit   (1)Completed
					if (control == 0 || havas == 1) { cout << "\a"; e = -1; havas = 0; break; } //Exit

					for (int i = 0 , havas=0 ; i < 100000 && havas==0; i++)
						{
							fscanf(accounts, "%s\t%s\t%s\n", hesab_num_temp, hesab_pas_temp, hesab_inventory_temp);

							if (strcmp(hesab_num, hesab_num_temp)==0)
								{
									if (strcmp(hesab_pas, hesab_pas_temp)==0)
									{
										//submit information
										fseek(users, 0, SEEK_END);
										fprintf(users, "1\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s\n", account_id, account_password, hesab_num, Phone, f_name, l_name);
										fclose(users);
										users = fopen("E:/users.txt", "r+");

										//Welcome
										control = khoshmad(); //(0)Exit (10)continue
										if (control == 0){ break; } //Exit
										if (control == 10) havas = 1;

										//Open Pannel
										user_pannel(account_id);
									}

									else {calculator = 1; break;} //Wrong information
								} //End of registration
							if (havas == 1) break;

						} //End for

					if (calculator == 1){khata(); continue;}

				}//end while
			if (e == -1){e = 0; continue;}  /*if press Exit --> Exit to First page*/
		}
//end Account Biuld


	}//end main while*/
	return 0;
}


void admin_pannel()
{
	int control, type, vehicle;
	char ac_pas[20], ac_id[20];
	char hesab_num[20], hesab_pas[20];
	char Phone[20], f_name[20], l_name[20], moarref_id[20];
	
	char panel[] = "Exit-275+190\tadd driver-050+140\tshow tickets-050+110\tshow Passengers-050+080\tshow Trips-050+050\tChange information-050+020\tdiscount code-050-010\tVehicles Setting-050-040\t\t";
	
	while (true)
	{ 
		//(0)Exit (1)Add Driver (2)Show tickets (3)show Passengers (4)show Trips (5)Change information (6)discount code (7)Vehicles Setting
		strcpy(panel , "Exit-275+190\tadd driver-050+140\tshow tickets-050+110\tshow Passengers-050+080\tshow Trips-050+050\tChange information-050+020\tdiscount code-050-010\tVehicles Setting-050-040\t\t");
		control = page(panel);
		DrawCanvas();

		if (control == 0) { cout << "\a"; break; } //End

		//Add Driver
		if (control == 1)
		{
			if (add_driver(ac_pas, hesab_num, Phone, ac_id, f_name, l_name) == 1)
			{
				fseek(users, 0, SEEK_END);
				fprintf(users, "2\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s\n", ac_id, ac_pas, hesab_num, Phone, f_name, l_name);
				fclose(users);
				users = fopen("E:/users.txt", "r+");
				sabt();
			}
			else continue; //enter back in add driver
		}
		//End Add Driver


		//show tickets
		if (control == 2)
		{

		}
		//End show tickets


		//show Passengers
		if (control == 3)
		{

		}
		//End Show Passengers


		//show Trips
		if (control == 4)
		{

		}
		//End Show Trips


		//Change information
		if (control == 5)
		{
			char account_id_temp[20], account_password_temp[20];
			char hesab_num_temp[20], hesab_pas_temp[20];
			char Phone_temp[20], f_name_temp[20], l_name_temp[20], moarref_id_temp[20];

			control=Change_information(ac_id, ac_pas, hesab_num, hesab_pas, Phone, f_name, l_name);
			if (control == 0) { continue; } //if press Back

			fseek(users, 0, SEEK_SET);
			for (int i = 0, havas = 0; i < 100000; i++)
			{
				fscanf(users, "%d\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s", &type, account_id_temp, account_password_temp, hesab_num_temp, Phone_temp, f_name_temp, l_name_temp);
				if (type == 0)
				{
					havas++;
					fseek(users, -126, SEEK_CUR);
					fprintf(users, "\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s", ac_id, ac_pas, hesab_num, Phone, f_name, l_name);
					fclose(users);
					users = fopen("E:/users.txt", "r+");
					schange();
					break;
				}
				if (type != 0 && i == 99999 && havas == 0)
				{errore2(); control = 0;}

			}//end of 'for' sercher

			if (control == 0){ cout << "\a"; continue; } //Exit
		}
		//End Change information


		//discount code
		if (control == 6)
		{

		}
		//End discount code


		//Vehicles Setting
		if (control == 7)
		{
			char device[20];
			char speed[5], capacity[5], cost[5];
			char device_t[20];
			int speed_d = 0, capacity_d = 0, cost_d = 0;
			int speed_t = 0, capacity_t = 0, cost_t = 0;
		
			char v[] = "Exit-275+190\tBus0000+150\tTrain+000+100\tAirplane0000+050\t\t";
			vehicle = page(v);
			if (vehicle == 0) { continue; }
			if (vehicle == 1) strcpy(device, "Bus");
			if (vehicle == 2) strcpy(device, "Train");
			if (vehicle == 3) strcpy(device, "Airplan");
		
			fseek(vehicles, 0, SEEK_SET);

			control=initialize_vehicles(speed, capacity, cost);
			if (control == 0) { continue; } //If press Back

			//Convert string to integer(Beginning)
			int legth = strlen(speed);
			for (int i = 0; speed[i] != 0; i++)
				speed_d += (speed[i] - '0')*pow(10.0, --legth);

			legth = strlen(capacity);
			for (int i = 0; capacity[i] != 0; i++)
				capacity_d += (capacity[i] - '0')*pow(10.0, --legth);

			legth = strlen(cost);
			for (int i = 0; cost[i] != 0; i++)
				cost_d += (cost[i] - '0')*pow(10.0, --legth);
			//Convert string to integer(Ending)

			for (int i = 0, havas=0; i < 10; i++)
			{
				fscanf(vehicles, "%20s%5d%5d%5d", device_t, &speed_t, &capacity_t, &cost_t);
				if (strcmp(device_t, device) == 0)
				{
					havas++;
					fseek(vehicles, -35, SEEK_CUR);
					fprintf(vehicles, "%20s%5d%5d%5d\n", device, speed_d, capacity_d, cost_d);
					fclose(vehicles);
					vehicles = fopen("E:/vehicles.txt", "r+");
				}
				if (i==9 && havas==0)
				{
					fseek(vehicles, 0, SEEK_END);
					fprintf(vehicles, "%20s%5d%5d%5d\n", device, speed_d, capacity_d, cost_d);
					fclose(vehicles);
					vehicles = fopen("E:/vehicles.txt", "r+");
				}
			}//End for
			continue;
		}
		//Vehicles Setting


	}//End while

}
void Driver_pannel(char f_name[])
{
	int control, origin=0, destination=0, price;
	int origin_t, destination_t;
	char origin_str[10], destination_str[10];
	char vehicle[10], time[10], date[10];
	unsigned long number_trips;

	char d[300] = "Exit-275+190\tDefine travel-000+140\tShow Trips-000+110\tchange Trips-000+080\tDelay on trip-000+050\tCancel on trip-000+020\tTravel history-000-010\t\t";
	while (true)
	{
		control = page(d);
		DrawCanvas();
		//(0)Exit (1)Define travel (2)See travelers (3)Show Trips (4)change Trips (5)Delay on trip (6)Cancel on trip (7)Travel history

		if (control == 0) { cout << "\a"; break; }//End

		//Define travel
		if (control == 1)
		{
			destination = 0;
			origin = 0;
			int city, x1, x2, y1, y2;
			number_trips = ((rand() + 1358) / 10)*((rand() + 1498) / 10);
			control == Define_travel(origin_str, destination_str, vehicle, time, date);

			if (control==0) { continue; }//If press Back

			//Convert string to integer(Beginning)
			int legth1 = strlen(origin_str);
			for (int i = 0; origin_str[i] != 0; i++)
				origin += (origin_str[i] - '0')*pow(10.0, --legth1);

			int legth2 = strlen(destination_str);
			for (int i = 0; destination_str[i] != 0; i++)
				destination += (destination_str[i] - '0')*pow(10.0, --legth2);
			//Convert string to integer (Ending)

			fseek(cities, 0, SEEK_SET);
			for (int i = 0; i < 300; i++)
			{
				fscanf(cities, "%d\t%d\t%d", &city, &x1, &y1);
				if (city == origin) { break; }
			}
			fseek(cities, 0, SEEK_SET);
			for (int i = 0; i < 300; i++)
			{
				fscanf(cities, "%d\t%d\t%d", &city, &x2, &y2);
				if (city == destination) { break; }
			}
			fseek(cities, 0, SEEK_SET);

			price = (int)sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)) * cost(vehicle);

			//char time_temp[10];
			//_strtime_s(time_temp, 9);

			fseek(trips, 0, SEEK_END);
			fprintf(trips, "%20s%10u%5d%5d%10s%10s%10s%10d\n", f_name, number_trips, origin, destination, time, date, vehicle, price); //80byte
			fclose(trips);
			trips = fopen("E:/trips.txt", "r+");
			sabt2();
		}
		//End Define travel


		//See travels
		if (control == 2)
		{



		}
		//End See travels


		//Show trips
		if (control == 3)
		{
			int havas = 0;
			char f_name_t[20];
			fseek(trips, 0, SEEK_SET);
			for (int i = 0; i < 1000; i++)
			{
				fscanf(trips, "%20s%10u%5d%5d%10s%10s%10s%10d\n", f_name_t, &number_trips, &origin, &destination, time, date, vehicle, &price);
				if (strcmp(f_name_t, f_name) == 0);
				{
					control = show_trips(f_name_t, number_trips, origin, destination, time, date, vehicle, price);
					if (control == 0) { havas = 1; break; }
				}

			}
			if (havas == 1) { continue; }
		}
		//End Show Trips


		//change Trips
		if (control == 4)
		{
			int havas=0;
			char f_name_t[20];
			fseek(trips, 0, SEEK_SET);
			for (int i = 0; i < 1000; i++)
			{
				fscanf(trips, "%20s%10u%5d%5d%10s%10s%10s%10d\n", f_name_t, &number_trips, &origin, &destination, time, date, vehicle, &price);
				if (strcmp(f_name_t, f_name) == 0);
				{
					control = chang_trips(number_trips,time, date);
					if (control == 0) { havas = 1; break; }
				}

			}
			if (havas == 1) { continue; }
			schange();
		}
		//change Trips

	}//End while
	
}
void user_pannel(char id[])
{
	int control, type;
	int origin = 0, destination = 0, price, number_trips, hesab_inventory=0;
	int origin_t, destination_t;
	char origin_str[10], destination_str[10], vehicle[10], time[10], date[10], vehicle_t[10];
	char ac_pas[20], ac_id[20];
	char hesab_num[20], hesab_pas[20];
	char phone[20], f_name[20], f_name_d[20], l_name[20];
	char hesab_num_temp[20], hesab_pas_temp[20], hesab_inventory_temp[20];

	while (true){

		char a[200] = "Exit-275+190\tBuy tickets-200+120\tCancellation tickets+200+120\tView records-200+080\tMy account balance+200+080\t\t";
		control = page(a); //(0)Exit (1)Buy tickets (2)Cancellation tickets (3)View records (4)My account balance

		if (control == 0){ cout << "\a";  break; } //Exit
		
		//Buy tickets
		if (control == 1)
		{
			origin = 0;
			destination = 0;

			control = getmm(origin_str, destination_str, vehicle);

			if (control == 0) { continue; } //Back

			//Convert string to integer(Beginning)
			int legth1 = strlen(origin_str);
			for (int i = 0; origin_str[i] != 0; i++)
				origin += (origin_str[i] - '0')*pow(10.0, --legth1);

			int legth2 = strlen(destination_str);
			for (int i = 0; destination_str[i] != 0; i++)
				destination += (destination_str[i] - '0')*pow(10.0, --legth2);
			//Convert string to integer (Ending)

			int havas = 0;
			fseek(trips, 0, SEEK_SET);

			int havas2 = 0;
			for (int i = 0 ; i < 10000 ; i++)
			{
				if (havas2 == 1) { break; }
				fscanf(trips, "%20s%10d%5d%5d%10s%10s%10s%10d", f_name_d, &number_trips, &origin_t, &destination_t, time, date, vehicle_t, &price);

				if ((origin == origin_t) && (destination_t == destination) && (strcmp(vehicle,vehicle_t)==0) )
				{
					control = buy_ticket(f_name_d, number_trips, origin, destination, time, date, vehicle, price); //(0)Back (2)Buy (3)Next
					
					if (control == 0) { havas = 1; break; } //If press Back
					if (control == 2) //Buy
					{
						havas2 = 1;
						//پیدا کردن حساب خریدار
						fseek(users, 0, SEEK_SET);

						for (int i = 0; i < 10000; i++)
						{
							fscanf(users, "%d\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s", &type, ac_id, ac_pas, hesab_num, phone, f_name, l_name);
							if (strcmp(id, ac_id) == 0) { break; }
						}

						fseek(accounts, 0, SEEK_SET);
						for (int j = 0; j < 10000; j++)
						{
							fscanf(accounts, "%s\t%s\t%s", hesab_num_temp, hesab_pas_temp, hesab_inventory_temp);
							if (strcmp(hesab_num_temp, hesab_num) == 0) { break;}
						} 
						//پیدا کردن حساب خریدار

						
						//Convert string to integer(Beginning)
						int legth1 = strlen(hesab_inventory_temp);
						for (int i = 0; hesab_inventory_temp[i] != 0; i++)
							hesab_inventory += (hesab_inventory_temp[i] - '0')*pow(10.0, --legth1);
						//Convert string to integer(Ending)

						if (hesab_inventory > price)
						{
							control = finality(price); //(0)Exit (1)Yes (2)No
							if(control==0 || control==2) { havas = 1; break; } //If press Exit

							if (control == 1)
							{
								int h_balence_integer=0;
								int h_balence_integer2=0;
								char ai[20], ap[20], hn[20], p[20], fn[20], ln[20];
								char ai2[20], ap2[20], hn2[20], p2[20], fn2[20], ln2[20];
								char h_name[20], h_pas[20], h_balence[20], h_balence_t[20];
								char h_name2[20], h_pas2[20], h_balence2[20], h_balence_t2[20], hesab_inventory_temp2[20];
								
								{//پیدا کردن حساب مدیر
									fseek(users, 0, SEEK_SET);
									for (int i = 0; i < 10000; i++)
									{
										fscanf(users, "%d\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s", &type, ai, ap, hn, p, fn, ln);
										if (type == 0){ break; }
									}

									fseek(accounts, 0, SEEK_SET);
									for (int j = 0; j < 100000; j++)
									{
										fscanf(accounts, "%s\t%s\t%s\n", h_name, h_pas, h_balence);
										if (strcmp(h_name, hn) == 0) { break; }
									}
								}//پیدا کردن حساب مدیر

								{//پیدا کردن حساب راننده
									fseek(users, 0, SEEK_SET);
									for (int i = 0; i < 10000; i++)
									{
										fscanf(users, "%d\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s", &type, ai2, ap2, hn2, p2, fn2, ln2);
										if (strcmp(fn2, f_name_d) == 0){ break; }
									}

									fseek(accounts, 0, SEEK_SET);
									for (int j = 0; j < 100000; j++)
									{
										fscanf(accounts, "%s\t%s\t%s", h_name2, h_pas2, h_balence2);
										if (strcmp(h_name2, hn2) == 0) { break; }
									}
								}//پیدا کردن حساب راننده


							//کم کردن از حساب شخص
								hesab_inventory -= 0.9*price;
								integr_to_character(hesab_inventory, hesab_inventory_temp);
								fseek(accounts, 0, SEEK_SET);
								for (int j = 0; j < 100000; j++)
								{
									fscanf(accounts, "%s\t%s\t%s", hesab_num_temp, hesab_pas_temp, hesab_inventory_temp2);
									if (strcmp(hesab_num_temp, hesab_num) == 0)
									{
										fseek(accounts, -18, SEEK_CUR);
										fprintf(accounts, "%s\t%s\t%s", hesab_num_temp, hesab_pas_temp, hesab_inventory_temp);
										fclose(accounts);
										accounts = fopen("E:/accounts.txt", "r+");
										break;
									}
								}


							//اضافه کردن به حساب راننده
								//Convert string to integer(Beginning)
								int legth1 = strlen(h_balence2);
								for (int i = 0; h_balence2[i] != 0; i++)
									h_balence_integer2 += (h_balence2[i] - '0')*pow(10.0, --legth1);
								//Convert string to integer(Ending)

								h_balence_integer2 += 0.9*0.9*price;
								integr_to_character(h_balence_integer2, h_balence2);
								fseek(accounts, 0, SEEK_SET);
								for (int j = 0; j < 100000; j++)
								{
									fscanf(accounts, "%s\t%s\t%s", h_name2, h_pas2, h_balence_t2);
									if (strcmp(h_name2, hn2) == 0)
									{
										fseek(accounts, -18, SEEK_CUR);
										fprintf(accounts, "%s\t%s\t%s", h_name2, h_pas2, h_balence2);
										fclose(accounts);
										accounts = fopen("E:/accounts.txt", "r+");
										break;
									}
								}

							//اضافه کردن به حساب مدیر
								//Convert string to integer(Beginning)
								int legth2 = strlen(h_balence);
								for (int i = 0; h_balence[i] != 0; i++)
									h_balence_integer += (h_balence[i] - '0')*pow(10.0, --legth2);
								//Convert string to integer(Ending)
								h_balence_integer += 0.9*0.1*price;
								integr_to_character(h_balence_integer, h_balence);
								fseek(accounts, 0, SEEK_SET);
								for (int j = 0; j < 100000; j++)
								{
									fscanf(accounts, "%s\t%s\t%s", h_name, h_pas, h_balence_t);
									if (strcmp(h_name, hn2) == 0)
									{
										fseek(accounts, -18, SEEK_CUR);
										fprintf(accounts, "%s\t%s\t%s", h_name, h_pas, h_balence);
										fclose(accounts);
										accounts = fopen("E:/accounts.txt", "r+");
										break;
									}
								}
								sbuy();
							}
						}
						else{ havas = 1; break;}
					}
				}
			}//End for
			if (havas == 1) { continue; }
			else if(havas2==0) { yaftnashod(); continue; }
		}
		//End Buy tickets


		//My account balance
		if (control == 4)
		{
			fseek(users, 0, SEEK_SET);
			for (int i = 0; i < 10000; i++)
			{
				fscanf(users, "%d\t%20s\t%20s\t%20s\t%20s\t%20s\t%20s", &type, ac_id, ac_pas, hesab_num, phone, f_name, l_name);
				if (strcmp(id,ac_id)==0) {break;}

			}//End for
			fseek(accounts, 0, SEEK_SET);
			for (int j = 0; j < 10000; j++)
			{
				fscanf(accounts, "%s\t%s\t%s", hesab_num_temp, hesab_pas_temp, hesab_inventory_temp);
				if (strcmp(hesab_num_temp, hesab_num) == 0)
				{
					ResetCanvas();
					box(hesab_inventory_temp, 0, 0);
					box("Ok", 0, -150);
					DrawCanvas();

					while (!tach("Ok", 0, -150))
					{
						ResetCanvas();
						box(hesab_inventory_temp, 0, 0);
						box("Ok", 0, -150);
						DrawCanvas();
					}
				}
			} //End for

		}
		//End My account balance



	}//End while
}

double distance(int city1, int city2)
{
	int city, x1, y1 , x2 , y2;

	fseek(cities, 0, SEEK_SET);
	for (int i = 0; i < 300; i++)
	{
		fscanf(cities, "%d\t%d\t%d", &city, &x1, &y1);
		if (city == city1) { break; }
	}

	fseek(cities, 0, SEEK_SET);
	for (int i = 0; i < 300; i++)
	{
		fscanf(cities, "%d\t%d\t%d", &city, &x1, &y1);
		if (city == city2) { break; }
	}
	fseek(cities, 0, SEEK_SET);

	return ( sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) ) );
}
int cost(char v[])
{
	char vt[20];
	int speed, cap, price;
	fseek(cities, 0, SEEK_SET);
	for (int i = 0; i < 10; i++)
	{
		fscanf(vehicles, "%20s%5d%5d%5d", vt, &speed, &cap, &price);
		if(strcmp(v,vt)==0) { break; }
	}
	fseek(cities, 0, SEEK_SET);
	return price;
}