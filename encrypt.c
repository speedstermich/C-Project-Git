#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// finding key
void findKey(char *key, char *mark) {
  int len = strlen(key);

  int i = 0;
  int j = 0;
  memset(mark, 0, 26);

  for (i = 0; i < len; i++)
    if (mark[key[i] - 97] == 0) {
      mark[key[i] - 97] = 1;
      key[j] = key[i];
      j++;
    }
  key[j] = '\0';

  for (i = 0, j = 0; i < 26; i++)
    if (mark[i] == 0) {
      mark[j] = 97 + i;
      j++;
    }
  mark[j] = '\0';
}

int main() {
  char *encrypt;
  char map[27];
  char key[100];
  char mark[26];

  int len;
  int markLen;
  int i;
  int nFileLen;

  FILE *inputFile;
  FILE *outputFile;

  // printf("输入密钥:");
  scanf("%s", key);

  findKey(key, mark);

  // printf("得到密钥:%s\n", key);

  len = strlen(key);
  strcpy(map, key);

  markLen = strlen(mark);
  for (i = len; i < 26; i++)
    map[i] = mark[markLen + len - 1 - i];
  map[26] = '\0';
  // printf("映射关系:%s\n", map);

  inputFile = fopen("encrypt.txt", "r");

  if (inputFile == NULL) {
    printf("encrypt.txt不存在\n");
    return 1;
  }

  fseek(inputFile, 0, SEEK_END);
  nFileLen = ftell(inputFile);
  encrypt = (char *)malloc(nFileLen + 1);
  fseek(inputFile, 0, SEEK_SET);
  fread(encrypt, nFileLen, 1, inputFile);
  encrypt[nFileLen] = '\0';

  // printf("读取明文:%s\n", encrypt);

  for (i = 0; i < nFileLen; i++) {
    if (encrypt[i] < 123 && encrypt[i] > 96) {
      encrypt[i] = map[encrypt[i] - 97];
    }
  }

  outputFile = fopen("output.txt", "w+");

  fwrite(encrypt, nFileLen, 1, outputFile);

  // printf("加密的密文:%s\n", encrypt);

  fclose(outputFile);
  fclose(inputFile);
  free(encrypt);
  system("pause");

  return 0;
}
