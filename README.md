# hbrs

hbrs is a tracker for ["Prof. Grant Horner's Bible Reading System"](https://www.scribd.com/doc/12349985/Professor-Grant-Horners-Bible-Reading-System). The program will keep track of daily Bible readings. This reading plan is not as straightforward as other reading programs as it involves reading ten chapters from various areas of the Bible each day. Each of these ten chapters is part of a list of books. Once the list has been completed the reader starts back at the top of that list. Thus, this plan never ends and the further into the reading plan you get the harder it is to determine where you are. The plan uses bookmarks to manage the daily reading, which is fine if you a) use a physical book or b) enjoy ten separate bookmarks in your Bible. This program is an alternative to this. One or two other alternatives exist, but neither truly embrace the spirit of this program as they are all based upon reading plan platforms which use definite end dates. This plan could theoretically go on for ever, and this program will theoretically enable the reader to do just that.

Each book of the Bible is defined as the total number of books in the book. Then, each book for the day (10 total) is determined by determing which book corresponds with the current day. Example:

	day = 34;
	if (day <= MATTHEW) {
		list.chapter = day;
		list.book = "Matthew";
		return list;
	}
	day -= MATTHEW;
	if (day <= MARK) {
		list.chapter = day;
		list.book = "Mark";
		return list;
	}

## Usage

The following is a goal, currently this program only returns the reading for day 54 which is what `day` is set to in source.

Each list, again ten in all, will be a seperate func. which will return the book of the day. A file will be read, this way `day` an be stored from day to day. hbrs `-s` or `--setup` will need to be run initially, and this will create the initial data file. If a number is passed along with `-s` it will initialize the reading plan to that value and set the date to today. `hbrs.data` will store two values, `day` and `date`. On each run the program will first read `date`and determine if it matches today. If it does it will read `day`. If the date has changed it will read`day + 1`, thus advancing the reading plan, while allowing for multiple queries in a single day. If `-y` or `--yesterday` is passed it will return the reading plan for `day - 1` and if `-t` or `--tomorrow` is passed it will return the reading plan for `day + 1`. If `-d #` or `--day #` is passed it will not read the data file at all, but instead will set `day` to the # passed in the argument and returning the appropriate reading for that day. Lastly, if `-C` or `--clear` is passed it will initialize `day` in the data file to 1, thus reseting the counter.

## To Do:

[ ] - Add time functionality

[ ] - Add read/write

[ ] - Add getopt parsing

[ ] - Add functions for `-y`, `-t`, `-d #`

[ ] - `make`

[ ] - crons job or deamon for daily autoupdate

[ ] - `sendmail` functionality
