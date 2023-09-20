#include <stdio.h>
#include <string.h>
int main(void)
{
  char number[20];
  int length, i;
  printf("금액을 입력하고 Enter>");
  scanf("%s", number);
  length=strlen(number);
  for(i=length;i>=0;i--)
     printf("%c\n", number[i]);
  return 0;
}

![5_4_2.c](.GamePrg/week03/class/img/money_split_and_print.png)
