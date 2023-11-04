/*
Name: zhong6688
Purpose: This program contains the main function and reads
into the CSV file "worldcup.csv" to obtain records. Depending
on whether the user chooses to look up records based on a country,
group, or points, the program calls the country.c file to
put together a comprehensive list.
*/

/*********************************************************
 * Program to read in country records from worldcup.csv  *
 * and search records by country, group, or points.      *
 *                                                       *
 *                                                       *
 * compile: gcc worldcup.c country.c                     *
 * usage:   ./worldcup <input filename>                  *
 * example: ./worldcup worldcup.csv                      *
 *********************************************************/

#include <stdio.h>
#include <string.h>
#include "country.h"

int main(int argc, char *argv[])
{
  FILE *fp;
  struct country countries[NUM_COUNTRIES];
  char code;
  int i = 0;

if ((fp = fopen(argv[1], "r")) == NULL)
{
  printf("%s can't be opened\n", argv[1]);
  return 1;
}

  //Gets rid of Header Line
  char Header_Line[1000];
  fscanf(fp,  "%[^\n]", Header_Line);

  //Read in CSV records into the array of structure "countries"
  while(!feof(fp) && !ferror(fp))
  {
    fscanf (fp, " %[^,],%c,%d,%d", countries[i].name, &countries[i].group, 
	     &countries[i].goals, &countries[i].points);
  i++;
  }

  for (;;) {
    printf("Search by country: c\n");
    printf("Search by group:   g\n");
    printf("Search by points:  p\n");
    printf("Quit:              q\n");
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'c': search_by_country(countries);
                break;
      case 'g': search_by_group(countries);
                break;
      case 'p': search_by_points(countries);
                break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
  return 0;
}
