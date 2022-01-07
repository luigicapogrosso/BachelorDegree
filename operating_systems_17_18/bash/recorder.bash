#!/bin/bash

SLEEP_FOR=1s

################################################################################
_set_csv_filename() {
    date=$(date +%Y%m%d_%H%M%S)
    echo $date
}
################################################################################
_set_csv_formatline() {
    u=$(echo $line | cut --delimiter ' ' --field 1)   # Utente
    p=$(echo $line | cut --delimiter ' ' --field 2)   # Pid del processo
    c=$(echo $line | cut --delimiter ' ' --field 5)   # Nome del processo
    s=$(echo $line | cut --delimiter ' ' --field 3)   # Tempo di inizio
    t=$(echo $line | cut --delimiter ' ' --field 4)   # Tempo di esecuzione CPU

    # Se il processo è stato eseguito oltre le 24 ore cambia il
    # formato relativo al tempo di inizio in "Mmm dd".
    if [[ ${#s} -lt 8 ]]; then
        c=$(echo $line | cut --delimiter ' ' --field 6)
        s+=$(echo " $(echo $line | cut --delimiter ' ' --field 4)")
        t=$(echo $line | cut --delimiter ' ' --field 5)
    fi

    echo "$u;$p;$c;$s;$t"
}
################################################################################
while [[ true ]];
do
    csv_filename="report_$(_set_csv_filename).csv"
    while read line;
    do
        csv_formatline=$(_set_csv_formatline $line)
        echo "$csv_formatline" >> "$csv_filename"
    done <<< "$(ps --no-headers -eo user:32,pid,start,time,command | \
                tr --squeeze-repeats ' ')"
    sleep $SLEEP_FOR
done
