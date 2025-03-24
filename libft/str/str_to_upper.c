#include "libft.h"

// Function to convert a string to uppercase
char *str_to_upper(const char *str)
{
    size_t length;
    char *upper_str;
    size_t i;

    length = ft_strlen(str);

    upper_str = (char *)malloc((length + 1) * sizeof(char));
    if (upper_str == NULL)
        return (NULL);

    i = 0;
    while (str[i] != '\0')
    {
        upper_str[i] = ft_toupper((unsigned char)str[i]);
        i++;
    }
    upper_str[i] = '\0';
    return (upper_str);
}
