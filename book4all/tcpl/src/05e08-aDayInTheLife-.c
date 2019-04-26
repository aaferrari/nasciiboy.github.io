#include <stdio.h>

static char daytab[ 2 ][ 13 ] = {
  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

/* day_of_year: obtiene dia del año a partir de mes y dia */
int day_of_year( int year, int month, int day ){
  int i, leap;

  if( month >= 1 && month <= 12 ){
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if( day >= 1 && day <= daytab[ leap ][ month ] ){
      for( i = 1; i < month; i++ )
        day += daytab[ leap ][ i ];
      return day;
    }
  }

  return 0;
}

/* month_day: obtiene mes, y dia a partir de dia del año */
int month_day( int year, int yearday, int *pmonth, int *pday ){
  int i, leap;
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  if( yearday >= 1 && yearday <= ( leap ? 366 : 365 ) ){
    for( i = 1; yearday > daytab[ leap ][ i ]; i++ )
      yearday -= daytab[ leap ][ i ];
    *pmonth = i;
    *pday = yearday;
    return 1;
  }

  return 0;
}


int main(){
  int month, day;

  month_day( 2017, 366, &month, &day );
  printf( "day #%d - %d: month %d day %d\n",
          366, 2017, month, day );

  month_day( 2017, 365, &month, &day );
  printf( "day #%d - %d: month %d day %d\n",
          365, 2017, month, day );

  month_day( 2016, 366, &month, &day );
  printf( "day #%d - %d: month %d day %d\n",
          366, 2016, month, day );

  printf( "month %d day %d - %d: day #%d\n",
          2, 30, 2016, day_of_year( 2016, 2, 30 ) );

  return 0;
}


/* output
day #366 - 2017: month 0 day 0
day #365 - 2017: month 12 day 31
day #366 - 2016: month 12 day 31
month 2 day 30 - 2016: day #0
*/
