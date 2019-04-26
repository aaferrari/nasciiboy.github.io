#define NAME_MAX 14           /* componentes de nombre de archivo mas grande
                                 dependiente del sistema                       */

typedef struct {              /* entrada de directorio trasportable            */
  long ino;                   /* numero de inodo                               */
  char name[ NAME_MAX + 1 ];  /* nombre + terminador '\0'                      */
} Dirent;

typedef struct {              /* DIR minima: sin buffer, etc.                  */
  int fd;                     /* descriptor de archivo para el directorio      */
  Dirent d;                   /* la entrada del directorio                     */
} myDIR;

myDIR *my_opendir( char *dirname );
Dirent *my_readdir( myDIR *dfd );
void my_closedir( myDIR *dfd );
