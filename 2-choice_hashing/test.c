#include <stdio.h>
#include <stdlib.h>

#include "_2-choice_hash.h"

#define FIRST_NUM 1
#define LAST_NUM 200

int main(int argc, char* argv[])
{
    _2choice_hash *_2choice = malloc(sizeof(_2choice_hash));

    _2choice = _2choice_init(atoi(argv[1]));

    //_2choice = _2choice_init(13131); // This argument presents the max capacity of the hash table

    uint8_t key[KEY_LEN];
    uint8_t value[VALUE_LEN];
    //test insert
    int i, inserted = 0;
    for (i = FIRST_NUM; i < LAST_NUM; i++)
    {
        snprintf(key, KEY_LEN, "%d", i);
        snprintf(value, VALUE_LEN, "%d", 3*i);
        if (!_2choice_insert(_2choice, key, value))
            inserted++;
        else
            break;
    }

    printf("\nIhe number of inserted element:%d\n\n", inserted);

    //test query
    uint8_t *get_value;
    for (i = FIRST_NUM; i < LAST_NUM; i++)
    {
        snprintf(key, KEY_LEN, "%d", i);
        if (get_value = _2choice_query(_2choice, key))
            printf("Query key:%s value:%s\n", key, get_value);
    }
    printf("\n");
    //test delete
    for (i = FIRST_NUM; i < LAST_NUM; i++)
    {
        snprintf(key, KEY_LEN, "%d", i);
        if (!_2choice_delete(_2choice, key))
            printf("Delete key:%s\n", key);
    }

    printf("\nThe number of left element:%d\n", _2choice->num_total_element);

    _2choice_destory(_2choice);

    return 0;
}
