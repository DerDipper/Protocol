#include <assert.h>
#include <stdio.h>

#include "StateMachine.h"

typedef enum OneWireProtocolState_e
{
    ONEWIREPROTOCOLSTATE_INIT,
    ONEWIREPROTOCOLSTATE_IDLE,
    ONEWIREPROTOCOLSTATE_TRANSMITTING,
    ONEWIREPROTOCOLSTATE_RECEIVING,
    ONEWIREPROTOCOLSTATE_ERROR,
}OneWireProtocolState;

typedef enum OneWireProtocolEvents_e
{
    ONEWIREPROTOCOLEVENT_INIT_FINISHED,
    ONEWIREPROTOCOLEVENT_TRANSMIT,
    ONEWIREPROTOCOLEVENT_LISTEN_REQUEST,
    ONEWIREPROTOCOLEVENT_PAKET_FINISHED,
    ONEWIREPROTOCOLEVENT_ERROR,
}OneWireProtocolEvents;

StateMachine_Transition transitions[] = {
    {ONEWIREPROTOCOLSTATE_INIT, ONEWIREPROTOCOLSTATE_IDLE, ONEWIREPROTOCOLEVENT_INIT_FINISHED},
    {ONEWIREPROTOCOLSTATE_IDLE, ONEWIREPROTOCOLSTATE_TRANSMITTING, ONEWIREPROTOCOLEVENT_TRANSMIT},
    {ONEWIREPROTOCOLSTATE_IDLE, ONEWIREPROTOCOLSTATE_RECEIVING, ONEWIREPROTOCOLEVENT_LISTEN_REQUEST},
    {ONEWIREPROTOCOLSTATE_RECEIVING, ONEWIREPROTOCOLSTATE_IDLE, ONEWIREPROTOCOLEVENT_PAKET_FINISHED},
    {ONEWIREPROTOCOLSTATE_TRANSMITTING, ONEWIREPROTOCOLSTATE_IDLE, ONEWIREPROTOCOLEVENT_PAKET_FINISHED},
    {ONEWIREPROTOCOLSTATE_INIT, ONEWIREPROTOCOLSTATE_IDLE, ONEWIREPROTOCOLEVENT_ERROR},
    {ONEWIREPROTOCOLSTATE_IDLE, ONEWIREPROTOCOLSTATE_IDLE, ONEWIREPROTOCOLEVENT_ERROR},
    {ONEWIREPROTOCOLSTATE_RECEIVING, ONEWIREPROTOCOLSTATE_IDLE, ONEWIREPROTOCOLEVENT_ERROR},
    {ONEWIREPROTOCOLSTATE_TRANSMITTING, ONEWIREPROTOCOLSTATE_IDLE, ONEWIREPROTOCOLEVENT_ERROR},
};

StateMachine_Ret OneWireProtocolEvent_init_entry(void* pComponent);
StateMachine_Ret OneWireProtocolEvent_init_run(void* pComponent);
StateMachine_Ret OneWireProtocolEvent_init_exit(void* pComponent);

StateMachine_Ret OneWireProtocolEvent_idle_entry(void* pComponent);
StateMachine_Ret OneWireProtocolEvent_idle_run(void* pComponent);
StateMachine_Ret OneWireProtocolEvent_idle_exit(void* pComponent);

StateMachine_Ret OneWireProtocolEvent_transmitting_entry(void* pComponent);
StateMachine_Ret OneWireProtocolEvent_transmitting_run(void* pComponent);
StateMachine_Ret OneWireProtocolEvent_transmitting_exit(void* pComponent);

StateMachine_Ret OneWireProtocolEvent_receiving_entry(void* pComponent);
StateMachine_Ret OneWireProtocolEvent_receiving_run(void* pComponent);
StateMachine_Ret OneWireProtocolEvent_receiving_exit(void* pComponent);

StateMachine_Ret OneWireProtocolEvent_error_entry(void* pComponent);
StateMachine_Ret OneWireProtocolEvent_error_run(void* pComponent);
StateMachine_Ret OneWireProtocolEvent_error_exit(void* pComponent);

StateMachine_State states[] = {
    {ONEWIREPROTOCOLSTATE_INIT,OneWireProtocolEvent_init_entry, OneWireProtocolEvent_init_run, OneWireProtocolEvent_init_exit},
    {ONEWIREPROTOCOLSTATE_IDLE,OneWireProtocolEvent_idle_entry, OneWireProtocolEvent_idle_run, OneWireProtocolEvent_idle_exit},
    {ONEWIREPROTOCOLSTATE_TRANSMITTING,OneWireProtocolEvent_transmitting_entry, OneWireProtocolEvent_transmitting_run, OneWireProtocolEvent_transmitting_exit},
    {ONEWIREPROTOCOLSTATE_RECEIVING,OneWireProtocolEvent_receiving_entry, OneWireProtocolEvent_receiving_run, OneWireProtocolEvent_receiving_exit},
    {ONEWIREPROTOCOLSTATE_ERROR,OneWireProtocolEvent_error_entry, OneWireProtocolEvent_error_run, OneWireProtocolEvent_error_exit},
};


StateMachine_Config config = {BUFFER_INITIALIZE(transitions), BUFFER_INITIALIZE(states), ONEWIREPROTOCOLSTATE_INIT};

int main(void)
{
    StateMachine_Handle handle = StateMachine_init(&config, NULL);

    StateMachine_runState(handle);
    printf("%d\n", StateMachine_getState(handle));
    StateMachine_react(handle, ONEWIREPROTOCOLEVENT_INIT_FINISHED);
    printf("%d\n", StateMachine_getState(handle));
    StateMachine_runState(handle);
    StateMachine_runState(handle);
    StateMachine_runState(handle);
    StateMachine_react(handle, ONEWIREPROTOCOLEVENT_LISTEN_REQUEST);
    printf("%d\n", StateMachine_getState(handle));
}

StateMachine_Ret OneWireProtocolEvent_init_entry(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_init_run(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_init_exit(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_idle_entry(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_idle_run(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_idle_exit(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_transmitting_entry(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_transmitting_run(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_transmitting_exit(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_receiving_entry(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_receiving_run(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_receiving_exit(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_error_entry(void* pComponent)
{
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_error_run(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}

StateMachine_Ret OneWireProtocolEvent_error_exit(void* pComponent)
{
    printf(__func__);
    printf("\n");
    return STATEMACHINE_RET_OK;
}
