/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"
#include "synchconsole.h"
#include "string"


void SysHalt()
{
  kernel->interrupt->Halt();
}


int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysPrint(char* input, int num){

  char data[100];
  char res[100];
  int i = -1;
  do {
  	i++;
    kernel->machine->ReadMem((int)input+i, 1, (int* )(data+i)); 
  } while(data[i]!='\0');

  
  sprintf(res, data, num);
	std::string str = (char*) res;
	// kernel->synchConsoleOut->PutString(res[0]);
	kernel->synchConsoleOut->PutString(res);
  return i;
}




#endif /* ! __USERPROG_KSYSCALL_H__ */
