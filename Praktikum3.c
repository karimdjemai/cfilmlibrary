#include<stdio.h>



int main() {
    typedef enum {
        unbekannt = 0,
        DVD,
        BluRay,
        BluRay3d
    } TFilmTyp;

    typedef struct 
    {
        char name[60];
        char regie[40];
        int laenge;
        char monat;
        short jahr;
        TFilmTyp typ;
    } TFilm;

}

