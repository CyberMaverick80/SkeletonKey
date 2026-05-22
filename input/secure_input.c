#include "secure_input.h"

#include "secure_input_queue.h"
#include "secure_input_events.h"

void secure_input_init(void)
{
    secure_input_queue_init();
}

void secure_input_process(void)
{
    secure_input_event_t event;

    while (
        secure_input_queue_pop(&event)
    )
    {
        secure_input_process_event(event);
    }
}
