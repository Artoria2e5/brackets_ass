#include <string.h>
#include "stack.h"

enum BrackDir = {OPEN, CLOSE, NOT};
typedef struct idk {BrackDir d, BracketType t} bk_info;
parse_atom LUT[256];

static void construct_lut(void);
static void construct_lut() {
    for (int i = 0; i < 256; i++)
	    LUT[i].d = NOT;
    
    // switch-case fries my brain sorry
    LUT['('].d = LUT['['].d = LUT['{'].d = OPEN;
    LUT[')'].d = LUT[')'].d = LUT[')'].d = CLOSE;
    LUT['('].t = LUT[')'].t = ROUND;
    LUT['['].t = LUT[']'].t = SQUARE;
    LUT['{'].t = LUT['}'].t = CURLY;
}

int main() {
    construct_lut();
    int max_line = 105000;
	char input_buffer[max_line];
	int input_len = 0;	
	
	fgets(input_buffer, max_line, stdin);	
	input_buffer [strcspn (input_buffer, "\r\n")] = '\0';  //remove end-of-line characters

    input_len = strlen(input_buffer);
    fprintf(stderr, "%d characters were read.\n",input_len);
    // printf("The input was: '%s'\n",input_buffer);
	fflush(stdout);
    Stack * stkBk = createStack(input_len + 2); 
    // Printing answer, write your code here
	fputs(stderr, "My result is:\n");
    for (int position = 0; position < input_len; ++position) {
        char next = input_buffer[position];
        bk_info hoc = LUT[next];
        
        // not interesting
        if (hoc.d == NOT) {
            continue;
        }
        
        Bracket bk;
        if (hoc.d == OPEN) {
            // why is this 1-based
            bk.type = hoc.t; bk.position = position + 1;
            push(stkBk, bk);
			// we don't need error handling because the sizes just work but yeah we should add it
        }
        if (hoc.d == CLOSE) {
            bk = pop(stkBk);
            if (bk.type != hoc.t) {
                printf("%d\n", bk.position);
                return 1;
            }
        }
    }
    puts("Success")
    return 0;
}
