tests = [ {'description': 'PINA:0x00 => PORTB: 0x0F',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}], #INIT
    'expected': [('PORTB',0x0F)],
    },
    ]
#watch = ['<function>::<static-var>','PORTB']

