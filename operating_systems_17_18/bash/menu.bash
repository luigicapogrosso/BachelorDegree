#!/bin/bash

################################################################################
_menu() {
    echo -e "\nMonitoraggio server. Comandi disponibili:"
    echo "1) Inizia monitoraggio"
    echo "2) Ferma monitoraggio"
    echo "3) Stampa info utilizzo"
    echo "4) Chiudi"
    echo "5) Ottimizza spazio"
    read -p "Inserisci numero comando[1-5]: " choose
    case $choose in
        "1")
            _start_monitoring;;
        "2")
            _stop_monitoring;;
        "3")
            _print_info;;
        "4")
            _exit;;
        "5")
            _reduce_space;;
    esac
}
################################################################################
_is_running() {
    run=$(ps -ef | grep "$name" | grep --invert-match "grep")
    echo $run
}
################################################################################
_start_monitoring() {
    name="recorder.bash"
    running=$(_is_running $name)
    # Se l'operando ha lunghezza uguale a zero lo script recorder.bash viene
    # eseguito.
    if [[ -z "$running" ]]; then
        bash recorder.bash &
        echo "Monitoraggio avviato."
    fi
}
################################################################################
_stop_monitoring() {
    name="recorder.bash"
    running=$(_is_running $name)
    process_pid=$(ps -ef                          | \
                  tr --squeeze-repeats ' '        | \
                  grep "recorder.bash"            | \
                  grep --invert-match "grep"      | \
                  cut --delimiter ' ' --field 2)
    # Se l'operando ha lunghezza diversa da zero lo script recorder.bash viene
    # fermato.
    if [[ -n "$running" ]]; then
        kill -13 $process_pid
        echo "Monitoraggio fermato [$process_pid]."
    fi
}
################################################################################
_print_info() {
    bash query.bash
}
################################################################################
_exit() {
    exit;
}
################################################################################
_reduce_space() {
    name="checkSpace.bash"
    running=$(_is_running $name)
    if [[ -z "$running" ]]; then
        bash checkSpace.bash
    fi
}
################################################################################
while [[ true ]];
do
    _menu
done
