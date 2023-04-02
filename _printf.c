#include "main.h"

void printOutput(char outputBuffer[], int *bufferIndex);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed characters.
 */
int _printf(const char *format, ...) {
  int i, printedChars = 0, charsPrinted = 0;
  int flag, width, precision, size, bufferIndex = 0;
  va_list argumentList;
  char outputBuffer[BUFFER_SIZE];
  
  if (format == NULL) {
    return (-1);
  }
  
  va_start(argumentList, format);
  
  for (i = 0; format && format[i] != '\0'; i++) {
    if (format[i] != '%') {
      outputBuffer[bufferIndex++] = format[i];
      
      if (bufferIndex == BUFFER_SIZE) {
        printOutput(outputBuffer, &bufferIndex);
      }
      
      printedChars++;
    } else {
      printOutput(outputBuffer, &bufferIndex);
      
      flag = getFlags(format, &i);
      width = getWidth(format, &i, argumentList);
      precision = getPrecision(format, &i, argumentList);
      size = getSize(format, &i);
      ++i;
      
      printedChars = handlePrint(format, &i, argumentList, outputBuffer,
                                 flag, width, precision, size);
      
      if (printedChars == -1) {
        return (-1);
      }
      
      charsPrinted += printedChars;
    }
  }
  
  printOutput(outputBuffer, &bufferIndex);
  va_end(argumentList);
  
  return (charsPrinted);
}

/**
 * printOutput - Prints the contents of the buffer if it exists
 * @outputBuffer: Array of chars
 * @bufferIndex: Index at which to add next char, represents the length.
 */
void printOutput(char outputBuffer[], int *bufferIndex) {
  if (*bufferIndex > 0) {
    write(1, &outputBuffer[0], *bufferIndex);
  }
  *bufferIndex = 0;
}
