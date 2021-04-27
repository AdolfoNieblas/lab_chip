tests = [ 
      #1
    {'description': 'PINA: 0x00, => PORTB: 0, state: SM_INIT',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #INIT
    'expected': [('PORTB',0x00)],
    },#2
    {'description': 'PINA: 0x01 => PORTB: 0x09, state: SM_Trail:',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #Trail
    'expected': [('PORTB',0x09)],
    },#3
    {'description': 'PINA: 0x00 => PORTB: 0x12, state: SM_Trail',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #Trail
    'expected': [('PORTB',0x12)],
    },#4
    {'description': 'PINA: 0x00 => PORTB: 0x24, state: SM_Trail',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #Trail
    'expected': [('PORTB',0x24)],
    },#5
    {'description': 'PINA: 0x01 => PORTB: 0x2A, state: SM_Alternate',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #Alternate
    'expected': [('PORTB',0x2A)],
    },#6
    {'description': 'PINA: 0x00 => PORTB: 0x15, state: SM_Alternate',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #Alternate
    'expected': [('PORTB',0x15)],
    },#7
    {'description': 'PINA: 0x00 => PORTB: 0x2A, state: SM_Alternate',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #Alternate
    'expected': [('PORTB',0x2A)],
    },#8
    {'description': 'PINA: 0x01 => PORTB: 0x21, state: SM_OutToFill',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #OutToFill
    'expected': [('PORTB',0x21)],
    },#9
    {'description': 'PINA: 0x00 => PORTB: 0x33, state: SM_OutToFill',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #OutToFill
    'expected': [('PORTB',0x33)],
    },#10
    {'description': 'PINA: 0x00 => PORTB: 0x3F, state: SM_OutToFill',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #OutToFill
    'expected': [('PORTB',0x3F)],
    },#11
    {'description': 'PINA: 0x00 => PORTB: 0x1E, state: SM_OutToFill',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #OutToFill
    'expected': [('PORTB',0x1E)],
    },#12
    {'description': 'PINA: 0x00 => PORTB: 0x0C, state: SM_OutToFill',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #OutToFill
    'expected': [('PORTB',0x0C)],
    },#13
    {'description': 'PINA: 0x00 => PORTB: 0x00, state: SM_OutToFill',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #OutToFill
    'expected': [('PORTB',0x00)],
    },#15
    {'description': 'PINA: 0x00 => PORTB: 0x21, state: SM_OutToFill',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #OutToFill
    'expected': [('PORTB',0x21)],
    },#16
    {'description': 'PINA: 0x01 => PORTB: 0x00, state: SM_INIT',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #INIT
    'expected': [('PORTB',0x00)],
    },#17
    {'description': 'PINA: 0x01 => PORTB: 0x09, state: SM_Trail',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #Trail
    'expected': [('PORTB',0x09)],
    },#18
    {'description': 'PINA: 0x01 => PORTB: 0x2A, state: SM_Alternate',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #Alternate
    'expected': [('PORTB',0x2A)],
    },#19
    {'description': 'PINA: 0x01 => PORTB: 0x21, state: SM_OutToFill',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #OutToFill
    'expected': [('PORTB',0x21)],
    },#20
    {'description': 'PINA: 0x01 => PORTB: 0x00, state: SM_INIT',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}], #INIT
    'expected': [('PORTB',0x00)],
    },
    ]

# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
watch = ['state']

