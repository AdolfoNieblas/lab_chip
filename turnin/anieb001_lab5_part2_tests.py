            #1
tests = [ {'description': 'PINA: 0x00, => PORTC: 7, state: SM_INIT',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #INIT
    'expected': [('PORTC',0x07)],
    },#2
    {'description': 'PINA: 0x01 => PORTC: 8, state: SM_INC',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #INCREMENT
    'expected': [('PORTC',0x08)],
    },#3
    {'description': 'PINA: 0x01 => PORTC: 8, state: SM_INC',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #INCREMENT
    'expected': [('PORTC',0x08)],
    },#4
    {'description': 'PINA: 0x00 => PORTC: 8, state: SM_INIT',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #INIT
    'expected': [('PORTC',0x08)],
    },#5
    {'description': 'PINA: 0x02 => PORTC: 7, state: SM_DEC',
    'steps': [{'inputs': [('PINA', 0x02)], 'iterations': 1}], #DECREMENT
    'expected': [('PORTC',0x07)],
    },#6
    {'description': 'count up to 9, PINA: 0x02 => PORTC: 9, state: SM_INIT',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #INIT
    #'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #INCREMENT
    #'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #INIT
    #'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #INCREMENT
    #'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #INIT
    'expected': [('PORTC',0x07)],
    },#7
    {'description': 'count at 9, PINA: 0x02->0x03 => PORTC: 0, state: SM_RESET',
    'steps': [{'inputs': [('PINA', 0x02),('PINA', 0x03)], 'iterations': 2}], #DEC->RESET
    'expected': [('PORTC',0x00)], #resets on trans.
    },#8
    {'description': 'count at 0, PINA: 0x02 => PORTC: 0, state: SM_RESET',
    'steps': [{'inputs': [('PINA', 0x02)], 'iterations': 1}], #RESET
    'expected': [('PORTC',0x00)],
    },#9
    {'description': 'count up to 2 down to 1, PINA: 0x01 => PORTC: 1, state: SM_DEC',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 5}], #INIT
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #INCREMENT
    #'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #INIT
    #'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #INCREMENT
    #'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #INIT
    #'steps': [{'inputs': [('PINA', 0x02)], 'iterations': 1}], #DECREMENT
    'expected': [('PORTC',0x01)],
    },#10
    {'description': 'count at 1, PINA: 0x01->0x03 => PORTC: 0, state: SM_RESET',
    'steps': [{'inputs': [('PINA', 0x01),('PINA', 0x03)], 'iterations': 1}], #RESET
    'expected': [('PORTC',0x00)],
    },
    ]

# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
watch = ['state']

