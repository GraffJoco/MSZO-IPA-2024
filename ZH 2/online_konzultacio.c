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
	// Kezdeti változók
	char* input_channel = (char*)malloc(STR_LENGHT); // kért csatorna neve
	int does_channel_exist = 0; // létezik a csatorna? (bool is lehetne)
	// Beolvasott időpont óra, perc
	int input_hour = 0;
	int input_minute = 0;

	// Addig nyaggatjuk a felhasználót, amíg nincs jó csatorna
	while (!does_channel_exist)
	{
		// csatorna nevének olvasása
		memset(input_channel, 0, STR_LENGHT);
		printf("The channel you're looking for: ");
		scanf_s("%s", input_channel, STR_LENGHT); // <- Ide inkább gets_s lenne jó!
		
		// ellenőrizzük, hogy a beolvasott csatorna létezik-e
		if ((strcmp("M1", input_channel) == 0 || strcmp("M2", input_channel) == 0 || strcmp("RTLKLUB", input_channel) == 0 || strcmp("TV2", input_channel) == 0 || strcmp("AXN", input_channel) == 0 || strcmp("COOL", input_channel) == 0))
			does_channel_exist = 1;
		else
			printf("The given channel doesn't exist\n");
	}

	printf("When do you want to watch TV?\n");
	scanf_s("%i:%i", &input_hour, &input_minute);
	int input_time = input_hour * 100 + input_minute;

	// Fájlolvasás
	FILE* file;

	fopen_s(&file, file_name, "r");
	if (!file)                        //hiba esetén
	{
		printf("Hiba: a fajl nem talalhato (%s)\n", file_name);
		//getchar();
		return -1;                    //vissza a hívóhoz
	}

	// Sor string
	char* row = (char*)malloc(STR_LENGHT);

	// ideiglenes string, abból int változók
	char* channel, * program, * hour_str, * minute_str, * next;
	int hour, minute;

	char* channel_prev, * program_prev;
	int hour_prev, minute_prev;

	while (!feof(file))
	{
		memset(row, 0, STR_LENGHT);            //előző string törlése
		fgets(row, STR_LENGHT, file);

		//ha sikerült beolvasni valamit -> feldolgozzuk
		if (strlen(row) > 0) //nem üres, van benne elválasztó
		{
			// string elemeinek olvasása CSATORNA\tORA:PERC\tPROGRAMNEV\n formátumból
			channel = strtok_s(row, "\t", &next);
			hour_str = strtok_s(NULL, ":", &next);
			minute_str = strtok_s(NULL, "\t", &next);
			program = strtok_s(NULL, "\n", &next);

			// strtok stringet ad, int kell
			hour = atoi(hour_str);
			minute = atoi(minute_str);

			// kicsit brute force kiírás (ha a perc <10, akkor kell 0 elé, hogy szépen nézzen ki)
			// Ha a műsor 16:15 és 20:00 között van, akkor kiírjuk a konzolba
			if (strcmp(channel, input_channel) == 0 && (hour <= 19 ||(hour == 20 && minute == 0)) && (hour >= 17 || (hour == 16 && minute >= 15)))
			{
				if (minute < 10)
					printf("%s\t%i:0%i\t%s\n", channel, hour, minute, program);
				else
					printf("%s\t%i:%i\t%s\n", channel, hour, minute, program);

			}
		}
	}
	fclose(file);

	// fájl újranyitása további feldolgozásra
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
	channel_prev = "";
	program_prev = "";

	// Megadott idő utáni események kiírása
	while (!feof(file))
	{
		memset(row, 0, STR_LENGHT);            //előző string törlése
		fgets(row, STR_LENGHT, file);

		//ha sikerült beolvasni valamit -> feldolgozzuk
		if (strlen(row) > 0) //nem üres, van benne elválasztó
		{
			channel = strtok_s(row, "\t", &next);
			hour_str = strtok_s(NULL, ":", &next);
			minute_str = strtok_s(NULL, "\t", &next);
			program = strtok_s(NULL, "\n", &next);

			hour = atoi(hour_str);
			minute = atoi(minute_str);
			int time = hour * 100 + minute;
			int prev_time = hour_prev * 100 + minute_prev;

			// Bekért idő összehasonlítása a mostanival
			if ((input_time >= prev_time && input_time < time) || (input_time >= prev_time && time < 100 && prev_time > 1200))
			{
				if (minute < 10)
					printf("%s\t%i:0%i\t%s\n", channel_prev, hour_prev, minute_prev, program_prev);
				else
					printf("%s\t%i:%i\t%s\n", channel_prev, hour_prev, minute_prev, program_prev);
			}

			channel_prev = channel;
			program_prev = program;
			hour_prev = hour;
			minute_prev = minute;
		}
	}

	// Fájl zárás, és memória felszabadítása (el ne felejtsd!)
	fclose(file);

	free(row);
	free(input_channel);
}