#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

char readFilms() {
    char filmNames[300][200];
    char authors[300][200];
    int namesI = 0; // Index
    
    char word[40];
    int wordI = 0; //Index
    bool wordNotEmpty = false;
    
    FILE *fp;
    char buff[2];

    fp = fopen("FilmDatenbank.dat", "r");
    
    while (fgets(buff, 2, (FILE*) fp) != 0) {
        // check if char from buff is printable
        if (isprint(buff[0])) {
            // add character to word
            word[wordI] = buff[0];
            wordI++;
            wordNotEmpty = true;
        } else {
            if (wordNotEmpty) {
                if (wordI > 5) {
                    if (namesI % 2 == 0) { //alternate between films and authors (doesnt work from a certain point because the scanning process breaks a title with non-ascii characters into two words)
                        printf("Film: '%s'\n", word);
                
                        // add film to list
                        strcpy(filmNames[namesI], word);
                    } else {
                        printf("Author: '%s'\n\n", word);

                        // add author to list
                        strcpy(authors[namesI], word);
                    }
                    namesI++;
                }

                //reset the word
                wordI = 0;
                memset(word, '\0', sizeof word);
                wordNotEmpty = false;
            }
        }
    }
    
    fclose(fp);

    return 0;
}

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

    //TFilm films[300];
    readFilms();
    //printFilms(films, filmCount);

    return 0;
}


// void printFilms(TFilm[] films, int filmCount) {
//     for (int i; i < filmCount; i++) {
//         name ="a";
//         regie ="a";
//         datum ="a";
//         typ ="a";
//         printf('Filmname: %s');
//         printf('Regisseur: %s');
//         printf('Datum: %s');
//         printf('Typ: %s');
//     }
// }



