#!/bin/sh
### BEGIN INIT INFO
# Provides:          esme-pwm
# Required-Start:    $remote_fs $time
# Required-Stop:     $remote_fs $time
# Default-Start:     345
# Default-Stop:      0126
# Short-Description: ESME PWM#0 GPIO#12 animation service
### END INIT INFO

# Définir le chemin du programme
PROGRAM="/usr/bin/esme-pwm-gpio12"
NAME="esme-pwm-gpio12"

# Fonction pour démarrer le programme
start() {
    echo "Démarrage de $NAME..."
    start-stop-daemon --start --background --exec $PROGRAM
}

# Fonction pour arrêter le programme
stop() {
    echo "Arrêt de $NAME..."
    start-stop-daemon --stop --exec $PROGRAM
}

# Fonction pour redémarrer le programme
restart() {
    stop
    start
}

# Fonction pour afficher le statut
status() {
    PID=$(pgrep -x "$NAME")
    if [ -n "$PID" ]; then
        echo "Status of $NAME : running with PID=$PID"
    else
        echo "Status of $NAME : stopped"
    fi
}

# Vérification de l'argument passé au script
case "$1" in
    start)
        start
        ;;
    stop)
        stop
        ;;
    restart)
        restart
        ;;
    status)
        status
        ;;
    *)
        echo "Usage : esme-pwm (start | stop | restart | status)"
        exit 1
        ;;
esac

