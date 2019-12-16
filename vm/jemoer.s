.name       "Jemoer"
.comment    "This city needs me"

loop:
        sti r1, %:live, %1
live:
        live %1
        st r1, 100
        zjmp %:loop
