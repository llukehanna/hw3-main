#ifndef GATE_H
#define GATE_H

#include <vector>
#include "event.h"
#include "wire.h"

// Base Gate class
class Gate {
public:
    // Constructor: num_inputs specifies the number of inputs; output is the output wire.
    Gate(int num_inputs, Wire* output);
    virtual ~Gate();
    
    // Pure virtual update: returns a new Event if the gate's output changes.
    virtual Event* update(uint64_t current_time) = 0;
    
    // Sets the input wire at the given index.
    void wireInput(unsigned int id, Wire* in);
    
protected:
    Wire* m_output;
    std::vector<Wire*> m_inputs;
    uint32_t m_delay;        // Propagation delay (default 0)
    char m_current_state;    // Current output state ('X', '0', or '1')
};

// AND gate with 2 inputs
class And2Gate : public Gate {
public:
    And2Gate(Wire* a, Wire* b, Wire* o);
    virtual Event* update(uint64_t current_time);
};

// OR gate with 2 inputs
class Or2Gate : public Gate {
public:
    Or2Gate(Wire* a, Wire* b, Wire* o);
    virtual Event* update(uint64_t current_time);
};

// NOT gate with 1 input
class NotGate : public Gate {
public:
    NotGate(Wire* in, Wire* out);
    virtual Event* update(uint64_t current_time);
};

#endif // GATE_H
