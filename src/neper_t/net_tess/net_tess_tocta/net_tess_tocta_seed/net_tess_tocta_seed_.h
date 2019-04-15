/* This file is part of the Neper software package. */
/* Copyright (C) 2003-2019, Romain Quey. */
/* See the COPYING file in the top-level directory. */

#include<stdio.h>
#include<stdlib.h>
#include<gsl/gsl_rng.h>

#include"structIn_t.h"
#include"ut.h"
#include"orilib.h"
#include"neut_t.h"
#include"net_ori/net_ori.h"

#include"net_tess_tocta_seed.h"
#include"net_tess/net_tess_opt/net_tess_opt_init/net_tess_opt_init_sset/net_tess_opt_init_sset_pre/net_tess_opt_init_sset_pre.h"

extern int net_tess_tocta_seed_readargs (char *morpho, int *pn);

extern int net_tess_tocta_seed_set (struct IN_T In, int level, struct MTESS MTess, struct TESS *Tess, int dtess, int dcell, struct TESS Dom, int n, struct SEEDSET *SSet, struct SEEDSET *pSSet);

extern int net_tess_tocta_seed_set_finalize (struct SEEDSET *pSSet);
