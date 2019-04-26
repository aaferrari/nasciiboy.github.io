#include <stdio.h>

static char daytab[ 2 ][ 13 ] = {
  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

/* day_of_year: obtiene dia del año a partir de mes y dia */
int day_of_year( int year, int month, int day ){
  int i, leap;
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for( i = 1; i < month; i++ )
    day += daytab[ leap ][ i ];
  return day;
}

/* month_day: obtiene mes, y dia a partir de dia del año */
void month_day( int year, int yearday, int *pmonth, int *pday ){
  int i, leap;
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for( i = 1; yearday > daytab[ leap ][ i ]; i++ )
    yearday -= daytab[ leap ][ i ];
  *pmonth = i;
  *pday = yearday;
}


int main(){
  int month, day;

  month_day( 2017, 61, &month, &day );
  printf( "day #%d - %d: month %d day %d\n",
          61, 2017, month, day );

  month_day( 2017, 60, &month, &day );
  printf( "day #%d - %d: month %d day %d\n",
          60, 2017, month, day );

  month_day( 2016, 61, &month, &day );
  printf( "day #%d - %d: month %d day %d\n",
          61, 2016, month, day );

  month_day( 2016, 60, &month, &day );
  printf( "day #%d - %d: month %d day %d\n",
          60, 2016, month, day );

  printf( "month %d day %d - %d: day #%d\n",
          month, day, 2016, day_of_year( 2016, month, day ) );

  return 0;
}


/* output
day #61 - 2017: month 3 day 2
day #60 - 2017: month 3 day 1
day #61 - 2016: month 3 day 1
day #60 - 2016: month 2 day 29
month 2 day 29 - 2016: day #60
*/
