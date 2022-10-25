#include "common.h"
#include<time.h>

#define film_length  (50)

int randomi(int range){
    return rand() % range + 1;
}

void Toupper(char *a){
    int i=0;
    while(i<strlen(a)){
        if(a[i]-'a'<25 && a[i]-'a'>=0)
        a[i] = (a[i]-'a')+'A';
        i++;
    }
}

int main(){
    FILE *fp;
    srand(time(NULL));
    int c,filmcount = 0,fileno,i=0,j,randval,length,lives=10,score=0,changed;
    char s[film_length],disps[film_length],guess[film_length];
    if (NULL == (fp = fopen("movie-list.txt", "r")))
        ERR_MESG("error opening file");
    while (NULL != fgets(s, film_length, fp)){
        filmcount++;
    }
    fclose(fp);
    fileno = randomi(filmcount);
     if (NULL == (fp = fopen("movie-list.txt", "r")))
        ERR_MESG("error opening file");
    while (NULL != fgets(s, film_length, fp)){
        i++;
        if(i==fileno)
        break;
    }
    fclose(fp);
    s[strlen(s)-1] = '\0';
    length = strlen(s);
    Toupper(s);
    strcpy(disps,s);
    //printf("%s\n",s);
    //randomly changes the values of 
    for(i=0;i<length/2;i++){
        randval = randomi(length);
        if(disps[randval]!=' ' && disps[randval]!='_'){
            for(j=0;j<length;j++){
                if(s[randval]==disps[j])
                disps[j] = '_';
            }
        }
    }
    while(lives>0){       
        printf("%s\tLives : %d\n",disps,lives);
        i=0;
        while('\n'!=(c=fgetc(stdin))){
        	guess[i] = c;
        	i++;
        }
        guess[i] = '\0';
        Toupper(guess);
        changed = 0;
        if(strlen(guess)==1){
            for(i=0;i<strlen(disps);i++){
                if(s[i]==guess[0] && disps[i]=='_'){
                    disps[i] = s[i];
                    changed = 1;
                }
            }
        }
        if(strcmp(guess,s)==0 || strcasecmp(disps,s)==0){
            printf("%s\n",s);
            printf("Correct! Your score is %d.\n",score+2);
            break;
        }
        if(changed==0){
            lives--;
            printf("Wrong guess!\n");
        }
        score++;
    }
    return 0;
}
