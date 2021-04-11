/* page 29 -------------------------------------------------------------------------------------------------- */
/* Getline : read a line into s, return length */
int32_t Getline(char s[], int lim){
    int32_t c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
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
/* -------------------------------------------------------------------------------------------------------------*/

/* page 29 -------------------------------------------------------------------------------------------------- */
#define MAXLINE 1000 /* maximum input line */
int32_t Getline_extern(void){
    int32_t c, i;
    extern char line[];

    for(i = 0; i < MAXLINE -1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* Copy : copy 'from' into 'to' : assume to is big enough */
void Copy_extern(void){
    int32_t i;
    extern char line[], longest[];

    i = 0;
    while((line[i] = longest[i]) != '\0'){
        ++i;
    }
}

/* ---------------------------------------------------------------------------------------------------------- */