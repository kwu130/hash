#include <stdio.h>
#include <stdlib.h>

#include "linear_probing_hash.h"

#define FIRST_NUM 1
#define LAST_NUM 100

int main(int argc, char* argv[])
{
    linear_hash *linear = malloc(sizeof(linear_hash));

    linear = linear_init(atoi(argv[1]));

    //linear = linear_init(13131); //The argument presents the capacity of linear hash table

    uint8_t key[KEY_LEN];
    uint8_t value[VALUE_LEN];

    //test insert
    int i, inserted = 0;
    for (i = FIRST_NUM; i < LAST_NUM; i++)
    {
        snprintf(key, KEY_LEN, "%d", i);
        snprintf(value, VALUE_LEN, "%d", 3*i);
        if (!linear_insert(linear, key, value))
            inserted++;
    }

    printf("\nThe number of inserted element:%d\n\n", inserted);
    //test query
    uint8_t *get_value;
    for (i = FIRST_NUM; i < LAST_NUM; i++)
    {
        snprintf(key, KEY_LEN, "%d", i);
        if (get_value = (uint8_t*)linear_query(linear, key))
            printf("Query key:%s value:%s\n", key, get_value);
    }

    printf("\n");
    //test delete
    for (i = FIRST_NUM; i < LAST_NUM; i++)
    {
        snprintf(key, KEY_LEN, "%d", i);
        if (!linear_delete(linear, key))
            printf("Delete key:%s\n", key);
    }

    printf("\nThe number of left element:%d\n", linear->num_total_element);

    linear_destory(linear);

    return 0;
}
