
/* Exercise 1 - 16 -------------------------------------------------------------------------------*/
/* Getline : read a line into s, return length */
int32_t Getline(char s[], int lim){
    int32_t i, j;
    char c;

    j = 0;
    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if(i < lim - 2){
            s[j] = c; /* line still in boundaries */
            ++j;
        }        
    if(c == '\n'){
        s[j] = c;
        ++i;
        ++j;
    }
    s[j] = '\0';
    return i;
}

/* Copy : copy 'from' into 'to' : assume to is big enough */
void Copy(char to[], char from[]){
    int32_t i;

    i = 0;
    while((to[i] = from[i]) != '\0'){
        ++i;
    }
}

/* -----------------------------------------------------------------------------------------------*/
/* Exercise 1 - 17 -------------------------------------------------------------------------------*/

char* Print_line(char *str, int num){
    int index = 0;
    int word = 0;
    char *temp;
    str = (char *) malloc(sizeof(char) * num);

    while((word = getchar()) != EOF ){
        if(word != 10)        
            str[index] = word;
        index++;
        // printf("%s", str);
        if(index == num - 1){
            temp = (char *) malloc((num * 2));
            strcpy(temp, str);
            str = temp;
            num *= 2;
        }
    }       
    str[index] = word;    

    return str;
}

/* -----------------------------------------------------------------------------------------------*/

/* Exercise 1 - 18 -------------------------------------------------------------------------------*/

void remove(char str[]){

    int index = 0;

    while(str[index] != '\n')
        index++;
    
    index--;

    while(str[index] == '\t' || str[index] == ' ')
        index--;

    if(index < 0)
        printf("The line only contains blank or tab.\n");
    else{
        index++;
        str[index] = '\n';
        printf("The text line : %s", str);
    }
}

/* -----------------------------------------------------------------------------------------------*/
/* Exercise 1 - 19 -------------------------------------------------------------------------------*/

/* Example 
    a = 10, b = 11
    a = 10(a) xor 11(b) = 01
    b = 01(a) xor 11(b) = 10
    a = 01(a) xor 10(b) = 11
    a = 11, b = 10
*/

void reverse(char *str){    
    int head, end;
    head = 0;
    end = strlen(str) - 1;
    while(head < end){
        str[head] = str[head]^str[end]; 
        str[end] = str[head]^str[end];;
        str[head] = str[head]^str[end];
        head++;
        end--;
    }
}

/* -----------------------------------------------------------------------------------------------*/
/* Exercise 1 - 20 -------------------------------------------------------------------------------*/


/* -----------------------------------------------------------------------------------------------*/