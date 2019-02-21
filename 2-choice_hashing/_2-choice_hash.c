#include "_2-choice_hash.h"

_2choice_hash* _2choice_init(uint32_t size)
{
    _2choice_hash *_2choice = malloc(sizeof(_2choice_hash));

    _2choice->max_capacity = size;
    _2choice->num_total_element = 0;
    srand(time(NULL));
    _2choice->seed = rand();
    _2choice->seed = _2choice->seed << (rand() % 63);
    _2choice->node = calloc(_2choice->max_capacity, sizeof(hash_node));

    printf("The max capacity:%d\n", _2choice->max_capacity);
    printf("The number of element:%d\n", _2choice->num_total_element);

    return _2choice;
}

uint8_t _2choice_insert(_2choice_hash *_2choice, uint8_t *key, uint8_t *value)
{
    uint32_t index1 = hash((void *)key, strlen(key), _2choice->seed) % (_2choice->max_capacity / 2);
    uint32_t index2 = hash((void *)key, strlen(key), _2choice->seed) % (_2choice->max_capacity / 2) + (_2choice->max_capacity / 2);

    if (!_2choice->node[index1].token)
    {
        memcpy(_2choice->node[index1].key, key, KEY_LEN);
        memcpy(_2choice->node[index1].value, value, VALUE_LEN);
        _2choice->node[index1].token = 1;
        _2choice->num_total_element++;
        return 0;
    }

    if (!_2choice->node[index2].token)
    {
        memcpy(_2choice->node[index2].key, key, KEY_LEN);
        memcpy(_2choice->node[index2].value, value, VALUE_LEN);
        _2choice->node[index2].token = 1;
        _2choice->num_total_element++;
        return 0;
    }

    printf("Insert Failure\n");
    return 1;
}

uint8_t* _2choice_query(_2choice_hash *_2choice, uint8_t *key)
{
    uint32_t index1 = hash((void *)key, strlen(key), _2choice->seed) % (_2choice->max_capacity / 2);
    uint32_t index2 = hash((void *)key, strlen(key), _2choice->seed) % (_2choice->max_capacity / 2) + (_2choice->max_capacity / 2);

    if (_2choice->node[index1].token)
    {
        if (strcmp(_2choice->node[index1].key, key) == 0)
            return _2choice->node[index1].value;
    }

    if (_2choice->node[index2].token)
    {
        if (strcmp(_2choice->node[index2].key, key) == 0)
            return _2choice->node[index2].value;
    }

    printf("The key is not exist:%s\n", key);
    return NULL;
}

uint8_t _2choice_delete(_2choice_hash *_2choice, uint8_t *key)
{
    uint32_t index1 = hash((void *)key, strlen(key), _2choice->seed) % (_2choice->max_capacity / 2);
    uint32_t index2 = hash((void *)key, strlen(key), _2choice->seed) % (_2choice->max_capacity / 2) + (_2choice->max_capacity / 2);

    if (_2choice->node[index1].token)
    {
        if (strcmp(_2choice->node[index1].key, key) == 0)
            return _2choice->node[index1].token = 0;
    }

    if (_2choice->node[index2].token)
    {
        if (strcmp(_2choice->node[index2].key, key) == 0)
            return _2choice->node[index2].token = 0;
    }

    printf("The key is not exist:%s\n", key);
    return 1;
}

uint8_t _2choice_destory(_2choice_hash *_2choice)
{
    free(_2choice->node);
    free(_2choice);
    return 0;
}
