#include <stdio.h>   // printf, scanf(_s)
#include <conio.h>   // getch()
#include <string.h>
#include <stdlib.h>	 // RANAD_MAX, malloc, atof...
#include <math.h>    // matematikai készlet
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

#define file_name "tvmusor.txt"
#define STR_LENGHT 100


int main() {

	char* input_chanel = (char*)malloc(STR_LENGHT);
	int is_chanel_exist = 0;
	int input_hour = 0;
	int input_minute = 0;

	while (!is_chanel_exist)
	{
		memset(input_chanel, 0, STR_LENGHT);
		printf("The chanel you're looking for: ");
		scanf_s("%s", input_chanel, STR_LENGHT);
		if ((strcmp("M1", input_chanel) == 0 || strcmp("M2", input_chanel) == 0 || strcmp("RTLKLUB", input_chanel) == 0 || strcmp("TV2", input_chanel) == 0 || strcmp("AXN", input_chanel) == 0 || strcmp("COOL", input_chanel) == 0))
			is_chanel_exist = 1;
		else
			printf("The given chanel doesn't exist\n");
	}

	printf("When do you want to watch TV?\n");
	scanf_s("%i:%i", &input_hour, &input_minute);
	int input_time = input_hour * 100 + input_minute;

	FILE* file;

	fopen_s(&file, file_name, "r");
	if (!file)                        //hiba esetén
	{
		printf("Hiba: a fajl nem talalhato (%s)\n", file_name);
		//getchar();
		return -1;                    //vissza a hívóhoz
	}

	char* row = (char*)malloc(STR_LENGHT);
	char* chanel, * program, * hour_str, * minute_str, * next;
	int hour, minute;

	char* chanel_prev, * program_prev;
	int hour_prev, minute_prev;

	while (!feof(file))
	{
		memset(row, 0, STR_LENGHT);            //előző string törlése
		fgets(row, STR_LENGHT, file);

		//ha sikerült beolvasni valamit -> feldolgozzuk
		if (strlen(row) > 0) //nem üres, van benne elválasztó
		{
			chanel = strtok_s(row, "\t", &next);
			hour_str = strtok_s(NULL, ":", &next);
			minute_str = strtok_s(NULL, "\t", &next);
			program = strtok_s(NULL, "\n", &next);

			hour = atoi(hour_str);
			minute = atoi(minute_str);

			if (strcmp(chanel, input_chanel) == 0 && (hour <= 19 ||(hour == 20 && minute == 0)) && (hour >= 17 || (hour == 16 && minute >= 15)))
			{
				if (minute < 10)
					printf("%s\t%i:0%i\t%s\n", chanel, hour, minute, program);
				else
					printf("%s\t%i:%i\t%s\n", chanel, hour, minute, program);

			}
		}
	}
	fclose(file);

	fopen_s(&file, file_name, "r");
	if (!file)                        //hiba esetén
	{
		printf("Hiba: a fajl nem talalhato (%s)\n", file_name);
		//getchar();
		return -1;                    //vissza a hívóhoz
	}

	for (int i = 0; i < 100; i++)printf("=");
	printf("\n\n");

	minute_prev = 100;
	hour_prev = 100;
	chanel_prev = "";
	program_prev = "";

	while (!feof(file))
	{
		memset(row, 0, STR_LENGHT);            //előző string törlése
		fgets(row, STR_LENGHT, file);

		//ha sikerült beolvasni valamit -> feldolgozzuk
		if (strlen(row) > 0) //nem üres, van benne elválasztó
		{
			chanel = strtok_s(row, "\t", &next);
			hour_str = strtok_s(NULL, ":", &next);
			minute_str = strtok_s(NULL, "\t", &next);
			program = strtok_s(NULL, "\n", &next);

			hour = atoi(hour_str);
			minute = atoi(minute_str);
			int time = hour * 100 + minute;
			int prev_time = hour_prev * 100 + minute_prev;

			if ((input_time >= prev_time && input_time < time) || (input_time >= prev_time && time < 100 && prev_time > 1200))
			{
				if (minute < 10)
					printf("%s\t%i:0%i\t%s\n", chanel_prev, hour_prev, minute_prev, program_prev);
				else
					printf("%s\t%i:%i\t%s\n", chanel_prev, hour_prev, minute_prev, program_prev);
			}

			chanel_prev = chanel;
			program_prev = program;
			hour_prev = hour;
			minute_prev = minute;
		}
	}
	fclose(file);

	free(row);
	free(input_chanel);
}