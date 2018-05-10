#include <stdio.h>
#include "cJSON.h"


#define  _TEST_CJSON_ 1


void test_cJSON()
{
    char *str = NULL;
    cJSON *root = NULL;
    cJSON *status = NULL;
    cJSON *array = NULL;
    cJSON *sub_num = NULL;
    
    root = cJSON_CreateObject();
    status = cJSON_CreateObject();
    array = cJSON_CreateArray();
    sub_num = cJSON_CreateObject();
    
    cJSON_AddItemToObject(root, "status", status);
    cJSON_AddStringToObject(status, "Yunchun", "name");
    cJSON_AddNumberToObject(status, "age", 25);
    cJSON_AddStringToObject(sub_num, "type", "Awesome 4K");
    cJSON_AddStringToObject(sub_num, "error_code", "error_code");
    cJSON_AddNumberToObject(sub_num, "error_code", 100);
    cJSON_AddItemToArray(array, sub_num);
    cJSON_AddItemToObject(status, "array", array);
    cJSON_AddItemToObject(root, "array", array);
    
    str = cJSON_Print(root);
    printf("\n%s\n", str);
    //cJSON_Delete(root);
}

int main()
{
#if _TEST_CJSON_
    test_cJSON();
#endif
    
    return 0;
}