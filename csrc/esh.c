#include "esh.h"
#include "renderer.h"

int strcmp(char input[],char check[])
{
    int i,result=1;
    for(i=0; input[i]!='\0' || check[i]!='\0'; i++) {
        if(input[i] != check[i]) {
            result=0;
            break;
        }
    }
    return result;
}

void esh_parse_command(char *str) {
	char argv[8][COLUMNS] = {"","","","","","","",""};

	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int k = 0;
	while (str[i] != '\0') {
		if(str[i] != ' ') {
			argv[j][k] = str[i];
			k++;
		} else {
			j++;
			k = 0;
		}
		i++;
	}

	if (strcmp(argv[0],"echo") == 1) {
		char *echostr = "";
		unsigned int l = 0;
		unsigned int m = 1;
		while (argv[m][0] != '\0') {
			unsigned int n = 0;
			while (argv[m][n] != '\0') {
				echostr[l] = argv[m][n];
				l++;
				n++;
			}
			echostr[l] = ' ';
			l++;
			m++;
		}
		stdin_clear();
		stdout_put(echostr);
		stdout_newline();
		return;
	}


	stdin_clear();
	stdout_put(argv[0]);
	stdout_put(": Command not found.");
	stdout_newline();
}