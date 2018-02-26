/*
 *
 * PROJECT	:	GateOfIshtar
 ***************************************************************************
 * !File			: Guard.c
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
#include "Guard.h"
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

typedef enum
{
  Mon = (char) 0,
  Tue,
  Wed,
  Thu,
  Fri,
  Sat,
  Sun
} weekDay;
/*****************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES                                              */
/*****************************************************************************/

weekDay getCurrentWeekDay(void);
char isGuardActive(guard_cfg guard);

/*****************************************************************************/
/* PRIVATE VARIABLES                                                         */
/*****************************************************************************/


/*****************************************************************************/
/* PUBLIC FUNCTIONS                                                          */
/*****************************************************************************/

int GUARD_getCurrentDamagePower()
{
  int index;
  guard_cfg guard;
  weekDay day = getCurrentWeekDay();
  char damage = 0;

  if((Tue == day) || (Thu == day))
  {
    /* Tuesdays and Thursdays are holly days in ancient babylon, so no guards
     * roam around the Gate, and no damage is inflicted on crossers */
    damage = 0;
  }
  else
  {
    /* check which guards are currently on the gate, accumulate their damage */

    for(index = 0; index < NB_GUARDS; index ++)
    {
      guard = guard_config[index];

      if( 1 == isGuardActive(guard) )
      {
        /* This guard is currently on duty at the gate, accumulate damage */
        damage += (int) guard.damage;
      }
      else
      {
        /* Keep looping */
      }
    }
  }

  return damage;
}

/*****************************************************************************/
/* PRIVATE FUNCTIONS                                                         */
/*****************************************************************************/

weekDay getCurrentWeekDay(void)
{
  struct tm *currentTimeDesc;

  /* get current time details */
  currentTimeDesc = localtime(NULL);
  return (weekDay) currentTimeDesc->tm_wday;
}

char isGuardActive(guard_cfg guard)
{
  time_t currentTime, startTime, endTime;
  struct tm *currentTimeDesc;

  /* get current time details */
  currentTimeDesc = localtime(&currentTime);

  /* we are only interested in hour and minute, the rest we will put = 0 */
  currentTimeDesc->tm_sec = 0;
  currentTimeDesc->tm_mday = 0;
  currentTimeDesc->tm_mon = 0;
  currentTimeDesc->tm_year = 0;
  currentTimeDesc->tm_wday = 0;
  currentTimeDesc->tm_yday = 0;
  currentTimeDesc->tm_isdst = 0;

  currentTime = mktime(currentTimeDesc);

  /* prepare values of time window */
  startTime = mktime(&guard.timeWindowStart);
  endTime = mktime(&guard.timeWindowEnd);

  /* check if current time fals within guard time window */
  if( (currentTime >= startTime) & (currentTime <= endTime) )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

