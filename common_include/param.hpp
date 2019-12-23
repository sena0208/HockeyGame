#ifndef __PARAM_H__
#define __PARAM_H__

//TIMER
#define DT           1.0e-1

#define MAXTIME      1000
#define OUTTIME      1.0

#define MAXITER      (int)(MAXTIME / DT)
#define OUTITER      (int)(OUTTIME / DT)

//FIELD
#define FIELD_WIDTH  4.0
#define FIELD_HEIGHT 3.0

#define GOAL_WIDTH   4.0

#define MAX_VEL      10

//MALLET
#define NUM_MALLET   2
#define MALLET_R     0.3

//PUCK
#define PUCK_R       0.2

enum CommandResult
{
  SUCCESS = 0,
  LIMITED = 1,
  FAIL    = 2,
};

#endif //__PARAM_H__
