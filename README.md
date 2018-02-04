# hbrs

Each book of the Bible is defined as the total number of books in the book.
Then, each book for the day (10 total) is determined by determing which book
corresponds with the current day. Example:
day = 34
if (MATTHEW > day <= MARK) {
      book = day - MATTEW
      printf("Mark %d\n", book)
}
Each list, again ten in all, will be a seperate func. which will return the book of the day.
A file will be read, this way `day` an be stored from day to day. hbrs -s or --setup 
will need to be run initially, and this will create the initial data file. If a number is passed
along with -s it will initialize the reading plan to that value and set the date to today.
hbrs.data will store two values, `day` and `date`. On each run the prog will first read `date`and 
determine if it matches today. If it does it will read `day`, and the date has changed it will read
`day + 1`, thus advancing the reading plan, while allowing for multiple queries in a single day.
if -y or --yesterday is passed it will return the reading plan for `day - 1`
 and if -t or --tomorrow is passed it will return the reading plan for `day + 1`. 
 If -d # or --day # is passed it will not read the data file at all, but instead will set 
`day` to the # passed in the argument and returning the appropriate reading plan.
Lastly, if -c or --clear is passed it will initialize `day` in the data file to 1. 
To Do:
[X] - List 0
[ ] - List 1
[ ] - List 2
[ ] - List 3
[ ] - List 4
[ ] - List 5
[ ] - List 6
[ ] - List 7
[ ] - List 8
[ ] - List 9
[ ] - git
[ ] - Add time functionality
[ ] - Add read/write
[ ] - Add getopt parsing
[ ] - Add functions for `-y`, `-t`, `-d #`
[ ] - `make`
[ ] - crons job or deamon for daily autoupdate
[ ] - `sendmail` functionality
