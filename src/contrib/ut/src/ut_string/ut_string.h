/* Copyright (C) 2003-2019, Romain Quey */
/* see the COPYING file in the top-level directory.*/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef UT_STRING_H
#define UT_STRING_H

/// \file ut_string.h
/// \brief String-related functions
/// \author Romain Quey
/// \bug No known bugs
/// \todo ut_string_find needed?
/// \todo remove ut_string_fnr?
/// \todo rename ut_string_body into ut_string_rmext[ension]?
/// \todo rename ut_string_addextension into ut_string_addext[ension]?

/// \brief Replace a character in a \c char*
/// \param string: character string
/// \param char1: character 1, to be replaced
/// \param char2: character 2, replacing
/// \return 1 if something replaced, 0 on failure
extern int ut_string_fnr (char *string, char char1, char char2);

/// \brief Replace a character string by another in a \c char*
/// \param string: character string
/// \param substring1: string to be replaced
/// \param substring2: replacing string
/// \param number: number of repetitions
/// \return 1 if something replaced, 0 on failure
extern int ut_string_fnrs (char *string, const char* substring1, const char* substring2, int number);

/// \brief Concatenate 2 strings
/// \param string1: string 1
/// \param string2: string 2
/// \return string composed of string1 then string2
extern char* ut_string_paste (char *string1, char *string2);

/// \brief Concatenate several strings
/// \param strings: array of strings
/// \param size: size of \c strings
/// \return concatenations of all strings
extern char* ut_string_array_paste (char **strings, int size);

/// \brief Remove extension from a string
/// \param string: input string
/// \param sep: separator (usually ".")
/// \param *pbody: string without extension
extern void ut_string_body (char *string, char *sep, char **pbody);

/// \brief Add extension to a string
/// \param string: string
/// \param ext: extension
/// \return string with extension
extern char* ut_string_addextension (const char* string, const char *ext, ...);

/// \brief Test if a string is made of digits
/// \param string: string
/// \return 1 on success and 0 on failure
extern int ut_string_isdigits (char *string);

/// \brief Test if a string is a number
/// \param string: string
/// \return 1 on success and 0 on failure
extern int ut_string_isnumber (char *s);

/// \brief Test if a string is a file name
/// \param string: string
/// \return 1 on success and 0 on failure
/// \note To be a file name, the string has to start by 'file(', 'msfile' or '@'
extern int ut_string_isfilename (char* string);

/// \brief Convert a string into \c double
/// \param string: string
/// \param *pres: result
/// \return 1 on success and 0 on failure
/// \note \c string can be a mathematical expression, in which case it is evaluated
extern void ut_string_real (char* string, double* pres);

/// \brief Convert a string into an \c int
/// \param string: string
/// \param *pres: result
/// \return 1 on success and 0 on failure
/// \note \c string can be a mathematical expression, in which case it is evaluated
extern void ut_string_int (char* string, int* pres);

/// \brief Copy a string into another string a string into an \c int
/// \param string1: input string
/// \param *pstring2: output string (does not need to be preallocated)
extern void ut_string_string (const char* string1, char** pstring2);

/// \brief Get the format of a string
/// \param string: string
/// \param format: format (needs to be preallocated)
/// \note \c format can be \c %s, \c %*.*d or \c %*.*f
extern int ut_string_format (const char *string, char *format);

/// \brief Test the format of a string
/// \param string: string
/// \param format: format (needs to be preallocated)
/// \return 1 if format matches and 0 otherwise
/// \note \c format can be \c %s, \c %*.*d or \c %*.*f
extern int ut_string_format_test (char *string, char *format);

/// \brief Convert a string into a function
/// \param string: string
/// \param *pfct: name of the function
/// \param *vars: variables
/// \param *vals: values
/// \param *psize: number of variables/values
/// \note A typical example is \c "myfct(foo=10,bar=2)".  A variable may not be provided (in which case it is \c NULL).
extern void ut_string_function (char *string, char** pfct,
                             char ***vars, char ***vals, int *psize);

/// \brief Convert a string into a function, keep arguments as strings
/// \param string: string
/// \param *pfct: name of the function
/// \param *pargs: arguments
/// \param *psize: number of arguments
/// \see ut_string_function
extern void ut_string_function_expr (char *string, char** pfct,
                                     char ***pargs, int *psize);

// completion -----------------------------------------------------------------
/// \brief Apply completion to a string
/// \param string1: input string
/// \param array: array of reference strings
/// \param size: number of strings
/// \param *pstring2: output string
/// \return 0 on success, 1 if multiple matches and -1 on failure
/// \note \c array is indexed 1
/// \todo index \c array from 0
extern int ut_string_completion (char *string1, char **array, int size, char **pstring2);

// only used internally
/// @cond INTERNAL
extern int ut_string_thischarqty (char *, char);
extern int ut_string_thischarpos (char *, char, int);
extern int ut_string_nbwords (char*);
extern int ut_string_substrings (char *string, char ***psubstrings, int *psubstringqty);
extern int ut_string_section_level (char *string, int *plevel);
extern int ut_string_untilchar (char *string, char c, int *ppos, char *res);
extern int ut_string_untilstring (const char *string, const char* s, int *ppos, char *res);
/// @endcond

#endif /* UT_STRING_H */

#ifdef __cplusplus
}
#endif
