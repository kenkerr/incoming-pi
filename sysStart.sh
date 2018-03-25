SYSTEM=$(uname -a)

if [[ $SYSTEM == *"raspberrypi"* ]]; then
    echo "Starting incoming on Pi"
    BINDIR="~/projects/incoming/bin"
    CFGDIR=~/projects/incoming/config
    MY_EVENT_LOG=~/projects/incoming/logs/event.log
else
    echo "Starting incoming on MAC"
    BINDIR="/Users/kenkerr/projects/incoming-pi/bin"
    CFGDIR=/Users/kenkerr/projects/incoming-pi/config
    MY_EVENT_LOG=/Users/kenkerr//projects/incoming-pi/logs/event.log
fi

export MY_EVENT_LOG
export CFGDIR
$BINDIR/configure
$BINDIR/io
$BINDIR/cmdServer
