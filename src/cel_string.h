/**
 * cel string module interface header file.
 *     @package src/cel_string.h. <br />
 *
 * @author adan-shaw <adan_shaw@qq.com>
 */
#ifndef cel_string_h
#define cel_string_h

#include "cel_api.h"
#include <string.h>

CEL_API void cel_left_trim (char *);
CEL_API void cel_right_trim (char *);

//cel string block.
typedef struct
{
	cstring str;
	uint_t len;
} cel_string_t;

//function to create a new cel string.
CEL_API cel_string_t *new_cel_string (cstring);

//function to free the specified cel string.
CEL_API void free_cel_string (cel_string_t **);

CEL_API cel_string_t *cel_string_long (long);

CEL_API cel_string_t *cel_string_double (double);

/* {{{ string buffer.
 * */
typedef struct
{
	cstring buffer;
	uint_t opacity;								/*opacity of the buffer in bytes */
	uint_t size;									/*length of the string in bytes. */
} cel_strbuff_t;

//default string buffer length.
#define _CEL_DEFAULT_STRBUFF_OPACITY_ 8

#define cel_strbuff_opacity(sb)    sb->opacity
#define cel_strbuff_size(sb)    sb->size
#define cel_strbuff_empty(sb)    (sb->size==0)

/* interface to create new cel_strbuff_entry
 * */
//CEL_API cel_strbuff_t *new_cel_strbuff();
#define new_cel_strbuff() \
    new_cel_strbuff_opacity(_CEL_DEFAULT_STRBUFF_OPACITY_)

CEL_API cel_strbuff_t *new_cel_strbuff_opacity (int);
CEL_API cel_strbuff_t *new_cel_strbuff_string (cstring);

//free the specified string buffer.
CEL_API void free_cel_strbuff (cel_strbuff_t **);

/*
 * create the specified string buffer
 *
 * @param   cel_strbuff_t
 * @param   uint_t default opacity
 * @param   cstring default string -  could be NULL
 * @return  int 1 for success and 0 for failed
 */
CEL_API int cel_strbuff_init (cel_strbuff_t *, int, cstring);

/*
 * destroy the specified cel_strbuff_t
 *
 * @param   cel_strbuff_t
 * @return  int 1 for success and 0 for failed
 */
CEL_API int cel_strbuff_destroy (cel_strbuff_t *);

/*
 * append a new string to the buffer.
 *
 * @param cstring - the string to append to.
 * */
//CEL_API void cel_strbuff_append( cel_strbuff_t, cstring );
#define cel_strbuff_append(sb, str, count) \
    cel_strbuff_append_from( sb, str, strlen(str), count )

/* append some bytes from a specified buffer
 *
 * @param   cstring - the buffer to copy byte from.
 * @param   len - the number of bytes to copy.
 * @param   count - repeat times.
 * @return  int 1 for success and 0 for failed
 * */
CEL_API int cel_strbuff_append_from (cel_strbuff_t *, cstring, uint_t, int);

/* append a char to the buffer.
 *
 * @param   char
 * @param   count - repeat times.
 * @return  1 for success and 0 for failed
 * */
CEL_API int cel_strbuff_append_char (cel_strbuff_t *, char, int);

/* insert a new string to the buffer from the specified position.
 *
 * @param   uint_t - the start position.
 * @param   cstring - the string to insert in
 * @return  1 for success and 0 for failed
 * */
//CEL_API void cel_strbuff_insert( cel_strbuff_t *, uint_t, cstring );
#define cel_strbuff_insert(sb, idx, str, count)\
    cel_strbuff_insert_from( sb, idx, str, strlen(str), count )

/* insert part of buffer to the buffer.
 *
 * @param   uint_t - start position
 * @param   cstring - source buffer
 * @param   uint_t - number of bytes to copy
 * @param   count - repeat times
 * @return  1 for success and 0 for failed
 * */
CEL_API int cel_strbuff_insert_from (cel_strbuff_t *, uint_t, cstring, uint_t, int);

/* insert a char to the buffer from a specified index position.
 *
 * @param   char
 * @return  1 for success and 0 for failed
 * */
CEL_API int cel_strbuff_insert_char (cel_strbuff_t *, uint_t, char, int);

//get the char at a specified position.
#define cel_strbuff_get( strbuff, idx ) strbuff->buffer[(idx)]

/* remove  specified char from a specified position from the buffer
 *
 * @param   uint_t - the start index
 * @param   uint_t - number of chars to remove
 * @return  1 for success and 0 for failed
 * */
CEL_API int cel_strbuff_remove (cel_strbuff_t *, uint_t, uint_t);

/*
 * clear the specified string buffer
 *
 * @return  1 for success and 0 for failed
 */
CEL_API int cel_strbuff_clear (cel_strbuff_t *);
/* end of string buffer.
 * }}} */

/* {{{ utf-8 unicode convert.
 * */
CEL_API uint_t cel_utf8_charbytes (char);

CEL_API uint_t cel_utf8_to_ucode (cstring);

CEL_API int cel_ucode_to_utf8 (uint_t, cstring);
/* end of utf-8 unicode conver.
 * }}} */
#endif /*end ifndef */
