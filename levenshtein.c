#include <string.h>
#include <stdlib.h>

unsigned int levenshtein(const char *a, const char *b)
{
    unsigned int length = strlen(a);
    unsigned int bLength = strlen(b);
    unsigned int *cache = calloc(length, sizeof(unsigned int));
    unsigned int index = 0;
    unsigned int bIndex = 0;
    unsigned int distance;
    unsigned int bDistance;
    unsigned int result;
    char code;

    if (a == b)
    {
        return 0;
    }

    if (length == 0)
    {
        return bLength;
    }

    if (bLength == 0)
    {
        return length;
    }

    while (index < length)
    {
        cache[index] = index + 1;
        index++;
    }

    while (bIndex < bLength)
    {
        code = b[bIndex];
        result = distance = bIndex++;
        index = -1;

        while (++index < length)
        {
            bDistance = code == a[index] ? distance : distance + 1;
            distance = cache[index];

            // cache[index] = result = distance > result ? bDistance > result ? result + 1 : bDistance : bDistance > distance ? distance + 1 : bDistance;
            if (distance > result)
            {
                if (bDistance > result)
                {
                    cache[index] = result = result + 1;
                }
                else
                {
                    cache[index] = result = bDistance;
                }
            }
            else if (bDistance > distance)
            {
                cache[index] = result = distance + 1;
            }
            else
            {
                cache[index] = result = bDistance;
            }
        }
    }

    free(cache);

    return result;
}
