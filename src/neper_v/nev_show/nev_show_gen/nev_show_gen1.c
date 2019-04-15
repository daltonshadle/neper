/* This file is part of the Neper software package. */
/* Copyright (C) 2003-2019, Romain Quey. */
/* See the COPYING file in the top-level directory. */

#include"nev_show_gen_.h"

void
nev_show_csys (char **argv, int *pi, struct PRINT *pPrint)
{
  (*pi)++;
  ut_string_int (argv[(*pi)], &((*pPrint).showcsys));

  return;
}

void
nev_show_shadow (char **argv, int *pi, struct PRINT *pPrint)
{
  (*pi)++;
  ut_string_int (argv[(*pi)], &((*pPrint).showshadow));

  return;
}
