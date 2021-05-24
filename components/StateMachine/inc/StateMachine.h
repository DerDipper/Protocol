/**
 * @file StateMachine.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

/* Compiler Includes */
#include <stdint.h>

/* Local Includes */
#include "Buffer.h"

/* Defines */

/* Types */

/**
 * @brief Handle for State Machines
 * 
 */
typedef struct StateMachine_s* StateMachine_Handle;

/**
 * @brief Return Values of StateMachine Module
 * 
 */
typedef enum StateMachine_Ret_e
{
    STATEMACHINE_RET_OK,
    STATEMACHINE_RET_FAIL,
}StateMachine_Ret;

/**
 * @brief Function Ran by a state
 * 
 */
typedef StateMachine_Ret (*pFuncStateMachineExec)(void* pComponent);

/**
 * @brief Entry Function into state
 * 
 */
typedef pFuncStateMachineExec StateMachine_entry;
/**
 * @brief Function executed by state
 * 
 */
typedef pFuncStateMachineExec StateMachine_run;
/**
 * @brief Function ran when exiting state
 * 
 */
typedef pFuncStateMachineExec StateMachine_exit;


/**
 * @brief Transition for state machine
 * 
 */
typedef struct StateMachine_Transition_s
{
    uint32_t sourceState;
    uint32_t destinationState;
    uint32_t event;
}StateMachine_Transition;

/**
 * @brief State for state machine
 * 
 */
typedef struct StateMachine_State_s
{
    uint32_t state;
    StateMachine_entry entry;
    StateMachine_run run;
    StateMachine_exit exit;
}StateMachine_State;

/**
 * @brief Configuration Definition for state machine
 * 
 */
typedef struct StateMachine_Config_s
{
    BUFFER_DEFINE(StateMachine_Transition) transitions;
    BUFFER_DEFINE(StateMachine_State) states;
    uint32_t initialState;
}StateMachine_Config;

/* Interface */

/**
 * @brief Function initializing a state machine from a configuration
 * 
 * @param pConfig pointer to configuration
 * @param pComponent pointer to a component that can be managed by the state machine
 * @return StateMachine_Handle 
 */
extern StateMachine_Handle StateMachine_init(const StateMachine_Config* pConfig, void* pComponent);

/**
 * @brief Let state machine react on event
 * 
 * @param handle Handle to current state machine 
 * @return StateMachine_Ret 
 */
extern StateMachine_Ret StateMachine_react(StateMachine_Handle handle, uint32_t event);

/**
 * @brief Execute current run function
 * 
 * @param handle Handle to current state machine
 * @return StateMachine_Ret 
 */
extern StateMachine_Ret StateMachine_runState(StateMachine_Handle handle);

/**
 * @brief Get the current State
 * 
 * @param handle 
 * @return StateMachine_Ret 
 */
extern uint32_t StateMachine_getState(StateMachine_Handle handle);
