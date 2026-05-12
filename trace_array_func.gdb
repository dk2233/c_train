# Nie wyświetlamy potwierdzeń przy przeładowaniu
set confirm off
#do we need to see every commands?
set trace-command off

define diag1
    printf "--- Diagnostyka Funkcji ---\n"
    # Wyświetla adres i plik/linię
    i args
    info line
     frame
     where 3
    disassemble $pc, +20 
    printf "Adres w rejestrze PC: %p\n", $pc
    printf "---------------------------\n"
end

b check_array_argument
set $bp1 = $bpnum


commands $bp1
    printf "arrays argument function\n no copy of array argument\n\n"
    diag1
    printf "argument address %p\n\n", tab
    i args
    #set $addr=&array_int
end 

start 

p/x tab_test 

c

p/x &tab_test
p tab_test
printf "address of array_int %p argument of this function %p\n", &tab_test, tab
printf "using of address argument does not copy whole array to function \n"
