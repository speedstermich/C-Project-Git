#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void findKey(char* key, char* mark)
{
	int len = strlen(key);

	int i = 0;
	int j = 0;
	memset(mark,0,26);

	for (i = 0; i < len;i++)
	if (mark[key[i] - 97] == 0)
	{
		mark[key[i] - 97] = 1;
		key[j] = key[i];
		j++;
	}
	key[j] = '\0';

	for (i = 0, j = 0; i < 26; i++)
	if (mark[i] == 0)
	{
		mark[j] = 97 + i;
		j++;
	}
mark[j] = '\0';
}

int main()
{
	char* encrypt;
	char map[27];
	char key[100];
	char mark[26];

	int len;
	int markLen;
	int i;
	int nFileLen;

	FILE* inputFile;
	FILE* outputFile;

//printf("输入密钥:");
	scanf("%s",key);

	findKey(key, mark);

//printf("得到密钥:%s\n", key);

	len = strlen(key);
strcpy(map, key);

markLen = strlen(mark);
for (i = len; i < 26; i++) map[i] = mark[markLen+len-1-i];
map[26] = '\0';
//printf("映射关系:%s\n", map);

inputFile = fopen("encrypt.txt", "r");

if (inputFile == NULL) {
printf("encrypt.txt不存在\n");
return 1;
}

fseek(inputFile, 0, S    #include <stdio.h>
    #include <string.h>

    int main ()
    {
        char ch, words[50], secret_key[50], str[100];
        char alphabet[27] = {"abcdefghijklmnopqrstuvwxyz"};
        int i, j, k, len;
        i = 0;
    /*  ch = getchar();
        while (ch != '\n')
        {
            words[i] = ch;
            ch =getchar();
            i ++;
        }
        words[i] = '\0';

        i = 0;
        ch = getchar();
        while (ch != '\n')
        {
            str[i] = ch;
            ch =getchar();
            i ++;
        }
        str[i] = '\0';
    */
        gets(words);
        gets(str);
        len = strlen(words);
        for (i = 0; i < len; i ++)//去掉密钥单词中的重复字母
        {
            for (j = i + 1; j < len; j ++)
            {
                if (words[i] == words[j])
                {
                    for (k = j ; k < len; k ++)
                    {
                        words[k] = words[k + 1];
                        len --;
                    }
                }
            }
        }

        //得到密钥串
        for (i = len - 1, j = 0; i >= 0; i --, j ++)
        {
            secret_key[j] = words[i];
        }
        i = len;
        j = 25;
        while (i < 26 && j >= 0)
        {
            for (k = 0; k < len; k ++)//看字母在密钥串中已存在
            {
                if (secret_key[k] == alphabet[j])//若存在，则不保存，跳过该字母
                {
                    j --;
                    break;
                }
            }
            if (k == len)//若不存在，则保存该字母
            {
                secret_key[i] = alphabet[j];
                i ++;
                j --;
            }
        }

        //加密部分
        for (i = 0; str[i] != '\0'; i ++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                len = str[i] - 'a';
                putchar(secret_key[len]);
            }
            else
                putchar(str[i]);
        }
        putchar('\n');
        return 0;
    }  EEK_END);
nFileLen = ftell(inputFile);
encrypt = (char*)malloc(nFileLen + 1);
fseek(inputFile, 0, SEEK_SET);
fread(encrypt, nFileLen, 1, inputFile);
encrypt[nFileLen] = '\0';

//printf("读取明文:%s\n",encrypt);

for (i = 0; i < nFileLen; i++){
if (encrypt[i]<123 && encrypt[i]>96){
encrypt[i] = map[encrypt[i] - 97];
}
}

outputFile = fopen("output.txt", "w+");

fwrite(encrypt,nFileLen,1,outputFile);

//printf("加密的密文:%s\n", encrypt);

fclose(outputFile);
fclose(inputFile);
free(encrypt);
//system("pause");

return 0;
}
