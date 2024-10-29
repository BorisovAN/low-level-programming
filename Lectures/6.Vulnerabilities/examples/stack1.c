#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <err.h>



int main(int argc, char **argv)
{
	struct{
		char buffer[64];
		volatile int modified;
	} s;
	

    if(argc == 1) {
        errx(1, "please specify an argument\n");
    }

    s.modified = 0;
    strcpy(s.buffer, argv[1]);

    if(s.modified == 0x61626364) {
        printf("you have correctly got the variable to the right value\n");
    } else {
        printf("Try again, you got 0x%08x\n", s.modified);
    }
}

