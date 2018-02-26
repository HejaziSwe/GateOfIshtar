/*
 *
 * PROJECT	:	GateOfIshtar
 ***************************************************************************
 * !File			: Gate.c
 *
 *
 *
 * !Author          : ahejazi					!Date: Feb 24, 2018

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
#include "Gate.h"
#include "Guard.h"
#include "Champion.h"
/*********************** Definition of common types **************************/

/****************** Sources to be used within the module *********************/

/***************** Headers implemented within the module *********************/

/*****************************************************************************/
/*  ANTS, MACROS                                                         */
/*****************************************************************************/


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

void GATE_cross(champion *champ)
{
  int damage;

  if(NULL != champ)
  {
    damage = GUARD_getCurrentDamagePower();

    CHAMPION_loseHealth(champ, damage);

    if( champ->health > 0)
    {
      /* the champion made it through the gate */

      /* update gate crossing time stamp */
      localtime(&(champ->lastCrossTimeStamp));

      /*




       code for meeting the council of wise




       */
    }
    else
    {
      /* champion is dead :( */
    }

  }
}

/*****************************************************************************/
/* PRIVATE FUNCTIONS                                                         */
/*****************************************************************************/
