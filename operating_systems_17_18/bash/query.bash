#!/bin/bash

NAME_REGEX="^[a-z][-a-z0-9_]*$"

# Ordino solo i file con estensione ".csv" in modo alfabetico.
# L'ultimo quindi, quello con la data più giovane, è il meno recente.
last_report=$(find *.csv | sort --dictionary-order | tail --lines 1)
echo "Last report: $last_report"

# Stampa sullo standard output del file.
# Selezione del solo primo campo del file.
# Ordino le linee della prima colonna in modo alfabetico.
# Rimozione delle linee ripetute.
users=$(cat $last_report              | \
        cut --delimiter ';' --field 1 | \
        sort --dictionary-order       | \
        uniq)
for user in $users;
do
    n=$(grep $user $last_report | wc --words)
    echo "$user: $n"
done

# Il controllo relativo al nome degli utenti avviene secondo la seguente
# espressione regolare:
# ^             --> posizione iniziale nella stringa;
# -             --> case sensitive;
# [a-z]         --> singolo carattere fra i disponibili, per la prima lettera;
# [-a-z0-9_]    --> singolo carattere fra i disponibili, per il resto del nome;
# *             --> ripetizione di zero o più volte, relatiivo all'ultima classe;
# $             --> posizione finale nella stringa;
# Tale è contenuta all'inteno /usr/share/adduser/adduser.conf.
# Difatti i nomi degli utenti in fase di creazione sono controllati rispetto a
# questa regexp. Se il nome non corrisponde la crezione viene rifiutata.
read -p "Inserire utente: " user
exit_status=0
while [[ "$exit_status" != 1 ]];
do
    if ! [[ "$user" =~ $NAME_REGEX ]]; then
        read -p "Input errato. Inserire utente: " user
    else
        exit_status=1
    fi
done

for file in $(find *.csv);
do
    n=$(grep --word-regexp "$user" "$file" | wc --words)
    echo "report: $file processi $n"
done
