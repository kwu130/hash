#include "linear_probing_hash.h"

linear_hash* linear_init(uint32_t size)
{
    linear_hash * linear = malloc(sizeof(linear_hash));

    linear->num_total_element = 0;
    linear->max_capacity = size;
    srand(time(NULL));
    linear->seed = rand();
    linear->seed = linear->seed << (rand() % 63);
    //linear->seed = 10;
    linear->node = calloc(linear->max_capacity, sizeof(hash_node));

    printf("The number of element:%d\n", linear->num_total_element);
    printf("The max capacity:%d\n", linear->max_capacity);

    return linear;
}

uint8_t* linear_query(linear_hash *linear, uint8_t *key)
{
    uint32_t index = hash((void *)key, strlen(key), linear->seed) % linear->max_capacity;

    uint32_t i = index;
    while (1)
    {
        if (strcmp(linear->node[i].key, key) == 0)
            return linear->node[i].value;
        i++;
        i %= linear->max_capacity;
        if (i == index)
            break;
    }

    printf("The key is not exist:%s\n", key);
    return NULL;
}

uint8_t linear_insert(linear_hash *linear, uint8_t *key, uint8_t *value)
{
    uint32_t index = hash((void *)key, strlen(key), linear->seed) % linear->max_capacity;

    uint32_t i = index;
    while (1)
    {
        if (linear->node[i].token == 0)
        {
            memcpy(linear->node[i].key, key, KEY_LEN);
            memcpy(linear->node[i].value, value, VALUE_LEN);
            linear->node[i].token = 1;
            //printf("insert key:%s value:%s index:%d\n", linear->node[i].key, linear->node[i].value, index);
            linear->num_total_element++;
            return 0;
        }
        i++;
        i %= linear->max_capacity;
        if (i == index)
            break;
    }

    printf("Insert failure!\n");
    return 1;
}

uint8_t linear_delete(linear_hash *linear, uint8_t *key)
{
    uint32_t index = hash((void *)key, strlen(key), linear->seed) % linear->max_capacity;

    uint32_t i = index;
    while (1)
    {
        if (linear->node[i].token && !strcmp(linear->node[i].key, key))
        {
            linear->node[i].token = 0;
            linear->num_total_element--;
            return 0;
        }
        i++;
        i %= linear->max_capacity;
        if (i == index)
            break;
    }

    printf("The key is not exist:%s\n", key);
    return 1;
}

uint8_t linear_destory(linear_hash *linear)
{
    free(linear->node);
	free(linear);
    return 0;
}


