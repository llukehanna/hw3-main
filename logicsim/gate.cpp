#include "gate.h"
#include "wire.h"

//------------------- Gate Base Class -------------------------

Gate::Gate(int num_inputs, Wire* output)
    : m_output(output), m_inputs(num_inputs), m_delay(0), m_current_state('X')
{
}

Gate::~Gate() {
}

void Gate::wireInput(unsigned int id, Wire* in) {
    if (id < m_inputs.size()) {
        m_inputs[id] = in;
    }
}

//------------------- And2Gate ---------------------------

And2Gate::And2Gate(Wire* a, Wire* b, Wire* o)
    : Gate(2, o)
{
    wireInput(0, a);
    wireInput(1, b);
}

Event* And2Gate::update(uint64_t current_time) {
    char state = '1';
    Event* e = nullptr;
    for (auto w : m_inputs) {
        char in = w->getState();
        if (in == '0') {
            state = '0';
            break;
        } else if (in == 'X') {
            state = 'X';
        }
    }
    if (state != m_current_state) {
        m_current_state = state;
        uint64_t next = current_time + m_delay;
        e = new Event{ next, m_output, state };
    }
    return e;
}

//------------------- Or2Gate ----------------------------

Or2Gate::Or2Gate(Wire* a, Wire* b, Wire* o)
    : Gate(2, o)
{
    wireInput(0, a);
    wireInput(1, b);
}

Event* Or2Gate::update(uint64_t current_time) {
    char state = '0';
    Event* e = nullptr;
    for (auto w : m_inputs) {
        char in = w->getState();
        if (in == '1') {
            state = '1';
            break;
        } else if (in == 'X') {
            state = 'X';
        }
    }
    if (state != m_current_state) {
        m_current_state = state;
        uint64_t next = current_time + m_delay;
        e = new Event{ next, m_output, state };
    }
    return e;
}

//------------------- NotGate ----------------------------

NotGate::NotGate(Wire* in, Wire* out)
    : Gate(1, out)
{
    wireInput(0, in);
}

Event* NotGate::update(uint64_t current_time) {
    char in_state = m_inputs[0]->getState();
    char new_state;
    if (in_state == 'X')
        new_state = 'X';
    else if (in_state == '0')
        new_state = '1';
    else if (in_state == '1')
        new_state = '0';
    else
        new_state = 'X';  // fallback
    
    if (new_state != m_current_state) {
        m_current_state = new_state;
        uint64_t next = current_time + m_delay;
        return new Event{ next, m_output, new_state };
    }
    return nullptr;
}
