#define ATTR(key) __attribute__((key))
#define ALIAS(name) ATTR(alias(name))
#define USED ATTR(used)

int length_of_longest_substring(char * s)
{
    return 0;
}

int lengthOfLongestSubstring() USED ALIAS("length_of_longest_substring");
