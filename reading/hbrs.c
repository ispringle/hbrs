/********************************
*Horner Bible Reading System v0.2.0
Copyright (C) 2018 Ian S. Pringle

License GNU GPLv3+: GNU GPL Version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software. You are free to change and redistribute it.
There is NO warranty.
********************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//Define Books by their chapter length
#define GENESIS 50
#define EXODUS 40
#define LEVITICUS 27
#define NUMBERS 36
#define DEUTERONOMY 34
#define JOSHUA 24
#define JUDGES 21
#define RUTH 4
#define OSAMUEL 31
#define TSAMUEL 24
#define OKINGS 22
#define TKINGS 25
#define OCHRONICLES 29
#define TCHRONICLES 36
#define EZRA 10
#define NEHEMIAH 13
#define ESTHER 10
#define JOB 42
#define PSALMS 150
#define PROVERBS 31
#define ECCLESIASTES 12
#define SONGOFSONGS 8
#define ISAIAH 66
#define JEREMIAH 52
#define LAMENTATIONS 5
#define EZEKIEL 48
#define DANIEL 12
#define HOSEA 14
#define JOEL 3
#define AMOS 9
#define OBADIAH 1
#define JONAH 4
#define MICAH 7
#define NAHUM 3
#define HABAKKUK 3
#define ZEPHANIAH 3
#define HAGGAI 2
#define ZECHARIAH 14
#define MALACHI 4
#define MATTHEW 28
#define MARK 16
#define LUKE 24
#define JOHN 21
#define ACTS 28
#define ROMANS 16
#define OCORINTHIANS 16
#define TCORINTHIANS 13
#define GALATIANS 6
#define EPHESIANS 6
#define PHILIPPIANS 4
#define COLOSSIANS 4
#define OTHESSALONIANS 5
#define TTHESSALONIANS 3
#define OTIMOTHY 6
#define TTIMOTHY 4
#define TITUS 3
#define PHILEMON 1
#define HEBREWS 13
#define JAMES 5
#define OPETER 5
#define TPETER 3
#define OJOHN 5
#define TJOHN 1
#define HJOHN 1
#define JUDE 1
#define REVELATION 22

//Declare structs
typedef struct reading{
	char * book;
	int chapter;
} reading;

typedef struct r_plan {
	int day;
	char * date;
} r_plan;

//Declare functions
void get_readings(int day);

void read(void);
int write(void);
char * curtime(void);
int comp_time(void);
reading list0 (int day);
reading list1 (int day);
reading list2 (int day);
reading list3 (int day);
reading list4 (int day);
reading list5 (int day);
reading list6 (int day);
reading list7 (int day);
reading list8 (int day);
reading list9 (int day);

static r_plan * plan;

int main (int argc, char *argv[]) {

// Determine if a day is provided in argv
	int day;
	if(argc > 1) {
		day = atoi(argv[1]);
	} else {
	//Read hbrs.data and save to struct plan
		plan = malloc(sizeof(r_plan));
		int n = sizeof("01/01/70") + 1;
		plan->date = malloc(sizeof(n));
		read();
		day = plan->day;
	
	//Determines if date has changed since last time it was saved to hbrs. If it has, increases day and date
		int new_day = comp_time();
		if (new_day == 0) {
			plan->day = ++day;
			plan->date = curtime();
		}
		
	//Increase day by 1 and write back to hbrs.data
	//plan->day = ++day;
		int success = write();
		if (success == 1) {
			free(plan);
			return 0;
		}
		else {
			printf("An error occcured while writing to file!\n");
			free(plan);
			return 1;
		}
	}

//Get readings
// printf("Readings for %s, day number %d:\n", plan->date, day);
	get_readings(day);

}

void get_readings(int day) {

//Get each reading and set it into struct reading
	reading list_0 = list0(day);
	reading list_1 = list1(day);
	reading list_2 = list2(day);
	reading list_3 = list3(day);
	reading list_4 = list4(day);
	reading list_5 = list5(day);
	reading list_6 = list6(day);
	reading list_7 = list7(day);
	reading list_8 = list8(day);
	reading list_9 = list9(day);
//Print each reading out.
	printf("%s.%d, ", list_0.book, list_0.chapter);
	printf("%s.%d, ", list_1.book, list_1.chapter);
	printf("%s.%d, ", list_2.book, list_2.chapter);
	printf("%s.%d, ", list_3.book, list_3.chapter);
	printf("%s.%d, ", list_4.book, list_4.chapter);
	printf("%s.%d, ", list_5.book, list_5.chapter);
	printf("%s.%d, ", list_6.book, list_6.chapter);
	printf("%s.%d, ", list_7.book, list_7.chapter);
	printf("%s.%d, ", list_8.book, list_8.chapter);
	printf("%s.%d\n", list_9.book, list_9.chapter);
}

void read(void) {

	FILE * fp;

	fp = fopen("hbrs.data", "r");
	if (fp == NULL) {
		printf("Initializing new reading plan!\n");
		plan->day = 1;
		plan->date = curtime();
		write();
		return;
	}
	else {
		fscanf(fp, "%d %s", &plan->day, plan->date);
	}

	fclose(fp);
	return;
}

int write(void) {
	FILE * fp;

	fp = fopen("hbrs.data", "w");

	if (fp == NULL) {
		fprintf(fp, "%d %s\n", plan->day, plan->date);
	}
	else {
		fprintf(fp, "%d %s\n", plan->day, plan->date);
	}
	fclose(fp);
	return 1;
}

char * curtime(void) {
	time_t rawtime;
	struct tm *info;
	static char buffer[80];

	time (&rawtime );

	info = localtime ( &rawtime );

	strftime(buffer, 80, "%x", info);
	return buffer;
}

int  comp_time(void) {
	char * today = curtime();
	//printf("%s\n", today);
	if (strcmp(today, plan->date) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

reading list0 (int day) {
	reading list;
	while (day > (MATTHEW + MARK + LUKE + JOHN)) {
		day -= (MATTHEW + MARK + LUKE +JOHN);
	}
	if (day <= MATTHEW) {
		list.chapter = day;
		list.book = "Matt";
		return list;
	}
	day -= MATTHEW;
	if (day <= MARK) {
		list.chapter = day;
		list.book = "Mark";
		return list;
	}
	day -= MARK;
	if (day <= LUKE) {
		list.chapter = day;
		list.book = "Luke";
		return list;
	}
	day -= LUKE;
	if (day <= JOHN) {
		list.chapter = day;
		list.book  = "John";
		return list;
	}
	else {
		list.book = "error!";
		return list;
	}
}

reading list1 (int day) {
	reading list;
	while (day > (GENESIS + EXODUS + LEVITICUS + NUMBERS + DEUTERONOMY)) {
		day -= (GENESIS + EXODUS + LEVITICUS + NUMBERS + DEUTERONOMY);
	}
	if (day <= GENESIS) {
		list.chapter = day;
		list.book = "Gen";
		return list;
	}
	day -= GENESIS;
	if (day <= EXODUS) {
		list.chapter = day;
		list.book = "Exod";
		return list;
	}
	day -= EXODUS;
	if (day <= LEVITICUS) {
		list.chapter = day;
		list.book = "Lev";
		return list;
	}
	day -= LEVITICUS;
	if (day <= NUMBERS) {
		list.chapter = day;
		list.book = "Num";
		return list;
	}
	day -= NUMBERS;
	if (day <= DEUTERONOMY) {
		list.chapter = day;
		list.book = "Deut";
		return list;
	}
	else{
		list.book = "error!";
		return list;
	}
}

reading list2 (int day) {
	reading list;
	while (day > (ROMANS + OCORINTHIANS + TCORINTHIANS + GALATIANS + EPHESIANS + PHILIPPIANS + COLOSSIANS + HEBREWS)) {
		day -= (ROMANS + OCORINTHIANS + TCORINTHIANS + GALATIANS + EPHESIANS + PHILIPPIANS + COLOSSIANS + HEBREWS);
	}
	if (day <= ROMANS) {
		list.chapter = day;
		list.book = "Rom";
		return list;
	}
	day -= ROMANS;
	if (day <= OCORINTHIANS) {
		list.chapter = day;
		list.book = "1Cor";
		return list;
	}
	day -= OCORINTHIANS;
	if (day <= TCORINTHIANS) {
		list.chapter = day;
		list.book = "2Cor";
		return list;
	}
	day -= TCORINTHIANS;
	if (day <= GALATIANS) {
		list.chapter = day;
		list.book = "Gal";
		return list;
	}
	day -= GALATIANS;
	if (day <= EPHESIANS) {
		list.chapter = day;
		list.book = "Eph";
		return list;
	}
	day -= EPHESIANS;
	if (day <= PHILIPPIANS) {
		list.chapter = day;
		list.book = "Phil";
		return list;
	}
	day -= PHILIPPIANS;
	if (day <= COLOSSIANS) {
		list.chapter = day;
		list.book = "Col";
		return list;
	}
	day -= COLOSSIANS;
	if (day <= HEBREWS) {
		list.chapter = day;
		list.book = "Heb";
		return list;
	}
	else {
		list.book = "error!";
		return list;
	}
}

reading list3 (int day) {
	reading list;
	while (day > (OTHESSALONIANS + TTHESSALONIANS + OTIMOTHY + TTIMOTHY + TITUS + PHILEMON +
				JAMES + OPETER + TPETER + OJOHN + TJOHN + HJOHN + JUDE + REVELATION)) {
		day -= (OTHESSALONIANS + TTHESSALONIANS + OTIMOTHY + TTIMOTHY + TITUS + PHILEMON +
				JAMES + OPETER + TPETER + OJOHN + TJOHN + HJOHN + JUDE + REVELATION);
	}
	if (day <= OTHESSALONIANS) {
		list.chapter = day;
		list.book = "1Thess";
		return list;
	}
	day -= OTHESSALONIANS;
	if (day <= TTHESSALONIANS) {
		list.chapter = day;
		list.book = "2Thess";
		return list;
	}
	day -= TTHESSALONIANS;
	if (day <= OTIMOTHY) {
		list.chapter = day;
		list.book = "1Tim";
		return list;
	}
	day -= OTIMOTHY;
	if (day <= TTIMOTHY) {
		list.chapter = day;
		list.book = "2Tim";
		return list;
	}
	day -= TTIMOTHY;
	if (day <= TITUS) {
		list.chapter = day;
		list.book = "Titus";
		return list;
	}
	day -= TITUS;
	if (day <= PHILEMON) {
		list.chapter = day;
		list.book = "Phlm";
		return list;
	}
	day -= PHILEMON;
	if (day <= JAMES) {
		list.chapter = day;
		list.book = "Jas";
		return list;
	}
	day -= JAMES;
	if (day <= OPETER) {
		list.chapter = day;
		list.book = "1Pet";
		return list;
	}
	day -= OPETER;
	if (day <= TPETER) {
		list.chapter = day;
		list.book = "2Pet";
		return list;
	}
	day -= TPETER;
	if (day <= OJOHN) {
		list.chapter = day;
		list.book = "1John";
		return list;
	}
	day -= OJOHN;
	if (day <= TJOHN) {
		list.chapter = day;

		list.book = "2John";
		return list;
	}
	day -= TJOHN;
	if (day <= HJOHN) {
		list.chapter = day;
		list.book = "3John";
		return list;
	}
	day -= HJOHN;
	if (day <= JUDE) {
		list.chapter = day;
		list.book = "Jude";
		return list;
	}
	day -= JUDE;
	if (day <= REVELATION) {
		list.chapter = day;
		list.book = "Rev";
		return list;
	}
	else {
		list.book = "error!";
		return list;
	}
}

reading  list4 (int day) {
	reading list;
	while (day > (JOB + ECCLESIASTES + SONGOFSONGS)) {
		day -= (JOB + ECCLESIASTES + SONGOFSONGS);
	}
	if (day <= JOB ) {
		list.chapter = day;
		list.book = "Job";
		return list;
	}
	day -= JOB;
	if (day <=  ECCLESIASTES) {
		list.chapter = day;
		list.book = "Eccl";
		return list;
	}
	day -= ECCLESIASTES;
	if (day <= SONGOFSONGS) {
		list.chapter = day;
		list.book = "Song";
		return list;
	}
	else {
		list.book = "error!";
		return list;
	}
}

reading  list5 (int day) {
	reading list;
	while (day > (PSALMS)) {
		day -= (PSALMS);
	}
	if (day <=  PSALMS) {
		list.chapter = day;
		list.book = "Ps";
		return list;
	}
	else {
		list.book = "error!";
		return list;
	}
}

reading  list6 (int day) {
	reading list;
	while (day > (PROVERBS)) {
		day -= (PROVERBS);
	}
	if (day <=  PROVERBS) {
		list.chapter = day;
		list.book = "Prov";
		return list;
	}
	else {
		list.book = "error!";
		return list;
	}
}

reading  list7 (int day) {
	reading list;
	while (day > (JOSHUA + JUDGES + RUTH + OSAMUEL + TSAMUEL + OKINGS + TKINGS +
				OCHRONICLES + TCHRONICLES + EZRA + NEHEMIAH + ESTHER)) {
		day -= (JOSHUA + JUDGES + RUTH + OSAMUEL + TSAMUEL + OKINGS + TKINGS +
				OCHRONICLES + TCHRONICLES + EZRA + NEHEMIAH + ESTHER) ;
	}
	if (day <= JOSHUA) {
		list.chapter = day;
		list.book = "Josh";
		return list;
	}
	day -= JOSHUA;
	if (day <= JUDGES) {
		list.chapter = day;
		list.book = "Judg";
		return list;
	}
	day -= JUDGES;
	if (day <= RUTH) {
		list.chapter = day;
		list.book = "Ruth";
		return list;
	}
	day -= RUTH;
	if (day <= OSAMUEL) {
		list.chapter = day;
		list.book = "1Sam";
		return list;
	}
	day -= OSAMUEL;
	if (day <= TSAMUEL) {
		list.chapter = day;
		list.book = "2Sam";
		return list;
	}
	day -= TSAMUEL;
	if (day <= OKINGS) {
		list.chapter = day;
		list.book = "1Kgs";
		return list;
	}
	day -= OKINGS;
	if (day <= TKINGS) {
		list.chapter = day;
		list.book = "2Kgs";
		return list;
	}
	day -= TKINGS;
	if (day <= OCHRONICLES) {
		list.chapter = day;
		list.book = "1Chr";
		return list;
	}
	day -= OCHRONICLES;
	if (day <= TCHRONICLES) {
		list.chapter = day;
		list.book = "2Chr";
		return list;
	}
	day -= TCHRONICLES;
	if (day <= EZRA) {
		list.chapter = day;
		list.book = "Ezra";
		return list;
	}
	day -= EZRA;
	if (day <= NEHEMIAH) {
		list.chapter = day;
		list.book = "Neh";
		return list;
	}
	day -= NEHEMIAH;
	if (day <= ESTHER) {
		list.chapter = day;
		list.book = "Esth";
		return list;
	}
	else {
		list.book = "error!";
		return list;
	}
}

reading  list8 (int day) {
	reading list;
	while (day > (ISAIAH + JEREMIAH + LAMENTATIONS + EZEKIEL + DANIEL + HOSEA + JOEL + AMOS +
			OBADIAH + JONAH + MICAH + NAHUM + HABAKKUK + ZEPHANIAH + HAGGAI + ZECHARIAH + MALACHI)) {
		day -= (ISAIAH + JEREMIAH + LAMENTATIONS + EZEKIEL + DANIEL + HOSEA + JOEL + AMOS +
			OBADIAH + JONAH + MICAH + NAHUM + HABAKKUK + ZEPHANIAH + HAGGAI + ZECHARIAH + MALACHI);
	}
	if (day <= ISAIAH) {
		list.chapter = day;
		list.book = "Isa";
		return list;
	}
	day -= ISAIAH;
	if (day <= JEREMIAH) {
		list.chapter = day;
		list.book = "Jer";
		return list;
	}
	day -= JEREMIAH;
	if (day <= LAMENTATIONS) {
		list.chapter = day;
		list.book = "Lam";
		return list;
	}
	day -= LAMENTATIONS;
	if (day <= EZEKIEL) {
		list.chapter = day;
		list.book = "Ezek";
		return list;
	}
	day -= EZEKIEL;
	if (day <= DANIEL) {
		list.chapter = day;
		list.book = "Dan";
		return list;
	}
	day -= DANIEL;
	if (day <= HOSEA) {
		list.chapter = day;
		list.book = "Hos";
		return list;
	}
	day -= HOSEA;
	if (day <= JOEL) {
		list.chapter = day;
		list.book = "Joel";
		return list;
	}
	day -= JOEL;
	if (day <= AMOS) {
		list.chapter = day;
		list.book = "Amos";
		return list;
	}
	day -= AMOS;
	if (day <= OBADIAH) {
		list.chapter = day;
		list.book = "Obad";
		return list;
	}
	day -= OBADIAH;
	if (day <= JONAH) {
		list.chapter = day;
		list.book = "Jonah";
		return list;
	}
	day -= JONAH;
	if (day <= MICAH) {
		list.chapter = day;
		list.book = "Mic";
		return list;
	}
	day -= MICAH;
	if (day <= NAHUM) {
		list.chapter = day;
		list.book = "Nah";
		return list;
	}
	day -= NAHUM;
	if (day <= HABAKKUK) {
		list.chapter = day;
		list.book = "Hab";
		return list;
	}
	day -= HABAKKUK;
	if (day <= ZEPHANIAH) {
		list.chapter = day;
		list.book = "Zeph";
		return list;
	}
	day -= ZEPHANIAH;
	if (day <= HAGGAI) {
		list.chapter = day;
		list.book = "Hag";
		return list;
	}
	day -= HAGGAI;
	if (day <= ZECHARIAH) {
		list.chapter = day;
		list.book = "Zech";
		return list;
	}
	day -= ZECHARIAH;
	if (day <= MALACHI) {
		list.chapter = day;
		list.book = "Mal";
		return list;
	}
	else {
		list.book = "error!";
		return list;
	}
}

reading  list9 (int day) {
	reading list;
	while (day > (ACTS)) {
		day -= (ACTS);
	}
	if (day <= ACTS) {
		list.chapter = day;
		list.book = "Acts";
		return list;
	}
	else {
		list.book = "error!";
		return list;
	}
}

/* Example Func
 * reading list# (int day) {
 * 	reading list;
 * 	while (day > (SUM_OF_ALL_BOOKS_IN_LIST)) {
 * 		day -= (SUM_OF_AL_BOOKS_IN_LIST);
 * 	}
 * 	if (day <= BOOK_1) {
 * 		list.chapter = day;
 * 		list.book = "Book_1";
 *		return list;
 * 	}
 *	day -= BOOK_1;
 * 	if (day <= BOOK_2) {
 * 		list.chapter = day;
 * 		list.book = "Book_2";
 *		return list;
 * 	}
 *	day -= BOOK_2;
 * 	if (day <= BOOK_3) {
 * 		list.chapter = day;
 * 		list.book = "Book_3";
 *		return list;
 * 	}
 * 	else {
 * 		list.book = "error!";
 *		return list;
 * 	}
 * }
 */
