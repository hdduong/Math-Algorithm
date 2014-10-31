#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <assert.h>

# define bool int
 
int getNumeralValue(char );
char getNumeral(int );
 
/* Function to add two numbers in base 14 */
char *sumBase14(char *num1,  char *num2)
{
   int l1 = strlen(num1);
   int l2 = strlen(num2);  
   char *res; 
   int i;
   int nml1, nml2, res_nml;   
   bool carry = 0;
    
   if(l1 != l2)
   {
     printf("Function doesn't support numbers of different"
            " lengths. If you want to add such numbers then"
            " prefix smaller number with required no. of zeroes"); 
     getchar();         
     assert(0);
   }      
 
   res = (char *)malloc(sizeof(char)*(l1 + 2)); // final string for /0
   
       
   for(i = l1-1; i >= 0; i--)
   {
     nml1 = getNumeralValue(num1[i]);
     nml2 = getNumeralValue(num2[i]);
      
     /* Add decimal values of numerals and carry */
     res_nml = carry + nml1 + nml2;
      
     if(res_nml >= 14)
     {
       carry = 1;
       res_nml -= 14;
     }   
     else
     {
       carry = 0;     
     }       
     res[i+1] = getNumeral(res_nml);
   }
   
   res[l1+1] = '\0';

   if(carry == 0)
     return (res + 1);   
 
   res[0] = '1';
   return res;
}
 
int getNumeralValue(char num)
{
  if( num >= '0' && num <= '9')
    return (num - '0');
  if( num >= 'A' && num <= 'D')  
    return (num - 'A' + 10);
}
 
char getNumeral(int val)
{
  if( val >= 0 && val <= 9)
    return (val + '0');
  if( val >= 10 && val <= 14)  
    return (val + 'A' - 10);
}
 
/*Driver program to test above functions*/
int main()
{
    //char *num1 = "DC2";
    //char *num2 = "0A3";
	char* num1 = (char*)malloc(sizeof(char) * sizeof("DC2"));
	char* num2 = (char*)malloc(sizeof(char) * sizeof("0A3"));

	strncpy(num1,"DC2",sizeof("DC2"));
	strncpy(num2,"0A3",sizeof("0A3"));
 

	//char* num1 = (char*)malloc(sizeof(char) * sizeof('DC2'));
	//char* num2 = (char*)malloc(sizeof(char) * sizeof('0A3'));

	//strncpy(num1,'DC2',sizeof('DC2'));
	//strncpy(num2,'0A3',sizeof('0A3'));
 

    printf("Result is %s", sumBase14(num1, num2));     
    getchar();
    return 0;
}