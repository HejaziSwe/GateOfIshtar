/*
 *
 * PROJECT	:	GateOfIshtar
 ***************************************************************************
 * !File			: Champion.c
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
#include "Champion.h"
#include "Config.h"
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

double getTimeSince(time_t lastCrossTimeStamp);
void doDamage(champion *champ, int damage);
char getMaxHelath(championType champType);

/*****************************************************************************/
/* PRIVATE VARIABLES                                                         */
/*****************************************************************************/


/*****************************************************************************/
/* PUBLIC FUNCTIONS                                                          */
/*****************************************************************************/

void CHAMPION_init(champion *champ, championType champType)
{
  int index;
  champion_cfg champ_config;

  if(NULL != champ)
  {
    for(index = 0; index < NB_CHAMPION_TYPES; index++)
    {
      champ_config = champion_config[index];

      if(champ_config.type == champType)
      {
        champ -> type = champ_config.type;
        champ -> health = champ_config.maxHealth;
        champ -> isMagic = champ_config.isMagic;

        break;
      }
      else
      {
        /* keep looping */
      }
    }
  }
}

void CHAMPION_loseHealth(champion *champ, int damage)
{
  char max_helath;

  if( NULL != champ )
  {
    if( 1 == champ->isMagic)
    {
      /* Champ is magical, immune to damage, do nothing */
    }
    else  if( damage > 0 )
    {
      /* inflicted damage = 0 , do nothing */
    }
    else
    {
      /*  Check if champion has been damaged before */
      max_helath = getMaxHelath(champ->type);

      if(champ->health < max_helath)
      {
        /* champ health has been damaged before, check last damage time */
        if( ((double) 3600) < getTimeSince(champ->lastCrossTimeStamp) )
        {
          /* champ health has been damaged less than an hour ago, do nothing */
        }
        else
        {
          /* an hour or more passed since last health damage */
          doDamage(champ, damage);
        }
      }
      else
      {
        /* this is the first time champ health will be damaged*/
        doDamage(champ, damage);
      }
    }
  }
}

/*****************************************************************************/
/* PRIVATE FUNCTIONS                                                         */
/*****************************************************************************/

double getTimeSince(time_t lastCrossTimeStamp)
{
  time_t currentTime;

  localtime(&currentTime);

  return difftime(currentTime, lastCrossTimeStamp);
}

void doDamage(champion *champ, int damage)
{
  char champ_damage;

  /* damage value should be between 7 and 25 */
  if(damage > (int) MAX_CHAMP_DAMAGE)
  {
    champ_damage = (char) MAX_CHAMP_DAMAGE;
  }
  else if(damage < (int) MIN_CHAMP_DAMAGE)
  {
    champ_damage = (char) MIN_CHAMP_DAMAGE;
  }
  else
  {
    champ_damage = (char) damage;
  }

  /* Update HP*/
  if(champ->health > champ_damage)
  {
    /* reduce HP */
    champ->health -= champ_damage;
  }
  else
  {
    /* damage was greater than or equal to remaining HP.  Champ is dead :( */
    champ->health = 0;
  }
}

char getMaxHelath(championType champType)
{
  int index;
  champion_cfg champCfg;

  for(index = 0; index < NB_CHAMPION_TYPES; index ++)
  {
    champCfg = champion_config[index];

    if( champType == champCfg.type )
    {
      return champCfg.maxHealth;
    }
    else
    {
      /* Keep looping */
    }
  }

  return 0;
}
