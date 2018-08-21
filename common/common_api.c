/*************************************************************************
 *
    > File Name: common_api.c
    > Author: Yunchun
    > Mail: zyc@baic.io 
    > Created Time: 2018年08月21日 星期二 17时49分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "common_api.h"



int bytes2hexStr(const unsigned char *buf, char *hexStr, int bufLen)
{
    int i;
    
    for(i = 0; i < bufLen; i++)
    {
        sprintf(&(hexStr[i * 2]), "%02x", buf[i]);
    }
    
    // Each 2 hex characters is one byte
    return bufLen * 2;
}


int hexStr2bytes(const char *hexStr, unsigned char *buf, int bufLen)
{
    int i;
    
    for(i = 0; i < bufLen / 2; i++)
    {
        sscanf(&(hexStr[i * 2]), "%2hhx", &(buf[i]));
    }
    
    // Each 2 hex characters is one byte
    return bufLen / 2;
}


#if 1 
int main()
{
    char *hex_str = "00A404000B464D53482E44432E415050";
    unsigned char buf[18];
    int sum, i;
    
    sum = hexStr2bytes(hex_str, buf, 32);
    printf("length = %d data = ", sum);
    for(i = 0; i < sum; i++)
    {
        printf("%x ", buf[i]);
    }
    printf("\n");
    
    
    unsigned char buf2[16] = {0x00, 0xA4, 0x04, 0x00, 0x0B, 0x46, 0x4D, 0x53, 0x48, 0x2E, 0x44, 0x43, 0x2E, 0x41, 0x50, 0x50};
    char *hex_str2;
    int sum2;
    
    hex_str2 = malloc(16 * sizeof(char *));
    sum2 = bytes2hexStr(buf2, hex_str2, 16);
    printf("%s\n", hex_str2);
    free(hex_str2);
    
    
    return 0;
}
#endif
