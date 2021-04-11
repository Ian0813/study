/*
 * =====================================================================================
 *
 *       Filename:  ip_convert_int.c
 *
 *    Description:  a dotted-decimal notation IP convert to Int.
 *
 *        Version:  1.0
 *        Created:  2021年04月10日 14時27分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>


long long IP_Convert_Int(char *ip){

	long long num = 0, index = 0, partial = 1;
	
	char ip_part[3] = {0};

	for(int i = 0; i < strlen(ip); i++){

		if(ip[i] != '.'){
			ip_part[index] = ip[i];
			index++;
		}

		if(ip[i] == '.' || i == (strlen(ip) - 1)){
			index = 0;
			switch(partial){

				case 4:
					num |= (atoll(ip_part) & 0xFF);
					printf("Case 1 : %lld\n", atoll(ip_part));
					printf("Num : %lld\n", num);
					break;

				case 3:
					num |= ((atoll(ip_part) & 0xFF) << 8);
					printf("Case 2 : %lld\n", atoll(ip_part));
					printf("Num : %lld\n", num);
					break;

				case 2:
					num |= ((atoll(ip_part) & 0xFF) << 16);
					printf("Case 3 : %lld\n", atoll(ip_part));
					printf("Num : %lld\n", num);
				        break;

				case 1:
					num |= ((atoll(ip_part) & 0xFF) << 24);
					printf("Case 4 : %lld\n", atoll(ip_part));
					printf("Num : %lld\n", num);

					break;	
			}
			partial += 1;
			memset(ip_part, 0, sizeof(ip_part));
		}
	}

	return num;
}


int main(int argc, char *argv[]){

	if(argc < 1){
		printf("Please follow : %s [IP ADDRESS]\n", argv[0]);
		exit(1);
	}

	
	char ip[INET_ADDRSTRLEN] = {0};

	strcpy(ip, argv[1]);

	long long result = IP_Convert_Int(ip);
	printf("Result : %lld\n", result);

	return 0;

}


