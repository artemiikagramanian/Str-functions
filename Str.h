#ifndef STR_H
#define STR_H

int str_len (char* s);

char* str_copy (char* str_1, const char* str_2);

char* str_n_copy (char* str_1, const char* str_2, int n);

int str_cmp (char* str_1, char* str_2);

char* str_cat (char* str_1, const char* str_2);

char* str_n_cat (char* str_dst, const char* str_src, int n);

char* str_chr (char* str, char sym);

int fgets (FILE* file, char* str, int lim);

int get_line (FILE* file, char** buf, int* lim);

char* str_dup (char* str_src);

#endif
