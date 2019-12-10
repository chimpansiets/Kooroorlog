.name       "Jemoer"
.comment    "This city needs me"

loop:
        sti r1, %:live, %1
live:
        live %1
        ld %0, r2
        zjmp %:loop
