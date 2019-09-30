#include <curses.h>
#include <string.h>

void nasciiboy(){
#define CATNU( fil, msg ) strcpy( NU[fil], #msg )
#define NU_H  9
#define NU_W 17
  char NU[NU_H][NU_W + 3];
  CATNU( 0,"  ,           ,  ");
  CATNU( 1," /             \ ");
  CATNU( 2,"((__-^^-,-^^-__))");
  CATNU( 3," `-_---' `---_-' ");
  CATNU( 4,"  `--|o` 'o|--'  ");
  CATNU( 5,"     \  `  /     ");
  CATNU( 6,"      ): :(      ");
  CATNU( 7,"      :o_o:      ");
  CATNU( 8,"       "-"       ");

  int nu_y = ( LINES -  NU_H ) / 2;
  int nu_x  = ( COLS  - 18 ) / 2;

  int i, ii;
  clear();

  // draw GNU ascii(nu)
  for( i = 0; i < NU_H; i++ )
    for( ii = 0; ii < NU_W; ii++ )
      mvaddch( nu_y + i, nu_x + ii, NU[ i ][ ii + 1 ] );
  refresh();
  napms( 1000 );

  i = 0;
  // draw lines
  while( i < nu_y ){
    for( ii = 0; ii < COLS; ii++ ){
      mvaddch(             i, ii, ' ' | A_REVERSE );
      mvaddch( LINES - 1 - i, ii, ' ' | A_REVERSE );
    }
    refresh();
    napms( 500 );
    i++;
  }

#define CATNB( fil, msg ) strcpy( NB[fil], #msg )
#define NB_H  5
#define NB_W 36
  char NB[NB_H][NB_W + 3];
  CATNB( 0,"                  _ _ ___           ");
  CATNB( 1," _ _  __ _ ___ __(_|_) _ ) ___ _  _ ");
  CATNB( 2,"| ' \/ _` (_-</ _| | | _ \/ _ \ || |");
  CATNB( 3,"|_||_\__,_/__/\__|_|_|___/\___/\_, |");
  CATNB( 4,"                               |__/ ");

  int nb_y = nu_y + 2;
  int nb_x = COLS - 1;
  // move & draw nasciiBoy & GNU ascii
  while( nu_x > 2 ){
    for( i = 0; i < NB_H; i++ )
      for( ii = 0; ii < NB_W; ii++ )
        if( nb_x + ii < COLS )
          mvaddch( nb_y + i, nb_x + ii, NB[ i ][ ii + 1 ] );
    for( i = 0; i < NU_H; i++ )
      for( ii = 0; ii < NU_W; ii++ )
        mvaddch( nu_y + i, nu_x + ii, NU[ i ][ ii + 1 ] );

    // move position
    nb_x--;
    if( nb_x < nu_x + NU_W + 4 ){
      mvaddch( nu_y + 2, nu_x + NU_W, ' ' );
      nu_x--;
    }

    refresh();
    napms( 75 );
  }

  napms( 2000 );
  flushinp();
}

int main(){
  initscr();
  noecho();
  curs_set( FALSE );
  cbreak();
  keypad( stdscr, TRUE );

  // Descomentar en compilacion con PDCurses
  // PDC_set_title( "Emacs Rocks!" );

  nasciiboy();

  endwin();
  return 0;
}
