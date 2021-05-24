/**
 * @file StateMachine.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/* Interface Implemented */
#include "StateMachine.h"

/* Compiler Includes */
#include <stdbool.h>

/* Local Includes */
#include "AllocRedirect.h"

/* Defines */

/* Types */
typedef struct StateMachine_s
{
    const StateMachine_Config* pConfig;
    void* pComponent;
    StateMachine_State* currentState;
}StateMachine;


/* Local Functions */
static StateMachine_State* getState(StateMachine* handle, uint32_t state);

static bool isTransition(StateMachine_Transition* pTransition, uint32_t currentState, uint32_t event);

/* Implementation of Interface */

extern StateMachine_Handle StateMachine_init(const StateMachine_Config* pConfig, void* pComponent)
{
    StateMachine* handle = NULL;

    handle = AllocRedirect(sizeof(StateMachine));
    handle->pConfig = pConfig;
    handle->pComponent = pComponent;

    handle->currentState = getState(handle, pConfig->initialState);

    handle->currentState->entry(pComponent);

    return handle;
}

extern StateMachine_Ret StateMachine_react(StateMachine_Handle handle, uint32_t event)
{
    StateMachine_Ret retVal = STATEMACHINE_RET_FAIL;
    const StateMachine_Transition* pTransition = NULL;

    for(size_t i = 0; i < handle->pConfig->transitions.size; i++)
    {
        if(true == isTransition(&handle->pConfig->transitions.values[i], handle->currentState->state, event))
        {
            pTransition = &handle->pConfig->transitions.values[i];
        }
    }

    retVal = handle->currentState->exit(handle->pComponent);
    if(STATEMACHINE_RET_OK == retVal)
    {
        handle->currentState = getState(handle, pTransition->destinationState);
        retVal = handle->currentState->entry(handle->pComponent);
    }

    return retVal;
}

extern StateMachine_Ret StateMachine_runState(StateMachine_Handle handle)
{
    return handle->currentState->run(handle->pComponent);
}

extern uint32_t StateMachine_getState(StateMachine_Handle handle)
{
    return handle->currentState->state;
}

/* Implementation of Local Functions */
static StateMachine_State* getState(StateMachine* handle, uint32_t state)
{
    StateMachine_State* found = NULL;

    for(size_t i = 0; i < handle->pConfig->states.size; i++)
    {
        if( handle->pConfig->states.values[i].state == state )
        {
            found = &handle->pConfig->states.values[i];
        }
    }

    return found;
}

static bool isTransition(StateMachine_Transition* pTransition, uint32_t currentState, uint32_t event)
{
    bool retVal = false;

    if( pTransition->sourceState == currentState )
    {
        if( pTransition->event == event )
        {
            retVal = true;
        }
    }


    return retVal;
}

