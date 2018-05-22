#include <stdio.h>
#include <ctype.h>

int main(){
    char s[300]={'\0'},ch;
    int i=0;
    ch=getchar();
    while(ch!='\n'){
        s[i]=ch;
        i++;
        ch=getchar();
    }
    for(i=0;s[i];i++){
        if(s[i]=='-'){
            if(isdigit(s[i-1])&&isdigit(s[i+1])&&s[i-1]<=s[i+1]){
                for(ch=s[i-1]+1;ch<s[i+1];ch++)
                    printf("%c",ch);
            }else if(islower(s[i-1])&&islower(s[i+1])&&s[i-1]<=s[i+1]){
                for(ch=s[i-1]+1;ch<s[i+1];ch++)
                    printf("%c",ch);
            }else if(isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<=s[i+1]){
                for(ch=s[i-1]+1;ch<s[i+1];ch++)
                    printf("%c",ch);
            }else
                printf("%c",s[i]);
        }else
            printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}  
