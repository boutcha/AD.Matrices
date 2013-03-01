#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<string.h >
#include<stdlib.h>




float convert ( char * chaine )
{float res = 0, mul = 1 ;bool  vir = false ; char c ;
     
      for (int i = 0 ; chaine[i] != '\0' ; i ++ )
      {
            if (chaine[i] == ',' || chaine[i] == ',')
               {
               vir = true ;
               mul = 0.1 ;
               }
            else 
               {
                   if ( chaine[i] >= 48 && chaine[i] <= 57)
                   {    if (!vir)
                        {
                        res = res * mul + chaine[i] - 48 ;
                        mul = mul * 10;
                        }
                        else 
                        {
                             res = res + ((chaine[i]-48)*mul);
                             mul = mul / 10 ;
                        } 
                   }
                   else return INT_MAX;
               }
      }
      return res ;
} 



bool seek_l_m( char * path , int &l , int &m)
{    
     l=1;
     m=0;
     FILE * f = NULL ; char c ;
     f = fopen(path ,"r");     
     
     if ( f == NULL) return false ;
     
     do {
          c = fgetc(f);
          if ( c == 10 || c ==13 )
          l++;
          }
          while(c != EOF);
     rewind(f);
     
       do {
          c = fgetc(f);
          if ( c == 9 )
          m++;
          if(c==10 || c == 13 )
          break;
          }
          while(c!= EOF );
       fclose(f);
       return true ;
}

bool alloc( int l , int m )
{
     
     float **t ;
     t = (float **) malloc( l * sizeof(float*));
     for (int i = 0 ; i < l ;i ++)
     {
         t[i] = (float *) malloc(m * sizeof ( float));
     }
     return t ;
}
char * file_read_number(char *path ,float **t , int l , int m )
{
     FILE *f = NULL;char *chaine , c ;int i = 0 ;
     f = fopen(path , "r");
     chaine = new char ;
     do {
         c=fgetc(f);
       if ( c == ',' || c == '.'|| (c<=57||c>=48))
       {
       chaine [i] = c ;
       i++;
       realloc(chaine , i+1);
       }
       else return NULL ;
       }while(c!=EOF);
     
 
 }
 /* complete ou re cree la fonction qui lit un nombre a partir du fichier 
            - verifier si le fichier est dans le format convenable (une matrice avec des nombre et des tab et retour chariot)
            - extraire le nombre sous forme de chaine de caractere pour etre converti par la  fonction convert 
            ( on traivail dans un fichier text   )
*/
     













main () 

{char chemin[10] = "test.txt";
int l ,m;
bool x = seek_l_m(chemin , l , m);
if (x == false ){ printf("%s","ERREUR FICHIER !");getch();exit(0);}
printf("%d \n",l);
printf("%d \n",m);
getch();

    

}
