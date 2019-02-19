#include <stdio.h>
#include <stdlib.h>

#include "chained_hash.h"

#define FIST_NUM 1
#define LAST_NUM 1000
int main(int argc, char* argv[])
{
    chained_hash *chain = chained_init(atoi(argv[1]));

    //chained_hash *chain = chained_init(113); //This argument presents the number of bucket

    uint8_t key[KEY_LEN];
    uint8_t value[VALUE_LEN];

    //insert test
    int i, inserted = 0;
    for (i = FIST_NUM; i <= LAST_NUM; i++)
    {
        snprintf(key, KEY_LEN, "%d", i);
        snprintf(value, VALUE_LEN, "%d", i*3);
        if (!chained_insert(chain, key, value))
            inserted++;
        else
            break;
    }
    printf("\n");
    printf("The number of inserted element:%d\n", inserted);
    printf("\n");

    //query test
    uint8_t* get_value;
    for (i = FIST_NUM; i <= LAST_NUM; i++)
    {
        snprintf(key, KEY_LEN, "%d", i);
        if (get_value = (uint8_t *)chained_query(chain, key))
            ;//printf("Query key:%s value:%s\n", key, get_value);
    }

    //delete test
    for (i = FIST_NUM; i <= LAST_NUM; i++)
    {
        snprintf(key, KEY_LEN, "%d", i);
        if (!chained_delete(chain, key))
            ;//printf("Delete:%s\n", key);
    }

    printf("The number of total element:%d\n", chain->num_total_element);

    //chained_destory(chain);
    return 0;
}
