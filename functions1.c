#include "main.h"

/************************* PRINT UNSIGNED NUMBER ***********************/
/

print_unsigned - Prints an unsigned number
@args: List a of arguments
@buf: Buffer array to handle print
@flg: Calculates active flags
@wid: Get width
@pre: Precision specification
@siz: Size specifier
Return: Number of chars printed.
*/
int print_unsigned(va_list args, char buf[],
int flg, int wid, int pre, int siz)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(args, unsigned long int);
num = convert_size_unsgnd(num, siz);
if (num == 0)
buf[i--] = '0';
buf[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buf[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_unsgnd(0, i, buf, flg, wid, pre, siz));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL **************/
/

print_octal - Prints an unsigned number in octal notation
@args: Lista of arguments
@buf: Buffer array to handle print
@flg: Calculates active flags
@wid: Get width
@pre: Precision specification
@siz: Size specifier
Return: Number of chars printed
*/
int print_octal(va_list args, char buf[],
int flg, int wid, int pre, int siz)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(args, unsigned long int);
unsigned long int init_num = num;
UNUSED(wid);
num = convert_size_unsgnd(num, siz);
if (num == 0)
buf[i--] = '0';
buf[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buf[i--] = (num % 8) + '0';
num /= 8;
}
if (flg & F_HASH && init_num != 0)
buf[i--] = '0';
i++;
return (write_unsgnd(0, i, buf, flg, wid, pre, siz));
}
/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL ************/
/

print_hexadecimal - Prints an unsigned number in hexadecimal notation
@args: Lista of arguments
@buf: Buffer array to handle print
@flg: Calculates active flags
@wid: Get width
@pre: Precision specification
@siz: Size specifier
Return: Number of chars printed
*/
int print_hexadecimal(va_list args, char buf[],
int flg, int wid, int pre, int siz)
{
return (print_hexa(args, "0123456789abcdef", buf,
flg, 'x', wid, pre, siz));
}
/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ************/
/

print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
@args: Lista of arguments
@buf: Buffer array to handle print
@flg: Calculates active flags
@wid: Get width
@pre: Precision specification
@siz: Size specifier
Return: Number of chars printed
*/
int print_hexa_upper(va_list args, char buf[],
int flg, int wid, int pre, int
