/*
Name: zhong6688
Purpose: This program contains three void functions each of which
list information from the CSV file depending on whether the user
chooses to look up records based on a country, group, or points.
*/

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "country.h"

int i;
char name[100];
/**********************************************************
 * search_by_country: Prompts the user to enter a country *
 *                    name, then prints the record of     *
 *                    that country if it exists.          *
 **********************************************************/
void search_by_country(struct country countries[])
{
  int x; 
 
  printf("Enter a country name: ");
  
  //Calls a read line
  read_line(name, 100);

  //Header
  printf("Country\t\tGroup\tGoals\tPoints\n");
  for(i = 0; i < NUM_COUNTRIES; i++)
  {
    if (strcmp(countries[i].name, name) == 0)
    {
      printf("%-12s\t", countries[i].name);
      printf("%3c\t", countries[i].group);
      printf("%3d\t", countries[i].goals);
      printf("%3d\n", countries[i].points);    
    }
  }
}
/**********************************************************
 * search_by_group: Prompts the user to enter a group,    *
 *                  then prints the records of that group *
 *                  if it exists.                         *
 **********************************************************/
void search_by_group(struct country countries[])
{
  char gr;
  
  printf("Enter group: ");
  scanf("%c", &gr);

  //Header
  printf("Country\t\tGroup\tGoals\tPoints\n");
  for(i = 0; i < NUM_COUNTRIES; i++)
  {  
    if(countries[i].group == gr)
    {
      printf("%-12s\t", countries[i].name);
      printf("%3c\t", countries[i].group);
      printf("%3d\t", countries[i].goals);
      printf("%3d\n", countries[i].points);
    }
  }
}

/**********************************************************
 * search_by_points: Prompts the user to enter a point,   *
 *                   then prints the records having       *
 *                   that many points, if it exists.      *
 **********************************************************/
void search_by_points(struct country countries[])
{
  int p;
  
  printf("Enter points: ");
  scanf("%d", &p);

  //Header
  printf("Country\t\tGroup\tGoals\tPoints\n");
  for(i = 0; i < NUM_COUNTRIES; i++)
  {
    if(countries[i].points == p)
    {
      printf("%-12s\t", countries[i].name);
      printf("%3c\t", countries[i].group);
      printf("%3d\t", countries[i].goals);      
      printf("%3d\n", countries[i].points);
    }
  }
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  while (ch != '\n' && ch != EOF) {
    if (i < n)
      str[i++] = ch;
    ch = getchar();
  }
  str[i] = '\0';
  return i;
}
