/*
 *
 * PROJECT	:	GateOfIshtar
 ***************************************************************************
 * !File			: Config.c
 *
 *
 *
 * !Author          : ahejazi					!Date: Feb 25, 2018

 * !Coding Language : C
 *
 * All rights reserved
 ****************************************************************************/
/*****************************************************************************/
/* EVOLUTIONS (automatic update under PVCS)                                  */
/*****************************************************************************/
/* $Log: $*/
/*****************************************************************************/

/*****************************************************************************/
/* INCLUDE FILES                                                             */
/*****************************************************************************/
#include "Config.h"
/*********************** Definition of common types **************************/

/****************** Sources to be used within the module *********************/

/***************** Headers implemented within the module *********************/

/*****************************************************************************/
/* CONSTANTS, MACROS                                                         */
/*****************************************************************************/

const champion_cfg champion_config[NB_CHAMPION_TYPES] =
{
    {
        Wizard, /* type */
        1, /* isMagic */
        (char) 100 /* maxHealth */
    },
    {
        Spirit, /* type */
        1, /* isMagic */
        (char) 100 /* maxHealth */
    },
    {
        Human, /* type */
        0, /* isMagic */
        (char) 100 /* maxHealth */
    },
    {
        Giant, /* type */
        0, /* isMagic */
        (char) 150 /* maxHealth */
    },
    {
        Vampire, /* type */
        0, /* isMagic */
        (char) 110 /* maxHealth */
    }
};

const guard_cfg guard_config[NB_GUARDS] =
{
    {
        Janna, /* name */
        (int) 7, /* damage */
        {0,0,6,0,0,0,0,0,0}, /* timeWindowStart */
        {0,29,6,0,0,0,0,0,0}, /* timeWindowEnd */
    },
    {
        Tiamat, /* name */
        (int) 18, /* damage */
        {0,30,6,0,0,0,0,0,0}, /* timeWindowStart */
        {0,59,6,0,0,0,0,0,0}, /* timeWindowEnd */
    },
    {
        Mithra, /* name */
        (int) 25, /* damage */
        {0,0,7,0,0,0,0,0,0}, /* timeWindowStart */
        {0,59,7,0,0,0,0,0,0} /* timeWindowEnd */
    },
    {
        Warwick, /* name */
        (int) 18, /* damage */
        {0,0,8,0,0,0,0,0,0}, /* timeWindowStart */
        {0,29,8,0,0,0,0,0,0} /* timeWindowEnd */
    },
    {
        Kalista, /* name */
        (int) 7, /* damage */
        {0,30,8,0,0,0,0,0,0}, /* timeWindowStart */
        {0,59,14,0,0,0,0,0,0} /* timeWindowEnd */
    },
    {
        Ahri, /* name */
        (int) 13, /* damage */
        {0,0,15,0,0,0,0,0,0}, /* timeWindowStart */
        {0,29,15,0,0,0,0,0,0} /* timeWindowEnd */
    },
    {
        Brand, /* name */
        (int) 25, /* damage */
        {0,0,15,0,0,0,0,0,0}, /* timeWindowStart */
        {0,59,16,0,0,0,0,0,0} /* timeWindowEnd */
    },
    {
        Rumble, /* name */
        (int) 18, /* damage */
        {0,0,17,0,0,0,0,0,0}, /* timeWindowStart */
        {0,59,17,0,0,0,0,0,0} /* timeWindowEnd */
    },
    {
        Skarner, /* name */
        (int) 7, /* damage */
        {0,0,18,0,0,0,0,0,0}, /* timeWindowStart */
        {0,59,19,0,0,0,0,0,0} /* timeWindowEnd */
    },
    {
        Luna, /* name */
        (int) 13, /* damage */
        {0,0,20,0,0,0,0,0,0}, /* timeWindowStart */
        {0,59,20,0,0,0,0,0,0} /* timeWindowEnd */
    }
};


/*****************************************************************************/
/* TYPES                                                                     */
/*****************************************************************************/


/*****************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES                                              */
/*****************************************************************************/


/*****************************************************************************/
/* PRIVATE VARIABLES                                                         */
/*****************************************************************************/


/*****************************************************************************/
/* PUBLIC FUNCTIONS                                                          */
/*****************************************************************************/


/*****************************************************************************/
/* PRIVATE FUNCTIONS                                                         */
/*****************************************************************************/
