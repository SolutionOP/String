#include "s21_string.h"

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Вычисляет количество символов в строке.
 *
 * @param str Указатель на строку.
 * @return Функция возвращает количество символов в строке до первого вхождения
 * символа конца строки.
 */
s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  while (str[len]) len++;
  return len;
}

/**
 * @brief  Ищет вхождение в массив символа, код которого задан аргументом c,
сравнивая каждый байт массива.
 *
 * @param arr Указатель на массив, в котором будет осуществляться поиск.
 * @param c Код искомого символа.
 * @param n Размер сравниваемой части массива в байтах.
 * @return Указатель на найденный символ, если, на указанном участке массива,
найден требуемый символ. NULL – если требуемый символ не найден.
 */
void *s21_memchr(const void *arr, int c, s21_size_t n) {
  const char *str = arr;
  char k = c;
  for (s21_size_t i = 0; i < n; i++) {
    if (str[i] == k) {
      return (char *)str + i;
    }
  }
  return s21_NULL;
}

/**
 * @brief Побайтно сравнивает два массива, на которые указывают аргументы arr1 и
 * arr2.
 *
 * @param arr1 Указатель на сравниваемый массив.
 * @param arr2 Указатель на сравниваемый массив.
 * @param n Размер сравниваемой части массива в байтах.
 * @return Результат сравнивания.
 */
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *s1;
  const unsigned char *s2;
  s1 = str1;
  s2 = str2;
  char count = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      count = s1[i] - s2[i];
      break;
    }
  }
  return count;
}

/**
 * @brief Копирует n байт в массив.
 *
 * @param destination Указатель на массив в которой будут скопированы данные.
 * @param source Указатель на массив источник копируемых данных.
 * @param n Количество байт для копирования.
 * @return Возвращает указатель на массив, в который скопированы данные.
 */
void *s21_memcpy(void *destination, const void *source, s21_size_t n) {
  char *dst = destination;
  const char *src = source;
  while (n--) *dst++ = *src++;
  return destination;
}

/**
 * @brief Определяет наибольшую длину начального участка строки.
 *
 * @param str1 Указатель на строку, в которой ведется поиск.
 * @param str2 Указатель на строку с набором символов, которые должны входить в
 * участок строки str1.
 * @return Функция возвращает длину начального участка строки, содержащую только
 * символы, указанные в аргументе sym&
 */
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t n = 0, i = 0, k;
  for (i = 0; i < s21_strlen(str1); i++) {
    for (k = 0; k < s21_strlen(str2); k++) {
      if (str1[i] == str2[k]) {
        return n;
      }
    }
    n++;
  }
  return n;
}

/**
 * @brief Копирует n байт из массива в массив.
 *
 * @param dest Указатель на массив в который будут скопированы данные.
 * @param src Указатель на массив источник копируемых данных.
 * @param n Количество байт для копирования.
 * @return Функция возвращает указатель на массив, в который скопированы данные.
 */
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *dst = dest;
  const char *o_src = src;
  if (dst > o_src && dst < o_src + n) {
    o_src += n;
    dst += n;
    while (n--) *--dst = *--o_src;
  } else {
    while (n--) *dst++ = *o_src++;
  }
  return dest;
}

/**
 * @brief Поднимает все символы из нижнего регистра в верхний.
 *
 * @param str Указатель на изначальный массив.
 * @return Функция возвращает указатель на измененный массив.
 */
void *s21_to_upper(const char *str) {
  char *dst = s21_NULL;
  if (str) {
    dst = (char *)realloc(dst, (s21_strlen(str) + 1) * sizeof(char));
    dst[s21_strlen(str)] = '\0';
  }
  if (dst) {
    s21_strncpy(dst, str, s21_strlen(str));
    for (char *i = dst; *i; i++) {
      if (*i >= 'a' && *i <= 'z') *i -= 32;
    }
  }
  return (void *)dst;
}

/**
 * @brief Опускает все символы из верхнего регистра в нижний.
 *
 * @param str Указатель на изначальный массив.
 * @return Функция возвращает указатель на измененный массив.
 */
void *s21_to_lower(const char *str) {
  char *our_str2 = s21_NULL;
  if (str) {
    our_str2 = (char *)realloc(our_str2, (s21_strlen(str) + 1) * sizeof(char));
    our_str2[s21_strlen(str)] = '\0';
  }
  if (our_str2) {
    s21_strncpy(our_str2, str, s21_strlen(str));
    for (char *i = our_str2; *i; i++) {
      if (*i >= 'A' && *i <= 'Z') *i += 32;
    }
  }
  return (void *)our_str2;
}

/**
 * @brief Заполняет первые n байт в области памяти.
 *
 * @param str Указатель на заполняемый массив.
 * @param c Код символа для заполнения.
 * @param n Размер заполняемой части массива в байтах.
 * @return Функция возвращает указатель на заполняемый массив.
 */
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *a = str;
  while (n--) *a++ = c;
  return str;
}

/**
 * @brief Объединение строк
 *
 * @param dest Указатель на строку назначения, к которой добавятся символы
 * строки source
 * @param src Си-строка, которая добавляется в конец строки destination.
 * @return char* Возвращает указатель на массив, в который добавлена строка .
 */
char *s21_strcat(char *dest, const char *src) {
  char *a = dest;
  while (*a) a++;
  while ((*a++ = *src++)) continue;
  return dest;
}

/**
 * @brief Функция добавляет в строку, на которую указывает аргумент dest,
 * строку, на которую указывает аргумент append, пока не встретится символ конца
 * строки или пока не будет добавлено n символов.
 *
 * @param dest Указатель на массив в который будет добавлена строка.
 * @param src Указатель на массив из которого будет скопирована строка.
 * @param n Максимальная длина добавляемой строки.
 * @return char* Возвращает указатель на массив, в который добавлена строка
 */
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *a = dest + s21_strlen(dest);

  while (*src && n--) *a++ = *src++;
  *a = '\0';
  return dest;
}

/**
 * @brief Функция strchr ищет последнее вхождения символа, код которого указан в
 * аргументе ch, в строке, на которую указывает аргумент str.
 *
 * @param str Указатель на строку, в которой будет осуществляться поиск.
 * @param c Код искомого символа.
 * @return char* Указатель на искомый символ, если он найден в строке str, иначе
 * NULL.
 */

char *s21_strchr(const char *str, int c) {
  while (*str != c && *str) str++;
  return *str == c ? (char *)str : 0;
}

/**
 * @brief Функция побайтно сравнивает коды символов двух строк, на которые
 * указывают аргументы функции.
 *
 * @param str1  Указатель на сравниваемую строку.
 * @param str2  Указатель на сравниваемую строку.
 * @return int 0 – если сравниваемее строки идентичны;
 * Положительное число – если строки отличаются;Отрицательное число – если
 * строки отличаются
 */
int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}

/**
 * @brief Функция побайтно сравнивает коды символов двух строк, на которые
 * указывают аргументы функции.
 *
 * @param str1 Указатель на сравниваемую строку.
 * @param str2 Указатель на сравниваемую строку.
 * @param n Количество символов для сравнения.
 * @return int 0 – если сравниваемее строки идентичны;
 * Положительное число – если строки отличаются;Отрицательное число – если
 * строки отличаются
 */
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i = 0;
  while (*str1 && (*str1 == *str2) && i < n - 1) {
    str1++;
    str2++;
    i++;
  }
  return *str1 - *str2;
}

/**
 * @brief Копирует данные из строки, на которую указывает аргумент src, в dest
 *
 * @param dest Указатель на строку, в которую будут скопированы данные.
 * @param src Указатель на строку источник копируемых данных.
 * @return char* Возвращает указатель на строку, в которую скопированы данные.
 */
char *s21_strcpy(char *dest, const char *src) {
  char *res = &dest[0];
  for (int i = 0; (dest[i] = src[i]); i++) {
  }
  return res;
}

/**
 * @brief Копирует  данные из строки, на которую указывает аргумент src, в dest
 *
 * @param dest Указатель на строку в которую будут скопированы данные.
 * @param src Указатель на строку источник копируемых данных.
 * @param n Ограничение длинны копирования
 * @return char* Возвращает указатель на строку, в которую скопированы данные.
 */
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n && src[i]) {
    dest[i] = src[i];
    i++;
  }
  if (i > s21_strlen(src)) {
    dest[i++] = 0;
  }
  return dest;
}

/**
 * @brief Ищет последнее вхождения символа, код которого указан в аргументе c, в
 * строке, на которую указывает аргумент str.
 *
 * @param str Указатель на строку, в которой будет осуществляться поиск.
 * @param c Код искомого символа.
 * @return char* Указатель на искомый символ, если он найден в строке str, иначе
 * NULL.
 */
char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  do {
    if (*str == c) result = (char *)str;
  } while (*str++);

  return result;
}

/**
 * @brief Определяет наибольшую длину начального участка строки содержащего
 * только символы строки, на которую указывает аргумент
 *
 * @param str1 Указатель на строку, в которой ведется поиск.
 * @param str2 Указатель на строку с набором символов, которые должны входить в
 * участок строки str1.
 * @return s21_size_t Длина начального участка строки, содержащая только
 * символы, указанные в аргументе str2.
 */
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t i, j, counter = 0;

  for (i = 0; &str1[i] != s21_NULL; i++) {
    if (counter != i) break;
    for (j = 0; &str2[j] != s21_NULL; j++) {
      if (str1[i] == str2[j]) {
        counter++;
      } else {
        break;
      }
    }
  }
  return counter;
}

/**
 * @brief Ищет первое вхождение в строку, одного из символов, входящих в строку
 * 2
 *
 * @param str1 Указатель на строку, в которой ведется поиск.
 * @param str2 Указатель на строку с набором искомых символов.
 * @return char* Указатель на первый найденный в строке str1 символ из множества
 * символов строки str2.
 */
char *s21_strpbrk(const char *str1, const char *str2) {
  char *string1 = (char *)str1;
  char *string2 = (char *)str2;
  int flag = 1;
  char *res = s21_NULL;
  for (int i = 0; string1[i] != '\0' && flag == 1; i++) {
    char symbol = string1[i];
    if (s21_strchr(string2, symbol) != s21_NULL) {
      res = &string1[i];
      flag = 0;
    }
  }
  return res;
}

/**
 * @brief Ищет первое вхождение строки 1 в строку 2. Если строка 2 имеет нулевую
 * длину, то функция вернет указатель на начало строки 2.
 *
 * @param haystack Указатель на строку, в которой ведется поиск.
 * @param needle Указатель на искомую строку.
 * @return char* NULL – если строка heystack не входит в строку needle.
 * Указатель на первое вхождение строки heystack в строку needle.
 */
char *s21_strstr(const char *haystack, const char *needle) {
  int len_needle = s21_strlen(needle) - 1;
  char *str = s21_NULL;
  char *ptr = (char *)haystack;

  for (int i = 0; ptr[i] != '\0' && str == s21_NULL; i++) {
    int count = 0, flag = 1;
    while ((count <= len_needle) && flag) {
      flag = ptr[i + count] == needle[count];
      count++;
    }
    if (flag && (count > len_needle)) {
      str = &(ptr[i]);
    }
  }
  return str;
}

/**
 * @brief Выделяет очередную часть строки, отделенную одним из символов
 * разделителей указанных в строке, на которую указывает 2 аргумент
 *
 * @param str Указатель на разбиваемую строку.
 * @param delim Указатель на строку, содержащую набор символов разделителей.
 * @return char* NULL – если строку str невозможно разделить на части. Указатель
 * на первый символ выделенной части строки.
 */
char *s21_strtok(char *s, const char *delim) {
  static char *p;
  int null_flag = 0;

  if (!s) s = p;
  if (!s) null_flag = 1;

  while (1 && !null_flag) {
    if (is_delim(*s, delim)) {
      s++;
      continue;
    }

    if (*s == '\0') null_flag = 1;
    break;
  }

  char *ret = s;

  while (1 && !null_flag) {
    if (*s == '\0') {
      p = s;
      break;
    }

    if (is_delim(*s, delim)) {
      *s = '\0';
      p = s + 1;
      break;
    }

    s++;
  }

  return null_flag ? NULL : ret;
}

/**
 * @brief Вспомогательная функция определения является ли делитель частью строки
 * @param c строка
 * @param delim делитель
 * @return Булево значение
 */
int is_delim(char c, const char *delim) {
  int ret_flag = 0;

  while (*delim != '\0') {
    if (c == *delim) {
      ret_flag = 1;
      break;
    }

    delim++;
  }
  return ret_flag;
}

char *s21_strerror(int errnum) {
  static const char *strerr[] = s21_error;
  return (char *)strerr[errnum - 1];
}

/**
 * @brief Возвращает новую строку, со вставленной подстрокой
 * @param src - Основной массив, в который будем помещать подстроку
 * @param str - Подстрока, которую будем помещать в src
 * @param start_index - Индекс позиции, с которой будем начинать вставку
 * @returns Новая строка
 */
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t head = s21_strlen(src);
  s21_size_t minor = s21_strlen(str);
  s21_size_t am = 0;

  static char man[BUFF_SIZE] = {0};
  s21_size_t fromSrc = 0;
  s21_size_t fromStr = 0;

  while (fromSrc < head && fromSrc != start_index) {
    man[am++] = src[fromSrc];
    fromSrc++;
  }

  while (fromStr < minor) {
    man[am++] = str[fromStr];
    fromStr++;
  }

  while (fromSrc < head) {
    man[am++] = src[fromSrc];
    fromSrc++;
  }
  man[am] = '\0';
  return start_index <= head ? man : s21_NULL;
}

int start(const char *mani, const char *minor, s21_size_t head,
          s21_size_t nohead) {
  int start_i = 0;
  for (s21_size_t i = 0; i < head; i++) {
    int flag1 = 0;
    for (s21_size_t j = 0; j < nohead; j++) {
      if (mani[i] == minor[j]) {
        flag1 = 1;
        break;
      }
    }
    if (flag1 == 1) {
      start_i++;
    } else {
      break;
    }
  }
  return start_i;
}

int end(const char *mani, const char *minor, s21_size_t head,
        s21_size_t nohead) {
  int end_i = head;
  for (int i = head - 1; i > -1; i--) {
    int flag2 = 0;
    for (s21_size_t j = 0; j < nohead; j++) {
      if (mani[i] == minor[j]) {
        flag2 = 1;
        break;
      }
    }
    if (flag2 == 1) {
      end_i--;
    } else {
      break;
    }
  }
  return end_i;
}

/**
 * @brief Удаляет все начальные и конечные вхождения набора символов, заданного
 * в виде массива, из текущей строки.
 *
 * @param src Искомая строка
 * @param trim_chars Символы которые нужно заменить
 * @return void* Возвращает новую строку, в которой удаляются все начальные и
 * конечные вхождения набора заданных символов из данной строки
 */
void *s21_trim(const char *src, const char *trim_chars) {
  char *mani = (char *)src;
  char *minor = (char *)trim_chars;
  char *arr;
  int man = 1;
  if (minor == s21_NULL) {
    trim_chars = " ";
    minor = (char *)trim_chars;
  }
  if (mani == s21_NULL) man = 0;
  if (man) {
    int arr_i = 0;
    s21_size_t head = s21_strlen(src);
    s21_size_t nohead = s21_strlen(trim_chars);
    arr = (char *)malloc((head + 1) * sizeof(char));
    int st_i = start(mani, minor, head, nohead);
    int en_i = end(mani, minor, head, nohead);
    for (int i = st_i; i < en_i; i++) {
      arr[arr_i] = src[i];
      arr_i++;
    }
    arr[arr_i] = '\0';
  }
  if (man == 0) {
    return s21_NULL;
  } else {
    return (char *)arr;
  }
}

/**
 * @brief Записывает данные в массив.
 *
 * @param str Указатель на изначальный массив.
 * @param format Формат для обработки.
 * @return Функция возвращает количество успешно записанных символов.
 */
int s21_sprintf(char *str, const char *format, ...) {
  va_list vl;
  va_start(vl, format);
  while (*format) {
    if (*format != '%') {
      *str = *format;
      str++;
      format++;
    } else {
      format++;
      struct format_sprintf _format_sprintf;
      ZeroingFields(&_format_sprintf);

      if (parsing(&format, &_format_sprintf) == 1) {
        record_arg(&format, &str, &_format_sprintf, vl);
      }
    }
  }
  va_end(vl);
  return 0;
}

void record_arg(const char **format, char **str,
                struct format_sprintf *_format_spr, va_list vl) {
  char buffer[BUFF_SIZE];

  if (**format == 'c') {
    char ch = _format_spr->length_l ? va_arg(vl, long int) : va_arg(vl, int);

    if (_format_spr->flag_minus) {
      **str = ch;
      (*str)++;
    }

    for (int i = 1; i < _format_spr->width; i++) {
      **str = ' ';
      (*str)++;
    }

    if (!_format_spr->flag_minus) {
      **str = ch;
      (*str)++;
    }

    (*format)++;

  } else if (**format == '%') {
    **str = '%';
    (*str)++;
    (*format)++;

  } else if (**format == 'd' || **format == 'i') {
    int int_temp;

    short int si_temp;
    char *str_temp;
    char str_res[BUFF_SIZE] = {0};

    if (_format_spr->length_l) {
      long int li_temp;
      li_temp = va_arg(vl, long int);
      str_temp = litos(li_temp, buffer, 10, 0);
    } else if (_format_spr->length_h) {
      si_temp = (short)va_arg(vl, int);
      str_temp = sitos(si_temp, buffer, 10, 0);
    } else {
      int_temp = va_arg(vl, int);
      str_temp = itos(int_temp, buffer, 10, 0);
    }

    int len = s21_strlen(str_temp);
    int res_len = len;

    if (_format_spr->flag_plus && !_format_spr->flag_space &&
        str_temp[0] != '-') {
      s21_strcat(str_res, "+");
      res_len++;
    }

    if (_format_spr->flag_space) {
      s21_strcat(str_res, " ");
      res_len++;
    }

    while (_format_spr->precision-- > len) {
      s21_strcat(str_res, "0");
      res_len++;
    }

    s21_strcat(str_res, str_temp);

    if (_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }

    for (; res_len < _format_spr->width--;) {
      **str = ' ';
      (*str)++;
    }

    if (!_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }

    (*format)++;

  } else if (**format == 's') {
    char *str_temp;
    char str_res[BUFF_SIZE] = {0};

    str_temp = va_arg(vl, char *);

    int len = s21_strlen(str_temp);
    int res_len = len;

    s21_strcat(str_res, str_temp);

    if (_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }

    for (; res_len < _format_spr->width--;) {
      **str = ' ';
      (*str)++;
    }

    if (!_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }
    (*format)++;

  } else if (**format == 'u') {
    unsigned short int si_temp;
    char *str_temp;
    char str_res[BUFF_SIZE] = {0};

    if (_format_spr->length_l) {
      unsigned long int li_temp;
      li_temp = va_arg(vl, unsigned long int);
      str_temp = uitos(li_temp, buffer, 10, 0);
    } else if (_format_spr->length_h) {
      si_temp = (short)va_arg(vl, unsigned int);
      str_temp = uitos(si_temp, buffer, 10, 0);
    } else {
      unsigned int int_temp;
      int_temp = va_arg(vl, unsigned int);
      str_temp = uitos(int_temp, buffer, 10, 0);
    }

    int len = s21_strlen(str_temp);
    int res_len = len;

    while (_format_spr->precision-- > len) {
      s21_strcat(str_res, "0");
      res_len++;
    }

    s21_strcat(str_res, str_temp);

    if (_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }

    for (; res_len < _format_spr->width--;) {
      **str = ' ';
      (*str)++;
    }

    if (!_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }
    (*format)++;

  } else if (**format == 'f') {
    double double_temp = va_arg(vl, double);
    char *str_temp;
    char str_res[BUFF_SIZE] = {0};
    int decimal = 0;
    int sign = 0;
    int counter = 0;

    int fact = fabs(double_temp) > 1.0 ? 1 : 0;
    if (_format_spr->is_pricision != 1) {
      _format_spr->precision = 6;
    }
    str_temp =
        fcvt(double_temp, _format_spr->precision + fact, &decimal, &sign);
    int len = s21_strlen(str_temp);
    int res_len = len;

    if (_format_spr->flag_plus && !_format_spr->flag_space && sign == 0) {
      s21_strcat(str_res, "+");
      res_len++;
    }

    if (_format_spr->flag_space) {
      s21_strcat(str_res, " ");
      res_len++;
    }

    if (sign != 0) {
      s21_strcat(str_res, "-");
      res_len++;
    }

    if (decimal <= 0) {
      s21_strcat(str_res, "0.");
      res_len += 2;
      decimal *= -1;

      for (int i = 0; i < decimal; i++) {
        s21_strcat(str_res, "0");
        res_len++;
      }

      for (int i = 0; str_temp[i] != '\0'; i++) {
        char ch = str_temp[i];
        str_res[res_len - len + i] = ch;
        if (counter == decimal + 1) {
          str_res[res_len - len + i] = '.';
        }
      }

    } else {
      for (int i = 0; str_temp[i]; i++) {
        counter++;
        char ch = str_temp[i];
        str_res[res_len - len + i] = ch;
        if (counter == decimal + 1) {
          str_res[res_len - len + i] = '.';
        }
      }
    }
    if (_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }

    for (; res_len < _format_spr->width--;) {
      **str = ' ';
      (*str)++;
    }

    if (!_format_spr->flag_minus) {
      for (int i = 0; i < res_len; i++) {
        **str = str_res[i];
        (*str)++;
      }
    }
    /*
    if (sign != 0) {
      **str = '-';
      str++;
    }
    */

    (*format)++;
  }
}

/**
 * @brief Парсит данные и записывает в поля структуры.
 *
 * @param format Исходная строка.
 * @param _format_sprintff Указатель на структуру.
 * @param flag_pars Указатель на возвращаемое значение.
 * @returns Возвращает значение.
 */
int parsing(const char **format, struct format_sprintf *_format_sprintff) {
  int flag_pars = 0;
  while (**format) {
    if (**format == '-' || **format == '+' ||
        **format == ' ') {  // Ckeck for flags
      if (**format == '-') {
        _format_sprintff->flag_minus = 1;
      } else if (**format == '+') {
        _format_sprintff->flag_plus = 1;
      } else if (**format == ' ') {
        _format_sprintff->flag_space = 1;
      }
      (*format)++;

    } else if (is_digit(**format) == ON) {  // Check for Width
      while (is_digit(**format)) {
        _format_sprintff->width = **format - '0' + _format_sprintff->width * 10;
        (*format)++;
      }

    } else if (**format == '.') {  // Check for precision
      _format_sprintff->is_pricision = 1;
      (*format)++;
      while (is_digit(**format)) {
        _format_sprintff->precision =
            **format - '0' + _format_sprintff->precision * 10;
        (*format)++;
      }

    } else if (**format == 'h' || **format == 'l') {  // Check for length
      if (**format == 'h') {
        _format_sprintff->length_h = 1;
      } else if (**format == 'l') {
        _format_sprintff->length_l = 1;
      }
      (*format)++;

    } else if (is_specifier(**format) == ON) {  // Check for specifier
      flag_pars = 1;
      break;

    } else {  // Returns error
      flag_pars = 0;
      break;
    }
  }
  return flag_pars;
}

/**
 * @brief Проверяет символ на число.
 *
 * @param ch Входной символ.
 * @returns Функция возвращает положительный или негативный резульатат.
 */
int is_digit(char ch) {
  int f = OFF;
  if (ch >= '0' && ch <= '0' + 10) {
    f = ON;
  }
  return f;
}

/**
 * @brief Проверяет символ на спецификатор.
 *
 * @param is Входной символ.
 * @returns Функция возвращает положительный или негативный резульатат.
 */
int is_specifier(char ch) {
  int f = OFF;
  if (ch == 'd' || ch == 'i' || ch == 'c' || ch == 'f' || ch == 's' ||
      ch == 'u' || ch == '%') {
    f = ON;
  }
  return f;
}

/**
 * @brief Обнуляет поля структуры.
 *
 * @param formatS Указатель на структуру.
 */
void ZeroingFields(struct format_sprintf *formatS) {
  formatS->flag_minus = 0;
  formatS->flag_plus = 0;
  formatS->flag_space = 0;
  formatS->length_h = 0;
  formatS->length_l = 0;
  formatS->precision = 0;
  formatS->width = 0;
  formatS->is_pricision = 0;
}

/**
 * @brief Проверка символа.
 *
 * @param val Значение.
 * @param base Система счисления.
 * @param upperCase Верхний регистр.
 * @return Верхний регистр.
 */
int itoc(int val, int base, int upperCase) {
  const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
  const char DIGITS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  return upperCase ? DIGITS[val % base] : digits[val % base];
}

/**
 * @brief Проверяет строку.
 *
 * @param number Числовое значение.
 * @param str Входная строка.
 * @param base Система счисления.
 * @param upperCase Верхний регистр.
 * @return Верхний регистр.
 */
char *itos(int number, char *str, int base, int upperCase) {
  int isNegative = 0, i = 0;

  if (!number) {
    str[i++] = '0';
    str[i] = '\0';
    return str;
  }

  if (number < 0 && base == 10) {
    isNegative++;
    number = -number;
  }

  while (number > 0) {
    int digit = number % base;
    str[i++] = itoc(digit, base, upperCase);
    number /= base;
  }

  if (isNegative) str[i++] = '-';

  str[i] = '\0';

  int pos = 0;
  i--;

  while (pos < i) {
    int swap = str[pos];
    str[pos] = str[i];
    str[i] = swap;

    pos++;
    i--;
  }

  return str;
}

/**
 * @brief Проверяет длины строк.
 *
 * @param number Числовое значение.
 * @param str Входная строка.
 * @param base Система счисления.
 * @param upperCase Верхний регистр.
 * @return Функция возвращает указатель на строку.
 */
char *litos(long int number, char *str, long int base, int upperCase) {
  int isNegative = 0, i = 0;

  if (!number) {
    str[i++] = '0';
    str[i] = '\0';
    return str;
  }

  if (number < 0 && base == 10) {
    isNegative++;
    number = -number;
  }

  while (number > 0) {
    int digit = number % base;
    str[i++] = itoc(digit, (int)base, upperCase);
    number /= base;
  }

  if (isNegative) str[i++] = '-';
  str[i] = '\0';

  int pos = 0;
  i--;

  while (pos < i) {
    int swap = str[pos];
    str[pos] = str[i];
    str[i] = swap;

    pos++;
    i--;
  }

  return str;
}

/**
 * @brief Проверяет короткую строку.
 *
 * @param number Числовое значение.
 * @param str Входная строка.
 * @param base Числовое значение.
 * @param upperCase Верхний регистр.
 * @return Функция возвращает указатель на строку.
 */
char *sitos(short int number, char *str, short int base, int upperCase) {
  int isNegative = 0, i = 0;

  if (!number) {
    str[i++] = '0';
    str[i] = '\0';
    return str;
  }

  if (number < 0 && base == 10) {
    isNegative++;
    number = -number;
  }

  while (number > 0) {
    int digit = number % base;
    str[i++] = itoc(digit, (int)base, upperCase);
    number /= base;
  }

  if (isNegative) str[i++] = '-';
  str[i] = '\0';

  int pos = 0;
  i--;

  while (pos < i) {
    int swap = str[pos];
    str[pos] = str[i];
    str[i] = swap;

    pos++;
    i--;
  }

  return str;
}

/**
 * @brief Проверка беззнакового числа.
 *
 * @param number Числовое значение.
 * @param str Входная строка.
 * @param base Система счисления.
 * @param upperCase Верхний регист.
 * @return Функция возвращает указатель на строку.
 */
char *uitos(unsigned number, char *str, unsigned base, int upperCase) {
  int i = 0;

  if (!number) {
    str[i++] = '0';
    str[i] = '\0';
    return str;
  }

  while (number != 0) {
    int digit = base > 0 ? number % base : number % 10;
    str[i++] = uitoc(digit, base, upperCase);
    number /= base;
  }

  str[i] = '\0';

  int pos = 0;
  i--;

  while (pos < i) {
    int swap = str[pos];
    str[pos] = str[i];
    str[i] = swap;

    pos++;
    i--;
  }

  return str;
}

/**
 * @brief Переводит беззнакового числа в целочисленное.
 *
 * @param val Значение.
 * @param base Система счисления.
 * @param upperCase Верхний регистр.
 * @return Целочисленное значение.
 */
int uitoc(unsigned val, unsigned base, int upperCase) {
  const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
  const char DIGITS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  return upperCase ? DIGITS[val % base] : digits[val % base];
}
