#include "chained_hash.h"

chained_hash* chained_init(uint32_t num_bucket)
{
    chained_hash *chain = malloc(sizeof(chained_hash));
    if (!chain)
    {
        printf("The Initialization Fails1!\n");
        exit(1);
    }

    chain->num_bucket = num_bucket;
    chain->num_total_element = 0;
    srand(time(NULL));
    chain->seed = rand();
    chain->seed = chain->seed << (rand() % 63);
    chain->buckets = calloc(chain->num_bucket, sizeof(chained_node*));

    if (!chain->buckets)
    {
        printf("The Initialization Fails2!\n");
        exit(1);
    }

    printf("The number of bucket:%d\n", chain->num_bucket);
    printf("The number of element:%d\n", chain->num_total_element);

    return chain;

}

uint8_t* chained_query(chained_hash *chain, uint8_t *key)
{
    uint32_t index = hash((void *)key, strlen(key), chain->seed) % chain->num_bucket;
    chained_node *head = chain->buckets[index];

    while (head)
    {
        //printf("%s %s\n", head->key, key);
        if (strcmp(head->key, key) == 0)
            return head->value;
        else
            head = head->next;
    }

    printf("The key does not exist: %s\n", key);
    return NULL;
}

uint8_t chained_insert(chained_hash *chain, uint8_t *key, uint8_t* value)
{
    uint32_t index = hash((void *)key, strlen(key), chain->seed) % chain->num_bucket;
    chained_node *head = chain->buckets[index];

    if (!head)
    {
        chained_node *cur = malloc(sizeof(chained_node));
        memcpy(cur->key, key, KEY_LEN);
        memcpy(cur->value, value, VALUE_LEN);
        cur->next = NULL;
        chain->buckets[index] = cur;
        //printf("%s %s\n", head->key, head->value);
    }
    else
    {
        chained_node *cur = malloc(sizeof(chained_node));
        memcpy(cur->key, key, KEY_LEN);
        memcpy(cur->value, value, VALUE_LEN);
        cur->next = head->next;
        head->next = cur;
    }
    chain->num_total_element++;

    return 0;
}

uint8_t chained_delete(chained_hash *chain, uint8_t *key)
{
    uint32_t index = hash((void *)key, strlen(key), chain->seed) % chain->num_bucket;
    chained_node *head = chain->buckets[index];

    chained_node *cur = head;
    chained_node *pre = NULL;
    while (cur)
    {
        if (strcmp(cur->key, key) == 0)
        {
            if (cur == head)
                chain->buckets[index] = cur->next;
            else
                pre = cur->next;
            free(cur);
            chain->num_total_element--;
            return 0;
        }
        pre = cur;
        cur = cur->next;
    }

    printf("The key does not exist: %s\n", key);
    return 1;
}

uint8_t chained_destory(chained_hash *chain)
{
    uint32_t i;
    for (i = 0; i < chain->num_bucket; i++)
    {
        chained_node *head = chain->buckets[i];
        chained_node *tmp;
        while (head)
        {
            tmp = head;
            head = head->next;
            free(tmp);
        }
    }

    free(chain);
    return 0;
}



