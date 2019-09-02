/*************************************************************************
 *
    > File Name: common_api.h
    > Author: Yunchun
    > Mail: zyc@baic.io 
    > Created Time: 2018年08月21日 星期二 17时44分35秒
 ************************************************************************/

 #ifndef _COMMON_API_H_
#define _COMMON_API_H_


#ifdef __cplusplus
extern "C"
{
#endif

extern int bytes2hexStr(const unsigned char *buf, char *hexStr, int bufLen);
extern int hexStr2bytes(const char *hexStr, unsigned char *buf, int bufLen);


#ifdef __cplusplus
}
#endif

#endif
