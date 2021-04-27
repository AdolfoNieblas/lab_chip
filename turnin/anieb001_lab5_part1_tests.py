# Array of tests to run (in order)
tests = [ {'description': 'PINA: 0x00 => PORTC: 0x00',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 1 } ],
    'expected': [('PORTC',0x40)],
    },
    {'description': 'PINA: 0x04 => PORTC: 0x70',
    'steps': [ {'inputs': [('PINA',0x04)], 'iterations': 1 } ],
    'expected': [('PORTC',0x70)],
    },
    {'description': 'PINA: 0x0F => PORTC: 0x3F',
    'steps': [ {'inputs': [('PINA',0x0F)], 'iterations': 1 } ],
    'expected': [('PORTC',0x3F)],
    },
    {'description': 'PINA: 0xFF => PORTC: 0x3F',
    'steps': [ {'inputs': [('PINA',0xFF)], 'iterations': 1 } ],
    'expected': [('PORTC',0x3F)],
    },
    {'description': 'PINA: 0x3F => PORTC: 0x3F',
    'steps': [ {'inputs': [('PINA',0x3F)], 'iterations': 1 } ],
    'expected': [('PORTC',0x3F)],
    },
    {'description': 'PINA: 0x00 => PORTC: 0x40',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 1 } ],
    'expected': [('PORTC',0x40)],
    },
    ]
#watch = ['PORTB']
