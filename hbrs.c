#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
#define JOB 10
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

//Each book of the Bible is defined as the total number of books in the book.
//Then, each book for the day (10 total) is determined by determing which book
//corresponds with the current day. Example:
//day = 34
//if (MATTHEW > day <= MARK) {
//	book = day - MATTEW
//	printf("Mark %d\n", book)
//}
//Each list, again ten in all, will be a seperate func. which will return the book of the day.
//A file will be read, this way `day` an be stored from day to day. hbrs -s or --setup 
//will need to be run initially, and this will create the initial data file. If a number is passed
//along with -s it will initialize the reading plan to that value and set the date to today.
//hbrs.data will store two values, `day` and `date`. On each run the prog will first read `date`and 
//determine if it matches today. If it does it will read `day`, and the date has changed it will read
//`day + 1`, thus advancing the reading plan, while allowing for multiple queries in a single day.
//if -y or --yesterday is passed it will return the reading plan for `day - 1`
// and if -t or --tomorrow is passed it will return the reading plan for `day + 1`. 
// If -d # or --day # is passed it will not read the data file at all, but instead will set 
//`day` to the # passed in the argument and returning the appropriate reading plan.
//Lastly, if -c or --clear is passed it will initialize `day` in the data file to 1. 
//To Do:
//[X] - List 0
//[ ] - List 1
//[ ] - List 2
//[ ] - List 3
//[ ] - List 4
//[ ] - List 5
//[ ] - List 6
//[ ] - List 7
//[ ] - List 8
//[ ] - List 9
//[ ] - git
//[ ] - Add time functionality
//[ ] - Add read/write
//[ ] - Add getopt parsing
//[ ] - Add functions for `-y`, `-t`, `-d #`
//[ ] - `make`
//[ ] - crons job or deamon for daily autoupdate
//[ ] - `sendmail` functionality

typedef struct reading{
	char * book;
	int chapter;
} reading;

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

int main (int argv, char *argc[]) {

	int day = 34;

	reading list_0 = list0(day);
	char * book = list_0.book;
	int chapter = list_0.chapter;
	
	printf("%s %d\n", book, chapter);
	return 0;
}

reading list0 (int day) {
	reading list;
	while (day > (MATTHEW + MARK + LUKE + JOHN)) {
		day -= (MATTHEW + MARK + LUKE +JOHN);
	}
	if (day <= MATTHEW) {
		list.chapter = day; 
		list.book = "Mattew";
	}
	else if (MATTHEW < day && day >= MARK) {
		list.chapter = day - MATTHEW;
		list.book = "Mark";
	}
	else if (MARK < day && day >= LUKE) {
		list.chapter = day - (MATTHEW + MARK);
		list.book = "Luke";
	}
	else if (LUKE < day && day >= JOHN) {
		list.chapter = day - (MATTHEW + MARK + LUKE);
		list.book  = "John";
	}
	else {
		list.book = "error!";
	}
	return list;
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
 * 	}
 * 	else if (BOOK_1 < day && day >= BOOK_2) {
 * 		list.chapter = day - BOOK_ONE;
 * 		list.book = "Book_2";
 * 	}
 * 	else if (BOOK_2 < day && day >= BOOK_3) {
 * 		list.chapter = day - (BOOK_1 + BOOK_2);
 * 		list.book = "Book_3";
 * 	}
 * 	else {
 * 		list.book = "error!";
 * 	}
 * 	return list;
 * }
 */
