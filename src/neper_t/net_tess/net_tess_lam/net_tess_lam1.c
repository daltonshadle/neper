/* This file is part of the Neper software package. */
/* Copyright (C) 2003-2020, Romain Quey. */
/* See the COPYING file in the top-level directory. */

#include "net_tess_lam_.h"

int
net_tess_lam (struct IN_T In, int level, char *morpho, struct MTESS *pMTess,
              struct TESS *Tess, int dtess, int dcell, int TessId,
              struct SEEDSET *SSet)
{
  struct TESS *pTess = Tess + TessId;
  struct SEEDSET *pSSet = SSet + TessId;
  struct TESS Dom;

  neut_tess_set_zero (&Dom);

  neut_tess_poly_tess (Tess[dtess], dcell, &Dom);

  ut_print_message (0, 2, "Running tessellation...\n");

  net_tess_lam_seed (In, level, morpho, *pMTess, Tess, dtess, dcell, Dom,
                     SSet, pSSet);

  net_tess3d (Tess[dtess], dcell, *pSSet, "nanoflann", TessId, pMTess, pTess);

  neut_tess_init_seeds_fromcell (pTess);

  ut_print_message (0, 2, "Generating crystal orientations...\n");
  net_ori (In, level, *pMTess, Tess, SSet, dtess, dcell, pSSet, 3);

  neut_tess_free (&Dom);

  return 0;
}
