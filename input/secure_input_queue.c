#include "secure_input_queue.h"

static secure_input_event_t queue[SECURE_INPUT_QUEUE_SIZE];

static int head = 0;
static int tail = 0;

void secure_input_queue_init(void)
{
    head = 0;
    tail = 0;
}

bool secure_input_queue_push(
    secure_input_event_t event
)
{
    int next =
        (head + 1) % SECURE_INPUT_QUEUE_SIZE;

    if (next == tail)
    {
        return false;
    }

    queue[head] = event;

    head = next;

    return true;
}

bool secure_input_queue_pop(
    secure_input_event_t *event
)
{
    if (head == tail)
    {
        return false;
    }

    *event = queue[tail];

    tail =
        (tail + 1) % SECURE_INPUT_QUEUE_SIZE;

    return true;
}
