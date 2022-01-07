#!/bin/bash

THRESHOLD=$((30))

################################################################################
_set_filesizes() {
    dim=$(du --total *.csv | tail --lines 1 | cut --field 1)
    echo "$(($dim))"
}
################################################################################
_check_status() {
    echo "Soglia: $THRESHOLD KB"
    echo "Spazio: $size KB"

    if [[ $size -lt $THRESHOLD ]]; then
        echo "Lo spazio occupato dai report è stato ottimizzato."
        exit;
    fi
}
################################################################################
# Se il comando ha lunghezza uguale a zero lo script termina poichè non ci
#sono file csv.
if [[ -z "$(find . -name '*.csv')" ]]; then
    echo "Non sono presenti file csv."
    exit;
fi

while [[ true ]];
do
    size=$(_set_filesizes)
    _check_status $size
    leastfile=$(find *.csv | head --lines 1)
    rm -f $leastfile
    echo "Rimosso $leastfile"
done
