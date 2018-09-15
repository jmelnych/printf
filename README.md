# Project Overview
An implementation of libc's printf function.

# About ft_printf
The ft_printf function is prototyped as follows:
```C
int ft_printf(const char *format, ...);
```

## The function manage: 
* the flags #0-+, space and *
* the following conversions: sSpdDioOuUxXcC and b to binary
* %%
* the minimum field-width
* the precision
* the flags hh, h, l, ll, j, z.

# Usage
```ft_printf("%s\n", "whatever"); ```
