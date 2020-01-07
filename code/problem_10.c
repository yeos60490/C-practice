#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
};




//년과 날수를 입력 받아 월과 일수를 계산  
void month_day(int year, int yearday, int *pmonth, int *pday) { 
	int i, leap;
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i]; 
	*pmonth = i;
	*pday = yearday;

}


//년,월,일을 입력 받아 그 해 지난 날수 계산 
int day_of_year_large(int year, int month, int day) { 
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i]; 
	return day;
}



//년,월,일을 입력 받아 그 해에 남은 날수 계산
int day_of_year_small(int year, int month, int day) { 
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i]; 

	day = 365 - day;
	return day;
}


//윤년 개수 
int count_number_of_leap(int year, int year1){
	int count = 0;

	for (int i=year; i<year1; i++){
		if ((i%4 == 0 && i%100 != 0) || i%400 == 0){
			count ++;
		}

	}

	return count;
}


//case 1
void project_one(int year_large, int month_large, int day_large, int year_small, int month_small, int day_small){



	int leap_count = count_number_of_leap(year_small, year_large);


    int count_large = day_of_year_large(year_large, month_large, day_large);
    int count_small = day_of_year_small(year_small, month_small, day_small);

    int year_btw = year_large - year_small;


    int day_btw = count_large + count_small + leap_count + (year_btw-1)*365;
    printf("%d", day_btw);



}


//요일 계산 
void count_days(int day_btw){

	int d = day_btw % 7;
	//printf("%c", days[d]);
	
	switch (d){
		case 1:
			printf("mon");
			break;

		case 2:
			printf("tue");
			break;
		case 3:
			printf("wed");
			break;
		case 4:
			printf("thu");
			break;
		case 5:
			printf("fri");
			break;
		case 6:
			printf("sat");
			break;
		case 0:
			printf("sun");
			break;
	}
}





int main(int argc, char *argv[]) {
    
    
	int year = 0, month= 0, day= 0;
    int year1= 0, month1= 0, day1= 0;

    int year_large, month_large, day_large;
    int year_small, month_small, day_small;



    
	if(argc == 2){

		sscanf(argv[1], "%d.%d.%d" ,&year,&month,&day);
		if(year>3000 || year <1){
			printf("error");
			return 0;
		}
		//project_three;
	    else if(month<1 || month>12){
	    	printf("error");
	    	return 0;
	    }
	    else if(day<1 || day>31){
	    	printf("error");
	    	return 0;
	    }

	    //project_three;
		int leap_count = count_number_of_leap(1, year);

		int day_btw = day_of_year_large(year, month, day) + leap_count + (year-1)*365;

		count_days(day_btw);


	}
	else {
		sscanf(argv[1], "%d.%d.%d" ,&year,&month,&day);
		sscanf(argv[2], "%d.%d.%d" ,&year1,&month1,&day1);

		if(year>3000 || year <1 || year1 >3000 || year1 <1){
			printf("error");
			return 0;
		}



		if(month1 == 0 && day1 == 0){
			//project_two;

			int day_add = year1;
		    int count_left = day_of_year_small(year, month, day);


		    if(count_left > day_add){
		    	int count_pass = day_of_year_large(year,month,day);
		    	count_pass = count_pass + day_add;

		    	month_day(year,count_pass, &month1, &day1);

		    	printf("%d.%d.%d", year, month1, day1);

		    }

		    else{
		    	day_add = day_add - count_left;
		    	year ++;
		    	while(day_add >365){
		    		day_add = day_add - (365+count_number_of_leap(year,year+1));
		    		year ++;
		    	}
		    	

		    	month_day(year,day_add, &month1, &day1);
		    	printf("%d.%d.%d", year, month1, day1);

		    }



		}


		else{

		
		    if(year < year1){
		    	year_large = year1; month_large = month1; day_large = day1;
		    	year_small = year; month_small = month; day_small = day;

		    }
		    else{
		    	year_large = year; month_large = month; day_large = day;
		    	year_small = year1; month_small = month1; day_small = day1;
		    }

			project_one(year_large,month_large, day_large, year_small, month_small, day_small);

		}



	}



    return 0;
}



