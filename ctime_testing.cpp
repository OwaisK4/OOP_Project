#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

int main()
{
	time_t curr_time;
	curr_time = time(NULL);

//	char *tm = ctime(&curr_time);
//	cout << "Today is : " << tm;
//	cout << "Size of tm = " << strlen(tm);
	
//	struct tm* tm = localtime(&base);
	struct tm* tm = localtime(&curr_time);
    tm->tm_mday += 1;
    time_t next = mktime(tm);
    cout << ctime(&next);
	
	return 0;
}
